#include <iostream>
#include <unistd.h>
#include <vector>
#include <wait.h>
#include <cmath>
#include <chrono>
#include "generationByCubitect/generator.hpp"
#include "generationByCubitect/finders.hpp"
#include <mutex>

std::mutex mu;
#define STRIDE 2000000000000000000
#define PROGRESS 20000
#define USE_SIMD
#define BIOME 151
#define PROCESSES 4

void signalHandler(int signum) {
    std::cout << "received SIGTERM " << signum << " on group pid : " << getgid() << std::endl;
    kill(-getgid(), SIGKILL);
}

void shared_cout(int64_t seed) {
    mu.lock();
    std::cout <<  "seed hit: " <<seed<< std::endl;
    mu.unlock();
}

void gen(int process) {
    initBiomes();
    LayerStack g = setupGenerator(MC_1_12);
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    int *map = allocCache(&g.layers[g.layerNum - 1], 1, 1);
    Pos pos = {0, 0};

    for (int64_t seed = (process * STRIDE);
         seed < (STRIDE + process * STRIDE); seed++) {

        if (seed % PROGRESS == 0 && !process) {
            std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
                    t2 - t1);
            std::cout << "We are on thread  " << process << " at: " << seed << " and it took me " << time_span.count()
                      << " seconds." << std::endl;
        }
        applySeed(&g, (int64_t) seed);

        genArea(&g.layers[g.layerNum - 1], map, pos.x, pos.z, 1, 1);
        if (map[0] == BIOME) {
            shared_cout( seed);
        }

    }
    free(map);
    freeGenerator(g);
    exit(0);

}

int return_id(std::vector<pid_t> &array) {
    int retval = 0;
    for (int i = 0; i < (int) array.size(); i++) {
        retval += (array[i] > 0 ? 1 : 0) * (int) pow(2, i);
    }
    return retval;
}

void handler(int processes, pid_t pidMain) {
    std::vector<pid_t> pids;
    switch (processes) {
        case 2: {
            pid_t pid1 = fork();
            pids.push_back(pid1);
            break;
        }
        case 4: {
            pid_t pid1 = fork();
            pid_t pid2 = fork();
            pids.push_back(pid1);
            pids.push_back(pid2);
            break;
        }
        case 8: {
            pid_t pid1 = fork();
            pid_t pid2 = fork();
            pid_t pid3 = fork();
            pids.push_back(pid1);
            pids.push_back(pid2);
            pids.push_back(pid3);
            break;
        }
        default: {
            processes = 1;
        }
    }
    setpgid(getpid(), pidMain);
    gen(return_id(pids));
}

int main() {
    pid_t pidMain = fork();
    if (pidMain == 0) {
        handler(PROCESSES, getppid());
    } else {
        setpgid(getpid(), getpid());
        signal(SIGTERM, signalHandler);
        while (waitpid(0, nullptr, WCONTINUED) != -1) {}
    }
    std::cout << "Done.";
}

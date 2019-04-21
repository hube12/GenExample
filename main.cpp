#include <iostream>
#include <unistd.h>
#include <vector>
#include <wait.h>
#include <cmath>
#include <chrono>
#include "generationByCubitect/generator.hpp"
#include "generationByCubitect/finders.hpp"

#define USE_SIMD

void signalHandler(int signum) {
    std::cout << "received SIGTERM " << signum << " on group pid : " << getgid() << std::endl;
    kill(-getgid(), SIGKILL);
}

void gen(int process) {
    initBiomes();
    LayerStack g = setupGenerator(MC_1_12);
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    for (int64_t seed = (400000000000 + 3620000 + process * 400000000000);
         seed < (800000000000 + 3620000 + process * 400000000000); seed++) {
        int64_t seed2 = seed;
        if (seed % 10000 == 0 && !process) {
            std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(
                    t2 - t1);
            std::cout << "We are on thread  " << process << " at: " << seed << " and it took me " << time_span.count()
                      << " seconds." << std::endl;
            std::string stde="curl -s -X POST https://api.telegram.org/bot830618853:AAGbhpAtk0RJgQ97KmCTQpxeyB6vveD2OJU/sendMessage "
                         "-d chat_id=616875529 -d text=\"We are at "+std::to_string(seed)+" with time "+std::to_string(time_span.count())+"since epoch\"";
            system(stde.c_str());
        }
        applySeed(&g, (int64_t) seed);
        bool hasJungle = false;
        bool hasRoofedForest = false;
        bool hasSavanna = false;
        bool hasSpruce = false;
        int *map = allocCache(&g.layers[g.layerNum - 1], 256, 256);
        Pos pos = getSpawn(MC_1_12, &g, map, seed2);
        genArea(&g.layers[g.layerNum - 1], map, pos.x , pos.z , 80, 80);

        for (long z = 0; z < 80 * 80; z++) {
            int biome = map[z];
            if (biome == 21 || biome == 22 || biome == 23)hasJungle = true;
            else if (biome == 29)hasRoofedForest = true;
            else if (biome == 35 || biome == 36)hasSavanna = true;
            else if (biome == 3 || biome == 5 || biome == 19 || biome == 30 || biome == 31 || biome == 32 ||
                     biome == 33 || biome == 133 || biome == 158 || biome == 160 || biome == 161)
                hasSpruce = true;
        }

        if (hasJungle && hasRoofedForest && hasSavanna && hasSpruce){
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Found good seed : " << seed << ".\n";
            std::string stde="curl -s -X POST https://api.telegram.org/bot830618853:AAGbhpAtk0RJgQ97KmCTQpxeyB6vveD2OJU/sendMessage "
                             "-d chat_id=616875529 -d text=\"Found good seed : " +std::to_string(seed)+"\"";
            system(stde.c_str());
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }

        free(map);
    }
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
    int processes = 8;
    pid_t pidMain = fork();
    if (pidMain == 0) {
        handler(processes, getppid());
    } else {
        setpgid(getpid(), getpid());
        signal(SIGTERM, signalHandler);
        while (waitpid(0, nullptr, WCONTINUED) != -1) {}
    }
    std::cout << "Done.";
    system("pause");
}

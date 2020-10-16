#include <iostream>
#include <vector>
#include <chrono>
#include "generationByCubitect/generator.h"
#include <mutex>


void gen() {
    initBiomes();
    LayerStack g;
    setupGenerator(&g, MC_1_7);
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    int *map = allocCache(&g.layers[L_RIVER_MIX_4], 57, 57);
    applySeed(&g, (int64_t) 10928L);
    genArea(&g.layers[L_RIVER_MIX_4], map, 130, 174, 57, 57);
    for (int i = 0; i < 50; ++i) {
        printf("%d: %d\n", i, map[i]);
    }
    free(map);
    exit(0);

}


int main() {
    gen();
}

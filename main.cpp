#include <iostream>
#include "generationByCubitect/generator.hpp"

int gen(int64_t seed,versions version, long x, long z){
    initBiomes();
    LayerStack g = setupGenerator(version);
    applySeed(&g, (int64_t) seed);
    int *map = allocCache(&g.layers[g.layerNum - 1], 1, 1);
    genArea(&g.layers[g.layerNum - 1], map, x, z, 1, 1);
    int biomeID = map[0];
    return biomeID;
}

int main() {
    std::cout << gen(1,MC_1_12,1,1) << std::endl;
    return 0;
}



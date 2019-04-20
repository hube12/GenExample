#include <iostream>
#include "generationByCubitect/generator.hpp"

int gen(int64_t seed,versions version, long x, long z, long sizeX, long sizeZ){
    initBiomes();
    LayerStack g = setupGenerator(version);
    applySeed(&g, (int64_t) seed);
    int *map = allocCache(&g.layers[g.layerNum - 1], sizeX, sizeZ);
    genArea(&g.layers[g.layerNum - 1], map, x, z, sizeX, sizeZ);
    for (long long i=0;i<sizeX*sizeZ;i++){
        std::cout << map[i] << " ";
    }
    std::cout<<std::endl;
    free(map);
    freeGenerator(g);
    return 0;
}

int main() {
    std::cout << gen(1,MC_1_12,1,1,10,10) << std::endl;
    return 0;
}



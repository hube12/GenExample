#include <iostream>
#include "generationByCubitect/generator.hpp"

int gen(int64_t seed,versions version, long x, long z, int sizeX, int sizeZ){
    initBiomes();
    LayerStack g = setupGenerator(version);
    applySeed(&g, (int64_t) seed);
    int *map = allocCache(&g.layers[g.layerNum - 1], sizeX, sizeZ);
    genArea(&g.layers[g.layerNum - 1], map, x, z, sizeX, sizeZ);
    for (int i=0;i<sizeX;i++){
        for (int j=0;j<sizeZ;j++){
            std::cout << map[i*sizeZ+j] << " ";
        }
        std::cout<<std::endl;
    }
    free(map);
    freeGenerator(g);
    return 0;
}

int main() {
    return gen(1,MC_1_12,1,1,100,100);
}



#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
#include <fstream>

#include "generationByCubitect//javarnd.h"
#include <iostream>
#include "generationByCubitect/layers.h"
#include "generationByCubitect/finders.h"
#include "generationByCubitect/generator.h"
#include <math.h>
#include <vector>
#include <iomanip>

void getStrongholdPositions(int64_t* worldSeed, int SH, Pos* out)
{
    const char* isStrongholdBiome = getValidStrongholdBiomes();

    LayerStack g;
    setupGenerator(&g, MC_1_7);
    applySeed(&g, *worldSeed);

    Layer *l = &g.layers[L_RIVER_MIX_4];

    setSeed(worldSeed);
    long double angle = nextDouble(worldSeed) * PI * 2.0;
    int var6 = 1;

    //1 here determines how many strongholds to generate
    for (int var7 = 0; var7 < SH; ++var7)
    {
        long double distance = (1.25 * (double)var6 + nextDouble(worldSeed)) * 32.0 * (double)var6;
        int x = (int)round(cos(angle) * distance);
        int z = (int)round(sin(angle) * distance);

        std::cout << "X - " << x << " Z - " << z << std::endl;

        Pos biomePos = findBiomePosition(MC_1_7, l, NULL, (x << 4) + 8, (z << 4) + 8, 112, isStrongholdBiome, worldSeed, NULL);

        out[var7].x = biomePos.x >> 4;
        out[var7].z = biomePos.z >> 4;

        angle += 2 * PI / 3.0;
    }
}

void generate(int64_t worldSeed) {
    initBiomes();

    int64_t seedCopy = worldSeed; //save the original seed for later use

    Pos strongholdPos[1];
    getStrongholdPositions(&seedCopy, 1, strongholdPos);

    for(int i = 0; i < 1; i++) {
        std::cout << "X: " << strongholdPos[i].x << " Z: " << strongholdPos[i].z << std::endl;
    }
}

int main(int argc, char *argv[]) {
    long long totalSeeds = 1;

    clock_t startTime = clock();
    int64_t seed = 10928;
    generate(seed);
    clock_t endTime = clock();

    double total_t = ((double)(endTime - startTime));
    printf("Total time spent: %f seconds | Total seeds: %lld | Seeds/second: %f", total_t / 1000, totalSeeds, totalSeeds / total_t * 1000);
    return 0;
}
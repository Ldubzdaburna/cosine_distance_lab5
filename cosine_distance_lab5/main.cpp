#include "cos_distance.h"
#include <iostream>

int main() {
    const std::string filename = "vectors.txt";

    auto vectors = readVectorsFromFile(filename);
    if (vectors.empty()) {
        std::cerr << "No vectors found in " << filename << "!" << std::endl;
        return 1;
    }

    auto results = computeAllPairwiseDistances(vectors);
    printResults(results);

    return 0;
}
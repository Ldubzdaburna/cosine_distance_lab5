#include "cos_distance.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>


std::vector<Vector> readVectorsFromFile(const std::string& filename) {
    std::vector<Vector> vectors;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Vector vec;
        double val;
        while (iss >> val) {
            vec.push_back(val);
        }
        if (!vec.empty()) {
            vectors.push_back(vec);
        }
    }

    return vectors;
}

double dotProduct(const Vector& a, const Vector& b) { // Corrected
    double dot = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];
    }
    return dot;
}

double magnitude(const Vector& v) {
    return std::sqrt(dotProduct(v, v));
}

double cosineDistance(const Vector& a, const Vector& b) {
    double magA = magnitude(a);
    double magB = magnitude(b);
    if (magA == 0.0 || magB == 0.0) {
        return 1.0; // Define distance as 1 if one of the vectors is zero-vector
    }
    double sim = dotProduct(a, b) / (magA * magB);
    return 1.0 - sim;
}

std::vector<Result> computeAllPairwiseDistances(const std::vector<Vector>& vectors) {
    std::vector<Result> results;

    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double dist = cosineDistance(vectors[i], vectors[j]);
            results.push_back({{static_cast<int>(i), static_cast<int>(j)}, dist});
        }
    }
    std::sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
        return a.distance < b.distance;
    });

    return results;
}

void printResults(const std::vector<Result>& results) {
    std::cout << std::fixed << std::setprecision(8); // Adjust precision as needed
    for (const auto& result : results) {
        std::cout << result.indices.first << " " << result.indices.second 
                  << " cos dist = " << result.distance << std::endl;
    }
}
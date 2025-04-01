#ifndef COS_DISTANCE_H
#define COS_DISTANCE_H

#include <vector>
#include <string>
#include <iomanip> 
#include <iostream>

using Vector = std::vector<double>;
using VectorPair = std::pair<int, int>;


struct Result {
    VectorPair indices;
    double distance;
};
std::vector<Vector> readVectorsFromFile(const std::string& filename);
double cosineDistance(const Vector& a, const Vector& b);
std::vector<Result> computeAllPairwiseDistances(const std::vector<Vector>& vectors);
void printResults(const std::vector<Result>& results);

#endif
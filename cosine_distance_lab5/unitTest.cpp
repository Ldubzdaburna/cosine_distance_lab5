#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "cos_distance.h"
#include "include/doctest.h"

// Test for cosineDistance function
TEST_CASE("Test cosineDistance") {
    Vector a = {1.0, 2.0, 3.0};
    Vector b = {4.0, 5.0, 6.0};
    double expected_distance = 1.0 - (32.0 / (std::sqrt(14.0) * std::sqrt(77.0))); // Precomputed value
    CHECK(doctest::Approx(cosineDistance(a, b)) == expected_distance);

    Vector c = {1.0, 0.0};
    Vector d = {0.0, 1.0};
    CHECK(doctest::Approx(cosineDistance(c, d)) == 1.0); // Orthogonal vectors have max distance (1.0)

    Vector e = {1.0, 1.0};
    Vector f = {1.0, 1.0};
    CHECK(doctest::Approx(cosineDistance(e, f)) == 0.0); // Identical vectors have min distance (0.0)
}

// Test for computeAllPairwiseDistances function
TEST_CASE("Test computeAllPairwiseDistances") {
    std::vector<Vector> vectors = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    auto results = computeAllPairwiseDistances(vectors);

    // Check the number of results
    CHECK(results.size() == 3); // 3 pairs for 3 vectors

    // Check the distances are sorted in ascending order
    for (size_t i = 1; i < results.size(); ++i) {
        CHECK(results[i - 1].distance <= results[i].distance);
    }
}

// Test for readVectorsFromFile function
TEST_CASE("Test readVectorsFromFile") {
    // Create a temporary file with test data
    std::ofstream testFile("test_vectors.txt");
    testFile << "1.0 2.0 3.0\n";
    testFile << "4.0 5.0 6.0\n";
    testFile << "7.0 8.0 9.0\n";
    testFile.close();

    auto vectors = readVectorsFromFile("test_vectors.txt");

    // Check the number of vectors read
    CHECK(vectors.size() == 3);

    // Check the contents of the vectors
    CHECK(vectors[0] == Vector{1.0, 2.0, 3.0});
    CHECK(vectors[1] == Vector{4.0, 5.0, 6.0});
    CHECK(vectors[2] == Vector{7.0, 8.0, 9.0});

    // Clean up the temporary file
    std::remove("test_vectors.txt");
}
# Cosine Distance Calculator

This is a C++ program that reads vectors of doubles from a file, computes the pairwise cosine distances between all pairs of vectors, and outputs the results ordered by the cosine closeness of the vectors.

## Features

- Reads vectors from a text file.
- Computes all pairwise cosine distances for the vectors.
- Outputs pairs of vectors, sorted by their cosine distances.
- Supports a user-defined dimension `k` (where k >= 2).

## Requirements

To compile and run this program, you need:
- A C++ compiler that supports C++11 or later (e.g., `g++`).
- The following header files included in your environment:
  - `<fstream>`
  - `<sstream>`
  - `<iostream>`
  - `<cmath>`
  - `<vector>`
  - `<algorithm>`
  - `<iomanip>`

## File Structure

The project consists of several files:
- **`main.cpp`**: The entry point of the program, handling reading of the input and outputting results.
- **`cos_distance.h`**: Header file containing function declarations and type definitions.
- **`cos_distance.cpp`**: Implementation of functions for reading vectors, calculating cosine distances, and processing results.
- **`unitTest.cpp`**: Unit tests for validating the correctness of the implemented functions.
- **`vectors.txt`**: Sample input file containing vectors of doubles.

## Usage

1. **Prepare Input**: Create a file named `vectors.txt` with the vectors you wish to analyze. The format should have vectors separated by whitespace, for example:

    ```
    1 2.5 0.5
    1 3.6 1.9
    1 4.5 3.2
    2.7 7 6
    9 11.5 22.99
    1 1 1
    1 1 0
    ```

2. **Compile the program**: Use the following command to compile the program:

    ```bash
    g++ -std=c++11 main.cpp cos_distance.cpp unitTest.cpp -o cosine_distance_calculator
    ```

3. **Run the program**: Execute the compiled program:

    ```bash
    ./cosine_distance_calculator
    ```

4. **Output**: The program will display the pairs of vectors along with their cosine distances. For example:

    ```
    2 3 cos dist = 0.00944726
    1 2 cos dist = 0.01028360
    ...
    ```

## Testing

Unit tests are included using the [doctest](https://github.com/onqtam/doctest) framework. To run the unit tests:
- Compile the `unitTest.cpp` file with `cos_distance.cpp` and `cos_distance.h`.
- Run the resulting executable to see the test results.

## Notes

- The distance calculations are based on the cosine similarity formula. If one of the vectors is a zero-vector, the cosine distance is defined as 1.0.
- Ensure that all vectors in the input file are of the same dimensio


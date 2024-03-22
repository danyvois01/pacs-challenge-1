#ifndef ASSIGNMENT_1_UTILS_H
#define ASSIGNMENT_1_UTILS_H

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

// Struct to hold optimization data
struct Data {
    double epsilon_residual; // Tolerance for residual
    double epsilon_step;     // Tolerance for step
    double alpha_0;          // Initial step size
    double mu;               // Decay parameter
    int max_iterations;      // Maximum number of iterations
    double sigma;            // Parameter for Armijo rule
    std::vector<double> x0;  // Initial guess
    int alpha_method;        // Method for selecting alpha
};

// Typedefs for function types
typedef std::function<double(const std::vector<double>&)> Function;
typedef std::function<std::vector<double>(const std::vector<double>&)> Gradient;
typedef std::function<double(const Function&, const std::vector<double>&, const std::vector<double>&, const Data&, int)> AlphaStrategy;

// Function to compute the norm of a vector
double vector_norm(const std::vector<double>& vec) {
    double sum = 0.0;
    for (double val : vec) {
        sum += val * val;
    }
    return std::sqrt(sum);
}

// Operator overloading for vector subtraction
template<typename T>
std::vector<T> operator-(const std::vector<T>& lhs, const std::vector<T>& rhs) {
    if(lhs.size() != rhs.size()) {
        std::cerr << "Vector sizes do not match";
    }
    std::vector<T> result(lhs.size());
    for(size_t i = 0; i < lhs.size(); ++i) {
        result[i] = lhs[i] - rhs[i];
    }
    return result;
}

// Operator overloading for vector-scalar multiplication
template<typename T>
std::vector<T> operator*(const std::vector<T>& vec, const T& scalar) {
    std::vector<T> result(vec.size());
    for(size_t i = 0; i < vec.size(); ++i) {
        result[i] = vec[i] * scalar;
    }
    return result;
}

#endif // ASSIGNMENT_1_UTILS_H
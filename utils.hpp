#ifndef ASSIGNMENT_1_UTILS_HPP
#define ASSIGNMENT_1_UTILS_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

// Struct to hold optimization data
struct Data {
    double epsilon_residual = 1e-8; // Tolerance for residual
    double epsilon_step = 1e-8;     // Tolerance for step
    double alpha_0 = 0.1;           // Initial step size
    double mu = 0.3;                // Decay parameter
    int max_iterations = 100;       // Maximum number of iterations
    double sigma = 0.2;             // Parameter for Armijo rule
    std::vector<double> x0{0, 0};   // Initial guess
    int alpha_method = 0;           // Method for selecting alpha
};

// using statements for function types
using Function = std::function<double(const std::vector<double>&)>;
using Gradient = std::function<std::vector<double>(const std::vector<double>&)>;
using AlphaStrategy = std::function<double(const Function&, const std::vector<double>&, const std::vector<double>&, const Data&, const int)>;

// Define the objective function
Function f = [](const std::vector<double>& x) {
    return x[0] * x[1] + 4 * pow(x[0], 4) + pow(x[1], 2) + 3 * x[0];
};

// Define the gradient of the objective function
Gradient grad_f = [](const std::vector<double>& x) {
    return std::vector<double>{x[1] + 16*pow(x[0], 3) + 3, x[0] + 2*x[1]};
};

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

#endif // ASSIGNMENT_1_UTILS_HPP
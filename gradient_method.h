#ifndef ASSIGNMENT_1_GRADIENT_METHOD_H
#define ASSIGNMENT_1_GRADIENT_METHOD_H

#include "utils.h"

// Function to perform gradient descent optimization
std::vector<double> gradient_method(const Function& f, const Gradient& grad_f, const Data& data, const AlphaStrategy& alpha_strategy) {
    bool converged = false;
    std::vector<double> x = data.x0; // Initialize x with initial guess
    for (int k = 0; k < data.max_iterations && !converged; ++k) { // Iterate until convergence or max iterations reached
        std::vector<double> grad = grad_f(x); // Compute gradient at current point
        double alpha = alpha_strategy(f, x, grad, data, k); // Compute step size
        std::vector<double> x_new = x - grad * alpha; // Update x using gradient and step size
        // Check convergence criteria
        converged = std::abs(f(x_new) - f(x)) < data.epsilon_residual
                    || vector_norm(x_new - x) < data.epsilon_step;
        x = x_new; // Update x for next iteration
        if (converged)
            std::cout << "Converged in " << k << " iterations" << std::endl; // Print convergence message
    }
    return x; // Return the optimal point
}

// Enumeration for alpha selection methods
enum AlphaMethod {
    ARMIJO_RULE = 0,
    EXPONENTIAL_DECAY = 1,
    INVERSE_DECAY = 2
};

// Armijo rule for selecting step size
double armijo_rule(const Function & f, const std::vector<double>& x, const std::vector<double>& grad, const Data& data, int k) {
    double sigma = data.sigma;
    double alpha = data.alpha_0;

    while (f(x) - f(x - grad * alpha) < sigma * alpha * vector_norm(grad) * vector_norm(grad)) {
        alpha /= 2; // Reduce step size
    }
    return alpha; // Return selected step size
}

// Exponential decay for selecting step size
double exponential_decay(const Function & f, const std::vector<double>& x, const std::vector<double>& grad, const Data& data, int k) {
    return data.alpha_0 * exp(-data.mu * k); // Compute step size using exponential decay
}

// Inverse decay for selecting step size
double inverse_decay(const Function & f, const std::vector<double>& x, const std::vector<double>& grad, const Data& data, int k) {
    return data.alpha_0 / (1 + data.mu * k); // Compute step size using inverse decay
}

#endif // ASSIGNMENT_1_GRADIENT_METHOD_H

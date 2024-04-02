#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#include "json.hpp" // JSON library

#include "utils.hpp" // Utility functions and data structures
#include "gradient_method.hpp" // Gradient descent optimization functions

using json = nlohmann::json;

int main() {

    // Read parameters from JSON file
    std::ifstream file("data.json");
    json j = json::parse(file);

    // Extract values from JSON and assign them to the Data struct
    Data data;
    data.epsilon_residual = j.value("epsilon_residual", 1e-8); // Tolerance for residual
    data.epsilon_step = j.value("epsilon_step", 1e-8); // Tolerance for step
    data.alpha_0 = j.value("alpha_0", 0.1); // Initial step size
    data.mu = j.value("mu", 0.3); // Decay parameter
    data.max_iterations = j.value("max_iterations", 100); // Maximum number of iterations
    data.sigma = j.value("sigma", 0.2); // Parameter for Armijo rule
    std::vector<double> initial_guess = j["x0"]; // Initial guess
    data.x0 = initial_guess;
    data.alpha_method = j.value("alpha_method", 0); // Alpha selection method

    std::vector<double> x_min(2); // Variable to store the minimum point

    // Select optimization method based on alpha selection method
    if (data.alpha_method == ARMIJO_RULE) {
        std::cout << "Selected method: Armijo Rule" << std::endl;
        x_min = gradient_method(f, grad_f, data, armijo_rule);
    } else if (data.alpha_method == EXPONENTIAL_DECAY) {
        std::cout << "Selected method: Exponential Decay" << std::endl;
        x_min = gradient_method(f, grad_f, data, exponential_decay);
    } else if (data.alpha_method == INVERSE_DECAY) {
        std::cout << "Selected method: Inverse Decay" << std::endl;
        x_min = gradient_method(f, grad_f, data, inverse_decay);
    } else {
        std::cerr << "Error: alpha method not valid" << std::endl;
        return 1;
    }

    // Output the optimal point and the value of the objective function at that point
    std::cout << "x_min: (" << x_min[0] << ", " << x_min[1] << ")" << std::endl;
    std::cout << "f(x_min): " << f(x_min) << std::endl;

    return 0; // Return success
}
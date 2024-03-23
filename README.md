# pacs-challenge-1

## A gradient method for the minimization of a multivariate functions

This repository hosts the first assignment of the APSC course 2023-2024.
The C++ program implements gradient descent optimization techniques to find the minimum of a given function.
It reads input parameters from a JSON file, computes optimization, and outputs the final result.
Offers various options for adjusting step sizes, such as exponential decay, inverse decay, and Armijo rule.

## Overview

The program consists of the following components:

- `main.cpp`: This file defines the objective function and its gradient, reads the input parameters from a JSON file, and executes the optimization function.
- `utils.h`: Header file containing utility functions and data structures.
- `gradient_method.h`: Header file containing implementations of gradient descent methods and alpha methods.

## Objective Function

## Objective Function and Gradient

The specific objective function and its gradient for which optimization is performed are defined in `main.cpp`. By default, the objective function $f(x_1, x_2)$ is set to:

$$f(x) = x_1 \cdot x_2 + 4 \cdot x_1^4 + x_2^2 + 3 \cdot x_1$$

Users can modify these functions in `main.cpp` according to their optimization problem.


## Requirements

- C++ compiler with C++11 support.
- [JSON for Modern C++](https://github.com/nlohmann/json) library for JSON file parsing.

## Usage

1. Clone the repository:
2. Modify the LIB_ROOT variable in the Makefile.
3. Adjust the data.json file with your desired parameters.
4. Compile and execute the program:

```
make
./main
```

## Input Parameters

The input parameters for optimization are provided via a JSON file (`data.json`). The following parameters are supported:

- `epsilon_residual`: Tolerance for residual (default: `1e-6`).
- `epsilon_step`: Tolerance for step (default: `1e-6`).
- `alpha_0`: Initial step size (default: `0.1`).
- `mu`: Decay parameter (default: `0.2`).
- `max_iterations`: Maximum number of iterations (default: `10000`).
- `sigma`: Parameter for Armijo rule (default: `0.2`).
- `x0`: Initial guess for optimization (default: `[0.0, 0.0]`).
- `alpha_method`: Alpha selection method (`0` for Armijo rule, `1` for exponential decay, `2` for inverse decay) (default: `0`).

## Output

The program outputs the following:

- The selected optimization method.
- The optimal values of `x` where the minimum is found.
- The minimum value of the objective function `f(x)` at the optimal point.

## Example `data.json`

```json
{
  "epsilon_residual" : 1e-6,
  "epsilon_step" : 1e-6,
  "alpha_0" : 0.1,
  "mu" : 0.2,
  "max_iterations" : 10000,
  "sigma" : 0.2,
  "x0" : [0.0, 0.0],
  "alpha_method" : 0
}
```

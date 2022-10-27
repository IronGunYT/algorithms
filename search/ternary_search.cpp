/****************************************************************
 * @file
 * @brief Ternary search Algorithm
 * @details
 * Ternary search is a searching algorithm that finds maximum or minimum of a unimodal function.
 * Unimodal function is a function which first increases and then decreases or vice versa.
 *
 * ### Complexity
 *
 * Average performance  O(log3 n)
 * Worst-case space complexity  O(1)
****************************************************************/

#include <iostream>
#include <cmath>

/****************************************************************
 * @brief Ternary search algorithm
 * @param f - function to search in
 * @param l - left border of function
 * @param r - right border of function
 * @param eps - precision
 * @param is_max - true if we need to find maximum, false if we need to find minimum
 * @return minimum or maximum of function
 ****************************************************************/
double ternary_search(double (*f)(double), double l, double r, double eps, bool is_max = true) {
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2) && is_max)
            l = m1;
        else if (f(m1) > f(m2) && is_max)
            r = m2;
        else if (f(m1) > f(m2) && !is_max)
            l = m1;
        else
            r = m2;
    }
    return (l + r) / 2;
}

int main(){

    // test 1
    double result = ternary_search([](double x){return x * x;}, 0, 10, 0.0001);
    std::cout << "Test 1" << std::endl;
    std::cout << "ternary_search([](double x){return x * x;}, 0, 10, 0.0001) = " << result << std::endl;
    std::cout << "correct answer = 10" << std::endl;
    if(fabs(result - 10) < 0.0001)
        std::cout << "Test 1 passed" << std::endl;
    else
        std::cout << "Test 1 failed" << std::endl;
    std::cout << std::endl;

    // test 2
    double result2 = ternary_search([](double x){return -x * x;}, 0, 10, 0.0001);
    std::cout << "Test 2" << std::endl;
    std::cout << "ternary_search([](double x){return -x * x;}, 0, 10, 0.0001) = " << result2 << std::endl;
    std::cout << "correct answer = 0" << std::endl;
    if(fabs(result2) < 0.0001)
        std::cout << "Test 2 passed" << std::endl;
    else
        std::cout << "Test 2 failed" << std::endl;
    std::cout << std::endl;

    // test 3
    double result3 = ternary_search([](double x){return x * x;}, 0, 10, 0.0001, false);
    std::cout << "Test 3" << std::endl;
    std::cout << "ternary_search([](double x){return x * x;}, 0, 10, 0.0001, false) = " << result3 << std::endl;
    std::cout << "correct answer = 0" << std::endl;
    if(fabs(result3) < 0.0001)
        std::cout << "Test 3 passed" << std::endl;
    else
        std::cout << "Test 3 failed" << std::endl;
    std::cout << std::endl;

    return 0;
}

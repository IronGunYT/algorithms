/****************************************************************
 * @file
 * @brief Ternary search Algorithm
 * @details
 * Ternary search is a searching algorithm that finds maximum or minimum of a unimodal function.
 * Unimodal function is a function which first increases and then decreases or vice versa.
 * Ternary search can also be used to find an element in an array.
 *
 * ### Complexity
 *
 * Average performance  O(log3 n)
 * Worst-case space complexity  O(1)
****************************************************************/

#include <iostream>
#include <cmath>
#include <vector>

/****************************************************************
 * @brief Ternary search algorithm
 * @param arr - array to search in
 * @param val - value to search
 * @return index of key in array or -1 if not found
 ****************************************************************/
template <typename T>
T ternary_search(std::vector<T> &arr, T val){
    int left = 0;  // left border of array
    int right = arr.size() - 1;  // right border of array

    while(left <= right){
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // if mid1 or mid2 is val, return it, else update borders
        if(arr[mid1] == val)
            return mid1;
        if(arr[mid2] == val)
            return mid2;

        // update borders
        if(val < arr[mid1])
            right = mid1 - 1;
        else if(val > arr[mid2])
            left = mid2 + 1;
        else{
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}

/****************************************************************
 * @brief Ternary search on function algorithm
 * @param f - function to search in
 * @param l - left border of function
 * @param r - right border of function
 * @param eps - precision
 * @param is_max - true if we need to find maximum, false if we need to find minimum
 * @return minimum or maximum of function
 ****************************************************************/
double ternary_search_function(double (*f)(double), double l, double r, double eps, bool is_max = true) {
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
    // region test 1
    double result = ternary_search_function([](double x){return x * x;}, 0, 10, 0.0001);
    std::cout << "Test 1" << std::endl;
    std::cout << "ternary_search([](double x){return x * x;}, 0, 10, 0.0001) = " << result << std::endl;
    std::cout << "correct answer = 10" << std::endl;
    if(fabs(result - 10) < 0.0001)
        std::cout << "Test 1 passed" << std::endl;
    else
        std::cout << "Test 1 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 2
    double result2 = ternary_search_function([](double x){return -x * x;}, 0, 10, 0.0001);
    std::cout << "Test 2" << std::endl;
    std::cout << "ternary_search([](double x){return -x * x;}, 0, 10, 0.0001) = " << result2 << std::endl;
    std::cout << "correct answer = 0" << std::endl;
    if(fabs(result2) < 0.0001)
        std::cout << "Test 2 passed" << std::endl;
    else
        std::cout << "Test 2 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 3
    double result3 = ternary_search_function([](double x){return x * x;}, 0, 10, 0.0001, false);
    std::cout << "Test 3" << std::endl;
    std::cout << "ternary_search([](double x){return x * x;}, 0, 10, 0.0001, false) = " << result3 << std::endl;
    std::cout << "correct answer = 0" << std::endl;
    if(fabs(result3) < 0.0001)
        std::cout << "Test 3 passed" << std::endl;
    else
        std::cout << "Test 3 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 4
    std::vector<int> arr4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result4 = ternary_search(arr4, 5);
    std::cout << "Test 4" << std::endl;
    std::cout << "ternary_search({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5) = " << result4 << std::endl;
    std::cout << "correct answer = 4" << std::endl;
    if(result4 == 4)
        std::cout << "Test 4 passed" << std::endl;
    else
        std::cout << "Test 4 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 5
    std::vector<int> arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result5 = ternary_search(arr5, 11);
    std::cout << "Test 5" << std::endl;
    std::cout << "ternary_search({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 11) = " << result5 << std::endl;
    std::cout << "correct answer = -1" << std::endl;
    if(result5 == -1)
        std::cout << "Test 5 passed" << std::endl;
    else
        std::cout << "Test 5 failed" << std::endl;
    std::cout << std::endl;
    // endregion
    return 0;
}

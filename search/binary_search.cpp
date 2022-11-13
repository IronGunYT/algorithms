/****************************************************************
 * @file
 * @brief Binary Search Algorithm
 * @details
 * Binary Search is a searching algorithm that finds the position of a target value within a sorted array.
 *
 * ### Complexity
 *
 * Worst-case performance  O(log n)
 * Best-case performance  O(1)
 * Average performance  O(log n)
 * Worst-case space complexity  O(1)
****************************************************************/

#include <vector>
#include <cmath>
#include <iostream>

/****************************************************************
 * @brief Binary search algorithm
 * @param arr - array to search in
 * @param val - value to search
 * @return index of key in array or -1 if not found
 ****************************************************************/
template <typename T>
T binary_search(std::vector<T> &arr, T val) {
    int left = 0;  // left border of array
    int right = arr.size() - 1;  // right border of array

    while(left <= right){
        int mid = left + (right - left) / 2;
        // if mid is val, return it, else update borders
        if(arr[mid] == val)
            return mid;
        else if(val < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

/****************************************************************
 * @brief Binary search on function algorithm
 * @param func - monotonically increasing function to search in
 * @param val - value to search
 * @param left - left border of function
 * @param right - right border of function
 * @param eps - precision of search
 * @return argument of function that is equal to val
 ****************************************************************/
template <typename T>
T binary_search_function(T (*func)(T), T val, T left = 0, T right = 1e3, T eps = 1e-6){
    while(right - left > eps){
        T mid = left + (right - left) / 2;
        if(func(mid) < val)
            left = mid;
        else
            right = mid;
    }
    return (left + right) / 2;
}

int main(){
    // region test 1
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result = binary_search(arr, 5);
    std::cout << "Test 1" << std::endl;
    std::cout << "arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}" << std::endl;
    std::cout << "binary_search(arr, 5) = " << result << std::endl;
    std::cout << "correct answer = 4" << std::endl;
    if(result == 4)
        std::cout << "Test 1 passed" << std::endl;
    else
        std::cout << "Test 1 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 2
    std::vector<double> arr2 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    int result2 = binary_search(arr2, 5.5);
    std::cout << "Test 2" << std::endl;
    std::cout << "arr2 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1}" << std::endl;
    std::cout << "binary_search(arr2, 5.5) = " << result2 << std::endl;
    std::cout << "correct answer = 4" << std::endl;
    if(result2 == 4)
        std::cout << "Test 2 passed" << std::endl;
    else
        std::cout << "Test 2 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 3
    std::vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int result3 = binary_search(arr3, 11);
    std::cout << "Test 3" << std::endl;
    std::cout << "arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}" << std::endl;
    std::cout << "binary_search(arr, 11) = " << result3 << std::endl;
    std::cout << "correct answer = -1" << std::endl;
    if(result3 == -1)
        std::cout << "Test 3 passed" << std::endl;
    else
        std::cout << "Test 3 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 4
    float x = 9.;
    auto result4 = binary_search_function<float>([](float x){return x * x;}, x, 0, x);
    std::cout << "Test 4" << std::endl;
    std::cout << "x = 9" << std::endl;
    std::cout << "binary_search_function<float>([](float x){return x * x;}, x, 0, x) = " << result4 << std::endl;
    std::cout << "correct answer = 3" << std::endl;
    if(fabs(result4 - 3) <= 1e-6)
        std::cout << "Test 4 passed" << std::endl;
    else
        std::cout << "Test 4 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 5
    float x2 = 29.12;
    auto result5 = binary_search_function<float>([](float x){return x*x*x;}, x2, 1, x2, 1e-4);
    std::cout << "Test 5" << std::endl;
    std::cout << "x2 = 9" << std::endl;
    std::cout << "binary_search_function<float>([](float x){return x*x*x;}, x2, 1, x2, 1e-4) = " << result5 << std::endl;
    std::cout << "correct answer = 3.0766" << std::endl;
    if(fabs(result5 - 3.0766) <= 1e-4)
        std::cout << "Test 5 passed" << std::endl;
    else
        std::cout << "Test 5 failed" << std::endl;
    std::cout << std::endl;
    // endregion

    return 0;
}

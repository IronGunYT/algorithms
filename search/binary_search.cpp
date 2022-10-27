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

int main(){
    // test 1
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

    // test 2
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

    // test 3
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
    return 0;
}

/****************************************************************
 * @file
 * @brief Bubble Sort Algorithm
 * @details
 * Bubble Sort is the simplest sorting algorithm that works by repeatedly
 * swapping the adjacent elements if they are in wrong order
 *
 * ### Complexity
 * Sort :  O(n^2)
 * Space Complexity : O(1)
****************************************************************/

#include <iostream>
#include <vector>

/****************************************************************
 * @brief Bubble Sort algorithm
 * @param arr - array to sort
 * @param func - comparison function
 ****************************************************************/
template <typename T>
void bubble_sort(std::vector<T> &arr, bool (*func)(T, T)) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!func(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
bool comp(T a, T b){return a > b;}

int main(){
    // region test 1
    std::vector<int> v1({5, 4, 3, 2, 1});
    for(auto i: v1)
        std::cout << i << " ";
    std::cout << std::endl;
    bubble_sort(v1, comp);
    for(auto i: v1)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion

    // region test 2
    std::vector<int> v2;
    bubble_sort(v2, comp);
    // endregion

    // region test 3
    std::vector<double> v3({1.1, -3.5, 2.3, 1123.3});
    for(auto i: v3)
        std::cout << i << " ";
    std::cout << std::endl;
    bubble_sort(v3, comp);
    for(auto i: v3)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion

    // region test 3
    std::vector<std::string> v4({"abc", "a", "aaa", "zxc"});
    for(auto i: v4)
        std::cout << i << " ";
    std::cout << std::endl;
    bubble_sort(v4, comp);
    for(auto i: v4)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion
}

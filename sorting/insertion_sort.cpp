/****************************************************************
 * @file
 * @brief Insertion Sort Algorithm
 * @details
 * Insertion sort is a simple sorting algorithm that builds the final
 * sorted array (or list) one item at a time.
 *
 * ### Complexity
 * Sort :  O(n^2)
 * Space Complexity : O(1)
****************************************************************/

#include <iostream>
#include <vector>

/****************************************************************
 * @brief Insertion Sort algorithm
 * @param arr - array to sort
 * @param func - comparison function
 ****************************************************************/
template <typename T>
void insertion_sort(std::vector<T> &arr, bool (*func)(T, T)) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && !func(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertion_sort(v1, comp);
    for(auto i: v1)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion

    // region test 2
    std::vector<int> v2;
    insertion_sort(v2, comp);
    // endregion

    // region test 3
    std::vector<double> v3({1.1, -3.5, 2.3, 1123.3});
    for(auto i: v3)
        std::cout << i << " ";
    std::cout << std::endl;
    insertion_sort(v3, comp);
    for(auto i: v3)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion

    // region test 3
    std::vector<std::string> v4({"abc", "a", "aaa", "zxc"});
    for(auto i: v4)
        std::cout << i << " ";
    std::cout << std::endl;
    insertion_sort(v4, comp);
    for(auto i: v4)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion
}

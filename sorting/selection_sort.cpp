/****************************************************************
 * @file
 * @brief Selection Sort Algorithm
 * @details
 * Selection Sort is the sorting algorithm that works by repeatedly
 * finding the minimum element from unsorted part and putting it at the beginning.
 *
 * ### Complexity
 * Sort :  O(n^2)
 * Space Complexity : O(1)
****************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

/****************************************************************
 * @brief Selection Sort algorithm
 * @param arr - array to sort
 * @param func - comparison function
 ****************************************************************/
template <typename T>
void selection_sort(std::vector<T> &arr, bool (*func)(T, T)) {
    for(auto i = arr.begin(); i != arr.end(); i++){
        auto min_el = std::min_element(i, arr.end(), func);
        std::swap(*i, *min_el);
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
    selection_sort(v1, comp);
    for(auto i: v1)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion

    // region test 2
    std::vector<int> v2;
    selection_sort(v2, comp);
    // endregion

    // region test 3
    std::vector<double> v3({1.1, -3.5, 2.3, 1123.3});
    for(auto i: v3)
        std::cout << i << " ";
    std::cout << std::endl;
    selection_sort(v3, comp);
    for(auto i: v3)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion

    // region test 3
    std::vector<std::string> v4({"abc", "a", "aaa", "zxc"});
    for(auto i: v4)
        std::cout << i << " ";
    std::cout << std::endl;
    selection_sort(v4, comp);
    for(auto i: v4)
        std::cout << i << " ";
    std::cout << std::endl;
    // endregion
}

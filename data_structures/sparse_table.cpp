/****************************************************************
 * @file
 * @brief Sparse Table Data Structure
 * @details
 * Sparse Table is a data structure, that allows answering range queries.
 * Operation: find maximum or minimum element in a subsection of elements in O(1)
 *
 * If any element in the array changes, the whole array is rebuilt.
 *
 * ### Complexity
 *
 * Build : O(n*logn)
 * Range Query : O(1)
 * Update : O(n*logn)
 * Space Complexity : O(n*logn)
****************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class SparseTable{
    std::vector<std::vector<T>> table;
    std::vector<int> logs;
    int n;  // size of input array
    T (*func)(T, T);  // function to use for range queries

    /**
     * @brief Fills the table with the values of the input array
     * @param arr
     */
    void build(std::vector<T> &arr){
        for(int i = 0; i < n; i++)
            table[i][0] = arr[i];
        for(int j = 1; (1 << j) <= n; j++)
            for(int i = 0; i + (1 << j) <= n; i++)
                table[i][j] = func(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    /**
     * @brief Fills the logs array with the values of log2(i)
     */
    void build_logs(){
        logs[1] = 0;
        for(int i = 2; i <= n; i++)
            logs[i] = logs[i / 2] + 1;
    }

public:
    /**
     * @brief Constructor
     * @param arr - input array
     * @param f - function to use for range queries
     */
    SparseTable(std::vector<T> &arr, T (*f)(T, T)){
        n = arr.size();
        func = f;
        table.resize(n, std::vector<T>(log2(n) + 1));
        logs.resize(n + 1);
        build_logs();
        build(arr);
    }

    /**
     * @brief Range Query
     * @param l - left border of range
     * @param r - right border of range
     * @return result of range query
     */
    T query(int l, int r){
        int j = logs[r - l + 1];
        return func(table[l][j], table[r - (1 << j) + 1][j]);
    }

    /**
     * @brief Updates the value at index idx to val
     * @param idx - index to update
     * @param val - new value
     */
    void update(int idx, T val){
        table[idx][0] = val;
        for(int j = 1; (1 << j) <= n; j++)
            table[idx][j] = func(table[idx][j - 1], table[idx + (1 << (j - 1))][j - 1]);
    }

    /**
     * @brief Prints the table
     */
    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= log2(n); j++)
                std::cout << table[i][j] << " ";
            std::cout << std::endl;
        }
    }
};

int main(){
    // region random test
    srand(time(NULL));
    int n = 20;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    std::cout << "Array: ";
    for(auto i : arr)
        std::cout << i << " ";
    std::cout << std::endl;

    SparseTable<int> st(arr, [](int a, int b){return std::min(a, b);});
    std::cout << "Sparse Table:" << std::endl;
    st.print();
    std::cout << "Range Query: " << st.query(0, 5) << std::endl;
    std::cout << "Updated 3-rd element to 2" << std::endl;
    st.update(3, 2);
    std::cout << "Range Query: " << st.query(0, 5) << std::endl;
    std::cout << "Range Query: " << st.query(3, 5) << std::endl;
    std::cout << "Range Query: " << st.query(10, 19) << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 2
    std::vector<int> arr2(10);
    for(int i = 0; i < 10; i++)
        arr2[i] = i + 1;
    std::cout << "Array: ";
    for(auto i : arr2)
        std::cout << i << " ";
    std::cout << std::endl;

    SparseTable<int> st2(arr2, [](int a, int b){return std::min(a, b);});
    std::cout << "Sparse Table:" << std::endl;
    st2.print();
    std::cout << "Range Query: " << st2.query(0, 8) << std::endl;
    std::cout << "Range Query: " << st2.query(1, 5) << std::endl;
    std::cout << "Range Query: " << st2.query(2, 7) << std::endl;
    // endregion

    // region test 3
    std::vector<double> arr3(10);
    for(int i = 0; i < 10; i++)
        arr3[i] = i + 1.5;
    std::cout << "Array: ";
    for(auto i : arr3)
        std::cout << i << " ";
    std::cout << std::endl;

    SparseTable<double> st3(arr3, [](double a, double b){return std::max(a, b);});
    std::cout << "Sparse Table:" << std::endl;
    st3.print();
    std::cout << "Range Query: " << st3.query(0, 8) << std::endl;
    std::cout << "Range Query: " << st3.query(1, 5) << std::endl;
    std::cout << "Range Query: " << st3.query(2, 7) << std::endl;
    // endregion

    return 0;
}

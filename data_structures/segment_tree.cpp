/****************************************************************
 * @file
 * @brief Segment Tree Data Structure
 * @details
 * A segment tree is a tree data structure for storing and updating information
 * about intervals or segments
 *
 * ### Complexity
 * Build : O(n)
 * Update : O(log n)
 * Query : O(log n)
 * Space Complexity : O(4*n)
 * Where n is the size of the array
****************************************************************/

#include <iostream>
#include <ostream>
#include <vector>

template <typename T>
class SegmentTree{
    int size;
    std::vector<T> tree;
    T (*func)(T, T);  // function to use for range queries

    // region Helper Functions

    /**
     * @brief Get the left child of a node
     * @param index - index of the node
     * @returns index of the left child
     */
    int get_left(int index){
        return 2 * index + 1;
    }

    /**
     * @brief Get the right child of a node
     * @param index - index of the node
     * @returns index of the right child
     */
    int get_right(int index){
        return 2 * index + 2;
    }

    /**
     * @brief Get the parent of a node
     * @param index - index of the node
     * @returns index of the parent
     */
    int get_parent(int index){
        return (index - 1) / 2;
    }

    // endregion

    /**
     * @brief Build the segment tree
     * @param arr - array to build the tree from
     * @param node - current node
     * @param left - left border of the array
     * @param right - right border of the array
     * @returns void
     */
    void build(const std::vector<T> &arr, int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, get_left(node), left, mid);
        build(arr, get_right(node), mid + 1, right);
        tree[node] = func(tree[get_left(node)], tree[get_right(node)]);
    }

    /**
     * @brief Update the segment tree
     * @param node - current node
     * @param left - left border of the array
     * @param right - right border of the array
     * @param index - index to update
     * @param value - value to update
     * @returns void
     */
    void update(int node, int left, int right, int index, T value){
        if(left == right){
            tree[node] = value;
            return;
        }
        int mid = (left + right) / 2;
        if(index <= mid)
            update(get_left(node), left, mid, index, value);
        else
            update(get_right(node), mid + 1, right, index, value);
        tree[node] = func(tree[get_left(node)], tree[get_right(node)]);
    }

    /**
     * @brief Query the segment tree
     * @param node - current node
     * @param left - left border of the array
     * @param right - right border of the array
     * @param query_left - left border of the query
     * @param query_right - right border of the query
     * @returns sum of the query
     */
    T query(int node, int left, int right, int query_left, int query_right){
        if(query_left > right || query_right < left)
            return 0;
        if(query_left <= left && query_right >= right)
            return tree[node];
        int mid = (left + right) / 2;
        T left_query = query(get_left(node), left, mid, query_left, query_right);
        T right_query = query(get_right(node), mid + 1, right, query_left, query_right);
        return func(left_query, right_query);
    }

public:
    /**
     * @brief Constructor
     * @param arr - array to build the tree from
     * @param f - function to use for range queries
     */
    SegmentTree(const std::vector<T> &arr, T (*func)(T, T)){
        size = arr.size();
        tree.resize(4 * size);
        this->func = func;
        build(arr, 0, 0, size - 1);
    }

    /**
     * @brief Update the segment tree
     * @param index - index to update
     * @param value - value to update
     * @returns void
     */
    void update(int index, T value){
        update(0, 0, size - 1, index, value);
    }

    /**
     * @brief Query the segment tree
     * @param left - left border of the query
     * @param right - right border of the query
     * @returns sum of the query
     */
    T query(int left, int right){
        return query(0, 0, size - 1, left, right);
    }

    /**
     * @brief Output the segment tree
     * @returns void
     */
     friend std::ostream &operator<<(std::ostream &os, const SegmentTree &segm_tree){
        for(auto &i : segm_tree.tree)
            os << i << " ";
        return os;
    }
};

int main(){
    // region test 1
    std::cout << "Test 1" << std::endl;
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SegmentTree<int> tree1(arr1, [](int a, int b){return a + b;});
    std::cout << tree1.query(0, 9) << ", correct answer: " << 55 << std::endl;
    tree1.update(0, 10);
    std::cout << tree1.query(0, 9) << ", correct answer: " << 65 << std::endl;
    std::cout << "Tree:" << std::endl;
    std::cout << tree1 << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 2
    std::cout << "Test 2" << std::endl;
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    SegmentTree<int> tree2(arr2, [](int a, int b){return a + b;});
    std::cout << tree2.query(0, 11) << ", correct answer: " << 78 << std::endl;
    tree2.update(0, 10);
    std::cout << tree2.query(0, 11) << ", correct answer: " << 88 << std::endl;
    std::cout << "Tree:" << std::endl;
    std::cout << tree2 << std::endl;
    std::cout << std::endl;
    // endregion

    // region test 3
    std::cout << "Test 3" << std::endl;
    std::vector<int> arr3 = {5, 7, 8, 1, 12, 3, 3, 3, 4, 1, 9, 7};
    SegmentTree<int> tree3(arr3, [](int a, int b){return std::max(a, b);});
    std::cout << tree3.query(3, 11) << ", correct answer: " << 12 << std::endl;
    tree3.update(0, 100);
    std::cout << tree3.query(0, 7) << ", correct answer: " << 100 << std::endl;
    std::cout << "Tree:" << std::endl;
    std::cout << tree3 << std::endl;
    return 0;
}

/****************************************************************
 * @file
 * @brief Disjoint Set Union Data Structure
 * @details
 * A disjoint set data structure (also called union find or merge find set)
 * is a data structure that tracks a set of elements partitioned into a number
 * of disjoint (non-overlapping) subsets.
 * Some situations where disjoint sets can be used are-
 * to find connected components of a graph, kruskal's algorithm for finding
 *
 * Operations:
 * 1) Make Set: Creates n disjoint sets with single item in each
 * 2) Union Sets: Joins two sets together to one set
 * 3) Find Set: Finds the set that a particular element is an element of
****************************************************************/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class DSU{
    vector<T> parent;  // parent[i] stores the parent of i
    vector<T> rank;  // rank[i] stores the rank of the tree rooted at i
    int n;  // number of elements in the set

public:
    /**
     * @brief Constructor
     * @param size - number of elements in the set
     */
    explicit DSU(T size){
        n = size;
        parent.resize(n);
        rank.resize(n);
        for(T i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    /**
     * @brief Find the set that i is an element of
     * @param i - element to find the set of
     * @returns representative of the set that i is an element of
     */
    T find_set(T i){
        if(parent[i] != i){
            parent[i] = find_set(parent[i]);
        }
        return parent[i];
    }

    /**
     * @brief Union two sets
     * @param i - first set
     * @param j - second set
     */
    void union_sets(T i, T j){
        T x = find_set(i);
        T y = find_set(j);
        if(x == y){
            return;
        }
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else if(rank[y] < rank[x]){
            parent[y] = x;
        }else{
            parent[x] = y;
            rank[y]++;
        }
    }

    /**
     * @brief Check if two elements are in the same set
     */
    bool same_set(T i, T j){
        return find_set(i) == find_set(j);
    }
};

int main(){
    // region test 1
    int n = 100;
    DSU<int> dsu(n);
    for(int i = 0; i < 100; ++i) {
        if(dsu.find_set(i) != i) {
            cout << "Fail" << endl;
            break;
        }
    }
    if(dsu.same_set(0, 1)) {
        cout << "Fail" << endl;
    }
    dsu.union_sets(0, 1);
    if(!dsu.same_set(0, 1)) {
        cout << "Fail" << endl;
    }
    cout << "Test 1 finished" << endl;
    // endregion
    return 0;
}

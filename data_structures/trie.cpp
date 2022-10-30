/****************************************************************
 * @file
 * @brief Trie Data Structure
 * @details
 * A trie is a tree-like data structure that is used to store a dynamic set
 * or associative array where the keys are usually strings
 * It is used for efficient retrieval of keys in a dataset of strings
 *
 * ### Complexity
 * Build : O(len)
 * Insert : O(len)
 * Search : O(len)
 * Remove : O(len)
 * Sort : O(n)
 * Where len is the length of the string and n is the number of strings
 * Space Complexity : O(len*a)
 * Where a is the size of the alphabet
****************************************************************/

#include <iostream>
#include <vector>

const int ALPHABET_SIZE = 26;
const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

struct TrieNode{
    std::vector<TrieNode*> children;
    int count;
    TrieNode(){
        children.resize(ALPHABET_SIZE, nullptr);
        count = 0;
    }
};

int main(){
    return 0;
}

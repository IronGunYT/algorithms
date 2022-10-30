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

class Trie{
    // region Node
    static constexpr int ALPHABET_SIZE = 26;
    static constexpr char FIRST_CHAR = 'a';

    struct TrieNode{
        std::vector<TrieNode*> children;
        int count;
        TrieNode(){
            children.resize(ALPHABET_SIZE, nullptr);
            count = 0;
        }
    };
    // endregion

    TrieNode *root;

    /**
     * @brief DFS for sorting
     * @param node - current node
     * @param str - current string
     * @param index - current index
     * @param sorted - sorted array
     * @returns void
     */
    void sortUtil(TrieNode *node, std::string str, int index, std::vector<std::string> &sorted){
        int count = node->count;
        while(count--)
            sorted.push_back(str);
        str += FIRST_CHAR;
        for(int i = 0; i < ALPHABET_SIZE; i++){
            if(node->children[i]){
                str[index] = (char) (FIRST_CHAR + i);
                sortUtil(node->children[i], str, index + 1, sorted);
            }
        }
    }

public:
    /**
     * @brief Constructor
     */
    Trie(){
        root = new TrieNode();
    }

    /**
     * @brief Inserts a string into the trie
     * @param str - string to insert
     */
    void insert(std::string str){
        TrieNode *curr = root;
        for(char c: str){
            if(curr->children[c - FIRST_CHAR] == nullptr)
                curr->children[c - FIRST_CHAR] = new TrieNode();
            curr = curr->children[c - FIRST_CHAR];
        }
        curr->count++;
    }

    /**
     * @brief Searches for a string in the trie
     * @param str - string to search
     * @returns true if the string is found
     */
    bool search(std::string str){
        TrieNode *curr = root;
        for(char c: str){
            if(curr->children[c - FIRST_CHAR] == nullptr)
                return false;
            curr = curr->children[c - FIRST_CHAR];
        }
        return curr->count > 0;
    }

    /**
     * @brief Removes a string from the trie
     * @param str - string to remove
     */
    void remove(std::string str){
        TrieNode *curr = root;
        for(char c: str){
            if(curr->children[c - FIRST_CHAR] == nullptr)
                throw std::runtime_error("String not found");
            curr = curr->children[c - FIRST_CHAR];
        }
        if(curr->count == 0)
            throw std::runtime_error("String not found");
        curr->count--;
    }

    /**
     * @brief Get sorted strings in the trie
     * @returns vector with sorted strings
     */
    std::vector<std::string> sort(){
        std::vector<std::string> sorted;
        sortUtil(root, "", 0, sorted);
        return sorted;
    }
};

int main(){
    std::cout << "Trie test" << std::endl;
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hello");
    trie.insert("a");
    trie.insert("b");
    trie.insert("abc");
    trie.insert("abcc");
    trie.insert("abcd");

    std::cout << "Search for hello: " << trie.search("hello") << std::endl;
    std::cout << "Search for unknown: " << trie.search("unknown") << std::endl;
    std::cout << "Search for abc: " << trie.search("abc") << std::endl;

    trie.remove("abc");
    std::cout << "Search for abc: " << trie.search("abc") << std::endl;

    std::cout << "Sorted strings: " << std::endl;
    for(const auto& s: trie.sort())
        std::cout << s << std::endl;
    return 0;
}

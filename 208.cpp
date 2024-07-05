#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        for (auto i : children) {
            i = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode node;

public:
    void insert(string word) {
        TrieNode* node1 = &this->node;;

        for (int i = 0;i < word.size();i++) {
            int count = word[i] - 'a';
            if (!node1->children[count]) {
                node1->children[count] = new TrieNode();
            }
            node1 = node1->children[count];
        }

        node1->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node1 = &this->node;;

        for (char ch : word) {
            int count = ch - 'a';
            if (!node1->children[count]) {
                return false;
            }
            node1 = node1->children[count];
        }
        return node1->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node1 = &this->node;;

        for (char ch : prefix) {
            int count = ch - 'a';
            if (!node1->children[count]) {
                return false;
            }
            node1 = node1->children[count];
        }
        return node1 != nullptr;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl; // Output: true
    cout << obj->search("app") << endl; // Output: false
    cout << obj->startsWith("app") << endl; // Output: true
    obj->insert("app");
    cout << obj->search("app") << endl; // Output: true

    delete obj;
    return 0;
}

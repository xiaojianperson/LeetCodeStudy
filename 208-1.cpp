#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        // 修改：使用普通的 for 循环初始化数组元素为 nullptr
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* node; // 修改：将 TrieNode 类型改为指针类型

public:
    Trie() {
        node = new TrieNode(); // 修改：动态分配内存来创建 Trie 树的根节点
    }

    void insert(string word) {
        TrieNode* node1 = node;

        for (char c : word) {
            int count = c - 'a';
            if (node1->children[count] == nullptr) { // 修改：判断是否为空应该用 ==
                node1->children[count] = new TrieNode();
            }
            node1 = node1->children[count];
        }

        node1->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node1 = node;

        for (char ch : word) {
            int count = ch - 'a';
            if (node1->children[count] == nullptr) { // 修改：判断是否为空应该用 ==
                return false;
            }
            node1 = node1->children[count];
        }
        return node1->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node1 = node;

        for (char ch : prefix) {
            int count = ch - 'a';
            if (node1->children[count] == nullptr) { // 修改：判断是否为空应该用 ==
                return false;
            }
            node1 = node1->children[count];
        }
        return node1 != nullptr; // 修改：判断前缀是否存在应该返回 node1 != nullptr
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

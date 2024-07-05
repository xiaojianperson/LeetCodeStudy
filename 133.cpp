#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> nodeMap;

        return nodeCreate(nodeMap, node);

    }

    Node* nodeCreate(unordered_map<int, Node*>& nodeMap, Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (nodeMap[node->val] != nullptr) {
            return nodeMap[node->val];
        }

        Node* cur = new Node();
        cur->val = node->val;
        nodeMap[cur->val] = cur;

        for (int i = 0;i < node->neighbors.size();i++) {
            Node* neiNode = nodeCreate(nodeMap, node->neighbors[i]);
            cur->neighbors.emplace_back(neiNode);
        }

        return cur;
    }
};


int main() {
    // 本地测试代码
    Solution solution;

    vector<vector<int>>adjList = { {2, 4}, {1, 3}, {2, 4}, {1, 3} };
    vector<Node*>nodeArr(adjList.size());

    for (int i = 0;i < nodeArr.size();i++) {
        nodeArr[i] = new Node(i + 1);
    }

    for (int i = 0;i < nodeArr.size();i++) {
        for (int j = 0;j < adjList[i].size();j++) {
            nodeArr[i]->neighbors.emplace_back(nodeArr[adjList[i][j] - 1]);
        }
    }

    Node* ans = solution.cloneGraph(nodeArr[0]);
    return 0;
}
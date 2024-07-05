#include <iostream>
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* node = new Node(0);
        node->next = head;

        while (node->next != NULL) {
            node = node->next;//7
            Node* node1 = new Node(0);
            node1->next = node->next;//7'->13
            node1->val = node->val;//7
            node->next = node1;
            node = node->next;
        }


        Node* node2 = new Node(0);
        node2->next = head;

        while (node2->next != nullptr) {
            node2 = node2->next;
            // std::cout << node->val << std::endl;
            if (node2->random != nullptr) {
                node2->next->random = node2->random->next;
            }
            else {
                node2->next->random = nullptr;
            }
            node2 = node2->next;
        }

        Node* node3 = new Node(0);
        node3 = head;
        Node* node4 = new Node(0);
        node4 = head->next;
        Node* node5 = new Node(0);
        node5 = head->next;

        while (node3->next != nullptr && node4->next != nullptr) {
            node3->next = node3->next->next;
            node4->next = node4->next->next;
            node3 = node3->next;
            node4 = node4->next;
        }
        node3->next = nullptr;
        return node5;
    }
};

int main() {
    // 创建原始链表
    Node* node7 = new Node(7);
    Node* node13 = new Node(13);
    Node* node11 = new Node(11);
    Node* node10 = new Node(10);
    Node* node1 = new Node(1);

    node7->next = node13;
    node13->next = node11;
    node11->next = node10;
    node10->next = node1;

    node7->random = nullptr;
    node13->random = node7;
    node11->random = node1;
    node10->random = node11;
    node1->random = node7;

    // 调用复制链表函数
    Solution solution;
    Node* copiedHead = solution.copyRandomList(node7);

    // // 打印复制后的链表信息（仅包含 val 和 random 的打印）
    // Node* cur = copiedHead;
    // while (cur != nullptr) {
    //     std::cout << "val: " << cur->val;
    //     if (cur->random != nullptr) {
    //         std::cout << ", random: " << cur->random->val;
    //     }
    //     else {
    //         std::cout << ", random: nullptr";
    //     }
    //     std::cout << std::endl;
    //     cur = cur->next;
    // }

    return 0;
}

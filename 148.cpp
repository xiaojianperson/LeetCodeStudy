#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* sortList(ListNode* head) {
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }

    //     ListNode* node = new ListNode();
    //     ListNode* node1;
    //     node->next = head->next;
    //     head->next = nullptr;

    //     ListNode* left = new ListNode(-1);
    //     left->next = head;
    //     ListNode* right;
    //     right = head;

    //     while (node->next != nullptr) {
    //         node1 = node->next;
    //         node->next = node->next->next;
    //         node1->next = nullptr;

    //         if (node1->val <= right->val) {
    //             sort(node1, left);
    //         }
    //         else {
    //             sort(node1, right);
    //         }
    //     }

    //     return left->next;
    // }

    // void sort(ListNode* node1, ListNode* node2) {
    //     if (node2->next != nullptr)
    //         if (node1->val <= node2->next->val) {
    //             node1->next = node2->next;
    //             node2->next = node1;
    //         }
    //         else {
    //             sort(node1, node2->next);
    //         }

    //     else
    //         node2->next = node1;
    // }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* l1S, l1E, l2S, l2E, node;
        l1S = head;
        int length = 0;

        while (l1S != nullptr) {
            l1S = l1S->next;
            length++;
        }
        


    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* node = ans;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                node->next = list1;
                list1 = list1->next;
            }
            else {
                node->next = list2;
                list2 = list2->next;
            }

            node = node->next;
        }

        node->next = (list1 != nullptr) ? list1 : list2;
        return ans->next;
    }
};

int main() {
    // 创建原始链表 [-1,5,3,4,0]
    ListNode* node0 = new ListNode(0);
    ListNode* node4 = new ListNode(4, node0);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node5 = new ListNode(5, node3);
    ListNode* head = new ListNode(-1, node5);

    // 调用链表排序函数
    Solution solution;
    ListNode* sortedHead = solution.sortList(head);

    // 打印排序后的链表内容
    ListNode* cur = sortedHead;
    while (cur != nullptr) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;
}

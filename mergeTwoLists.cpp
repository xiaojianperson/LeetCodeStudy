#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        return function(list1, list2);
    }

    ListNode* function(ListNode* list1, ListNode* list2) {
        if (list1 != NULL && list2 != NULL)
            if (list1->val <= list2->val) {
                function(list1->next, list2);
            }
            else {
                function(list2->next, list1);
            }
        if (list1->val <= list2->val) {
            return list1;
        }
        else {
            return list2;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int count = 0;
        if (l1->val + l2->val >= 10) {
            count = 1;
        }
        l1->val += l2->val;
        l1->val %= 10;
        if (l1->next == nullptr && l2->next == nullptr && count == 0) {
            return l1;
        }
        else {
            if (l1->next == nullptr) {
                ListNode node1(0);

                l1->next = &node1;
            }
            if (l2->next == nullptr) {
                ListNode node2(0);
                l2->next = &node2;
            }
            l1->next->val += count;
            std::cout << l1->next->val << std::endl;
        }
        addTwoNumbers(l1->next, l2->next);
        return l1;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        int count = 0;
        ListNode* node = new ListNode();
        node->next = head;

        while (node->next != nullptr) {
            node = node->next;
            count++;
        }

        if (count < k) {
            return head;
        }

        ListNode* ans = new ListNode();
        ListNode* start2 = new ListNode();
        node = new ListNode();
        node->next = head;
        ListNode* start1 = node;
        ListNode* end1 = node;
        ListNode* end2 = head;

        for (int i = k;i <= count;i += k) {
            for (int j = 0;j < k;j++) {
                end1 = end1->next;
            }

            end2 = end1->next;


            reverse(start1->next, end1);

            start1->next->next = end2;
            start2->next = end1;
            if (i == k) {
                ans->next = end1;
            }

            end1 = start1->next;
            start2 = end1;
            start1->next = end2;   
        }

        return ans->next;
    }

    void reverse(ListNode* node1, ListNode* node2) {
        if (node1 != nullptr&&node1->next!=nullptr) {
            if (node1->next != node2) {
                reverse(node1->next, node2);
            }
            
            node1->next->next = node1;
            node1->next = nullptr;
        }
    }
};

int main() {
    // // 创建链表 1: 1->2->4
    // ListNode* l1 = new ListNode(2);
    // l1->next = new ListNode(4);
    // l1->next->next = new ListNode(3);

    // // 创建链表 2: 1->3->4
    // ListNode* l2 = new ListNode(5);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);
    // 创建链表 1: 9->9->9->9->9->9->9

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    // l1->next->next->next->next->next = new ListNode(9);
    // l1->next->next->next->next->next->next = new ListNode(9);

    // 创建链表 2: 9->9->9->9
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);


    // 创建 Solution 对象并调用 mergeTwoLists 函数
    Solution solution;
    // ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    // // 打印合并后的链表
    // while (mergedList != NULL) {
    //     std::cout << mergedList->val << " ";
    //     mergedList = mergedList->next;
    // }
    // solution.addTwoNumbers(l1, l2);
    solution.reverseKGroup(l1, 1);
    return 0;
}

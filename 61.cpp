#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }

        ListNode* first, * second;
        int length = 1;
        first = head;
        second = head;

        while (second->next != nullptr) {
            second = second->next;
            length++;
        }

        k = k % length;

        for (int i = 0;i < length - k - 1;i++) {
            first = first->next;
        }

        second->next = head;
        head = first->next;
        first->next = nullptr;

        return head;
    }
};

int main() {
    // 本地测试代码
    Solution solution;
    return 0;
}
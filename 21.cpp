#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to print the elements of a linked list
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = { 2 };
    int arr2[] = { 1 };
    ListNode* l1 = createLinkedList(arr1, 1);
    ListNode* l2 = createLinkedList(arr2, 1);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printLinkedList(mergedList);

    return 0;
}

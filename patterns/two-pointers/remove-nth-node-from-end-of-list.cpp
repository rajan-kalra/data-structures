#include <iostream>
#include <unordered_set>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow is now at the node before the one to be removed
        ListNode* to_delete = slow->next;
        slow->next = to_delete->next;
        delete to_delete;
        
        return dummy->next;
    }
};

int main() {
    Solution solution;
    // Test 1: Remove 2nd node from end
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* result1 = solution.removeNthFromEnd(head1, 2);
    std::cout << "Test 1: ";
    printList(result1); // Expected: 1->2->3->5

    // Test 2: Remove last node
    ListNode* head2 = createList({1, 2});
    ListNode* result2 = solution.removeNthFromEnd(head2, 1);
    std::cout << "Test 2: ";
    printList(result2); // Expected: 1

    // Test 3: Remove first node
    ListNode* head3 = createList({1, 2, 3});
    ListNode* result3 = solution.removeNthFromEnd(head3, 3);
    std::cout << "Test 3: ";
    printList(result3); // Expected: 2->3

    // Test 4: Single node list
    ListNode* head4 = createList({1});
    ListNode* result4 = solution.removeNthFromEnd(head4, 1);
    std::cout << "Test 4: ";
    printList(result4); // Expected: (prints nothing)

    // Test 5: Remove middle node
    ListNode* head5 = createList({1, 2, 3});
    ListNode* result5 = solution.removeNthFromEnd(head5, 2);
    std::cout << "Test 5: ";
    printList(result5); // Expected: 1->3
  return 0;
}
#include <iostream>
#include <unordered_set>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    // Helper function to merge two sorted lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            std::vector<ListNode*> merged_lists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i+1] : nullptr;
                merged_lists.push_back(mergeTwoLists(l1, l2));
            }
            lists = merged_lists;
        }
        
        return lists.front();
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& vals) {
    ListNode dummy;
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
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Solution sol;

    // Test 1: Three sorted lists
    std::vector<ListNode*> lists1 = {
        createList({1,4,5}),
        createList({1,3,4}),
        createList({2,6})
    };
    ListNode* merged1 = sol.mergeKLists(lists1);
    std::cout << "Merged list 1: ";
    printList(merged1); // Expected: 1->1->2->3->4->4->5->6

    // Test 2: Empty input
    std::vector<ListNode*> lists2 = {};
    ListNode* merged2 = sol.mergeKLists(lists2);
    std::cout << "Merged list 2: ";
    printList(merged2); // Expected: (prints nothing)

    // Test 3: Lists with empty lists
    std::vector<ListNode*> lists3 = {nullptr, nullptr};
    ListNode* merged3 = sol.mergeKLists(lists3);
    std::cout << "Merged list 3: ";
    printList(merged3); // Expected: (prints nothing)

    // Test 4: Single list
    std::vector<ListNode*> lists4 = {createList({0})};
    ListNode* merged4 = sol.mergeKLists(lists4);
    std::cout << "Merged list 4: ";
    printList(merged4); // Expected: 0

    return 0;
}
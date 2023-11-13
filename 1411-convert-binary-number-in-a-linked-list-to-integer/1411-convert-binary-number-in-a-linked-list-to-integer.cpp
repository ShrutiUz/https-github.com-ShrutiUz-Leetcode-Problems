/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        // 0 -> 1 -> 0
        // sum = 0
        // node(0) -> sum = 0*2 = 0 -> sum += 1 -> sum = 1
        // node(1) -> sum = 1*2 = 2 -> sum += 0 -> sum = 2
        // node(1) -> sum = 2*2 = 4 -> sum += 1 -> sum = 5

        int sum = 0;
        ListNode* node = head;
        while(node!=NULL){
            sum = sum*2;
            sum += node->val;
            node = node->next;
        }
        return sum;
    }
};
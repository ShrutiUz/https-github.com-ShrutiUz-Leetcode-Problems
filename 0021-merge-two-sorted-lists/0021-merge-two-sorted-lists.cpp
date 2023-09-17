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
    ListNode* merge(ListNode *node1, ListNode *node2){
        if(node1==NULL) return node2;
        if(node2 == NULL) return node1;

        if(node1->val<node2->val){
            node1->next = merge(node1->next, node2);
            return node1;
        }
        else{
            node2->next = merge(node1, node2->next);
            return node2;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
};
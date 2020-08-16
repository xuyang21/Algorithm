/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /* 将两个链表连起来遍历 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* i = headA;
        ListNode* j = headB;
        while(i != j)
        {
            i = i == NULL? headB: i->next;
            j = j == NULL? headA: j->next;
        }
        return i;
    }
};
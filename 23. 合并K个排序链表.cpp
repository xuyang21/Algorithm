合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

/* 归并排序+合并两个链表 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1; 
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }   
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return _mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* _mergeKLists(vector<ListNode*>& lists, int left, int right)
    {
        if(left > right)
            return NULL;
        if(right == left)
            return lists[right];
        int mid = (right+left) >> 1;
        ListNode* leftList = _mergeKLists(lists, left, mid);
        ListNode* rightList = _mergeKLists(lists, mid + 1, right);
        return mergeTwoLists(leftList, rightList);
    }
};
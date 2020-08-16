您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，
可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此
类推，生成多级数据结构，如下面的示例所示。

扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。

 
示例:

输入:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

输出:
1-2-3-7-8-11-12-9-10-4-5-6-NULL


/* 解法类似树的遍历 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    stack<Node*> mystack;
    Node* flattenAlongChild(Node* head)
    {
        Node* tail;
        while(head != NULL)
        {
            tail = head;
            if(head->child != NULL)
            {
                if(head->next != NULL)
                    mystack.push(head->next);
                head->next = head->child;
                head->next->prev = head;
                head->child = NULL;
            }
            head = head->next;
        }
        return tail;
    }

    Node* flatten(Node* head) {
        Node* res = head;
        mystack.push(head);
        while(!mystack.empty())
        {
            Node* tmp = mystack.top();
            mystack.pop();
            Node* tail = flattenAlongChild(tmp);
            if(mystack.empty())
                break;
            else
            {
                tail->next = mystack.top();
                mystack.top()->prev = tail;
            }
        }
        return res;
    }
};
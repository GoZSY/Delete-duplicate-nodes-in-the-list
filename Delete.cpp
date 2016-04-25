/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};*/
//递归思路
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
		if(pHead !=NULL && pHead->next == NULL)
            return pHead;
        ListNode* current;
        if(pHead->val == pHead->next->val)
        {
            current = pHead->next->next;
            while(current != NULL && pHead->val == current->val)
                current = current->next;
            return deleteDuplication(current);
        }
        else
        {
           current = pHead->next;
           pHead->next = deleteDuplication(current);
           return pHead;
        }
        return pHead;
    }
};

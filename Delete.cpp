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
///使用三个滑动指针和一个初始节点
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = pHead;
        ListNode *p1 = dummy;
        ListNode *p2 = pHead;
        ListNode *p3 = p2 != NULL ? p2->next : NULL;   
        while(p3){  
            bool issame = false;
            while(p3 && p3->val == p2->val){
                issame = true;
                p3 = p3->next;
            }
            if(issame){
                ListNode* p = p2;
                while(p != p3){
                    ListNode *tmp = p->next;
                    delete p;
                    p = tmp;
                }
                p1->next = p3;
                p2 = p3;
                p3 = p2 != NULL ? p2->next : NULL;   
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
                p3 = p3 != NULL ? p3->next : NULL;
            }           
        }
        return dummy->next;
    }
};

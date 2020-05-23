struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* e=new ListNode(0);
        e->next=head;
        ListNode* current=head;
        if(!head) return head;
        while(current!=nullptr)
        {
            size++;
            current=current->next;
        }
        size-=n;
        current=e;
        while(size>0)
        {
            size--;
            current=current->next;          
        }
        current->next=current->next->next;
    return e->next;
    }     
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num=n+1;
        ListNode* e=new ListNode(0);
        e->next=head;
        ListNode* p=e;
        ListNode* q=e;
        if(!head)   return head;
        while(num>0)
        {   
            num--;
            p=p->next;
        }
        while(p!=nullptr)
        {
            p=p->next;
            q=q->next;
        }
        q->next=q->next->next;
        return e->next;
    }     
};

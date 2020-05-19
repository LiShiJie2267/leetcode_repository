
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        auto p=l1;
        auto q=l2;
        auto current=head;
        int carry=0;
        while(p||q)
        {     
            int x=(p)?(p->val):0;
            int y=(q)?(q->val):0;
            int sum=x+y+carry;
            carry=sum/10;
            current->next=new ListNode(sum%10);
            current=current->next;
            if(p) p=p->next;
            if(q) q=q->next;  
        }
        if(carry>0)
            current->next=new ListNode(1);
        return head->next;  
    }
};
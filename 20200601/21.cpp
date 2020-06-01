struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* current_one=l1;
        ListNode* current_two=l2;
        ListNode* ans=new ListNode();
        ListNode* current=ans;
        while(current_one!=nullptr&&current_two!=nullptr)
        {
            if(current_one->val<current_two->val)
            {
                ListNode* newnode=new ListNode(current_one->val);
                current->next=newnode;
                current_one=current_one->next;
            }
            else
            {
                ListNode* newnode=new ListNode(current_two->val);
                current->next=newnode;
                current_two=current_two->next;
            }
            current=current->next;
        }
        if(!current_one)
        {
            while(current_two)
            {
                ListNode* newnode=new ListNode(current_two->val);
                current->next=newnode;
                current_two=current_two->next;
                current=current->next;
            }
        }
        else
        {
            while(current_one)
            {
                ListNode* newnode=new ListNode(current_one->val);
                current->next=newnode;
                current_one=current_one->next;
                current=current->next;
            }
        }
        return ans->next;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};

class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
            return l2;
        else if(l2==nullptr)
            return l1;
        else if(l1->val<l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }       
    }
};
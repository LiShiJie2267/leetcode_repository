
#include <limits.h>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MAX,LONG_MIN);
    }
    bool helper(TreeNode* node,long long up,long long low)
    {
        if(node==nullptr)
            return true;
        if(node->val>=up||node->val<=low)
            return false;
        return helper(node->left,node->val,low)&&helper(node->right,up,node->val);
    }
};
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        vector<int> ans;
        ans=helper(root);
        return vaild(ans);

    }
    vector<int> helper(TreeNode* node)
    {
        vector<int> v;
        TreeNode* current=node;
        stack<TreeNode*> s;
        while(!s.empty()||current)
        {
            while(current)
            {
                s.push(current);
                current=current->left;
            }
            TreeNode* top=s.top();
            s.pop();
            v.push_back(top->val);
            if(top->right!=nullptr)
                current=top->right;
        }
        return v;
    }

    bool vaild(vector<int> iv)
    {
        for(auto ib=iv.begin();ib!=iv.end()-1;++ib)
            {
                auto ib_next=ib+1;
                if(*ib_next<=*ib)
                    return false;              
            }
        return true;
    }
};

#include <vector>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        help(root,ans);
        return ans;
    }
public:
    void help(TreeNode* node,vector<int> & res)
    {
        if(node!=nullptr){
            if(node->left!=nullptr)
                help(node->left,res);       
            res.push_back(node->val);
            if(node->right!=nullptr)
                help(node->right,res);
        }
    }
};

class Solution1_2 {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {          
        if(root)
            {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
            }
        return ans;
    }
};

#include <stack>
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur||!s.empty()){
            while(cur){
            s.push(cur);
            cur=cur->left;
            }
            TreeNode* top=s.top();
            s.pop();
            ans.push_back(top->val);
            if(top->right)
                cur=top->right;
        }  
        return ans;    
    }
};
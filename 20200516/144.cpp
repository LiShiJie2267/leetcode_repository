
#include <stack>
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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root)
        {
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }
};

class Solution2{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* current=root;
        while(current!=nullptr||!s.empty())
        {
            while(current)
            {
            ans.push_back(current->val);
            s.push(current);
            current=current->left;
            }
            if(!s.empty()){
                current=s.top();
                s.pop();
                current=current->right;
            }
        }
        return ans;
    }
};
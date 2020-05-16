#include <vector>
#include <stack>
using namespace std;
 /** Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ans.push_back(root->val);
        }
        return ans;
    }
};

class Solution {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* > s;
        vector<int> ans;
        if(root==NULL)
            return ans;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* top_node=s.top();
            s.pop();
            auto it=ans.begin();
            it=ans.insert(it,top_node->val);
            if(top_node->left)
                s.push(top_node->left);
            if(top_node->right)
                s.push(top_node->right);
        }
        return ans;
    }
};
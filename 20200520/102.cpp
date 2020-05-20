#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root==nullptr)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int currentsize=q.size();
            ans.push_back(vector<int>());
            for(int i=0;i<currentsize;i++)
            {
                auto node=q.front();
                q.pop();
                ans.back().push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

class Solution2 {
public:

    
    void subproblem(int index,TreeNode* node,vector<vector<int> > &ans)
    {
        if(ans.size()<=index)
            ans.push_back(vector<int>());
        ans[index].push_back(node->val);
        if(node->left!=nullptr)
            subproblem(index+1,node->left,ans);
        if(node->right!=nullptr)
            subproblem(index+1,node->right,ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {  
        vector<vector<int> > ans;
        if(root==nullptr)   return ans;
        subproblem(0,root,ans);
        return ans;
    }

};
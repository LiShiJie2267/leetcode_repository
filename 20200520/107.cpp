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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        if(root==nullptr)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            int currentsize=q.size();
            auto ib=ans.begin();
            ib=ans.insert(ib,vector<int>());
            for(int i=0;i<currentsize;i++)
            {
                auto node =q.front();
                q.pop();
                ans.front().push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = getDep(root);
        vector<vector<int>> ans(n, vector<int>());
        dfs(root, 0, ans, n - 1);
        return ans;
    }
    void dfs(TreeNode *root, int depth, vector<vector<int>>& ans, int n) {
        if (root == nullptr) return ;
        ans[n - depth].push_back(root->val); // 倒着装 n - depth
        if(root->left)  dfs(root->left, depth + 1, ans, n);
        if(root->right) dfs(root->right, depth + 1, ans, n);
    }
    int getDep(TreeNode *node) { // 求树的高度
        if (node == nullptr) return 0;
        return max(getDep(node->left), getDep(node->right)) + 1;
    }
};
//甚至可以改变数据结构本身　自己再动态维护一个depth属性．
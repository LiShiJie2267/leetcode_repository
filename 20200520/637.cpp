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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==nullptr)   return ans;
        queue<TreeNode*> q,p;
        q.push(root);
        while(!q.empty())
        {
            double sum=0;
            int count=0;
            while(!q.empty())
            {
                auto node =q.front();
                q.pop();
                sum+=double(node->val);
                count++;
                if(node->left)  p.push(node->left);
                if(node->right) p.push(node->right);
            }
        ans.push_back(sum/count);
        swap(q,p);
        }
        return ans;
    }
};


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==nullptr)   return ans;
        queue<TreeNode*> q,p;
        q.push(root);
        while(!q.empty())
        {
            double sum=0;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto node =q.front();
                q.pop();
                sum+=double(node->val);
                if(node->left)  p.push(node->left);
                if(node->right) p.push(node->right);
            }
        ans.push_back(sum/size);
        swap(q,p);
        }
        return ans;
    }
};
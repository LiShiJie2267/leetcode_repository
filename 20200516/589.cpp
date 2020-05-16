
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution1 {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        if(root)
        {
            ans.push_back(root->val);
            for(auto& node:root->children)
                preorder(node);
        }   
        return ans;
    }
};

class Solution2 {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        stack<Node* > s;
        Node *current=root;
        if(root==nullptr)
            return ans;
        s.push(root);
        while(!s.empty())
        {
            Node* top_node=s.top();
            ans.push_back(top_node->val);
            s.pop();
            auto this_children =(top_node->children);
            auto size=this_children.size();
            for(int i=size-1;i>=0;i--)
                s.push(this_children[i]);
        }
        return ans;     
    }
};
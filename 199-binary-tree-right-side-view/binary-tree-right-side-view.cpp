/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<int>ans;
        queue<TreeNode*>q;
        int put;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                put=q.front()->val;
                if(q.front()->left!=NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            ans.push_back(put);
        }    
        return ans;
    }
};
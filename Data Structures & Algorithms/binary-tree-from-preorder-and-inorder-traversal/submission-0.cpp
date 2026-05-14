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
    unordered_map<int,int>mp;
    int idx=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end) {
        if(start> end) return NULL;
        int rootVal = preorder[idx++];
        TreeNode* root =new TreeNode(rootVal);
        int pos = mp[rootVal];
        root->left = build(preorder,inorder,start,pos-1);
        root->right = build(preorder,inorder,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,inorder.size()-1);
    }
};

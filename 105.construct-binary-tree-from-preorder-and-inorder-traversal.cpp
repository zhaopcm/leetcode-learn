/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.01%)
 * Likes:    2043
 * Dislikes: 56
 * Total Accepted:    252.7K
 * Total Submissions: 587.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pre=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return subtree(preorder, inorder, 0, preorder.size()-1);
    }

    TreeNode* subtree(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(l > r) return NULL;
        if(l == r) return new TreeNode(preorder[pre++]);

        TreeNode* root = new TreeNode(preorder[pre++]);
        int id = find(inorder.begin()+l, inorder.begin()+l+r, preorder[pre-1]) - inorder.begin(); 
        root->left = subtree(preorder, inorder, l, id-1);
        root->right = subtree(preorder, inorder, id+1, r);
        return root;
    }
};


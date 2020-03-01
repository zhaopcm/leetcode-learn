/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (64.25%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 20.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size(); 
        return creat_tree(inorder, postorder, 0, inorder.size(), pos);
    }
    TreeNode* creat_tree(vector<int>& inorder, vector<int>& postorder, int l, int r, int &pos){
        if(l>=r || pos<0) return NULL;
        TreeNode *root = new TreeNode(postorder[--pos]);
        int cur = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        root->right = creat_tree(inorder, postorder, cur+1, r, pos);
        root->left = creat_tree(inorder, postorder, l, cur, pos);
        return root;
    } 
};


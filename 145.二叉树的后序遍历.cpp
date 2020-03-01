/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (67.50%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    29.3K
 * Total Submissions: 43.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*>trees;
        vector<int>ans;
        if(root) trees.push_back(root);
        while(!trees.empty()){
            TreeNode *node = trees.back();
            ans.push_back(node->val);
            trees.pop_back();
            if(node->left) trees.push_back(node->left);
            if(node->right) trees.push_back(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


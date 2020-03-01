/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (61.69%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 62.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
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
 * 输出: [1,2,3]
 * 
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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {

        if(!root) return ans;

        if(root->left&&root->right){
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        else if(!root->left&&root->right)
        {
            ans.push_back(root->val);
            preorderTraversal(root->right);
        }
        else if(root->left&&!root->right){
            ans.push_back(root->val);
            preorderTraversal(root->left);
        }
        else if(!root->left&&!root->right){
            ans.push_back(root->val);
        }
        return ans;
        
        
    }
};


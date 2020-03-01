/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (59.24%)
 * Likes:    296
 * Dislikes: 0
 * Total Accepted:    51.8K
 * Total Submissions: 87.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> subtree;
        if(root){
            subtree.push(root);
            levelth(subtree, ans);
        }
        return ans;
    }

    void levelth(queue<TreeNode*> &subtree, vector<vector<int>> &ans){
        TreeNode *cur;
        while(!subtree.empty()){
            vector<int> level;
            int width = subtree.size();
            for(int i=0; i<width; i++){
                cur = subtree.front();
                level.push_back(cur->val);
                subtree.pop();
                if(cur->left) subtree.push(cur->left);
                if(cur->right) subtree.push(cur->right);
            }
            ans.push_back(level);
        }
    }

};
// @lc code=end


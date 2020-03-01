/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (58.90%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 17.3K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
        vector<TreeNode*> generateTrees(int n) {
            if(n == 0) return vector<TreeNode*>();
            return creat_tree(1, n);      
        }

        vector<TreeNode*>  creat_tree(int from , int to){
            vector<TreeNode*> ans;
            if(to-from < 0) ans.push_back(nullptr);
            else if(to-from == 0) {ans.push_back(new TreeNode(from));}
            else{
                for (int i=from; i<=to; ++i){
                    vector<TreeNode*> l_subtree = creat_tree(from, i-1);
                    vector<TreeNode*> r_subtree = creat_tree(i+1, to);
                    for(int k=0; k<l_subtree.size(); k++){
                        for (int j=0; j<r_subtree.size(); j++){
                            TreeNode* root = new TreeNode(i);
                            root->left = l_subtree[k];
                            root->right = r_subtree[j];
                            ans.push_back(root);
                        }
                    }
                }
            }
            return ans;  
        }
    };


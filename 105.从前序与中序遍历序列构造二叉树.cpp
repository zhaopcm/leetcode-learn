/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (61.35%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 38K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
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


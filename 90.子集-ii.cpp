/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (57.22%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 22.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        if(nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        int start = 0;
        for(int i=0; i<nums.size(); i++){
            int len = ans.size();
            if(i>0 && nums[i]!=nums[i-1]) start = 0;
            for(int j=start; j<len; j++){
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
            start = ans.size() - (len - start);
        }
        return ans;
    }
};


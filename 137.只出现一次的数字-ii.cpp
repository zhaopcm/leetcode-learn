/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 *
 * https://leetcode-cn.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (64.62%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 22.6K
 * Testcase Example:  '[2,2,3,2]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,3,2]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 * 
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        if(nums.size()==1) return nums[0];
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(i==0) {
                if(nums[i]!=nums[i+1]) ans = nums[i];
            }
            else if(i==nums.size()-1){
                if(nums[i]!=nums[i-1]) ans = nums[i];
            } 
            else{
                if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1]) ans = nums[i];
            }
        }
        return ans;
    }
};
// @lc code=end


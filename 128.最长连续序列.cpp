/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (46.89%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    17.1K
 * Total Submissions: 36.5K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */

// @lc code=start
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
		int maxlen=0;
		set<int>ordernums(nums.begin(), nums.end());
		ordernums.insert(INT_MAX);
		set<int>::iterator num;
		set<int>::iterator pre_num;
		for(num = ordernums.begin(); num!=ordernums.end(); num++){
			int k = 1;
		start:
			pre_num = ordernums.find(*num - 1);
			if (pre_num != ordernums.end()&& *pre_num!= INT_MAX-1)
			{	
				k += 1;
				++num;
				goto start;
			}
			maxlen = max(maxlen, k);	
		}

		return maxlen;
	}
};
// @lc code=end


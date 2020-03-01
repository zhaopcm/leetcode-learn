/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (54.94%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 47.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        vector<bool> visited(n, false);
        DFS(nums, temp, res, 0, visited);
        return res;
    }

    void DFS(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, int cursize, vector<bool> &visited) {
        if (cursize == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                    continue;
                temp.push_back(nums[i]);
                visited[i] = true;
                DFS(nums, temp, res, cursize + 1, visited);

                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};

// @lc code=end


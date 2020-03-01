/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 *
 * https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (34.17%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    826
 * Total Submissions: 2.4K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * 给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和。
 * 
 * 示例:
 * 
 * 输入: matrix = [[1,0,1],[0,-2,3]], k = 2
 * 输出: 2 
 * 解释: 矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
 * 
 * 
 * 说明：
 * 
 * 
 * 矩阵内的矩形区域面积必须大于 0。
 * 如果行数远大于列数，你将如何解答呢？
 * 
 * 
 */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int maxS) {
        int maxA = INT32_MIN, r = matrix.size(), c = matrix[0].size();
        for(int i = 0; i < c; ++i) {
            vector<int> sum(r, 0);
            if(maxA == maxS) return maxA; // Stop if we can reach maxS
            for(int j = i; j < c; ++j) {
                for(int k = 0; k < r; ++k) sum[k] += matrix[k][j];
                
                //First try Kadane's Algo and see if maxSum is less than maxS. 
                int curMax = INT32_MIN, curSum = 0;
                for(int k = 0; k < r; ++k) {
                    curSum += sum[k];
                    curMax = max(curMax, curSum);
                    if(curSum < 0) curSum = 0;
                }
                if(curMax <= maxS) {maxA = max(maxA, curMax); continue;}
                
                // Only apply slow method when there maxSum that is greater than maxS.
                int csum = 0;
                set<int> s{csum};
                for(int k = 0; k < r; ++k) {
                    csum += sum[k];
                    auto it = s.lower_bound(csum - maxS);
                    if(it != s.end()) maxA = max(maxA, csum - *it);
                    s.insert(csum);
                }
            }
        }
        return maxA;
    }
};


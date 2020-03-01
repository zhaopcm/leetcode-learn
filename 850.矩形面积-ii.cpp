/*
 * @lc app=leetcode.cn id=850 lang=cpp
 *
 * [850] 矩形面积 II
 *
 * https://leetcode-cn.com/problems/rectangle-area-ii/description/
 *
 * algorithms
 * Hard (37.24%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    308
 * Total Submissions: 827
 * Testcase Example:  '[[0,0,2,2],[1,0,2,3],[1,0,3,1]]'
 *
 * 我们给出了一个（轴对齐的）矩形列表 rectangles 。 对于 rectangle[i] = [x1, y1, x2,
 * y2]，其中（x1，y1）是矩形 i 左下角的坐标，（x2，y2）是该矩形右上角的坐标。
 * 
 * 找出平面中所有矩形叠加覆盖后的总面积。 由于答案可能太大，请返回它对 10 ^ 9 + 7 取模的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[0,0,2,2],[1,0,2,3],[1,0,3,1]]
 * 输出：6
 * 解释：如图所示。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[0,0,1000000000,1000000000]]
 * 输出：49
 * 解释：答案是 10^18 对 (10^9 + 7) 取模的结果， 即 (10^9)^2 → (-7)^2 = 49 。
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= rectangles.length <= 200
 * rectanges[i].length = 4
 * 0 <= rectangles[i][j] <= 10^9
 * 矩形叠加覆盖后的总面积不会超越 2^63 - 1 ，这意味着可以用一个 64 位有符号整数来保存面积结果。
 * 
 * 
 */
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {

        //从低到高先把高度确定（set是一种将同一类型自动排序的方法）
        set<int>ys;
        for(auto const &r:rectangles){
            ys.insert(r[1]);
            ys.insert(r[3]);
        }

        //把x的起始位置进行排序，便于计算宽度值 用lambda内联函数进行sort排序，返回1表示从低到高排序
        sort(rectangles.begin(), rectangles.end(), [](auto const &r1, auto const &r2){return r1[0]<r2[0];});

        //从低到高计算面积
        int pre_y = *ys.begin();
        long long s = 0;
        int mod = 1000000007; 

        for(auto y:ys){
            long long height = y - pre_y;
            long long x_start = rectangles.front()[0];
            long long x_end = x_start;
            //查找每层的宽度值

            for (auto const &r:rectangles){
                //完全覆盖的情况
                if(r[1]<=pre_y && r[3]>=y){
                    if(r[0] > x_end){
                        //将该层的所有面积都计算在内
                        s += (height * (x_end - x_start)) % mod;
                        x_start = r[0];
                    }
                    if(r[2] > x_end){
                        x_end = r[2];
                    }
                }
            }

            s += (height * (x_end - x_start)) % mod;
            pre_y = y; 
        } 
        return s% mod;
    }
};


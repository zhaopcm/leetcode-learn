/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (37.28%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 18.1K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 * 
 * 说明：
 * 
 * 
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {

        unordered_set<string> t(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> m;

        return wordBreak2II_bt(s, t, m, 0);
    }

    vector<string> wordBreak2II_bt(string s, unordered_set<string> &t, unordered_map<int, vector<string>> &m, int index) {

        if (m.count(index)) {
            return m[index];
        }
        vector<string> ret;
        if (index == s.size()) {
            ret.emplace_back("");
        } else
            for (int i = index + 1; i <= s.size(); ++i) {

                if (t.count(s.substr(index, i - index))) {
                    vector<string> tmp = wordBreak2II_bt(s, t, m, i);
                    for (auto &j : tmp) {
                        ret.push_back(s.substr(index, i - index) + (j.empty() ? "" : " ") + j);
                    }
                }
            }
        m[index] = ret;
        return ret;
    }
};
// @lc code=end


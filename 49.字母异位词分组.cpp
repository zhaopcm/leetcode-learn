/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (59.03%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 58.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>>dic;
        int may =10;
        for (int i=0; i<strs.size(); i++){
            string tmp =  strs[i];
            sort(tmp.begin(), tmp.end());
            if(!dic.count(tmp)) dic.insert(pair<string,vector<string>>(tmp, {strs[i]}));
            else dic[tmp].push_back(strs[i]);
        }
        for(auto iter:dic){
            ans.push_back(iter.second);
        }
        return ans;
    }
};
// @lc code=end


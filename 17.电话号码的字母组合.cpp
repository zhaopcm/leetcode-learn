/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (51.29%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    53.8K
 * Total Submissions: 104.9K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string>ans;
        int length = digits.length();
        if(length == 0) return ans;
		queue<string>tmp;
		map<char, string> dic = { {'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
        string s = "";
        tmp.push(s);
        for(int i=0; i<length; i++){
            int size = tmp.size();
            for(int m=0; m<size; m++){
                for(int j=0; j<dic[digits[i]].length(); j++){
                    string t = tmp.front();
                    t += dic[digits[i]][j];
                    tmp.push(t);
                }
                tmp.pop();
            }
        }
        while (!tmp.empty())
        {
            ans.push_back(tmp.front());
            tmp.pop();
        }
        return ans;
    }   
};
// @lc code=end


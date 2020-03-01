/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (27.43%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    15.7K
 * Total Submissions: 57.2K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int>ans;
		if(words.size()<1 || s.size()<1 || s.size() < words[0].size()*words.size()) return ans;
		unordered_map<string, int>dic;
		unordered_map<string, int>::iterator itr;

		int len = words.size() * words[0].length();
		int size = words[0].size();

		for (int i = 0; i<words.size(); i++) {
			if(dic.count(words[i])) dic[words[i]]++;
			else dic.insert(pair<string, int>(words[i], 1));
		}

		for (int i = 0; i<s.length()-len+1;) {
            int cur = 0;
			unordered_map<string, int> copy = dic;
			string tmp = s.substr(i, len);

			for (int j = 0; j<len;) {
				string ms = tmp.substr(j, size);
				if (copy.count(ms)){
					copy[ms] -= 1;
				}
				else goto L1;
				j += size;
			}
			for (itr = copy.begin(); itr != copy.end(); itr++) {
				if (itr->second != 0) goto L1;
			}
			ans.push_back(i);
		L1:
			i++;
		}
		return ans;
	}
};

// @lc code=end


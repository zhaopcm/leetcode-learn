/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 *
 * https://leetcode-cn.com/problems/letter-tile-possibilities/description/
 *
 * algorithms
 * Medium (69.93%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    1.3K
 * Total Submissions: 1.9K
 * Testcase Example:  '"AAB"'
 *
 * 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："AAB"
 * 输出：8
 * 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
 * 
 * 
 * 示例 2：
 * 
 * 输入："AAABBC"
 * 输出：188
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= tiles.length <= 7
 * tiles 由大写英文字母组成
 * 
 * 
 */
class Solution {
public:
	int numTilePossibilities(string tiles) {
		int maxlen = tiles.size(), ans = 0;
		sort(tiles.begin(), tiles.end());
		for (int len = 1; len <= tiles.size(); ++len)
			permute(ans, tiles, 0, tiles.size(), len, 0);
		return ans;

	}
	void permute(int& ans, string str, int left, int right, int len, int cur)
	{
		if (cur == len)
			++ans;
		else
			for (int i = left; i<right; ++i)
			{
				if (i>left&&str[i] == str[left])
					continue;
				swap(str[left], str[i]);
				permute(ans, str, left + 1, right, len, cur + 1);
			}
	}

};


/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (40.00%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 12.2K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 设计一个支持以下两种操作的数据结构：
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
 * 
 * 示例:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 说明:
 * 
 * 你可以假设所有单词都是由小写字母 a-z 组成的。
 * 
 */

// @lc code=start
class WordDictionary {
public:
	/** Initialize your data structure here. */
	struct Node
	{
		bool isword;
		Node* next[26] = {};
	};
	
	Node* dic;
	WordDictionary() {
		dic = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node* p = dic;
		for(int i=0; dic&&i<word.size(); i++){
			if(p->next[word[i]-'a']==NULL){
				p->next[word[i]-'a'] = new Node();
			}
			p = p->next[word[i]-'a'];
		}
		p->isword = true;
	}

	bool dfs(Node* dic, string word, int deep){
		if(!dic) return false;
		if(deep>=word.size()) return dic->isword;
		//如果该点是正常节点
		if(word[deep]!='.'){
			if(dic->next[word[deep]-'a']) return dfs(dic->next[word[deep]-'a'], word, deep+1);
			else return false;
		}
		//如果为'.'
		for(int i=0; i<26; i++){
			if(dic->next[i]&&dfs(dic->next[i], word, deep+1)){
				return true;
			}
		}
		return false;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return dfs(dic, word, 0);
	}
};




/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end


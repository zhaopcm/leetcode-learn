/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (47.72%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    23.6K
 * Total Submissions: 49.6K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *start = head; 
        queue<ListNode*>rec;
        stack<ListNode*>rev;
        for(int i=1; start!=NULL; i++)
        {
            ListNode* tmp = new ListNode(start->val);
            if(i>=m && i<=n) rev.push(tmp);
            else rec.push(tmp);
            start = start->next;
        }
        ListNode *pre = new ListNode(0);
        ListNode *cur = pre;
        for(int i = 1; head!=NULL; i++){
            head = head->next;
            if(i<m||i>n){
                cur->next = rec.front();
                rec.pop();
            }
            else{
                cur->next = rev.top();
                rev.pop();
            }
            cur = cur->next;
        }
        return pre->next;
    }
};
// @lc code=end


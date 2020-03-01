/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (52.51%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 19.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    void reorderList(ListNode* head){
        if(!head){return ;}
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* preNode = nullptr;
        ListNode* p = slow->next;
        slow->next = nullptr;
        while(p){
            ListNode* next = p->next;
            p->next = preNode;
            preNode = p;
            p = next;
        }
        ListNode* res = new ListNode(-1);
        while(preNode){
            res->next = head;
            head = head->next;
            res = res->next;
            res->next = preNode;
            preNode = preNode->next;
            res = res->next;
        }
        res->next = head;
        head = res;
    }
};

// @lc code=end


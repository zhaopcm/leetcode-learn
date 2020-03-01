/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (50.37%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    51.1K
 * Total Submissions: 101.4K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */

// @lc code=start

#include<iostream>
#include<stack>

class MinStack {
public:
	/** initialize your data structure here. */
	typedef struct Node {
		int value;
		int cur;
		Node *next;
		Node(int x) :value(x), cur(x), next(NULL) {}
	}node;

	MinStack() {
		head = new node(NULL);
	}

	void push(int x) {
		node *pre = new node(x);
		if (min >= pre->value) {
			min = pre->value;
			mins.push(min);
		}
		pre->cur = mins.top();
		pre->next = head->next;
		head->next = pre;
	}

	void pop() {
		if (head->next->value == head->next->cur) {
			mins.pop();
			if (!mins.empty()) {
                min = mins.top();
                head->next->cur = mins.top();
            }
			else head->next->cur = NULL;
		}
		head->next = head->next->next;
		if (head->next == nullptr) {
			min = INT_MAX;
		}
	}

	int top() {
		int val;
		val = head->next->value;
		return val;
	}

	int getMin() {
		return head->next->cur;
	}
private:
	node *head;
	int min = INT_MAX;
	std::stack<int>mins;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
/**
链表要定义的三要素：
1、head：是链表的入口
2、cur：类似于迭代器，可以遍历整个链表，便于使用；
3、next参数：判断是否到了链表的尾部，xxx->next == NULL

考点：
1、考察构造新的链表，怎么返回
2、考察链表的遍历、迭代

思路：
链表的几个要素都要齐备，知道怎么判断是否到尾部
**/
        ListNode* first = l1;
        ListNode* second = l2;
		//实例化链表节点
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        int carry = 0;
		//以下可以判断链表是否尾
        while (first || second || carry) {
            int sum = (first ?first->val:0)+(second?second->val:0)+carry;
            carry = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if (first)
                first = first->next;
            if (second)
                second = second->next;
        }
		//根据题目，头不能为0，则head可以定义一个“非法”的数值
        return head->next;
    }
};
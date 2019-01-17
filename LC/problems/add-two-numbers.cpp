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
        int up_num = 0;
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while (l1 && l2) {
            res->next = new ListNode((l1->val+l2->val+up_num)%10);
            up_num = (l1->val + l2->val + up_num) / 10;
            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }
        while (l1) {
            res->next = new ListNode((l1->val+up_num)%10);
            up_num = (l1->val + up_num) / 10;
            l1 = l1->next;
            res = res->next;
        }

        while (l2) {
            res->next = new ListNode((l2->val+up_num)%10);
            up_num = (l2->val + up_num) / 10;
            l2 = l2->next;
            res = res->next;
        }

        return head->next;
    }
};

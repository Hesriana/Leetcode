/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode(0);
        ListNode* t = ans;
        int v1,v2,temp;
        int carry = 0;

        while(1){
            
            temp = 0;

            if(l1 == nullptr && l2 == nullptr)
                break;
            
            if(l1 != nullptr){
                temp += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                temp += l2->val;
                l2 = l2->next;
            }
            temp += carry;
            carry = 0;    
            
            if(temp >= 10){
                carry = 1;
                temp = temp - 10;
                t->next = new ListNode(temp);//新增一個數值
                t = t->next;//推到下一個
            }
            else{
                t->next = new ListNode(temp);
                t = t->next;
            }
        }


        if(carry == 1)
            t->next = new ListNode(1);
        ans = ans->next;//壓掉一開始的0
        return ans;
    }
};

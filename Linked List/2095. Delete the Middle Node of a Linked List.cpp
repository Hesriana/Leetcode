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
    ListNode* deleteMiddle(ListNode* head) {
        
        int num = 0;

        ListNode* temp = head;
        //知道有幾個元素
        while(temp != nullptr){
            temp = temp ->next;
            num++;
        }
        //只有一個元素的特殊情況
        if(head -> next == nullptr)
            return temp;//return empty linked list

        num = num/2;
        temp = head;
        //移動到中間元素的前一個
        for(int i = 0 ; i < num - 1 ;i++){
            temp = temp -> next;
        }
        //將它連接到嚇嚇個元素
        ListNode* t = temp;
        temp = temp->next->next;
        t ->next = temp;

        return head;
    }
};

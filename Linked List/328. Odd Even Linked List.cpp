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
    ListNode* oddEvenList(ListNode* head) {
        
        vector<int> temp;
        ListNode* ans = new ListNode(0);
        ListNode* t = ans;
        int count = 0;

        while(head != nullptr){

            if(count%2 == 0){
                t->next = new ListNode(head->val);
                t = t->next;
            }  
            else
                temp.push_back(head->val);
            
            head = head->next;
            count++;
        }

        for(int i = 0 ; i < temp.size() ; i++){
            t->next = new ListNode(temp[i]);
            t = t->next;
        }

        ans = ans->next;

        return ans;

    }
};

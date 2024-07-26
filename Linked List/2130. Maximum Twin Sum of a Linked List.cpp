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
    int pairSum(ListNode* head) {
        
        vector<int> data;
        int ans = 0;

        while(head != nullptr){
            data.push_back(head->val);
            head = head->next;
        }

        int s = data.size() - 1;

        for(int i = 0 ; i < data.size()/2 ; i++){
            if(data[i] + data[s - i] > ans)
                ans = data[i] + data[s - i];
        }

        return ans;
    }
};

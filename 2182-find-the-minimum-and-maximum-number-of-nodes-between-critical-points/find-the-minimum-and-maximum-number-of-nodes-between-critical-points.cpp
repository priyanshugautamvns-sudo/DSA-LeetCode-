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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev=head;
        if(prev==NULL || prev->next==NULL) return {-1,-1};
        ListNode*curr=prev->next;
        if(curr->next==NULL) return {-1,-1};
        ListNode*nex=curr->next;
        vector<int>cal;
        int cnt=1;
        int min_dis=INT_MAX;
        while(nex!=NULL)
        {
            if((curr->val>nex->val && curr->val>prev->val) || (curr->val<nex->val && curr->val<prev->val))
            {
                cal.push_back(cnt);
            }
            if(cal.size()>1)
            {
                min_dis=min(min_dis,cal[cal.size()-1]-cal[cal.size()-2]);
            }
            prev=curr;
            curr=nex;
            nex=nex->next;
            cnt++;
        }
        if(cal.size()<2) return {-1,-1};
        int max_dis=cal[cal.size()-1]-cal[0];
        return {min_dis,max_dis};
    }
};
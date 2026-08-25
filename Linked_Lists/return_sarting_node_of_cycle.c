/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    if(head==NULL){
        return NULL;
    }
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            struct ListNode *start=head;
            while(start!=slow){
                start=start->next;
                slow=slow->next;
            }
            return start;
        }

    }
    return NULL;
}
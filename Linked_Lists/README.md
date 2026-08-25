LINKED LIST SOLUTIONS
---------------------

Problem: Cycle Detection in a linked list (LeetCode 141)
Approach: To solve this specific problem i used floyd tortoise and hare algorithm where i created a node called slow(the tortoise) and fast(hare) and stored the head in both of them then i checked if the head is null is its so then no cycle so return false, then i runned a while loop explicitely untill my hare and hare->next is not null and i moved my tortoise one step and my hare two step strating from the head, now if a loop exist then my hare will run fast and eventually catch my tortoise returning true and if its not the case then there exist no cycle returning false
___________________________________________________________________________________________



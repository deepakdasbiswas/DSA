# LINKED LIST SOLUTIONS
-----------------------

* **Problem:** Cycle Detection in a linked list (LeetCode 141)
* **Approach:** To solve this specific problem I used Floyd's Tortoise and Hare algorithm. I created a node called `slow` (the tortoise) and `fast` (the hare) and stored the head in both of them. 
    * First, I checked if the head is NULL. If it is, there is no cycle, so return false.
    * Then, I ran a while loop explicitly until my hare and `hare->next` are not NULL. 
    * I moved my tortoise one step and my hare two steps starting from the head.
    * If a loop exists, my hare will run fast and eventually catch my tortoise, returning true. If that is not the case, there is no cycle, returning false.
# LINKED LIST SOLUTIONS
-----------------------

* **Problem:** Cycle Detection in a linked list (LeetCode 141)
* **Approach:** To solve this specific problem I used Floyd's Tortoise and Hare algorithm. I created a node called `slow` (the tortoise) and `fast` (the hare) and stored the head in both of them. 
    * First, I checked if the head is NULL. If it is, there is no cycle, so return false.
    * Then, I ran a while loop explicitly until my hare and `hare->next` are not NULL. 
    * I moved my tortoise one step and my hare two steps starting from the head.
    * If a loop exists, my hare will run fast and eventually catch my tortoise, returning true. If that is not the case, there is no cycle, returning false.

* **Problem:** Remove Nth Node From End of List (LeetCode 19)
* **Approach:** I used a two-pointer sliding window technique combined with a Dummy Head.
    * First, I created a `dummy` node pointing to the `head` to safely handle edge cases (like when the list only has one box, or when I need to delete the very first box).
    * I placed both my `slow` and `fast` pointers at the dummy node.
    * I moved the `fast` pointer forward exactly `n + 1` steps to create a fixed gap between the two runners.
    * Then, I moved both pointers forward one step at a time. When `fast` finally falls off the cliff (`NULL`), that perfectly measured gap ensures my `slow` pointer stops exactly *one box before* the target node.
    * Finally, I unlinked the target node by routing `slow->next` over it (`slow->next->next`), used `free()` to clear the memory, and safely returned `dummy.next`.

* **Problem:** Linked List Cycle II (LeetCode 142)
* **Approach:** I used Floyd's Tortoise and Hare algorithm, splitting the solution into two distinct phases to find the exact starting node of the loop without using extra memory (O(1) space).
    * **Phase 1 (Detection):** I placed both `slow` and `fast` pointers at the `head`. By moving `fast` two steps and `slow` one step, I forced them to crash if a cycle exists. 
    * **Phase 2 (Locating the Entrance):** The moment they collided, I left the `slow` pointer exactly at the crash site and spawned a new `start` pointer back at the `head`. 
    * Because of the geometric math behind the loop, moving both `start` and `slow` forward at the exact same speed (one step at a time) mathematically guarantees their paths will perfectly intersect at the exact node where the cycle begins.
    * If the `fast` pointer safely hits `NULL` during Phase 1, the list is a straight line, and I return `NULL`.
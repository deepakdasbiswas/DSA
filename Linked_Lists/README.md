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

* **Problem:** Delete Node in a Linked List (LeetCode 237)
* **Approach:** The "Imposter" Node Trick (O(1) Time, O(1) Space).
    * Because we are not given the `head` of the list, it is impossible to find the `prev` node required for a standard deletion.
    * Instead of deleting the given node, I copied the data (`val`) from the `next` node into the current node.
    * I then re-routed the current node's `next` pointer to skip the next node entirely (`node->next = node->next->next`).
    * Finally, I used `free()` to delete the next node from memory. The original node now perfectly impersonates the next node, effectively deleting the original value.

* **Problem:** Insert at Tail (Doubly Linked List)
* **Approach:** I used a temporary pointer to walk the list and handle the two-way pointer manipulation.
    * Handled the edge case where the list is entirely empty by immediately returning the safely initialized new node.
    * Used a `while(temp->next != NULL)` loop to walk down the track, intentionally stopping exactly on the very last node without falling off the edge into `NULL`.
    * Wired the current tail's `next` pointer forward to the new node, and the new node's `prev` pointer backward to complete the two-way street.
    * Time Complexity: O(N) to walk the track. Space Complexity: O(1).

* **Problem:** Delete a Node by Index (Doubly Linked List)
* **Approach:** I used a temporary pointer to traverse the list and perform a four-cable pointer bypass.
    * Initialized an index tracker (`int index = 1`) and a traversal pointer (`Node *temp = head;`).
    * **Edge Case 1 (Empty List):** If `head == NULL`, immediately return `NULL`.
    * **Traversal:** Used a `while(temp != NULL && index != target)` loop to walk the track, safely stopping exactly on the target node or falling off the end.
    * **Edge Case 2 (Out of Bounds):** If the loop finishes and `temp` is `NULL` (target not found), return the original `head` to leave the list intact.
    * **Edge Case 3 (The Head Chop):** If the target node is the `head`, shift the head forward (`head = temp->next`). If the new head exists, sever its backward cable (`head->prev = NULL`).
    * **The Bypass (Middle or Tail):** For any other node, bypass it forward (`temp->prev->next = temp->next`). Then, check if a node exists in front of it (`if(temp->next != NULL)`) before bypassing it backward (`temp->next->prev = temp->prev`).
    * Cleared the target node using `free(temp)` and returned the head.
    * **Time Complexity:** O(N) to walk the track. **Space Complexity:** O(1).
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();  // Dummy node
    ListNode* current = dummy;        // Pointer to build the result list
    int carry = 0;

    while (l1 || l2 || carry != 0) {
        int sum = carry;

        if (l1) {  // Add l1's value if it exists
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {  // Add l2's value if it exists
            sum += l2->val;
            l2 = l2->next;
        }

        int digit = sum % 10;    // Extract the current digit
        carry = sum / 10;        // Update the carry

        current->next = new ListNode(digit);  // Append the new digit
        current = current->next;             // Move to the new node
    }

    return dummy->next;  // Skip the dummy node and return the result


    }

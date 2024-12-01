int reverse(int x) {
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10; // Extract the last digit
        x /= 10;            // Remove the last digit

        // Check for overflow before updating `reversed`
        if (reversed > (INT_MAX / 10) || (reversed == (INT_MAX / 10) && digit > 7)) {
            return 0; // Overflow for positive numbers
        }
        if (reversed < (INT_MIN / 10) || (reversed == (INT_MIN / 10) && digit < -8)) {
            return 0; // Overflow for negative numbers
        }

        reversed = reversed * 10 + digit; // Update the reversed number
    }

    return reversed;
}

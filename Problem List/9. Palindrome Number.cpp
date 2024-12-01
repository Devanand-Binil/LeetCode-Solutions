bool isPalindrome(int x) {
    // If x is negative or ends with 0 but is not 0, it's not a palindrome
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // When the number of digits is odd, we can ignore the middle digit
    return x == reversed || x == reversed / 10;

int myAtoi(string s) {
    int i = 0, sign = 1, result = 0;
    int n = s.size();

    // Step 1: Skip leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Step 2: Check for sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Convert digits to integer
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';

        // Step 4: Handle overflow
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}

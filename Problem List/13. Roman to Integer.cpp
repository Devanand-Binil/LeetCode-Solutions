int romanToInt(string s) {
    // Array for Roman numerals, where index represents the numeral
    int roman[256] = {0};
    
    // Assign integer values to Roman numerals
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int result = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        // If current numeral is less than the next numeral, subtract it
        if (i + 1 < n && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }

    return result;
}

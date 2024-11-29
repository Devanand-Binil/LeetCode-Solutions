string longestPalindrome(string s) {
    if (s.empty()) return "";
    
    string longest = "";
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindromes (centered at s[i])
        string odd = expandAroundCenter(s, i, i);
        if (odd.length() > longest.length()) {
            longest = odd;
        }
        
        // Even length palindromes (centered between s[i] and s[i+1])
        string even = expandAroundCenter(s, i, i + 1);
        if (even.length() > longest.length()) {
            longest = even;
        }
    }
    return longest;     
    }

    // Function to expand around center and find the longest palindrome
string expandAroundCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return the substring that is the palindrome
    return s.substr(left + 1, right - left - 1);
}

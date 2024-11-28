int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet; // Stores unique characters in the current window
        int maxLength = 0;           // Tracks the length of the longest substring
        int start = 0;               // Left pointer of the window

        // Iterate with the right pointer
        for (int end = 0; end < s.length(); ++end) {
            // If the character is already in the set, shrink the window
            while (charSet.find(s[end]) != charSet.end()) {
                charSet.erase(s[start]);
                ++start;
            }

            // Add the current character to the set
            charSet.insert(s[end]);

            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }

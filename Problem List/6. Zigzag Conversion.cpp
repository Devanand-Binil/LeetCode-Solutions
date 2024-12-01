string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) {
        return s;
    }

    string result;
    int cycleLen = 2 * numRows - 2; // Full cycle length (down + up)

    // Iterate through each row
    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < s.size(); j += cycleLen) {
            // Add the character in the current cycle
            result += s[j];

            // Check and add the middle character in the zigzag
            int midChar = j + cycleLen - 2 * row;
            if (row != 0 && row != numRows - 1 && midChar < s.size()) {
                result += s[midChar];
            }
        }
    }

    return result;
}

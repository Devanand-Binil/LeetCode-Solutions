        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int partition1 = (left + right) / 2; // Partition in nums1
            int partition2 = (m + n + 1) / 2 - partition1; // Partition in nums2

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1]; // Max of left part of nums1
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1]; // Min of right part of nums1

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1]; // Max of left part of nums2
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2]; // Min of right part of nums2

            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If the total length is odd, return the max of left parts
                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                } else {
                    // If the total length is even, return the average of the two middle elements
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
            } else if (maxLeft1 > minRight2) {
                right = partition1 - 1; // Move left
            } else {
                left = partition1 + 1; // Move right
            }
        }

        // If we reach here, input arrays are not sorted properly or the input is invalid
        throw invalid_argument("Input arrays are not sorted properly.");
    

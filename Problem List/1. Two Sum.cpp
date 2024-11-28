vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // Hash map to store numbers and their indices
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement
        
        // Check if the complement exists in the map
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i}; // Return the indices
        }
        
        // Add the current number and its index to the map
        num_map[nums[i]] = i;
    }
    
    return {}; // Return an empty vector if no solution is found (though it won't happen per problem statement)
}

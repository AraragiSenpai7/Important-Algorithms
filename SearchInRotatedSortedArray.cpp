// Problem: Search in Rotated Sorted Array
// Solution by: Shaswat Shrivas
// Date: 01-10-2024

#include <iostream>
#include <vector>

class Solution {
public:
    
    int search(std::vector<int>& nums, int target) {

        int n = nums.size();         // Get the size of the array
        int left = 0;             // Initialize the left pointer
        int right = n - 1;      // Initialize the right pointer

        // Binary search loop
        while (left <= right) {
            int mid = left + (right - left) / 2;           // Calculate the middle index
            if (nums[mid] == target) return mid;           // If the target is found, return its index

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {

                // Check if the target is within the sorted left half
                if (nums[left] <= target && target <= nums[mid]) {

                    right = mid - 1; 	// Narrow the search to the left half
                } else {
                    left = mid + 1; 	// Narrow the search to the right half
                }
            } else {

                // Check if the target is within the sorted right half
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1; 	// Narrow the search to the right half
                } else {
                    right = mid - 1; 	// Narrow the search to the left half
                }
            }
        }

        return -1; // Return -1 if the target is not found
    }
};

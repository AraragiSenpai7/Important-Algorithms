// Problem: Search in Rotated Sorted Array
// Solution by: Shaswat Shrivas
// Date: 01-10-2024

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0, lp = 0, rp = height.size() - 1;   // Initializing two pointers, one at the beginning (left pointer) and one at the end (right pointer) of the vector
        
	// Loop until the two pointers meet
        while (lp < rp) {
	    
	    // Calculate the height of the container, which is the minimum height between the two pointers
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);

 	    // Update the maximum amount of water if the current amount is greater
            maxWater = max(maxWater, w * ht);
            
            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        
        return maxWater;
    }
};
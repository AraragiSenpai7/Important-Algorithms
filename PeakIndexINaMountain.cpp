// Problem: Peak Index in a Mountain Array
// Solution by: Shaswat Shrivas
// Date: 02-10-2024

#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // The search space is between the second and second-to-last elements (since arr must have a peak)
        int start = 1, end = arr.size() - 2;
        
        // Binary search to find the peak element
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // Check if the mid element is the peak
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) return mid;
            
            // If mid element is less than the next, move right to find the peak
            else if (arr[mid] < arr[mid + 1]) start = mid + 1;
            
            // Otherwise, move left
            else end = mid - 1;
        }
        
        // If no peak is found (which should not happen in a valid mountain array)
        return -1;
    }
};

// Problem: Single Element in a Sorted Array
// Solution by: Shaswat Shrivas
// Date: 04-10-2924

#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: if the array has only one element, return it
        if (n == 1) return arr[0];
        
        int st = 0, end = n - 1;

        // Binary search to find the single element
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // Check edge cases where the first or last element is the single one
            if (mid == 0 && arr[0] != arr[1]) return arr[mid];
            if (mid == n-1 && arr[n-1] != arr[n-2]) return arr[mid];

            // If mid is the single element
            if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1]) return arr[mid];

            // Adjust search range based on index parity and adjacent elements
            if (mid % 2 == 0) {
                if (arr[mid - 1] == arr[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if (arr[mid - 1] == arr[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;  // This should never be reached if input is valid
    }
};

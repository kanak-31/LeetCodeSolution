/*
Approach: Modified binary search on a rotated sorted array with duplicates.
Handled duplicate ambiguity by shrinking the search space, then identified
the sorted half to continue the search.

Time Complexity: O(log n) average, O(n) worst case (due to duplicates)
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            // for duplicats elements
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;  //shrink search space
                continue; //to restart loop
            }

            // left half sorted
            if (nums[mid] >= nums[low]) {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // right half sorted
            else {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

/*
Approach: Modified binary search on a rotated sorted array with duplicates.
Handled duplicate ambiguity by shrinking the search space, then identified
the sorted half to continue the search.

Time Complexity: O(log n) average, O(n) worst case (due to duplicates)
Space Complexity: O(1)
*/

int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target){
            return true;
        }

        // for duplicats elements
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;  //shrink search space
            continue; //to restart loop
        }

        if (nums[mid] >= nums[low]) {      // left half sorted
            if (target >= nums[low] && target < nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else {
        if (target > nums[mid] && target <= nums[high]){  //right half is shorted
                low = mid + 1;
        }else{
                high = mid - 1;
        }
    }
    }
return false;
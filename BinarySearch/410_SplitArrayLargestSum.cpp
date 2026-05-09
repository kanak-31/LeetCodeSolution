/*
Approach: Binary search on answer (range: max element → total sum).
For each mid, check if array can be split into <= k subarrays
such that no subarray sum exceeds mid.

Time Complexity: O(n log(sum))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {

        int low = *max_element(nums.begin(), nums.end()); // largest smallest possible sum
        int high = 0;                                     // larsget sum
        for (int i = 0; i < nums.size(); i++)
        {
            high += nums[i];
        }
        long long sum = 0;

        while (low < high)
        {

            int subArray = 1;
            int mid = low + (high - low) / 2;

            for (int i = 0; i < nums.size(); i++)
            {
                if ((sum + nums[i]) <= mid)
                {
                    sum += nums[i];
                }
                else
                {
                    subArray++;
                    sum = nums[i];
                }
            }

            if (subArray <= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
            sum = 0;
        }

        return low;
    }
};
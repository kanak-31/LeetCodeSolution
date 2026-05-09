/*
Approach:
- Use two pointers at the beginning and end of the array.
- Calculate the water area using:
      min(height[i], height[j]) * (j - i)
- Move the pointer pointing to the smaller height because it limits the water storage.
- Keep updating the maximum area found.

Time Complexity: O(n)
    - Each pointer moves at most once through the array.

Space Complexity: O(1)
    - No extra space used, only variables.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int maximum = 0;
        int amount;

        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {

            amount = min(height[i], height[j]) * (j - i);

            if (maximum < amount)
            {
                maximum = amount;
            }

            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return maximum;
    }
};

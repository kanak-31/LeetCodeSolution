/*
Approach:
1. Sort the array.
2. Use two pointers:
   - one at the beginning
   - one at the end
3. Try to pair the heaviest person with the lightest person.
4. If their sum is within the limit, move both pointers.
5. Otherwise, move only the right pointer.
6. Increase boat count in both cases.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int left = 0;
        int right = people.size()-1;

        sort(people.begin(), people.end());

        while(left <= right){
            if(people[left] + people[right] <= limit){
                count++;
                left++;
                right--;
            } else {
                count++;
                right--;
            }
        }

        return count;
    }
};
/*
Approach: Binary Search using the API bool isBadVersion(version)
Description: Minimizes the search space by checking the middle version and narrowing the range to efficiently locate the first bad version.
Time Complexity: O(log n)
Space Complexity: O(1)

*/int firstBadVersion(int n) {
    int low = 1, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                high = mid;          // first bad is at mid or before
            } else {
                low = mid + 1;       // first bad is after mid
            }
        }
        return low;  // low == high == first bad version
}

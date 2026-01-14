/*
Finds the peak index in a mountain array using binary search
Compares mid with mid+1 to decide whether the peak lies left or right
Time Complexity: O(log n), Space Complexity: O(1)
*/int peakIndexInMountainArray(vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        } else {            
            e = mid;
        }
    }
    return s;  
};
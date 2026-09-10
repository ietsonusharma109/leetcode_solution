class Solution {
public:
    int specialArray(vector<int>& arr) {
        // 0 0 3 4 4
        sort(arr.begin(),arr.end());
        // 0 3 6 7 7
        int n = arr.size();
        if(arr[0]>=n) return n;
        for(int i = 1; i < n; i++) {
            int len = n - i;
            if(arr[i]>=len && arr[i]!=arr[i-1] && len>arr[i-1]) return len;
        }
        return -1;
    }
};
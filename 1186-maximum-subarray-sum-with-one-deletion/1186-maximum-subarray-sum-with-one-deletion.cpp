class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];   // max sum ending at i, bina deletion  ke 
        int oneDel = 0;       // max sum ending at i,  ek deletion  ke saath
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            // i-th element delete karna ya i-th element include karna
            oneDel = max(oneDel + arr[i], noDel);
            noDel = max(noDel + arr[i], arr[i]);
            ans = max(ans, max(noDel, oneDel));
        }
        return ans;
    }
};
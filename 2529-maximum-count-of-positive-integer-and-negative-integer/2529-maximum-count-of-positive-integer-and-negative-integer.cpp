class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // calculating smallest positive number (and its index)
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < 0) lo = mid + 1;
            else hi = mid;
        }
        int neg = lo;
        // count of elements > 0
        lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= 0) lo = mid + 1;
            else hi = mid;
        }
        int pos = n - lo;
        return max(pos, neg);
    }
};
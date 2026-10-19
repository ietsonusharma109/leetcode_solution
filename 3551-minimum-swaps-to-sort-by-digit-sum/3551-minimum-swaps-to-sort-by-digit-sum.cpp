class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), swaps = 0;
        vector<pair<pair<int,int>, int>> v;

        for (int i = 0; i < n; i++) {
            int s = 0, x = nums[i];
            for (; x; x /= 10) s += x % 10;
            v.push_back({{s, nums[i]}, i});
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            while (v[i].second != i) {
                swap(v[i], v[v[i].second]);
                swaps++;
            }
        }
        return swaps;  
    }
};
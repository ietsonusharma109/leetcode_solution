class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1; // remainder 0 pehle se index -1 par maana
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (mp.count(rem)) {
                if (i - mp[rem] >= 2) return true; // length at least 2
            } else {
                mp[rem] = i; // sirf pehli baar store karo
            }
        }
        return false; 
    }
};
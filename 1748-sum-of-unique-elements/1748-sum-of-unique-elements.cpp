class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;

        int sum = 0;
        for (auto& [num, freq] : count) {
            if (freq == 1) sum += num;
        }
        return sum; 
    }
};
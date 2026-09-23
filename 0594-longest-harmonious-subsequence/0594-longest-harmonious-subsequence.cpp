class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int maxlen = 0;
        for (auto& [num, count] : freq) {
            if (freq.find(num + 1) != freq.end()) {
                maxlen = max(maxlen, count + freq[num + 1]);
            }
        }
        return maxlen;    
    }
};
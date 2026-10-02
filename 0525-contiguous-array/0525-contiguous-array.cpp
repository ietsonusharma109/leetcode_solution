class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIdx;
        firstIdx[0] = -1; // sum 0 pehle index -1 pe
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0) ? -1 : 1;  // 0 ko -1 maano
            if (firstIdx.count(sum)) {
                maxLen = max(maxLen, i - firstIdx[sum]);
            } else {
                firstIdx[sum] = i;
            }
        }
        return maxLen;  
    }
};
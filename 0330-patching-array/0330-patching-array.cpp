class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // sabse chota sum jo abhi tak cover nhi hua
        int patches = 0;
        int i = 0;
        int m = nums.size();
        
        while (miss <= n) {
            if (i < m && nums[i] <= miss) {
                // ye number already range [1, miss-1] ke andar hai, use kar lo
                miss += nums[i];
                i++;
            } else {
                // patch karna padega -> best patch = miss khud
                miss += miss; // miss = 2 * miss
                patches++;
            }
        }
        return patches;  
    }
};
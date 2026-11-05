class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for (int x : arr1) {
            // arr2 mai x ke sabse paas wali value dhundo (>= x - d)
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);

            // agar koi element [x - d, x + d] range mai hai to x count nahi hoga
            if (it == arr2.end() || *it > x + d) {
                count++;
            }
        }
        return count; 
    }
};
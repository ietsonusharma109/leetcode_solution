class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);
        for (int x : arr1) count[x]++;

        vector<int> ans;
        // pehle arr2 kr order main
        for (int x : arr2) {
            while (count[x]-- > 0) ans.push_back(x);
        }
        // baaki elements ascending order main
        for (int i = 0; i <= 1000; i++) {
            while (count[i] > 0) {
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;    
    }
};
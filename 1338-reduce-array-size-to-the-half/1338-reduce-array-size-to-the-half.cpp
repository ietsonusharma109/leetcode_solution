class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(100001, 0);
        for (int x : arr) freq[x]++;

        sort(freq.begin(), freq.end(), greater<int>());
        int removed = 0, count = 0;
        for (int f : freq) {
            removed += f;
            count++;
            if (removed >= n / 2) break;
        }
        return count;  
    }
};
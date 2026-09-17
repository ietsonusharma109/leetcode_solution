class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        // har word ke liye bitmask banao (kaunse letters use hue hain)
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                mask[i] |= (1 << (c - 'a'));
            }
        }
        int maxProd = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                // agar common letters nahi hai (AND = 0)
                if ((mask[i] & mask[j]) == 0) {
                    int prod = words[i].size() * words[j].size();
                    maxProd = max(maxProd, prod);
                }
            }
        }
        return maxProd; 
    }
};
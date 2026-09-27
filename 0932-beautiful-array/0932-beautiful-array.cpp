class Solution {
public:
    unordered_map<int, vector<int>> memo;
    vector<int> beautifulArray(int n) {
        if (memo.count(n)) return memo[n];
        vector<int> result;
        if (n == 1) {
            result = {1};
        } else {
            // left part: odd numbers (from beautifulArray((n + 1) / 2))
            vector<int>  left = beautifulArray((n + 1) / 2);
            // right part: even numbers (from beautifulArray(n/2))
            vector<int>  right = beautifulArray(n / 2);

            for (int x : left) result.push_back(2 * x - 1); // odds
            for (int x : right) result.push_back(2 * x); // evens
        }
        memo[n] = result;
        return result;  
    }
};
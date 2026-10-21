class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        // pehle se sorted hai
        if (is_sorted(s.begin(), s.end())) return 0;
        // n == 2 aur sorted nahi -> koi valid operation nahi (poori string select nahi kar sakte)
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        // pehla char min hai ya last char amx hai -> baaki hisa sort karo
        if (s[0] == mn || s[n - 1] == mx) return 1;
        // worst case: max sirf start mai (unique) aur min sirf end mai (unique)
        if (count(s.begin(), s.end(), mx) == 1 && s[0] == mx &&
            count(s.begin(), s.end(), mn) == 1 && s[n - 1] == mn) {
            return 3;
        }  
        return 2;
    }
};
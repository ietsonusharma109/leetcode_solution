class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        // option 1: sirf type1 or type2 kharido
        long long ans = n1 * c1 + n2 * c2;

        // option 2: min(n1, n2) type 3 kharido, baaki ek type ka alag se
        long long m = min(n1, n2);
        ans = min(ans, m * cb + (n1 - m) * c1 + (n2 - m) * c2);

        // option 3: max(n1, n2) type 3 kharido (dono cover ho jayega)
        long long M = max(n1, n2);
        ans = min(ans, M * cb);

        return ans;  
    }
};
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), r = n - 1;
        vector<long long> p(n + 1, 0);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + nums[i];
        auto C = [&](int s, int e) {return (long long)nums[s] * (e - s + 1) - (p[e + 1] - p[s]); };

        deque<int> dq;
        long long cost = 0, ans = 0;
        for (int l = n - 1; l >= 0; l--) {
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int e = dq.size() > 1 ? dq[1] - 1 : r;
                cost -= C(dq.front(), e);
                dq.pop_front();
            }
            cost += C(l, dq.empty() ? r : dq.front() - 1);
            dq.push_front(l);

            while (cost > k) {
                int b = dq.back();
                cost -= C(b, r);
                if (b == r) dq.pop_back();
                else cost += C(b, r - 1);
                r--;
            }
            ans += r - l + 1;
        }
        return ans; 
    }
};
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> count(k, 0);

        // free server ke Ids (sorted set)
        set<int> freeservers;
        for (int i = 0; i < k; i++) freeservers.insert(i);

        //busy servers: {end_time, server_id} (min heap)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;

        for (int i = 0; i < n; i++) {
            // jo servers ehs time tak free ho chuke hai unhe wapas free set mai daalo
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                freeservers.insert(busy.top().second);
                busy.pop();
            }
            // sab busy hai to request drop
            if (freeservers.empty()) continue;

            // (i % k) ya usse bada pehla free server
            auto it = freeservers.lower_bound(i % k);
            if (it == freeservers.end()) it = freeservers.begin();

            int id = *it;
            freeservers.erase(it);
            count[id]++;
            busy.push({arrival[i] + load[i], id});
        }
        int mx = *max_element(count.begin(), count.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (count[i] == mx) ans.push_back(i);
        }
        return ans; 
    }
};
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        typedef pair<long long,int> p;
        priority_queue<p, vector<p>, greater<p>> fr, bz; // fr: (weight, idx), bz: (free time, idx)
        for (int i = 0; i < servers.size(); i++) fr.push({servers[i], i});
        vector<int> ans(tasks.size());
        long long time = 0;
        for (int j = 0; j < tasks.size(); j++) {
            time = max(time, (long long)j);
            if (fr.empty()) time = max(time, bz.top().first);
            while (!bz.empty() && bz.top().first <= time) {
                int i = bz.top().second; bz.pop();
                fr.push({servers[i], i});
            }
            int i = fr.top().second; fr.pop();
            ans[j] = i;
            bz.push({time + tasks[j], i});
        }
        return ans;
    }
};
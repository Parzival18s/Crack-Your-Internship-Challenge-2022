class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int tasks_size = tasks.size();
        int max_freq = 0;
        for (auto &it : tasks) {
            count[it - 65]++;
            max_freq = max(max_freq, count[it - 65]);
        }

        int result = (max_freq - 1) * (n+1);
        for (auto &it : count) {
            if (max_freq == it) {
                result++;
            }
        }

        return max(result, tasks_size);
    }
};

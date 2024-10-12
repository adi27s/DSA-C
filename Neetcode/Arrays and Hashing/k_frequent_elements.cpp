class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;
        vector<int> v;
        vector<int> finalanswer;
        int index = 0;

        for (auto i : nums)
        {
            if (mp.find(i) == mp.end())
            {
                mp[i] = 1;
            }
            else
            {
                mp[i] += 1;
            }
        }

        for (auto i : mp)
        {
            v.push_back(i.second);
        }

        sort(v.begin(), v.end());

        int target = k;
        int end_freq = 0;
        auto it = v.end();
        while (target != 0)
        {
            --it;
            --target;
        }

        end_freq = *it;

        int max = -1;
        for (auto i : mp)
        {
            if (i.second >= end_freq)
            {
                finalanswer.push_back(i.first);
            }
        }

        return finalanswer;
    }
};
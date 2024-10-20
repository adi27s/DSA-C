class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        vector<int> v;
        vector<int> ans;
        int vindex = 0;
        for (auto i : nums)
        {
            v.resize(vindex + 1);
            v[vindex] = i;
            ++vindex;
        }
        sort(v.begin(), v.end());

        int count = 0;
        int temp = 0;
        bool init = true;
        vindex = 0;
        for (auto i : v)
        {
            if (init)
            {
                temp = i;
                count = 1;
                init = false;
            }
            else if (i == (temp + 1))
            {
                ++count;
                temp = i;
            }
            else if (i == temp)
            {
                continue;
            }
            else
            {
                ans.resize(vindex + 1);
                ans[vindex] = count;
                count = 1;
                temp = i;
                ++vindex;
            }
        }

        ans.resize(vindex + 1);
        ans[vindex] = count;

        int max = -1;
        for (auto i : ans)
        {
            if (i > max)
                max = i;
        }

        return max;
    }
};
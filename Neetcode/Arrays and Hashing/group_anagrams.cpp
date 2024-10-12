class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> answer;
        map<string, vector<int>> mp;
        int index = 0;
        for (auto i : strs)
        {
            // v.push_back(i);
            sort(i.begin(), i.end());
            mp[i].push_back(index);
            ++index;
        }

        int vindex = 0;
        for (auto i : mp)
        {
            answer.push_back(vector<string>{});
            for (auto j : i.second)
            {
                answer[vindex].push_back(strs[j]);
            }
            ++vindex;
        }

        return answer;
    }
};
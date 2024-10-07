// SOLUTION - 1
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> mp;
        map<char, int> mp2;
        for (auto i : s)
        {
            if (mp.find(i) != mp.end())
            {
                // if key found, then increment value
                mp[i] += 1;
            }
            else
            {
                mp[i] = 1;
            }
        }

        // Addition of elements is over
        for (auto i : t)
        {
            if (mp2.find(i) != mp2.end())
            {
                // if key found, then increment value
                mp2[i] += 1;
            }
            else
            {
                mp2[i] = 1;
            }
        }

        if (mp == mp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


// SOLUTION - 2 

map<char, int> mp;
for (auto i : s)
{
    if (mp.find(i) != mp.end())
    {
        mp[i] += 1;
    }
    else
    {
        mp[i] = 1;
    }
}

for (auto i : t)
{
    if (mp.find(i) != mp.end())
    {
        mp[i] -= 1;
    }
    else
    {
        return false;
    }
}

for (auto i = mp.begin(); i != mp.end(); ++i)
{
    if (i->second != 0)
    {
        return false;
    }
}

return true;
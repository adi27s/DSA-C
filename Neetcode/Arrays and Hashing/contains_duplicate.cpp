// Using STL
bool hasDuplicate(vector<int> &nums)
{
    set<int> a;
    for (auto i : nums)
    {
        a.insert(i);
    }
    return nums.size() != a.size();
}

// With sorting (best case)
    unordered_set<int> s;
        for(auto i: nums){
            if (s.find(i) != s.end()){
                return true;
            }
            else{
                s.insert(i);
            }
        }
        return false;
    }

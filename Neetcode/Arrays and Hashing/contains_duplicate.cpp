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

// Without STL

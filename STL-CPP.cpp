#include <iostream>
#include <vector>
#include <set>
#include <map>

#include <bits/stdc++.h>
/*
1. Vectors
2. Sets
3. Map
*/

//---------------- Vectors ----------------
vector<int> g1; // Init

for (int i = 1; i <= 5; i++) // Push
    g1.push_back(i);

cout << "Output of begin and end: "; // Traverse-1
for (auto i = g1.begin(); i != g1.end(); ++i)
    cout << *i << " ";

for (auto i : vec)   // Traverse-2
    cout<< i << " ";

cout << "Size : " << g1.size(); // Checks the Size

cout << "\nat : g1.at(4) = " << g1.at(4); // Element access at a position (0-based indexing)

g1.insert(g1.begin() + 3, 100); // 0-based indexing

g1.erase(g1.begin()); // Remove an element at Pos
g1.size();  // returns size
sort(answer.begin(), answer.end());
//-----------------------------------------

//---------------- Sets ----------------
set<int> a; // Init-1 (default - Ascending Order)
set<int, greater<int>> a; // Init-2 (Descending Order)

a.insert(4);    // Push

for (itr = a.begin(); itr != a.end(); itr++) // Traverse-1
    cout << *itr << " ";

for (auto i : a)       // Traverse-2
    cout << i << ' ';

a.erase(50);    // Erase an element
a.size();   // Returns size

a.find(number); // returns a.end() if number is not found in the set

//-----------------------------------------

//-------------Map----------------

map<string, int> mp; // Init

mp["one"] = 1; // Insertion

map.size(); // Size

for (auto itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) // Traversal-1
    cout << itr->first << itr->second;

for(auto i : mp)            // Traversal-2
    cout << i.first << i.second;

// Erase
map_name.erase(key);

// Find
if (mp.find(key1) != mp.end())
{
    cout << "Key '" << key1 << "' found with";
    cout << " value: " << mp[key1] << endl;
}

//--------------------------------


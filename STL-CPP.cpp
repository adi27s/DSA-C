#include <iostream>
#include <vector>
#include <set>

/*
1. Vectors
2. Sets
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

//-----------------------------------------

//---------------- Sets ----------------
set<int> a; // Init-1 (default - Ascending Order)
set<int, greater<int>> a; // Init-2 (Descending Order)

a.insert(4);    // Push

for (itr = a.begin(); itr != a.end(); itr++) // Traverse-1
{
    cout << *itr << " ";
}

for (auto i : a)       // Traverse-2
{
    cout << i << ' ';
}

a.erase(50);    // Erase an element
a.size();   // Returns size

a.find(number); // returns a.end() if number is not found in the set

//-----------------------------------------

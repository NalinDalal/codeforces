// https://codeforces.com/problemset/problem/344/A
/* A. Magnets
time limit per test1 second
memory limit per test256 megabytes
Mad scientist Mike entertains himself by arranging rows of dominoes. He doesn't
need dominoes, though: he uses rectangular magnets instead. Each magnet has two
poles, positive (a "plus") and negative (a "minus"). If two magnets are put
together at a close distance, then the like poles will repel each other and the
opposite poles will attract each other.

Mike starts by laying one magnet horizontally on the table. During each
following step Mike adds one more magnet horizontally to the right end of the
row. Depending on how Mike puts the magnet on the table, it is either attracted
to the previous one (forming a group of multiple magnets linked together) or
repelled by it (then Mike lays this magnet at some distance to the right from
the previous one). We assume that a sole magnet not linked to others forms a
group of its own.


Mike arranged multiple magnets in a row. Determine the number of groups that the
magnets formed.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 100000) — the number
of magnets. Then n lines follow. The i-th line (1 ≤ i ≤ n) contains either
characters "01", if Mike put the i-th magnet in the "plus-minus" position, or
characters "10", if Mike put the magnet in the "minus-plus" position.

Output
On the single line of the output print the number of groups of magnets.

Examples
Input
6
10
10
10
01
10
10
Output
3

Input
4
01
01
10
10
Output
2

Note
The first testcase corresponds to the figure. The testcase has three groups
consisting of three, one and two magnets. The second testcase has two groups,
each consisting of two magnets.*/

/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n; // number of magnets
  cin >> n;
  vector<string> magnets(n);    // vector of magnets
  for (int i = 0; i < n; i++) { // read magnets
    cin >> magnets[i] >> endl;
  }
  int count = 1; // number of groups

  // check if previous entry has same last symbol as current entry 1st symbol
  // if yes then count++
  // else do nothing

  for (int i = 1; i < n; i++) {
    // Compare the last symbol of the previous magnet with the first symbol of
    // the current one
    if (magnets[i - 1][1] != magnets[i][0]) {
      count++; // New group
    }
  }

  cout << count << endl; // Output the number of groups

  return 0;
}*/

// t.ly/ComG7
//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define itr(i, a, b) for (int i = int(a); i < int(b); i++)

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); // Fix: changed 'cin.tie(o)' to 'cin.tie(0)'

  int n, x = 1; // 'x' starts as 1 since there's at least one group
  string s, t;  // 's' is the previous magnet, 't' is the current magnet

  cin >> n >> s; // Input the number of magnets and the first magnet
  n--;           // Decrement 'n' as we already read the first magnet

  while (n--) {
    cin >> t;      // Read the next magnet
    x += (s != t); // Increment 'x' if the current magnet forms a new group
    s = t;         // Update 's' to the current magnet
  }

  cout << x << el; // Output the total number of groups
  return 0;
}

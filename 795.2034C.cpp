/*C. Trapped in the Witch's Labyrinth
time limit per test3 seconds
memory limit per test256 megabytes
In the fourth labor of Rostam, the legendary hero from the Shahnameh, an old
witch has created a magical maze to trap him. The maze is a rectangular grid
consisting of 𝑛 rows and 𝑚 columns. Each cell in the maze points in a specific
direction: up, down, left, or right. The witch has enchanted Rostam so that
whenever he is in a cell, he will move to the next cell in the direction
indicated by that cell.


If Rostam eventually exits the maze, he will be freed from the witch's
enchantment and will defeat her. However, if he remains trapped within the maze
forever, he will never escape.

The witch has not yet determined the directions for all the cells. She wants to
assign directions to the unspecified cells in such a way that the number of
starting cells from which Rostam will be trapped forever is maximized. Your task
is to find the maximum number of starting cells which make Rostam trapped.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104
), the number of test cases.

For each test case:

The first line contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤1000
), representing the number of rows and columns in the maze.
Each of the next 𝑛
 lines contains a string of 𝑚
 characters representing the directions in the maze. Each character is one of
the following: U (up) D (down) L (left) R (right) ? (unspecified direction) It's
guaranteed that the sum of 𝑛⋅𝑚 over all test cases is at most 106
.

Output
For each test case, print a single integer, the maximum number of starting cells
from which Rostam will be trapped forever after assigning directions to the
unspecified cells optimally.

Example
InputCopy
3
3 3
UUU
L?R
DDD
2 3
???
???
3 3
?U?
R?L
RDL
OutputCopy
0
6
5
Note
In the first test case, all of the cells will be good no matter what you do.

In the second test case, if you assign the ?s like the picture below, all of the
cells will be bad:


In the third test case, if you assign the ?s like the picture below, you will
have 5 bad cells (red-shaded cells):





*/

#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout.precision(numeric_limits<double>::max_digits10);

int solve(vector<int> &a, int n) {
  sort(a.begin(), a.end());
  int ans = -1;

  if (a[0] > n) {
    ans = n;
  }

  for (int i = 0; i < n; i++) {
    if (a[i] <= n - i - 1) {
      if (i == n - 1 || a[i + 1] > n - i - 1) {
        ans = n - i - 1;
      }
    }
  }

  return ans;
}

int main() {
  fastIO;

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    cout << solve(a, n) << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2034/345306410

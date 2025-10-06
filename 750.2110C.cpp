/*C. Racing
time limit per test2 seconds
memory limit per test256 megabytes
In 2077, a sport called hobby-droning is gaining popularity among robots.

You already have a drone, and you want to win. For this, your drone needs to fly
through a course with 𝑛 obstacles.

The 𝑖
-th obstacle is defined by two numbers 𝑙𝑖,𝑟𝑖
. Let the height of your drone at the 𝑖
-th obstacle be ℎ𝑖
. Then the drone passes through this obstacle if 𝑙𝑖≤ℎ𝑖≤𝑟𝑖
. Initially, the drone is on the ground, meaning ℎ0=0
.

The flight program for the drone is represented by an array 𝑑1,𝑑2,…,𝑑𝑛
, where ℎ𝑖−ℎ𝑖−1=𝑑𝑖
, and 0≤𝑑𝑖≤1
. This means that your drone either does not change height between obstacles or
rises by 1 . You already have a flight program, but some 𝑑𝑖 in it are unknown
and marked as −1 . Replace the unknown 𝑑𝑖 with numbers 0 and 1 to create a
flight program that passes through the entire obstacle course, or report that it
is impossible.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

In the first line of each test case, an integer 𝑛
 (1≤𝑛≤2⋅105)
 is given — the size of the array 𝑑
.

In the second line of each test case, there are 𝑛
 integers 𝑑1,𝑑2,…,𝑑𝑛
 (−1≤𝑑𝑖≤1
) — the elements of the array 𝑑
. 𝑑𝑖=−1
 means that this 𝑑𝑖
 is unknown to you.

Next, there are 𝑛
 lines containing 2
 integers 𝑙𝑖,𝑟𝑖
 (0≤𝑙𝑖≤𝑟𝑖≤𝑛
) — descriptions of the obstacles.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers 𝑑1,𝑑2,…,𝑑𝑛
, if it is possible to correctly restore the array 𝑑
, or −1
 if it is not possible.

Example
InputCopy
5
4
0 -1 -1 1
0 4
1 2
2 4
1 4
3
0 -1 -1
0 1
2 2
0 3
2
-1 -1
0 0
2 2
8
-1 -1 1 -1 -1 0 0 -1
0 0
0 1
0 2
0 2
1 3
0 4
2 5
4 5
1
0
1 1
OutputCopy
0 1 1 1
-1
-1
0 1 1 0 1 0 0 1
-1
Note
In the first test case, one possible answer is 𝑑=[0,1,1,1]
. The array ℎ
 will be [0,0+1,0+1+1,0+1+1+1]=[0,1,2,3]
. This array meets the conditions of the problem.

In the second test case, it can be proven that there is no suitable array 𝑑
, so the answer is −1
.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;

  while (t--) {
    long n;
    cin >> n;

    vector<long> dv(n), bl(n), bh(n);
    for (long &x : dv)
      cin >> x;
    for (long i = 0; i < n; i++)
      cin >> bl[i] >> bh[i];

    bool possible = true;
    stack<long> s;
    long h = 0;

    for (long p = 0; possible && p < n; p++) {
      if (dv[p] < 0) {
        s.push(p);
      } else {
        h += dv[p];
      }

      while (!s.empty() && h < bl[p]) {
        dv[s.top()] = 1;
        ++h;
        s.pop();
      }

      if (h < bl[p] || h > bh[p]) {
        possible = false;
        break;
      }

      while (h + (long)s.size() > bh[p]) {
        dv[s.top()] = 0;
        s.pop();
      }
    }

    if (!possible) {
      cout << -1 << '\n';
      continue;
    }

    while (!s.empty()) {
      dv[s.top()] = 0;
      s.pop();
    }

    for (long i = 0; i < n; i++) {
      cout << dv[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2110/342207618

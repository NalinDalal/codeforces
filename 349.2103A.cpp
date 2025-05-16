/* A. Common Multiple
time limit per test1 second
memory limit per test256 megabytes

You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛
. An array 𝑥1,𝑥2,…,𝑥𝑚
 is beautiful if there exists an array 𝑦1,𝑦2,…,𝑦𝑚
 such that the elements of 𝑦
 are distinct (in other words, 𝑦𝑖≠𝑦𝑗
 for all 1≤𝑖<𝑗≤𝑚
), and the product of 𝑥𝑖
 and 𝑦𝑖
 is the same for all 1≤𝑖≤𝑚
 (in other words, 𝑥𝑖⋅𝑦𝑖=𝑥𝑗⋅𝑦𝑗
 for all 1≤𝑖<𝑗≤𝑚
).

Your task is to determine the maximum size of a subsequence∗
 of array 𝑎
 that is beautiful.

∗
A sequence 𝑏
 is a subsequence of a sequence 𝑎
 if 𝑏
 can be obtained from 𝑎
 by the deletion of several (possibly, zero or all) element from arbitrary
positions.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of array 𝑎
.

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, output the maximum size of a subsequence of array 𝑎
 that is beautiful.

Example
InputCopy
3
3
1 2 3
5
3 1 4 1 5
1
1
OutputCopy
3
4
1
Note
In the first test case, the entire array 𝑎=[1,2,3]
 is already beautiful. A possible array 𝑦
 is [6,3,2]
, which is valid since the elements of 𝑦
 are distinct, and 1⋅6=2⋅3=3⋅2
.

In the second test case, the subsequence [3,1,4,5]
 is beautiful. A possible array 𝑦
 is [20,60,15,12]
. It can be proven that the entire array 𝑎=[3,1,4,1,5]
 is not beautiful, so the maximum size of a subsequence of array 𝑎
 that is beautiful is 4
.


*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    bool v[101] = {0};
    int total = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      total += 1 - v[x];
      v[x] = 1;
    }

    cout << total << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2103/319859259

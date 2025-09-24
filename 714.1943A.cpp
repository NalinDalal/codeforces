/*A. MEX Game 1
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob play yet another game on an array 𝑎
 of size 𝑛
. Alice starts with an empty array 𝑐
. Both players take turns playing, with Alice starting first.

On Alice's turn, she picks one element from 𝑎
, appends that element to 𝑐
, and then deletes it from 𝑎
.

On Bob's turn, he picks one element from 𝑎
, and then deletes it from 𝑎
.

The game ends when the array 𝑎
 is empty. Game's score is defined to be the MEX†
 of 𝑐
. Alice wants to maximize the score while Bob wants to minimize it. Find game's
final score if both players play optimally.

†
 The MEX
 (minimum excludant) of an array of integers is defined as the smallest
non-negative integer which does not occur in the array. For example:

The MEX of [2,2,1]
 is 0
, because 0
 does not belong to the array.
The MEX of [3,1,0,1]
 is 2
, because 0
 and 1
 belong to the array, but 2
 does not.
The MEX of [0,3,1,2]
 is 4
, because 0
, 1
, 2
 and 3
 belong to the array, but 4
 does not.
Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤2⋅104 ) — the number of test cases. The description of the test cases
follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖<𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, find game's score if both players play optimally.

Example
InputCopy
3
4
0 0 1 1
4
0 1 2 3
2
1 1
OutputCopy
2
1
0
Note
In the first test case, a possible game with a score of 2
 is as follows:

Alice chooses the element 1
. After this move, 𝑎=[0,0,1]
 and 𝑐=[1]
.
Bob chooses the element 0
. After this move, 𝑎=[0,1]
 and 𝑐=[1]
.
Alice chooses the element 0
. After this move, 𝑎=[1]
 and 𝑐=[1,0]
.
Bob chooses the element 1
. After this move, 𝑎=[]
 and 𝑐=[1,0]
.
At the end, 𝑐=[1,0]
, which has a MEX of 2
. Note that this is an example game and does not necessarily represent the
optimal strategy for both players.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x <= n)
        f[x]++;
    }

    int single = 0, ans = 0;
    for (int p = 0; p <= n; p++) {
      if (f[p] == 0) {
        ans = p;
        break;
      }
      single += (f[p] == 1);
      if (single == 2) {
        ans = p;
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1943/340109361

/*C. Training Before the Olympiad
time limit per test1 second
memory limit per test256 megabytes
Masha and Olya have an important team olympiad coming up soon. In honor of this,
Masha, for warm-up, suggested playing a game with Olya:

There is an array 𝑎
 of size 𝑛
. Masha goes first, and the players take turns. Each move is described by the
following sequence of actions:

∙
 If the size of the array is 1
, the game ends.

∙
 The player who is currently playing chooses two different indices 𝑖
, 𝑗
 (1≤𝑖,𝑗≤|𝑎|
), and performs the following operation — removes 𝑎𝑖
 and 𝑎𝑗
 from the array and adds to the array a number equal to ⌊𝑎𝑖+𝑎𝑗2⌋⋅2
. In other words, first divides the sum of the numbers 𝑎𝑖
, 𝑎𝑗
 by 2
 rounding down, and then multiplies the result by 2
.

Masha aims to maximize the final number, while Olya aims to minimize it.

Masha and Olya decided to play on each non-empty prefix of the initial array 𝑎
, and asked for your help.

For each 𝑘=1,2,…,𝑛
, answer the following question. Let only the first 𝑘
 elements of the array 𝑎
 be present in the game, with indices 1,2,…,𝑘
 respectively. What number will remain at the end with optimal play by both
players?

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the size of the array.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the array on which Masha and Olya play.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output 𝑛
 integers. The 𝑘
-th of these numbers should be equal to the number that will remain at the end
with optimal play by both players, on the array consisting of the first 𝑘
 elements of the array 𝑎
.

Example
InputCopy
4
1
31
6
6 3 7 2 5 4
3
3 10 11
5
7 13 11 19 1
OutputCopy
31
6 8 16 18 22 26
3 12 24
7 20 30 48 50
Note
In the third test case, for a prefix of length 1
, the answer is 3
. For a prefix of length 2
, Masha has only one move, so the answer is 12
. For a prefix of length 3
, Masha has three possible moves: she chooses 3
 and 10
, then the final number is 22
, 3
 and 11
, then the final number is 24
, 10
 and 11
, then the final number is 22
, so Masha will choose 3
 and 11
 and get 24
.



*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    ll cs = 0, cnt = 0;
    for (ll p = 0; p < n; p++) {
      ll x;
      cin >> x;
      cs += x;
      cnt += (x % 2);

      ll ans = cs;
      if (cnt % 3 == 0 || cnt % 3 == 2) {
        ans -= (cnt / 3);
      } else if (cnt % 3 == 1 && p > 0) {
        ans -= ((cnt / 3) + 1);
      }

      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1916/334611461

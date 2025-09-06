/*A. Cards Partition
time limit per test2 seconds
memory limit per test256 megabytes
DJ Genki vs Gram - Einherjar Joker
⠀
You have some cards. An integer between 1
 and 𝑛
 is written on each card: specifically, for each 𝑖
 from 1
 to 𝑛
, you have 𝑎𝑖
 cards which have the number 𝑖
 written on them.

There is also a shop which contains unlimited cards of each type. You have 𝑘
 coins, so you can buy at most 𝑘
 new cards in total, and the cards you buy can contain any integer between 1
 and 𝐧
, inclusive.

After buying the new cards, you must partition all your cards into decks,
according to the following rules:

all the decks must have the same size;
there are no pairs of cards with the same value in the same deck.
Find the maximum possible size of a deck after buying cards and partitioning
them optimally.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
, 𝑘
 (1≤𝑛≤2⋅105
, 0≤𝑘≤1016
) — the number of distinct types of cards and the number of coins.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤1010
, ∑𝑎𝑖≥1
) — the number of cards of type 𝑖
 you have at the beginning, for each 1≤𝑖≤𝑛
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer: the maximum possible size of a deck
if you operate optimally.

Example
InputCopy
9
3 1
3 2 2
5 4
2 6 1 2 4
2 100
1410065408 10000000000
10 8
7 4 6 6 9 3 10 2 8 7
2 12
2 2
2 70
0 1
1 0
1
3 0
2 1 2
3 1
0 3 3
OutputCopy
2
3
1
7
2
2
1
1
2
Note
In the first test case, you can buy one card with the number 1
, and your cards become [1,1,1,1,2,2,3,3]
. You can partition them into the decks [1,2],[1,2],[1,3],[1,3]
: they all have size 2
, and they all contain distinct values. You can show that you cannot get a
partition with decks of size greater than 2 , so the answer is 2
.

In the second test case, you can buy two cards with the number 1
 and one card with the number 3
, and your cards become [1,1,1,1,2,2,2,2,2,2,3,3,4,4,5,5,5,5]
, which can be partitioned into [1,2,3],[1,2,4],[1,2,5],[1,2,5],[2,3,5],[2,4,5]
. You can show that you cannot get a partition with decks of size greater than 3
, so the answer is 3
.
*/
#include <bits/stdc++.h>
using namespace std;

bool check(int d, long long sum, long long mx, long long k) {
  // Check if deck size d is possible
  long long target = mx * d;
  long long present = sum;

  long long low = 0, high = 1e12, best = high;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (target + d * mid >= present) {
      best = min(best, mid);
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  target += best * d;
  k -= (target - present);
  return k >= 0;
}

void solve() {
  int n;
  long long k;
  cin >> n >> k;

  vector<long long> a(n);
  long long sum = 0, mx = 0;

  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    sum += x;
    mx = max(mx, x);
  }

  int ans = 0;
  for (int d = 1; d <= n; d++) {
    if (check(d, sum, mx, k))
      ans = d;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2018/337092747

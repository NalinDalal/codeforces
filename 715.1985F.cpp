/*F. Final Boss
time limit per test2 seconds
memory limit per test256 megabytes
You are facing the final boss in your favorite video game. The boss enemy has ℎ
 health. Your character has 𝑛
 attacks. The 𝑖
'th attack deals 𝑎𝑖
 damage to the boss but has a cooldown of 𝑐𝑖
 turns, meaning the next time you can use this attack is turn 𝑥+𝑐𝑖
 if your current turn is 𝑥
. Each turn, you can use all attacks that are not currently on cooldown, all at
once. If all attacks are on cooldown, you do nothing for the turn and skip to
the next turn.

Initially, all attacks are not on cooldown. How many turns will you take to beat
the boss? The boss is beaten when its health is 0 or less.

Input
The first line contains 𝑡
 (1≤𝑡≤104
)  – the number of test cases.

The first line of each test case contains two integers ℎ
 and 𝑛
 (1≤ℎ,𝑛≤2⋅105
) – the health of the boss and the number of attacks you have.

The following line of each test case contains 𝑛
 integers 𝑎1,𝑎2,...,𝑎𝑛
 (1≤𝑎𝑖≤2⋅105
) – the damage of your attacks.

The following line of each test case contains 𝑛
 integers 𝑐1,𝑐2,...,𝑐𝑛
 (1≤𝑐𝑖≤2⋅105
) – the cooldown of your attacks.

It is guaranteed that the sum of ℎ
 and 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer, the minimum number of turns required to
beat the boss.

Example
InputCopy
8
3 2
2 1
2 1
5 2
2 1
2 1
50 3
5 6 7
5 6 7
50 3
2 2 2
3 3 3
90000 2
200000 200000
1 1
100000 1
1
200000
6 7
3 2 3 2 3 1 2
6 5 9 5 10 7 7
21 6
1 1 1 1 1 1
5 5 8 10 7 6
OutputCopy
1
3
15
25
1
19999800001
1
21
Note
For the first test case, you can use attacks 1
 and 2
 on the first turn, dealing 3
 damage in total, and slaying the boss.

For the second case, you can beat the boss in 3
 turns by using the following attacks:

Turn 1
: Use attacks 1
 and 2
, dealing 3
 damage to the boss. The boss now has 2
 health left.

Turn 2
: Use attack 2
, dealing 1
 damage to the boss. The boss now has 1
 health left.

Turn 3
: Use attack 1
, dealing 2
 damage to the boss. The boss now has −1
 health left. Since its health is less than or equal to 0
, you beat the boss.

For the sixth test case: remember to use 64-bit integers as the answer can get
large.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long h, n;
    cin >> h >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    vector<long long> c(n);
    for (int i = 0; i < n; i++)
      cin >> c[i];

    for (int i = 0; i < n; i++)
      h -= p[i];

    if (h <= 0) {
      cout << 1 << endl;
      continue;
    }

    long long l = 0;
    long long r = 1e12;
    long long ans;

    while (l <= r) // O(log2(1e12)) = O(40)
    {
      long long mid = (l + r) >> 1;

      long long s = 0;

      for (int i = 0; i < n; i++) // O(n)
      {
        s += (mid / c[i]) * p[i];
        if (s >= h)
          break;
      }
      if (h - s <= 0) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }

    cout << ans + 1 << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1985/340109810

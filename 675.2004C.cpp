/*C. Splitting Items
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob have 𝑛
 items they'd like to split between them, so they decided to play a game. All
items have a cost, and the 𝑖 -th item costs 𝑎𝑖 . Players move in turns starting
from Alice.

In each turn, the player chooses one of the remaining items and takes it. The
game goes on until no items are left.

Let's say that 𝐴
 is the total cost of items taken by Alice and 𝐵
 is the total cost of Bob's items. The resulting score of the game then will be
equal to 𝐴−𝐵
.

Alice wants to maximize the score, while Bob wants to minimize it. Both Alice
and Bob will play optimally.

But the game will take place tomorrow, so today Bob can modify the costs a
little. He can increase the costs 𝑎𝑖 of several (possibly none or all) items by
an integer value (possibly, by the same value or by different values for each
item). However, the total increase must be less than or equal to 𝑘 . Otherwise,
Alice may suspect something. Note that Bob can't decrease costs, only increase.

What is the minimum possible score Bob can achieve?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤5000
) — the number of test cases. Then 𝑡
 cases follow.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤2⋅105
; 0≤𝑘≤109
) — the number of items and the maximum total increase Bob can make.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the initial costs of the items.

It's guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print a single integer — the minimum possible score 𝐴−𝐵
 after Bob increases the costs of several (possibly none or all) items.

Example
InputCopy
4
2 5
1 10
3 0
10 15 12
4 6
3 1 2 4
2 4
6 9
OutputCopy
4
13
0
0
Note
In the first test case, Bob can increase 𝑎1
 by 5
, making costs equal to [6,10]
. Tomorrow, Alice will take 10
 and Bob will take 6
. The total score will be equal to 10−6=4
, and it's the minimum possible.

In the second test case, Bob can't change costs. So the score will be equal to
(15+10)−12=13 , since Alice will take 15 , Bob will take 12 , and Alice — 10
.

In the third test case, Bob, for example, can increase 𝑎1
 by 1
, 𝑎2
 by 3
, and 𝑎3
 by 2
. The total change is equal to 1+3+2≤6
 and costs will be equal to [4,4,4,4]
. Obviously, the score will be equal to (4+4)−(4+4)=0
.

In the fourth test case, Bob can increase 𝑎1
 by 3
, making costs equal to [9,9]
. The score will be equal to 9−9=0
.
*/

/*Sort array descending.

Compute prefix sums.

Base game score = Alice’s picks − Bob’s picks.

Bob’s best move is to spend his k to raise some of the smallest items (so Alice
doesn’t get huge extra advantage).

This reduces to: answer = min over i (total_sum − prefix[i] − (prefix[i] + k)).
Which simplifies to a neat greedy formula.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
      cin >> a[i];

    sort(a.rbegin(), a.rend());

    ll A = 0, B = 0;
    for (ll i = 0; i < n; i++) {
      if (i % 2 == 1) { // Bob’s turn
        ll diff = a[i - 1] - a[i];
        diff = min(diff, k);
        k -= diff;
        B += a[i] + diff;
      } else { // Alice’s turn
        A += a[i];
      }
    }

    cout << (A - B) << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2004/338027265

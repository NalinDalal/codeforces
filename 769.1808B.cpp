/*B. Playing in a Casino
time limit per test2 seconds
memory limit per test256 megabytes

Galaxy Luck, a well-known casino in the entire solar system, introduces a new
card game.

In this game, there is a deck that consists of 𝑛
 cards. Each card has 𝑚
 numbers written on it. Each of the 𝑛
 players receives exactly one card from the deck.

Then all players play with each other in pairs, and each pair of players plays
exactly once. Thus, if there are, for example, four players in total, then six
games are played: the first against the second, the first against the third, the
first against the fourth, the second against the third, the second against the
fourth and the third against the fourth.

Each of these games determines the winner in some way, but the rules are quite
complicated, so we will not describe them here. All that matters is how many
chips are paid out to the winner. Let the first player's card have the numbers
𝑎1,𝑎2,…,𝑎𝑚 , and the second player's card — 𝑏1,𝑏2,…,𝑏𝑚 . Then the winner of the
game gets |𝑎1−𝑏1|+|𝑎2−𝑏2|+⋯+|𝑎𝑚−𝑏𝑚| chips from the total pot, where |𝑥| denotes
the absolute value of 𝑥
.

To determine the size of the total pot, it is necessary to calculate the
winners' total winnings for all games. Since there can be many cards in a deck
and many players, you have been assigned to write a program that does all the
necessary calculations.

Input
Each test consists of several test cases. The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛⋅𝑚≤3⋅105
) — the number of cards in the deck and the count of numbers on the one card.

Each of the following 𝑛
 lines of the test case set contains 𝑚
 integers 𝑐𝑖,𝑗
 (1≤𝑐𝑖,𝑗≤106
) — a description of the 𝑖
-th card.

It is guaranteed that the total 𝑛⋅𝑚
 in all tests does not exceed 3⋅105
.

Output
For each test case, print one number — the total amount of winnings from all
games.

Example
InputCopy
3
3 5
1 4 2 8 5
7 9 2 1 4
3 8 5 3 1
1 4
4 15 1 10
4 3
1 2 3
3 2 1
1 2 1
4 2 7
OutputCopy
50
0
31
Note
Consider the first test case.

In the game between the first and second player, the winner receives
|1−7|+|4−9|+|2−2|+|8−1|+|5−4|=19 chips.

In the game between the first and third player, the winner receives
|1−3|+|4−8|+|2−5|+|8−3|+|5−1|=18 in chips.

In the game between the second and third player, the winner receives
|7−3|+|9−8|+|2−5|+|1−3|+|4−1|=13 chips.

The total is 19+18+13=50
 chips.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> f(n, vector<ll>(m, 0));
    for (ll row = 0; row < n; row++) {
      for (ll col = 0; col < m; col++) {
        cin >> f[row][col];
      }
    }

    ll total = 0;
    for (ll col = 0; col < m; col++) {
      vector<ll> v(n);
      for (ll row = 0; row < n; row++) {
        v[row] = f[row][col];
      }
      sort(v.begin(), v.end());
      for (ll p = 0; p < n; p++) {
        total += (2 * p - (n - 1)) * v[p];
      }
    }

    cout << total << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1808/343494363

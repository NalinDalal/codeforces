/*C. How Does the Rook Move?
time limit per test2 seconds
memory limit per test256 megabytes
You are given an 𝑛×𝑛
 chessboard where you and the computer take turns alternatingly to place white
rooks & black rooks on the board respectively. While placing rooks, you have to
ensure that no two rooks attack each other. Two rooks attack each other if they
share the same row or column regardless of color.

A valid move is placing a rook on a position (𝑟
, 𝑐
) such that it doesn't attack any other rook.

You start first, and when you make a valid move in your turn, placing a white
rook at position (𝑟 , 𝑐
), the computer will mirror you and place a black rook at position (𝑐
, 𝑟
) in its turn. If 𝑟=𝑐
, then the computer can't mirror your move, and skips its turn.

You have already played 𝑘
 moves with the computer (the computer tries to mirror these moves too), and you
must continue playing the game until there are no valid moves remaining. How
many different final configurations are possible when you continue the game
after the 𝑘 moves? It is guaranteed that the 𝑘 moves and the implied computer
moves are valid. Since the answer may be large, print it modulo 109+7
.

Two configurations are considered different if there exists a coordinate (𝑟
, 𝑐
) which has a rook in one configuration, but not in the other or the color of
the rook on the coordinate is different.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤3⋅105
, 0≤𝑘≤𝑛
) — the size of the chessboard and the number of moves you have already played
respectively.

Each of the next 𝑘
 lines of the test case contains two integers 𝑟𝑖
 and 𝑐𝑖
, denoting the 𝑖
-th move you made.

It is guaranteed that the 𝑘
 moves and the implied computer moves are valid.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 3⋅105
.

Output
For each test case, output a single integer on a new line — the total number of
possible final configurations modulo 109+7
.

Example
InputCopy
3
4 1
1 2
8 1
7 6
1000 4
4 4
952 343
222 333
90 91
OutputCopy
3
331
671968183
Note
In the first test case, we have a 4×4
 grid and you've already played 1
 move. After you and the computer play a turn, we have a white rook at (1
, 2
), and a black rook at (2
, 1
). There are three possible configurations from this state —

You place a white rook at (3
, 4
) and the computer places a black rook at (4
, 3
) as a response.
You place a white rook at (4
, 3
) and the computer places a black rook at (3
, 4
) as a response.
You place a white rook at (3
, 3
) and then at (4
, 4
), or the other way around. They both result in the same configuration.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll solveDP(ll n, vector<ll> &dp) {
  if (n <= 1)
    return 1;
  if (dp[n] != -1)
    return dp[n];
  // recurrence: f(n) = f(n-1) + 2*(n-1)*f(n-2)
  dp[n] = (solveDP(n - 1, dp) % MOD +
           (2 * (n - 1) % MOD * solveDP(n - 2, dp) % MOD) % MOD) %
          MOD;
  return dp[n];
}

void solveOne() {
  ll n, k;
  cin >> n >> k;

  set<ll> used;
  for (ll i = 0; i < k; i++) {
    ll r, c;
    cin >> r >> c;
    used.insert(r);
    used.insert(c);
  }

  ll free = n - (ll)used.size();
  vector<ll> dp(free + 1, -1);

  cout << solveDP(free, dp) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solveOne();
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1957/338553732

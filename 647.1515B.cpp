/*B. Phoenix and Puzzle
time limit per test2 seconds
memory limit per test256 megabytes
Phoenix is playing with a new puzzle, which consists of 𝑛
 identical puzzle pieces. Each puzzle piece is a right isosceles triangle as
shown below.

A puzzle piece
The goal of the puzzle is to create a square using the 𝑛
 pieces. He is allowed to rotate and move the pieces around, but none of them
can overlap and all 𝑛 pieces must be used (of course, the square shouldn't
contain any holes as well). Can he do it?

Input
The input consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤109
) — the number of puzzle pieces.

Output
For each test case[48;56;204;1792;2856t, if Phoenix can create a square with
the 𝑛 puzzle pieces, print YES. Otherwise, print NO.

Example
InputCopy
3
2
4
6
OutputCopy
YES
YES
NO
Note
For 𝑛=2
, Phoenix can create a square like this:


For 𝑛=4
, Phoenix can create a square like this:


For 𝑛=6
, it is impossible for Phoenix to create a square.
*/

// given n isosceles traignles, return "YES" if possible to make a square using
// all of them, otherwise return "NO"

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  // Precompute perfect squares
  unordered_set<ll> squares;
  for (ll p = 1; p * p <= 1e10; ++p) { // large enough
    squares.insert(p * p);
  }

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    bool canMake = (n % 2 == 0 && squares.count(n / 2)) ||
                   (n % 4 == 0 && squares.count(n / 4));
    if (canMake)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1515/336458518

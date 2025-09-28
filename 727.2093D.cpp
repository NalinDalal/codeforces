/*D. Skibidi Table
time limit per test2 seconds
memory limit per test256 megabytes
Vadim loves filling square tables with integers. But today he came up with a way
to do it for fun! Let's take, for example, a table of size 2×2 , with rows
numbered from top to bottom and columns numbered from left to right. We place 1
 in the top left cell, 2
 in the bottom right, 3
 in the bottom left, and 4
 in the top right. That's all he needs for fun!

Fortunately for Vadim, he has a table of size 2𝑛×2𝑛
. He plans to fill it with integers from 1
 to 22𝑛
 in ascending order. To fill such a large table, Vadim will divide it into 4
 equal square tables, filling the top left one first, then the bottom right one,
followed by the bottom left one, and finally the top right one. Each smaller
table will be divided into even smaller ones as he fills them until he reaches
tables of size 2×2 , which he will fill in the order described above.

Now Vadim is eager to start filling the table, but he has 𝑞
 questions of two types:

what number will be in the cell at the 𝑥
-th row and 𝑦
-th column;
in which cell coordinates will the number 𝑑
 be located.
Help answer Vadim's questions.
Input
Each test consists of several sets of input data. The first line contains a
single integer 𝑡 (1≤𝑡≤10) — the number of sets of input data. The following
lines describe the input data sets.

In the first line of each data set, there is an integer 𝑛
, describing the size of the table (1≤𝑛≤30)
.

In the second line of each data set, there is an integer 𝑞
  — the number of questions (1≤𝑞≤20000)
.

In the following 𝑞
 lines of each data set, the questions are described in the following formats:

-> x y  — What number will be in the cell (1≤𝑥,𝑦≤2𝑛)
;
<- d  — In which cell coordinates will the number (1≤𝑑≤22𝑛)
 be located.
It is guaranteed that the sum of 𝑞
 over all test cases does not exceed 20000
.

Output
Output the answers to each question on a separate line.

Example
InputCopy
2
2
5
-> 4 3
<- 15
<- 4
-> 3 1
-> 1 3
1
8
-> 1 1
-> 1 2
-> 2 1
-> 2 2
<- 1
<- 2
<- 3
<- 4
OutputCopy
7
2 3
1 2
9
13
1
4
3
2
1 1
2 2
2 1
1 2
Note
This is how the filled table from the first example looks:
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Find value at coordinates (r, c)
ll findValue(ll r, ll c, ll x, ll y, ll sz, ll value) {
  if (sz == 1) {
    return value;
  }
  ll subTotal = (sz * sz) / 4;
  ll half = sz / 2;
  int dx[] = {0, half, half, 0};
  int dy[] = {0, half, 0, half};

  for (int i = 0; i < 4; i++) {
    if (r >= x + dx[i] && r < x + dx[i] + half && c >= y + dy[i] &&
        c < y + dy[i] + half) {
      ll newValue = value + subTotal * i;
      return findValue(r, c, x + dx[i], y + dy[i], half, newValue);
    }
  }
  return -1; // unreachable
}

// Find coordinates from value d
pair<ll, ll> findCoords(ll d, ll x, ll y, ll sz, ll value) {
  if (sz == 1) {
    return {x, y};
  }
  ll subTotal = (sz * sz) / 4;
  ll half = sz / 2;

  for (int i = 0; i < 4; i++) {
    if (d >= value + subTotal * i && d < value + subTotal * (i + 1)) {
      ll newValue = value + subTotal * i;
      if (i == 0)
        return findCoords(d, x, y, half, newValue);
      if (i == 1)
        return findCoords(d, x + half, y + half, half, newValue);
      if (i == 2)
        return findCoords(d, x + half, y, half, newValue);
      if (i == 3)
        return findCoords(d, x, y + half, half, newValue);
    }
  }
  return {-1, -1}; // unreachable
}

void solve() {
  int n, q;
  cin >> n >> q;

  while (q--) {
    string type;
    cin >> type;

    if (type == "->") {
      ll r, c;
      cin >> r >> c;
      cout << findValue(r, c, 1, 1, 1LL << n, 1) << "\n";
    } else {
      ll d;
      cin >> d;
      auto [x, y] = findCoords(d, 1, 1, 1LL << n, 1);
      cout << x << " " << y << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
// sub: https://codeforces.com/problemset/submission/2093/340914897

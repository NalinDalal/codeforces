/*B. Circle Game
time limit per test1 second
memory limit per test256 megabytes
Mike and Joe are playing a game with some stones. Specifically, they have 𝑛
 piles of stones of sizes 𝑎1,𝑎2,…,𝑎𝑛
. These piles are arranged in a circle.

The game goes as follows. Players take turns removing some positive number of
stones from a pile in clockwise order starting from pile 1 . Formally, if a
player removed stones from pile 𝑖 on a turn, the other player removes stones
from pile ((𝑖mod𝑛)+1) on the next turn.

If a player cannot remove any stones on their turn (because the pile is empty),
they lose. Mike goes first.

If Mike and Joe play optimally, who will win?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). Description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
)  — the number of piles.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
)  — the size of the piles.

Output
For each test case print the winner of the game, either "Mike" or "Joe" on its
own line (without quotes).

Example
InputCopy
2
1
37
2
100 100
OutputCopy
Mike
Joe
Note
In the first test case, Mike just takes all 37
 stones on his first turn.

In the second test case, Joe can just copy Mike's moves every time. Since Mike
went first, he will hit 0 on the first pile one move before Joe does so on the
second pile.



*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    vector<long> a(n);
    for (long i = 0; i < n; i++)
      cin >> a[i];

    if (n % 2) {
      cout << "Mike\n";
      continue;
    }

    long idx = 0;
    for (long i = 0; i < n; i++) {
      if (a[i] < a[idx])
        idx = i;
    }

    cout << (idx % 2 ? "Mike\n" : "Joe\n");
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1695/345437890

/*E. Exchange
time limit per test2 seconds
memory limit per test512 megabytes
Monocarp is playing a MMORPG. There are two commonly used types of currency in
this MMORPG — gold coins and silver coins. Monocarp wants to buy a new weapon
for his character, and that weapon costs 𝑛 silver coins. Unfortunately, right
now, Monocarp has no coins at all.

Monocarp can earn gold coins by completing quests in the game. Each quest yields
exactly one gold coin. Monocarp can also exchange coins via the in-game trading
system. Monocarp has spent days analyzing the in-game economy; he came to the
following conclusion: it is possible to sell one gold coin for 𝑎 silver coins
(i. e. Monocarp can lose one gold coin to gain 𝑎 silver coins), or buy one gold
coin for 𝑏 silver coins (i. e. Monocarp can lose 𝑏 silver coins to gain one gold
coin).

Now Monocarp wants to calculate the minimum number of quests that he has to
complete in order to have at least 𝑛 silver coins after some abuse of the
in-game economy. Note that Monocarp can perform exchanges of both types (selling
and buying gold coins for silver coins) any number of times.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of one line containing three integers 𝑛
, 𝑎
 and 𝑏
 (1≤𝑛≤107
; 1≤𝑎,𝑏≤50
).

Output
For each test case, print one integer — the minimum possible number of quests
Monocarp has to complete.

Example
InputCopy
4
100 25 30
9999997 25 50
52 50 48
49 50 1
OutputCopy
4
400000
1
1
Note
In the first test case of the example, Monocarp should complete 4
 quests, and then sell 4
 gold coins for 100
 silver coins.

In the second test case, Monocarp should complete 400000
 quests, and then sell 400000
 gold coins for 10
 million silver coins.

In the third test case, Monocarp should complete 1
 quest, sell the gold coin for 50
 silver coins, buy a gold coin for 48
 silver coins, and then sell it again for 50
 coins. So, he will have 52
 silver coins.

In the fourth test case, Monocarp should complete 1
 quest and then sell the gold coin he has obtained for 50
 silver coins.



*/

// sell 1 gold for a sliver
// buy 1 gold for b silver
// min quest to get n silver coins
// weapon costs n silver coins

#include <iostream>
using namespace std;
int sol(int n, int a, int b) { return a <= b ? ((n + a - 1) / a) : 1; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    cout << sol(n, a, b) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1765/330071442

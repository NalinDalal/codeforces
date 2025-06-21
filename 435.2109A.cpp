/*A. It's Time To Duel
time limit per test1 second
memory limit per test256 megabytes
Something you may not know about Mouf is that he is a big fan of the Yu-Gi-Oh!
card game. He loves to duel with anyone he meets. To gather all fans who love to
play as well, he decided to organize a big Yu-Gi-Oh! tournament and invited 𝑛
 players.

Mouf arranged the 𝑛
 players in a line, numbered from 1
 to 𝑛
. They then held 𝑛−1
 consecutive duels: for each 𝑖
 from 1
 to 𝑛−1
, player 𝑖
 faced player 𝑖+1
, producing one winner and one loser per match. Afterward, each player reports a
value 𝑎𝑖(0≤𝑎𝑖≤1)
:

0
 indicating they won no duels;
1
 indicating they won at least one duel.
Since some may lie about their results (e.g., reporting a 1
 instead of a 0
, or vice versa) to influence prize outcomes, Mouf will cancel the tournament if
he can prove any report to be false.

Given the array 𝑎
, determine whether at least one player must be lying.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤100
) — the number of players in the tournament.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤1
) — denoting the report of the 𝑖
-th player.

Output
For each test case, print "YES" (without quotes) if there is at least one liar
among the players, and "NO" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
3
0 1 0
2
0 0
2
1 1
4
0 1 1 1
4
1 0 0 1
7
0 1 0 1 0 1 0
OutputCopy
NO
YES
YES
NO
YES
NO
Note
In the first test case, it is consistent if player 2
 defeats both players 1
 and 3
, so nobody's report is necessarily false.

In the second test case, in the only match between players 1
 and 2
, one must win — but both claimed zero wins, so someone must be lying.

In the third test case, the tournament consists of exactly one duel between
players 1 and 2 — but it's impossible for both to win, concluding that at least
one report is false.

In the fourth test case, a possible scenario is that player 2
 won against player 1
, then 3
 won against 2
, and then 4
 won against 3
. All reports align, so there is no evidence that someone lied.



*/

#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    bool liar = false;
    long cnt = 0;
    int prev = 1;

    for (long p = 0; p < n; ++p) {
      int x;
      std::cin >> x;

      if (prev == 0 && x == 0) {
        liar = true;
      }

      prev = x;
      cnt += x;
    }

    if (cnt >= n) {
      liar = true;
    }

    std::cout << (liar ? "YES" : "NO") << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2109/325396400

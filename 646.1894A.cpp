/*A. Secret Sport
time limit per test3 seconds
memory limit per test512 megabytes
Let's consider a game in which two players, A and B, participate. This game is
characterized by two positive integers, 𝑋 and 𝑌
.

The game consists of sets, and each set consists of plays. In each play, exactly
one of the players, either A or B, wins. A set ends exactly when one of the
players reaches 𝑋 wins in the plays of that set. This player is declared the
winner of the set. The players play sets until one of them reaches 𝑌 wins in the
sets. After that, the game ends, and this player is declared the winner of the
entire game.

You have just watched a game but didn't notice who was declared the winner. You
remember that during the game, 𝑛 plays were played, and you know which player
won each play. However, you do not know the values of 𝑋 and 𝑌 . Based on the
available information, determine who won the entire game — A or B. If there is
not enough information to determine the winner, you should also report it.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤104)
 - the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤20)
 - the number of plays played during the game.

The second line of each test case contains a string 𝑠
 of length 𝑛
, consisting of characters 𝙰
 and 𝙱
. If 𝑠𝑖=𝙰
, it means that player A won the 𝑖
-th play. If 𝑠𝑖=𝙱
, it means that player B won the 𝑖
-th play.

It is guaranteed that the given sequence of plays corresponds to at least one
valid game scenario, for some values of 𝑋 and 𝑌
.

Output
For each test case, output:

𝙰
 — if player A is guaranteed to be the winner of the game.
𝙱
 — if player B is guaranteed to be the winner of the game.
?
 — if it is impossible to determine the winner of the game.
Example
InputCopy
7
5
ABBAA
3
BBB
7
BBAAABA
20
AAAAAAAABBBAABBBBBAB
1
A
13
AAAABABBABBAB
7
BBBAAAA
OutputCopy
A
B
A
B
A
B
A
Note
In the first test case, the game could have been played with parameters 𝑋=3
, 𝑌=1
. The game consisted of 1
 set, in which player A won, as they won the first 3
 plays. In this scenario, player A is the winner. The game could also have been
played with parameters 𝑋=1 , 𝑌=3 . It can be shown that there are no such 𝑋 and
𝑌 values for which player B would be the winner.

In the second test case, player B won all the plays. It can be easily shown that
in this case, player B is guaranteed to be the winner of the game.

In the fourth test case, the game could have been played with parameters 𝑋=3
, 𝑌=3
:

In the first set, 3
 plays were played: AAA. Player A is declared the winner of the set.
In the second set, 3
 plays were played: AAA. Player A is declared the winner of the set.
In the third set, 5
 plays were played: AABBB. Player B is declared the winner of the set.
In the fourth set, 5
 plays were played: AABBB. Player B is declared the winner of the set.
In the fifth set, 4
 plays were played: BBAB. Player B is declared the winner of the set.
In total, player B was the first player to win 3
 sets. They are declared the winner of the game.
*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    bool a(0), b(0);
    for (long x = 1; x <= n; x++) {
      bool valid(true);
      long wa(0), wb(0), sa(0), sb(0);
      char last = 'N';
      for (long p = 0; p < n; p++) {
        if (s[p] == 'A') {
          ++wa;
          if (wa == x) {
            ++sa;
            wa = 0;
            wb = 0;
            last = 'A';
          }
        } else if (s[p] == 'B') {
          ++wb;
          if (wb == x) {
            ++sb;
            wa = 0;
            wb = 0;
            last = 'B';
          }
        }
      }

      if (wa > 0 || wb > 0) {
        valid = false;
      }
      if (sb == sa) {
        valid = false;
      }
      if (sa > sb && last != 'A') {
        valid = false;
      }
      if (sb > sa && last != 'B') {
        valid = false;
      }

      if (valid) {
        if (sa > sb) {
          a = true;
        } else {
          b = true;
        }
      }
    }

    char res('?');
    if (a && !b) {
      res = 'A';
    } else if (!a && b) {
      res = 'B';
    }
    std::cout << res << std::endl;
  }
}

// sub: https://codeforces.com/problemset/submission/1894/336458087

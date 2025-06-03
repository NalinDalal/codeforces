/* B. Card Game
time limit per test2 seconds
memory limit per test256 megabytes
Suneet and Slavic play a card game. The rules of the game are as follows:

Each card has an integer value between 1
 and 10
.
Each player receives 2
 cards which are face-down (so a player doesn't know their cards).
The game is turn-based and consists exactly of two turns. In a round, both
players pick a random unflipped card and flip it. The player who flipped a card
with a strictly greater number wins the round. In case of equality, no one wins
the round. A player wins a game if he wins the most number of rounds (i.e.
strictly greater than the other player). In case of equality, no one wins the
game. Since Suneet and Slavic aren't best friends, you need to calculate the
number of ways the game could happen that Suneet would end up as the winner.

For a better understanding, please check the notes section.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first and only line of each test case contains 4
 integers 𝑎1
, 𝑎2
, 𝑏1
, 𝑏2
 (1≤𝑎1,𝑎2,𝑏1,𝑏2≤10
) where 𝑎1
 and 𝑎2
 represent the cards Suneet has, and 𝑏1
 and 𝑏2
 represent the cards Slavic has, respectively.

Output
For each test case, output a single integer — the number of games Suneet would
win considering all possible games.

Example
InputCopy
5
3 8 2 6
1 1 1 1
10 10 2 2
1 1 10 10
3 8 7 2
OutputCopy
2
0
4
0
2
Note
Consider the first test case when Slavic starts with the cards that have the
values 2 and 6 , and Suneet starts with cards that have the values 3 and 8 . The
game could happen in 4 different ways:

Suneet flips 3
 and Slavic flips 2
. Suneet wins the first round. Then, Suneet flips 8
 and Slavic flips 6
. Suneet wins the second round as well. Since Suneet won 2
 rounds, he wins the game.

Suneet flips 3
 and Slavic flips 6
. Slavic wins the first round. Then, Suneet flips 8
 and Slavic flips 2
. Suneet wins the second round. Nobody wins since both players won an equal
amount of rounds.

Suneet flips 8
 and Slavic flips 6
. Suneet wins the first round. Then, Suneet flips 3
 and Slavic flips 2
. Suneet wins the second round as well. Since Suneet won 2
 rounds, he wins the game.

Suneet flips 8
 and Slavic flips 2
. Suneet wins the first round. Then, Suneet flips 3
 and Slavic flips 6
. Slavic wins the round. Nobody wins since both players won an equal amount of
rounds.

*/
#include <iostream>
using namespace std;

int f(int x, int y) { return (x > y) - (x < y); }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 2 * ((f(a, c) + f(b, d)) > 0) + 2 * ((f(a, d) + f(b, c)) > 0);
    cout << res << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1999/322611253

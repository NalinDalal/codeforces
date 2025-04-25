/* A. Nene's Game
time limit per test1 second
memory limit per test256 megabytes
Nene invented a new game based on an increasing sequence of integers 𝑎1,𝑎2,…,𝑎𝑘
.

In this game, initially 𝑛
 players are lined up in a row. In each of the rounds of this game, the
following happens:

Nene finds the 𝑎1
-th, 𝑎2
-th, …
, 𝑎𝑘
-th players in a row. They are kicked out of the game simultaneously. If the 𝑖
-th player in a row should be kicked out, but there are fewer than 𝑖
 players in a row, they are skipped.
Once no one is kicked out of the game in some round, all the players that are
still in the game are declared as winners.

For example, consider the game with 𝑎=[3,5]
 and 𝑛=5
 players. Let the players be named player A, player B, …
, player E in the order they are lined up initially. Then,

Before the first round, players are lined up as ABCDE. Nene finds the 3
-rd and the 5
-th players in a row. These are players C and E. They are kicked out in the
first round. Now players are lined up as ABD. Nene finds the 3 -rd and the 5 -th
players in a row. The 3 -rd player is player D and there is no 5 -th player in a
row. Thus, only player D is kicked out in the second round. In the third round,
no one is kicked out of the game, so the game ends after this round. Players A
and B are declared as the winners. Nene has not yet decided how many people
would join the game initially. Nene gave you 𝑞 integers 𝑛1,𝑛2,…,𝑛𝑞 and you
should answer the following question for each 1≤𝑖≤𝑞 independently:

How many people would be declared as winners if there are 𝑛𝑖
 players in the game initially?
Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤250
). The description of test cases follows.

The first line case contains two integers 𝑘
 and 𝑞
 (1≤𝑘,𝑞≤100
) — the length of the sequence 𝑎
 and the number of values 𝑛𝑖
 you should solve this problem for.

The second line contains 𝑘
 integers 𝑎1,𝑎2,…,𝑎𝑘
 (1≤𝑎1<𝑎2<…<𝑎𝑘≤100
) — the sequence 𝑎
.

The third line contains 𝑞
 integers 𝑛1,𝑛2,…,𝑛𝑞
 (1≤𝑛𝑖≤100
).

Output
For each test case, output 𝑞
 integers: the 𝑖
-th (1≤𝑖≤𝑞
) of them should be the number of players declared as winners if initially 𝑛𝑖
 players join the game.

Example
InputCopy
6
2 1
3 5
5
5 3
2 4 6 7 9
1 3 5
5 4
3 4 5 6 7
1 2 3 4
2 3
69 96
1 10 100
1 1
100
50
3 3
10 20 30
1 10 100
OutputCopy
2
1 1 1
1 2 2 2
1 10 68
50
1 9 9
Note
The first test case was explained in the statement.

In the second test case, when 𝑛=1
, the only player stays in the game in the first round. After that, the game
ends and the only player is declared as a winner.


*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    vector<int> n(q);
    for (int i = 0; i < k; i++)
      cin >> a[i];
    for (int i = 0; i < q; i++)
      cin >> n[i];

    // o/p q int , say vector of size q
    // vec[i]=num of player who are winner if initially n[i] playes join the
    // game
    int a0 = a[0] - 1; // Adjust as per the original logic
    for (int i = 0; i < q; i++) {
      cout << min(a0, n[i]) << " ";
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1956/317121070

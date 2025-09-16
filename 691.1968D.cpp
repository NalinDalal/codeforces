/*D. Permutation Game
time limit per test2 seconds
memory limit per test256 megabytes
Bodya and Sasha found a permutation 𝑝1,…,𝑝𝑛
 and an array 𝑎1,…,𝑎𝑛
. They decided to play a well-known "Permutation game".

A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

Both of them chose a starting position in the permutation.

The game lasts 𝑘
 turns. The players make moves simultaneously. On each turn, two things happen
to each player:

If the current position of the player is 𝑥
, his score increases by 𝑎𝑥
.
Then the player either stays at his current position 𝑥
 or moves from 𝑥
 to 𝑝𝑥
.
The winner of the game is the player with the higher score after exactly 𝑘
 turns.
Knowing Bodya's starting position 𝑃𝐵
 and Sasha's starting position 𝑃𝑆
, determine who wins the game if both players are trying to win.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The first line of each testcase contains integers 𝑛
, 𝑘
, 𝑃𝐵
, 𝑃𝑆
 (1≤𝑃𝐵,𝑃𝑆≤𝑛≤2⋅105
, 1≤𝑘≤109
) — length of the permutation, duration of the game, starting positions
respectively.

The next line contains 𝑛
 integers 𝑝1,…,𝑝𝑛
 (1≤𝑝𝑖≤𝑛
) — elements of the permutation 𝑝
.

The next line contains 𝑛
 integers 𝑎1,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — elements of array 𝑎
.

It is guaranteed that the sum of values of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each testcase output:

"Bodya" if Bodya wins the game.
"Sasha" if Sasha wins the game.
"Draw" if the players have the same score.
Example
InputCopy
10
4 2 3 2
4 1 2 3
7 2 5 6
10 8 2 10
3 1 4 5 2 7 8 10 6 9
5 10 5 1 3 7 10 15 4 3
2 1000000000 1 2
1 2
4 4
8 10 4 1
5 1 4 3 2 8 6 7
1 1 2 1 2 100 101 102
5 1 2 5
1 2 4 5 3
4 6 9 4 2
4 2 3 1
4 1 3 2
6 8 5 3
6 9 5 4
6 1 3 5 2 4
6 9 8 9 5 10
4 8 4 2
2 3 4 1
5 2 8 7
4 2 3 1
4 1 3 2
6 8 5 3
2 1000000000 1 2
1 2
1000000000 2
OutputCopy
Bodya
Sasha
Draw
Draw
Bodya
Sasha
Sasha
Sasha
Sasha
Bodya
Note
Below you can find the explanation for the first testcase, where the game
consists of 𝑘=2 turns.

Turn	Bodya's position	Bodya's score	Bodya's move	Sasha's position
Sasha's score	Sasha's move first	3 0+𝑎3=0+5=5 stays on the same position
2 0+𝑎2=0+2=2 moves to 𝑝2=1 second	3 5+𝑎3=5+5=10 stays on the same position
1 2+𝑎1=2+7=9 stays on the same position final results	3 10
1
9
As we may see, Bodya's score is greater, so he wins the game. It can be shown
that Bodya always can win this game.
*/

// permuataion: length n, contain from 1 to n
// while(k--){
//   if(currPos==x)score+=arr[x]
//   else if(currPos!=x)stay on currPos
//   else move from x to p[x]
// }
// winner is highest scorer after k turns

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    ll n, k, pb, ps;
    cin >> n >> k >> pb >> ps;

    vector<ll> m(n + 1);
    for (ll p = 1; p <= n; p++)
      cin >> m[p];

    vector<ll> a(n + 1);
    for (ll p = 1; p <= n; p++)
      cin >> a[p];

    // Bodya
    ll idxb = pb, csb = 0, kb = k, scoreb = 0;
    do {
      scoreb = max(scoreb, csb + kb * a[idxb]);
      csb += a[idxb];
      --kb;
      idxb = m[idxb];
    } while (kb && idxb != pb);

    // Sasha
    ll idxs = ps, css = 0, ks = k, scores = 0;
    do {
      scores = max(scores, css + ks * a[idxs]);
      css += a[idxs];
      --ks;
      idxs = m[idxs];
    } while (ks && idxs != ps);

    if (scoreb == scores) {
      cout << "Draw\n";
    } else {
      cout << (scoreb > scores ? "Bodya\n" : "Sasha\n");
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1968/338852386

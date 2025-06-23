/* A. Gellyfish and Tricolor Pansy
time limit per test1 second
memory limit per test256 megabytes
Gellyfish and Flower are playing a game called "Duel".

Gellyfish has 𝑎
 HP, while Flower has 𝑏
 HP.

Each of them has a knight. Gellyfish's knight has 𝑐
 HP, while Flower's knight has 𝑑
 HP.

They will play a game in rounds until one of the players wins. For 𝑘=1,2,…
 in this order, they will perform the following actions:

If 𝑘
 is odd and Gellyfish's knight is alive:
Gellyfish's knight can attack Flower and reduce 𝑏
 by 1
. If 𝑏≤0
, Gellyfish wins. Or,
Gellyfish's knight can attack Flower's knight and reduce 𝑑
 by 1
. If 𝑑≤0
, Flower's knight dies.
If 𝑘
 is even and Flower's knight is alive:
Flower's knight can attack Gellyfish and reduce 𝑎
 by 1
. If 𝑎≤0
, Flower wins. Or,
Flower's knight can attack Gellyfish's knight and reduce 𝑐
 by 1
. If 𝑐≤0
, Gellyfish's knight dies.
As one of the smartest people in the world, you want to tell them who will win
before the game. Assume both players play optimally.

It can be proven that the game will never end in a draw. That is, one player has
a strategy to end the game in a finite number of moves.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first and only line of each test case contains four integers 𝑎
, 𝑏
, 𝑐
, 𝑑
 (1≤𝑎,𝑏,𝑐,𝑑≤109
) — the HP of Gellyfish, the HP of Flower, the HP of Gellyfish's knight, and the
HP of Flower's knight, respectively.

Output
For each test case, if Flower will win, output "Flower", otherwise output
"Gellyfish".

Example
InputCopy
5
1 2 3 4
100 999 1 1
10 20 10 30
12 14 13 11
998 244 353 107
OutputCopy
Flower
Gellyfish
Flower
Gellyfish
Gellyfish
Note
In the first test case, Gellyfish has only 1
 HP. Therefore, no matter what Gellyfish does in the first round, Flower's
knight will attack Gellyfish in the second round, allowing Flower to win.

In the second test case, Flower's knight has only 1
 HP. Gellyfish will attack Flower's knight in the first round. Then Flower's
knight will no longer be able to attack, allowing Gellyfish to win.


*/
// gellyfish-a hp, gellyfish knioght-c hp
// flower-b hp, flower knight-d hp
// if(k%2){
// c can attack b-> b=b-1{if b<0 Gellyfish wins}
// or
// c can attack d-> d=d-1{if d<0, knight dies}
// }
// else if(k%2==0 && d>0){
// a=a-1(if a<=0, flower wins)
// or
// c=c-1(if c<=0, knight dies)
// }
// output "FLower" if flower wins, else "Gellyfish"
/* Use unordered_map or fixed-size 5D bool array (if size is small).

But better: use bitset for performance if fixed range.

3. BFS instead of DFS (best for shortest outcome)
However, here we care about guaranteed win, not shortest path. So stick to DFS,
but prune aggressively.

*/

#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long a, b, c, d;
    scanf("%ld %ld %ld %ld", &a, &b, &c, &d);
    long x = (a < c ? a : c);
    long y = (b < d ? b : d);
    puts(x >= y ? "Gellyfish" : "Flower");
  }
}
// sub: https://codeforces.com/problemset/submission/2116/325830678

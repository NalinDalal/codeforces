/*B. Apples in Boxes
time limit per test1 second
memory limit per test256 megabytes
Tom and Jerry found some apples in the basement. They decided to play a game to
get some apples.

There are 𝑛
 boxes, and the 𝑖
-th box has 𝑎𝑖
 apples inside. Tom and Jerry take turns picking up apples. Tom goes first. On
their turn, they have to do the following:

Choose a box 𝑖
 (1≤𝑖≤𝑛
) with a positive number of apples, i.e. 𝑎𝑖>0
, and pick 1
 apple from this box. Note that this reduces 𝑎𝑖
 by 1
.
If no valid box exists, the current player loses.
If after the move, max(𝑎1,𝑎2,…,𝑎𝑛)−min(𝑎1,𝑎2,…,𝑎𝑛)>𝑘
 holds, then the current player (who made the last move) also loses.
If both players play optimally, predict the winner of the game.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛,𝑘
 (2≤𝑛≤105,1≤𝑘≤109
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, print "Tom" (without quotes) if Tom will win, or "Jerry"
(without quotes) otherwise.

Example
InputCopy
3
3 1
2 1 2
3 1
1 1 3
2 1
1 4
OutputCopy
Tom
Tom
Jerry
Note
Note that neither player is necessarily playing an optimal strategy in the
following games, just to give you an idea of how the game is going.

In the first test case of the example, one possible situation is shown as
follows.

Tom takes an apple from the first box. The array 𝑎
 becomes [1,1,2]
. Tom does not lose because max(1,1,2)−min(1,1,2)=1≤𝑘
.
Jerry takes an apple from the first box as well. The array 𝑎
 becomes [0,1,2]
. Jerry loses because max(0,1,2)−min(0,1,2)=2>𝑘
.


*/

/*start with tom
1 turn:
choose an i, select a[i]{a[i]>0}
a[i]--;
if(a[i]<=0) player loses
if(after move, max(a[1],a[2]...,a[n])-min(a[1],a[2]...a[n])>k)) current player
loses

a/f decrement
if(a[i]<=0) player loses
else if(max-min>=k)player losses


both play optimally

mxa = max element

mna = min element

cntmx = number of times max appears

s = parity of sum

if(mxa>mna+k+1)JErry
else if(mxa == mna + k + 1 && cntmx > 1)JERRY
else if(sum%2)TOM
else JERRY

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long n, k;
    cin >> n >> k;

    long mna = 1e9 + 7, mxa = 0, cntmx = 0;
    int s = 0; // parity of sum

    for (int i = 0; i < n; i++) {
      long x;
      cin >> x;
      s = (s + x) % 2;
      if (x > mxa) {
        mxa = x;
        cntmx = 1;
      } else if (x == mxa) {
        ++cntmx;
      }
      mna = min(mna, x);
    }

    if ((mxa > mna + k + 1) || (mxa == mna + k + 1 && cntmx > 1)) {
      cout << "Jerry\n";
    } else {
      cout << (s ? "Tom\n" : "Jerry\n");
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2107/339323529

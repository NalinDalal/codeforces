/*A. Maximise The Score
time limit per test1 second
memory limit per test256 megabytes
There are 2𝑛
 positive integers written on a whiteboard. Being bored, you decided to play a
one-player game with the numbers on the whiteboard.

You start with a score of 0
. You will increase your score by performing the following move exactly 𝑛
 times:

Choose two integers 𝑥
 and 𝑦
 that are written on the whiteboard.
Add min(𝑥,𝑦)
 to your score.
Erase 𝑥
 and 𝑦
 from the whiteboard.
Note that after performing the move 𝑛
 times, there will be no more integers written on the whiteboard.

Find the maximum final score you can achieve if you optimally perform the 𝑛
 moves.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤5000 ) — the number of test cases. The description of the test cases
follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
) — the number of integers written on the whiteboard is 2𝑛
.

The second line of each test case contains 2𝑛
 integers 𝑎1,𝑎2,…,𝑎2𝑛
 (1≤𝑎𝑖≤107
) — the numbers written on the whiteboard.

Output
For each test case, output the maximum final score that you can achieve.

Example
InputCopy
3
1
2 3
2
1 1 2 1
3
1 1 1 1 1 1
OutputCopy
2
2
3
Note
In the first test case, you can only make one move. You select 𝑥=2
 and 𝑦=3
, and your score will be min(𝑥,𝑦)=2
.

In the second test case, the following is a sequence of moves that achieves a
final score of 2
:

In the first move, select 𝑥=1
 and 𝑦=1
. Then, add min(𝑥,𝑦)=1
 to the score. After erasing 𝑥
 and 𝑦
, the integers left on the whiteboard are 1
 and 2
.
In the second move, select 𝑥=1
 and 𝑦=2
. Then, add min(𝑥,𝑦)=1
 to the score. After removing 𝑥
 and 𝑦
, no more integers will be left on the whiteboard.
It can be proved that it is not possible to get a score greater than 2
.
In the third test case, you will perform the move thrice, adding 1
 to the score each time.



*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i)
      cin >> a[i];
    sort(a.begin(), a.end());

    long long score = 0;
    for (int i = 0; i < 2 * n; i += 2) {
      score += a[i];
    }
    cout << score << '\n';
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1930/332104922

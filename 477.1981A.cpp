/*A. Turtle and Piggy Are Playing a Game
time limit per test1 second
memory limit per test256 megabytes
Turtle and Piggy are playing a number game.

First, Turtle will choose an integer 𝑥
, such that 𝑙≤𝑥≤𝑟
, where 𝑙,𝑟
 are given. It's also guaranteed that 2𝑙≤𝑟
.

Then, Piggy will keep doing the following operation until 𝑥
 becomes 1
:

Choose an integer 𝑝
 such that 𝑝≥2
 and 𝑝∣𝑥
 (i.e. 𝑥
 is a multiple of 𝑝
).
Set 𝑥
 to 𝑥𝑝
, and the score will increase by 1
.
The score is initially 0
. Both Turtle and Piggy want to maximize the score. Please help them to
calculate the maximum score.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑙,𝑟
 (1≤𝑙≤𝑟≤109,2𝑙≤𝑟
) — The range where Turtle can choose the integer from.

Output
For each test case, output a single integer — the maximum score.

Example
InputCopy
5
2 4
3 6
2 15
6 22
114514 1919810
OutputCopy
2
2
3
4
20
Note
In the first test case, Turtle can choose an integer 𝑥
, such that 2≤𝑥≤4
. He can choose 𝑥=4
. Then Piggy can choose 𝑝=2
 for 2
 times. After that, 𝑥
 will become 1
, and the score will be 2
, which is maximized.

In the second test case, Turtle can choose an integer 3≤𝑥≤6
. He can choose 𝑥=6
. Then Piggy can choose 𝑝=2
, then choose 𝑝=3
. After that, 𝑥
 will become 1
, and the score will be 2
, which is maximum.

In the third test case, Turtle can choose 𝑥=12
.

In the fourth test case, Turtle can choose 𝑥=16
.
*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long l, r;
    cin >> l >> r;
    long cnt = 0;
    for (long p = 1; 2 * p <= r; p *= 2, ++cnt)
      ;
    cout << cnt << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1981/327791290

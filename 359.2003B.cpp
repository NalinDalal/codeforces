/* B. Turtle and Piggy Are Playing a Game 2
time limit per test1 second
memory limit per test256 megabytes
Turtle and Piggy are playing a game on a sequence. They are given a sequence
𝑎1,𝑎2,…,𝑎𝑛 , and Turtle goes first. Turtle and Piggy alternate in turns (so,
Turtle does the first turn, Piggy does the second, Turtle does the third, etc.).

The game goes as follows:

Let the current length of the sequence be 𝑚
. If 𝑚=1
, the game ends.
If the game does not end and it's Turtle's turn, then Turtle must choose an
integer 𝑖 such that 1≤𝑖≤𝑚−1 , set 𝑎𝑖 to max(𝑎𝑖,𝑎𝑖+1) , and remove 𝑎𝑖+1
.
If the game does not end and it's Piggy's turn, then Piggy must choose an
integer 𝑖 such that 1≤𝑖≤𝑚−1 , set 𝑎𝑖 to min(𝑎𝑖,𝑎𝑖+1) , and remove 𝑎𝑖+1
.
Turtle wants to maximize the value of 𝑎1
 in the end, while Piggy wants to minimize the value of 𝑎1
 in the end. Find the value of 𝑎1
 in the end if both players play optimally.

You can refer to notes for further clarification.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤105
) — the length of the sequence.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤105
) — the elements of the sequence 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output a single integer — the value of 𝑎1
 in the end if both players play optimally.

Example
InputCopy
5
2
1 2
3
1 1 2
3
1 2 3
5
3 1 2 2 3
10
10 2 5 2 7 9 2 5 10 7
OutputCopy
2
1
2
2
7
Note
In the first test case, initially 𝑎=[1,2]
. Turtle can only choose 𝑖=1
. Then he will set 𝑎1
 to max(𝑎1,𝑎2)=2
 and remove 𝑎2
. The sequence 𝑎
 becomes [2]
. Then the length of the sequence becomes 1
, and the game will end. The value of 𝑎1
 is 2
, so you should output 2
.

In the second test case, one of the possible game processes is as follows:

Initially 𝑎=[1,1,2]
.
Turtle can choose 𝑖=2
. Then he will set 𝑎2
 to max(𝑎2,𝑎3)=2
 and remove 𝑎3
. The sequence 𝑎
 will become [1,2]
.
Piggy can choose 𝑖=1
. Then he will set 𝑎1
 to min(𝑎1,𝑎2)=1
 and remove 𝑎2
. The sequence 𝑎
 will become [1]
.
The length of the sequence becomes 1
, so the game will end. The value of 𝑎1
 will be 1
 in the end.
In the fourth test case, one of the possible game processes is as follows:

Initially 𝑎=[3,1,2,2,3]
.
Turtle can choose 𝑖=4
. Then he will set 𝑎4
 to max(𝑎4,𝑎5)=3
 and remove 𝑎5
. The sequence 𝑎
 will become [3,1,2,3]
.
Piggy can choose 𝑖=3
. Then he will set 𝑎3
 to min(𝑎3,𝑎4)=2
 and remove 𝑎4
. The sequence 𝑎
 will become [3,1,2]
.
Turtle can choose 𝑖=2
. Then he will set 𝑎2
 to max(𝑎2,𝑎3)=2
 and remove 𝑎3
. The sequence 𝑎
 will become [3,2]
.
Piggy can choose 𝑖=1
. Then he will set 𝑎1
 to min(𝑎1,𝑎2)=2
 and remove 𝑎2
. The sequence 𝑎
 will become [2]
.
The length of the sequence becomes 1
, so the game will end. The value of 𝑎1
 will be 2
 in the end.

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    sort(v.begin(), v.end());
    cout << v[n / 2] << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2003/320468948

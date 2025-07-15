/*A. Strange Splitting
time limit per test1 second
memory limit per test256 megabytes
Define the range of a non-empty array to be the maximum value minus the minimum
value. For example, the range of [1,4,2] is 4−1=3
.

You are given an array 𝑎1,𝑎2,…,𝑎𝑛
 of length 𝑛≥3
. It is guaranteed 𝑎
 is sorted.

You have to color each element of 𝑎
 red or blue so that:

the range of the red elements does not equal the range of the blue elements, and
there is at least one element of each color.
If there does not exist any such coloring, you should report it. If there are
multiple valid colorings, you can print any of them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (3≤𝑛≤50
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
). It is guaranteed 𝑎1≤𝑎2≤…≤𝑎𝑛−1≤𝑎𝑛
.

Output
For each test case, if it is impossible to color 𝑎
 to satisfy all the constraints, output 𝙽𝙾
.

Otherwise, first output 𝚈𝙴𝚂
.

Then, output a string 𝑠
 of length 𝑛
. For 1≤𝑖≤𝑛
, if you color 𝑎𝑖
 red, 𝑠𝑖
 should be 𝚁
. For 1≤𝑖≤𝑛
, if you color 𝑎𝑖
 blue, 𝑠𝑖
 should be 𝙱
.

Example
InputCopy
7
4
1 1 2 2
5
1 2 3 4 5
3
3 3 3
4
1 2 2 2
3
1 2 2
3
1 1 2
3
1 9 84
OutputCopy
YES
RBRR
YES
BBRBB
NO
YES
RBBR
YES
RRB
YES
BRR
YES
BRB
Note
In the first test case, given the array [1,1,2,2]
, we can color the second element blue and the remaining elements red; then the
range of the red elements [1,2,2] is 2−1=1 , and the range of the blue elements
[1] is 1−1=0
.

In the second test case, we can color the first, second, fourth and fifth
elements [1,2,4,5] blue and the remaining elements [3] red.

The range of the red elements is 3−3=0
 and the range of the blue elements is 5−1=4
, which are different.

In the third test case, it can be shown there is no way to color 𝑎=[3,3,3]
 to satisfy the constraints.
*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x, y;
    cin >> x;
    for (int i = 1; i < n; i++) {
      cin >> y;
    }
    if (x == y) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    cout << "RB";
    for (int i = 2; i < n; i++) {
      cout << "R";
    }
    cout << endl;
  }
  return 0;
}
// suyb: https://codeforces.com/problemset/submission/1984/329015803

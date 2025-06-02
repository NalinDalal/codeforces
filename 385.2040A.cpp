/* A. Game of Division
time limit per test1 second
memory limit per test256 megabytes
You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛
 of length 𝑛
 and an integer 𝑘
.

Two players are playing a game. The first player chooses an index 1≤𝑖≤𝑛
. Then the second player chooses a different index 1≤𝑗≤𝑛,𝑖≠𝑗
. The first player wins if |𝑎𝑖−𝑎𝑗|
 is not divisible by 𝑘
. Otherwise, the second player wins.

We play as the first player. Determine whether it is possible to win, and if so,
which index 𝑖 should be chosen.

The absolute value of a number 𝑥
 is denoted by |𝑥|
 and is equal to 𝑥
 if 𝑥≥0
, and −𝑥
 otherwise.

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤100 ) — the number of test cases. The description of the
test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤100
; 1≤𝑘≤100
) — the length of the array and the number 𝑘
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤100
) — the elements of the array 𝑎
.

Output
For each test case, if it is impossible for the first player to win, print "NO"
(without quotes).

Otherwise, print "YES" (without quotes) and on the next line the appropriate
index 1≤𝑖≤𝑛 . If there are multiple solutions, print any of them.

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive
answer.

Example
InputCopy
7
3 2
1 2 3
4 2
1 2 4 5
5 3
10 7 3 4 5
5 3
1 31 15 55 36
2 1
17 17
2 2
17 18
1 3
6
OutputCopy
YES
2
NO
YES
3
NO
NO
YES
2
YES
1
Note
In the first test case, the first player can choose 𝑎2=2
. Then:

If the second player chooses 𝑎1=1
, the resulting difference is |2−1|=1
 which is not divisible by 𝑘=2
.
If the second player chooses 𝑎3=3
, the resulting difference is |2−3|=1
 which is not divisible by 𝑘=2
.
In the second test case:

If the first player chooses 𝑎1=1
 and then the second player chooses 𝑎4=5
, the resulting difference is |1−5|=4
 which is divisible by 𝑘=2
.
If the first player chooses 𝑎2=2
 and then the second player chooses 𝑎3=4
, the resulting difference is |2−4|=2
 which is divisible by 𝑘=2
.
If the first player chooses 𝑎3=4
 and then the second player chooses 𝑎2=2
, the resulting difference is |4−2|=2
 which is divisible by 𝑘=2
.
If the first player chooses 𝑎4=5
 and then the second player chooses 𝑎1=1
, the resulting difference is |5−1|=4
 which is divisible by 𝑘=2
.
In any case, the second player wins.

*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> v(k, 0);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      int m = a[i] % k;
      if (v[m] < 0) {
        continue;
      } else if (v[m] == 0) {
        v[m] = i + 1; // Store 1-based index
      } else {
        v[m] = -1; // Mark duplicate
      }
    }

    int res = -1;
    for (int i = 0; i < k; ++i) {
      if (v[i] > 0) {
        res = v[i];
        break;
      }
    }

    if (res > 0) {
      cout << "YES\n" << res << "\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2040/322498145

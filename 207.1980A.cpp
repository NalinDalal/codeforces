/*A. Problem Generator
time limit per test1 second
memory limit per test256 megabytes
Vlad is planning to hold 𝑚
 rounds next month. Each round should contain one problem of difficulty levels
'A', 'B', 'C', 'D', 'E', 'F', and 'G'.

Vlad already has a bank of 𝑛
 problems, where the 𝑖
-th problem has a difficulty level of 𝑎𝑖
. There may not be enough of these problems, so he may have to come up with a
few more problems.

Vlad wants to come up with as few problems as possible, so he asks you to find
the minimum number of problems he needs to come up with in order to hold 𝑚
 rounds.

For example, if 𝑚=1
, 𝑛=10
, 𝑎=
 'BGECDCBDED', then he needs to come up with two problems: one of difficulty
level 'A' and one of difficulty level 'F'.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤50
, 1≤𝑚≤5
) — the number of problems in the bank and the number of upcoming rounds,
respectively.

The second line of each test case contains a string 𝑎
 of 𝑛
 characters from 'A' to 'G' — the difficulties of the problems in the bank.

Output
For each test case, output a single integer — the minimum number of problems
that need to come up with to hold 𝑚 rounds.

Example
InputCopy
3
10 1
BGECDCBDED
10 2
BGECDCBDED
9 1
BBCDEFFGG
OutputCopy
2
5
1

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    // n problems, m round
    // ans=min no of problem needed to hold m rounds
    int v[7] = {0};
    for (int i = 0; i < s.size(); i++) {
      ++v[s[i] - 'A'];
    }
    int cnt = 0;
    for (int i = 0; i < 7; i++) {

      int diff = m - v[i];
      cnt += (diff > 0) * diff;
    }

    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1980/309849850

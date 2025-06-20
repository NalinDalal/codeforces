/*A. Twice
time limit per test1 second
memory limit per test256 megabytes
Kinich wakes up to the start of a new day. He turns on his phone, checks his
mailbox, and finds a mysterious present. He decides to unbox the present.

Kinich unboxes an array 𝑎
 with 𝑛
 integers. Initially, Kinich's score is 0
. He will perform the following operation any number of times:

Select two indices 𝑖
 and 𝑗
 (1≤𝑖<𝑗≤𝑛)
 such that neither 𝑖
 nor 𝑗
 has been chosen in any previous operation and 𝑎𝑖=𝑎𝑗
. Then, add 1
 to his score.
Output the maximum score Kinich can achieve after performing the aforementioned
operation any number of times.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤500
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤20
) — the length of 𝑎
.

The following line of each test case contains 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

Output
For each test case, output the maximum score achievable on a new line.

Example
InputCopy
5
1
1
2
2 2
2
1 2
4
1 2 3 1
6
1 2 3 1 2 3
OutputCopy
0
1
0
1
3
Note
In the first and third testcases, Kinich cannot perform any operations.

In the second testcase, Kinich can perform one operation with 𝑖=1
 and 𝑗=2
.

In the fourth testcase, Kinich can perform one operation with 𝑖=1
 and 𝑗=4
.



*/

#include <iostream>
#include <map>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    std::map<long, long> m;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      ++m[x];
    }

    long score = 0;
    for (std::map<long, long>::iterator it = m.begin(); it != m.end(); it++) {
      score += (it->second) / 2;
    }
    cout << score << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2037/325313802

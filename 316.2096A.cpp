/*A. Wonderful Sticks
time limit per test1 second
memory limit per test256 megabytes
You are the proud owner of 𝑛
 sticks. Each stick has an integer length from 1
 to 𝑛
. The lengths of the sticks are distinct.

You want to arrange the sticks in a row. There is a string 𝑠
 of length 𝑛−1
 that describes the requirements of the arrangement.

Specifically, for each 𝑖
 from 1
 to 𝑛−1
:

If 𝑠𝑖=<
, then the length of the stick at position 𝑖+1
 must be smaller than all sticks before it;
If 𝑠𝑖=>
, then the length of the stick at position 𝑖+1
 must be larger than all sticks before it.
Find any valid arrangement of sticks. We can show that an answer always exists.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤100
) — the number of sticks.

The second line of each test case contains a single string 𝑠
 of length 𝑛−1
 consisting of characters <
 and >
 — describing the requirements of the arrangement.

Output
For each test case, output 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
, the 𝑎𝑖
 are distinct) — the lengths of the sticks in order. If there are multiple
solutions, print any of them.

Example
InputCopy
5
2
<
5
<<><
2
>
3
<>
7
><>>><
OutputCopy
2 1
4 3 2 5 1
1 2
2 1 3
3 4 2 5 6 7 1
Note
For the first test case, the requirements of the arrangement are as follows:

𝑠1=<
, which means 𝑎2
 is smaller than 𝑎1
.
Thus, one possible arrangement is [2,1]
.

For the second test case, the requirements of the arrangement are as follows:

𝑠1=<
, which means 𝑎2
 is smaller than 𝑎1
;
𝑠2=<
, which means 𝑎3
 is smaller than 𝑎1
 and 𝑎2
;
𝑠3=>
, which means 𝑎4
 is larger than 𝑎1
, 𝑎2
, and 𝑎3
;
𝑠4=<
, which means 𝑎5
 is smaller than 𝑎1
, 𝑎2
, 𝑎3
, and 𝑎4.
Thus, one possible arrangement is [4,3,2,5,1].
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void solve(int n, string s) {
  int low = 1, high = n;
  vector<int> res;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == '>')
      res.emplace_back(high--);
    else
      res.emplace_back(low++);
  }
  res.emplace_back(low);
  reverse(res.begin(), res.end());
  for (int x : res)
    cout << x << ' ';

  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    solve(n, s);
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2096/317693500

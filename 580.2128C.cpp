/*C. Leftmost Below
time limit per test2 seconds
memory limit per test256 megabytes
Consider an array 𝑎1,…,𝑎𝑛
. Initially, 𝑎𝑖=0
 for every 𝑖
.

You can do operations of the following form.

You choose an integer 𝑥
 greater than min(𝑎)
.
Then, 𝑖
 is defined as the minimum index such that 𝑎𝑖<𝑥
. In other words, 𝑖
 is the unique integer between 1
 and 𝑛
 inclusive such that 𝑎𝑖<𝑥
 and 𝑎𝑗≥𝑥
 for every 1≤𝑗≤𝑖−1
.
Finally, 𝑎𝑖
 is incremented by 𝑥
.
For example, if 𝑎=[6,8,2,1]
 and you choose 𝑥=6
, then 𝑖
 will be equal to 3
 (since 𝑎1≥6
, 𝑎2≥6
, and 𝑎3<6
) and 𝑎
 will become [6,8,8,1]
.

You can do as many operations as you want. Can you reach a target array 𝑏1,…,𝑏𝑛
?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤10000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤200000
).

The second line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤109
).

The sum of 𝑛
 over all test cases does not exceed 200000
.

Output
For each test case, print YES if you can reach the target array and NO
otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
4
4
5 6 1 1
3
3 1 2
3
40 60 90
2
1 1
OutputCopy
YES
NO
NO
YES
Note
In the first test case, we can do the following sequence of operations:

we choose 𝑥=2
, 𝑎
 becomes [2,0,0,0]
we choose 𝑥=2
, 𝑎
 becomes [2,2,0,0]
we choose 𝑥=3
, 𝑎
 becomes [5,2,0,0]
we choose 𝑥=4
, 𝑎
 becomes [5,6,0,0]
we choose 𝑥=1
, 𝑎
 becomes [5,6,1,0]
we choose 𝑥=1
, 𝑎
 becomes [5,6,1,1]
In the second test case, we can prove there is no way to reach [3,1,2]
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long mn = 1e9 + 7;
    bool ans = true;

    while (n--) {
      long b;
      cin >> b;
      if (mn < b / 2 + 1) {
        ans = false;
      }
      mn = min(mn, b);
    }

    cout << (ans ? "YES" : "NO") << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2128/333087018

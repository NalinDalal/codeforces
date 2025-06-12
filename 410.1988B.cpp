/* B. Make Majority
time limit per test1.5 seconds
memory limit per test512 megabytes
You are given a sequence [𝑎1,…,𝑎𝑛]
 where each element 𝑎𝑖
 is either 0
 or 1
. You can apply several (possibly zero) operations to the sequence. In each
operation, you select two integers 1≤𝑙≤𝑟≤|𝑎| (where |𝑎| is the current length of
𝑎 ) and replace [𝑎𝑙,…,𝑎𝑟] with a single element 𝑥 , where 𝑥 is the majority of
[𝑎𝑙,…,𝑎𝑟]
.

Here, the majority of a sequence consisting of 0
 and 1
 is defined as follows: suppose there are 𝑐0
 zeros and 𝑐1
 ones in the sequence, respectively.

If 𝑐0≥𝑐1
, the majority is 0
.
If 𝑐0<𝑐1
, the majority is 1
.
For example, suppose 𝑎=[1,0,0,0,1,1]
. If we select 𝑙=1,𝑟=2
, the resulting sequence will be [0,0,0,1,1]
. If we select 𝑙=4,𝑟=6
, the resulting sequence will be [1,0,0,1]
.

Determine if you can make 𝑎=[1]
 with a finite number of operations.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤4⋅104
). Description of the test cases follows.

The first line of each testcase contains one integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line of each testcase contains a string consisting of 0
 and 1
, describing the sequence 𝑎
.

It's guaranteed that the sum of 𝑛
 over all testcases does not exceed 2⋅105
.

Output
For each testcase, if it's possible to make 𝑎=[1]
, print YES. Otherwise, print NO. You can output the answer in any case (upper
or lower). For example, the strings yEs, yes, Yes, and YES will be recognized as
positive responses.

Example
InputCopy
5
1
0
1
1
2
01
9
100000001
9
000011000
OutputCopy
No
Yes
No
Yes
No
Note
In the fourth testcase of the example, initially 𝑎=[1,0,0,0,0,0,0,0,1]
. A valid sequence of operations is:

Select 𝑙=2,𝑟=8
 and apply the operation. 𝑎
 becomes [1,0,1]
.
Select 𝑙=1,𝑟=3
 and apply the operation. 𝑎
 becomes [1]
.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long z(s[0] == '0'), a(s[0] == '1');
    for (long p = 1; p < n; p++) {
      if (s[p] == '1') {
        ++a;
      } else if (s[p - 1] == '1') {
        ++z;
      }
    }
    cout << (a > z ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1988/323984699

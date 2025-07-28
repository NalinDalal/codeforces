/*M. Minimum LCM
time limit per test2 seconds
memory limit per test512 megabytes
You are given an integer 𝑛
.

Your task is to find two positive (greater than 0
) integers 𝑎
 and 𝑏
 such that 𝑎+𝑏=𝑛
 and the least common multiple (LCM) of 𝑎
 and 𝑏
 is the minimum among all possible values of 𝑎
 and 𝑏
. If there are multiple answers, you can print any of them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤109
).

Output
For each test case, print two positive integers 𝑎
 and 𝑏
 — the answer to the problem. If there are multiple answers, you can print any
of them.

Example
InputCopy
4
2
9
5
10
OutputCopy
1 1
3 6
1 4
5 5
Note
In the second example, there are 8
 possible pairs of 𝑎
 and 𝑏
:

𝑎=1
, 𝑏=8
, 𝐿𝐶𝑀(1,8)=8
;
𝑎=2
, 𝑏=7
, 𝐿𝐶𝑀(2,7)=14
;
𝑎=3
, 𝑏=6
, 𝐿𝐶𝑀(3,6)=6
;
𝑎=4
, 𝑏=5
, 𝐿𝐶𝑀(4,5)=20
;
𝑎=5
, 𝑏=4
, 𝐿𝐶𝑀(5,4)=20
;
𝑎=6
, 𝑏=3
, 𝐿𝐶𝑀(6,3)=6
;
𝑎=7
, 𝑏=2
, 𝐿𝐶𝑀(7,2)=14
;
𝑎=8
, 𝑏=1
, 𝐿𝐶𝑀(8,1)=8
.
In the third example, there are 5
 possible pairs of 𝑎
 and 𝑏
:

𝑎=1
, 𝑏=4
, 𝐿𝐶𝑀(1,4)=4
;
𝑎=2
, 𝑏=3
, 𝐿𝐶𝑀(2,3)=6
;
𝑎=3
, 𝑏=2
, 𝐿𝐶𝑀(3,2)=6
;
𝑎=4
, 𝑏=1
, 𝐿𝐶𝑀(4,1)=4
.
*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long div = n;
    for (long p = 2; p * p <= n; p++) {
      if (n % p == 0) {
        div = p;
        break;
      }
    }
    cout << (n / div) << " " << ((div - 1) * (n / div)) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1765/331274742

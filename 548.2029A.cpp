/*A. Set
time limit per test1 second
memory limit per test256 megabytes
You are given a positive integer 𝑘
 and a set 𝑆
 of all integers from 𝑙
 to 𝑟
 (inclusive).

You can perform the following two-step operation any number of times (possibly
zero):

First, choose a number 𝑥
 from the set 𝑆
, such that there are at least 𝑘
 multiples of 𝑥
 in 𝑆
 (including 𝑥
 itself);
Then, remove 𝑥
 from 𝑆
 (note that nothing else is removed).
Find the maximum possible number of operations that can be performed.

Input
Each test contains multiple test cases. The first line of the input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of test
cases follows.

The only line of each test case contains three integers 𝑙
, 𝑟
, and 𝑘
 (1≤𝑙≤𝑟≤109
, 1≤𝑘≤𝑟−𝑙+1
) — the minimum integer in 𝑆
, the maximum integer in 𝑆
, and the parameter 𝑘
.

Output
For each test case, output a single integer — the maximum possible number of
operations that can be performed.

Example
InputCopy
8
3 9 2
4 9 1
7 9 2
2 10 2
154 220 2
147 294 2
998 24435 3
1 1000000000 2
OutputCopy
2
6
0
4
0
1
7148
500000000
Note
In the first test case, initially, 𝑆={3,4,5,6,7,8,9}
. One possible optimal sequence of operations is:

Choose 𝑥=4
 for the first operation, since there are two multiples of 4
 in 𝑆
: 4
 and 8
. 𝑆
 becomes equal to {3,5,6,7,8,9}
;
Choose 𝑥=3
 for the second operation, since there are three multiples of 3
 in 𝑆
: 3
, 6
, and 9
. 𝑆
 becomes equal to {5,6,7,8,9}
.
In the second test case, initially, 𝑆={4,5,6,7,8,9}
. One possible optimal sequence of operations is:

Choose 𝑥=5
, 𝑆
 becomes equal to {4,6,7,8,9}
;
Choose 𝑥=6
, 𝑆
 becomes equal to {4,7,8,9}
;
Choose 𝑥=4
, 𝑆
 becomes equal to {7,8,9}
;
Choose 𝑥=8
, 𝑆
 becomes equal to {7,9}
;
Choose 𝑥=7
, 𝑆
 becomes equal to {9}
;
Choose 𝑥=9
, 𝑆
 becomes equal to {}
.
In the third test case, initially, 𝑆={7,8,9}
. For each 𝑥
 in 𝑆
, no multiple of 𝑥
 other than 𝑥
 itself can be found in 𝑆
. Since 𝑘=2
, you can perform no operations.

In the fourth test case, initially, 𝑆={2,3,4,5,6,7,8,9,10}
. One possible optimal sequence of operations is:

Choose 𝑥=2
, 𝑆
 becomes equal to {3,4,5,6,7,8,9,10}
;
Choose 𝑥=4
, 𝑆
 becomes equal to {3,5,6,7,8,9,10}
;
Choose 𝑥=3
, 𝑆
 becomes equal to {5,6,7,8,9,10}
;
Choose 𝑥=5
, 𝑆
 becomes equal to {6,7,8,9,10}
.
*/
#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long l, r, k;
    cin >> l >> r >> k;
    long res = (r / k) - l + 1;
    cout << (res > 0 ? res : 0) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2029/331523885

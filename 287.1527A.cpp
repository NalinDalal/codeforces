/* A. And Then There Were K
time limit per test1 second
memory limit per test256 megabytes
Given an integer 𝑛
, find the maximum value of integer 𝑘
 such that the following condition holds:

𝑛
 & (𝑛−1
) & (𝑛−2
) & (𝑛−3
) & ... (𝑘
) = 0
where & denotes the bitwise AND operation.
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤3⋅104
). Then 𝑡
 test cases follow.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤109
).

Output
For each test case, output a single integer — the required integer 𝑘
.

Example
InputCopy
3
2
5
17
OutputCopy
1
3
15
Note
In the first testcase, the maximum value for which the continuous & operation
gives 0 value, is 1.

In the second testcase, the maximum value for which the continuous & operation
gives 0 value, is 3. No value greater then 3, say for example 4, will give the &
sum 0.

5&4≠0
,
5&4&3=0
.
Hence, 3 is the answer. */

/*given a number n, find the value of k such that
n & (n-1) & (n-2) & (n-3) & ... (k)=0;
print k atlast
*/

// count=1;
// do n with n-1, store the result, if result is 0 then log n-count
// else count++ and again check

/*int findZeroBitwisePoint(int n) {
  int result = n;
  int i = 1;

  while (result != 0 && (n - i) >= 0) {
    result &= (n - i);
    i++;
  }

  if (result == 0) {
    return n - i + 1; // the value of n-i where it became 0
  }

  return -1; // In case it never becomes 0
}
gives tle b/c `result &= (n - i);` excutes n time which is kinda slow
*/
/*int findZeroBitwisePoint(int n) {
  int result = n;
  int i = 1;

  while (result != 0) {
    result &= (n - i);
    i++;
  }

  return n - i + 1; // value where result became 0
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // n & n-1
    // n & n-1 & n-2
    // n & n-1 & till n-i such that all of bitwise and=0
    // log n-i
    cout << findZeroBitwisePoint(n) << endl;
  }
  return 0;
}*/
#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 1;
    while (2 * x <= n) {
      x *= 2;
    }
    --x;
    cout << x << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1527/314448567

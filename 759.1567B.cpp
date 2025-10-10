/*B. MEXor Mixup
time limit per test2 seconds
memory limit per test256 megabytes
Alice gave Bob two integers 𝑎
 and 𝑏
 (𝑎>0
 and 𝑏≥0
). Being a curious boy, Bob wrote down an array of non-negative integers with
MEX value of all elements equal to 𝑎 and XOR value of all elements equal to 𝑏
.

What is the shortest possible length of the array Bob wrote?

Recall that the MEX
 (Minimum EXcluded) of an array is the minimum non-negative integer that does
not belong to the array and the XOR of an array is the bitwise XOR of all the
elements of the array.

Input
The input consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤5⋅104
) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎≤3⋅105
; 0≤𝑏≤3⋅105
) — the MEX
 and XOR
 of the array, respectively.

Output
For each test case, output one (positive) integer — the length of the shortest
array with MEX 𝑎 and XOR 𝑏 . We can show that such an array always exists.

Example
InputCopy
5
1 1
2 1
2 0
1 10000
2 10000
OutputCopy
3
2
3
2
3
Note
In the first test case, one of the shortest arrays with MEX
 1
 and XOR
 1
 is [0,2020,2021]
.

In the second test case, one of the shortest arrays with MEX
 2
 and XOR
 1
 is [0,1]
.

It can be shown that these arrays are the shortest arrays possible.
*/

#include <iostream>
using std::cin, std::cout, std::endl;
long computeXOR(long n) {

  if (n % 4 == 0) {
    return n;
  } else if (n % 4 == 1) {
    return 1;
  } else if (n % 4 == 2) {
    return n + 1;
  }
  return 0;
}
int main() {
  long t;
  cin >> t;
  while (t--) {
    long a, b;
    cin >> a >> b;
    long x = computeXOR(a - 1);
    long res = a + 2;
    if (x == b) {
      res = a;
    } else if ((x ^ b) != a) {
      res = a + 1;
    }
    cout << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1567/342865903

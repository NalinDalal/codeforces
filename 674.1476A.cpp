/*A. K-divisible Sum
time limit per test1 second
memory limit per test256 megabytes
You are given two integers 𝑛
 and 𝑘
.

You should create an array of 𝑛
 positive integers 𝑎1,𝑎2,…,𝑎𝑛
 such that the sum (𝑎1+𝑎2+⋯+𝑎𝑛)
 is divisible by 𝑘
 and maximum element in 𝑎
 is minimum possible.

What is the minimum possible maximum element in 𝑎
?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first and only line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤109
; 1≤𝑘≤109
).

Output
For each test case, print one integer — the minimum possible maximum element in
array 𝑎 such that the sum (𝑎1+⋯+𝑎𝑛) is divisible by 𝑘
.

Example
InputCopy
4
1 5
4 3
8 8
8 17
OutputCopy
5
2
1
3
Note
In the first test case 𝑛=1
, so the array consists of one element 𝑎1
 and if we make 𝑎1=5
 it will be divisible by 𝑘=5
 and the minimum possible.

In the second test case, we can create array 𝑎=[1,2,1,2]
. The sum is divisible by 𝑘=3
 and the maximum is equal to 2
.

In the third test case, we can create array 𝑎=[1,1,1,1,1,1,1,1]
. The sum is divisible by 𝑘=8
 and the maximum is equal to 1
.
*/

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n <= k) {
      cout << (k + n - 1) / n << endl;
      ;
    } else {
      cout << 1 + (n % k > 0) << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1476/337903160

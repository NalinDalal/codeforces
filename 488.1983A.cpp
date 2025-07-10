/*A. Array Divisibility
time limit per test1 second
memory limit per test256 megabytes
An array of integers 𝑎1,𝑎2,⋯,𝑎𝑛
 is beautiful subject to an integer 𝑘
 if it satisfies the following:

The sum of 𝑎𝑗
 over all 𝑗
 such that 𝑗
 is a multiple of 𝑘
 and 1≤𝑗≤𝑛
, itself, is a multiple of 𝑘
.
More formally, if ∑𝑘|𝑗𝑎𝑗
 is divisible by 𝑘
 for all 1≤𝑗≤𝑛
 then the array 𝑎
 is beautiful subject to 𝑘
. Here, the notation 𝑘|𝑗
 means 𝑘
 divides 𝑗
, that is, 𝑗
 is a multiple of 𝑘
.
Given 𝑛
, find an array of positive nonzero integers, with each element less than or
equal to 105 that is beautiful subject to all 1≤𝑘≤𝑛
.
It can be shown that an answer always exists.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100
). The description of the test cases follows.

The first and only line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the size of the array.

Output
For each test case, print the required array as described in the problem
statement.

Example
InputCopy
3
3
6
7
OutputCopy
4 22 18
10 6 15 32 125 54
23 18 27 36 5 66 7
Note
In the second test case, when 𝑛=6
, for all integers 𝑘
 such that 1≤𝑘≤6
, let 𝑆
 be the set of all indices of the array that are divisible by 𝑘
.

When 𝑘=1
, 𝑆={1,2,3,4,5,6}
 meaning 𝑎1+𝑎2+𝑎3+𝑎4+𝑎5+𝑎6=242
 must be divisible by 1
.
When 𝑘=2
, 𝑆={2,4,6}
 meaning 𝑎2+𝑎4+𝑎6=92
 must be divisible by 2
.
When 𝑘=3
, 𝑆={3,6}
 meaning 𝑎3+𝑎6=69
 must divisible by 3
.
When 𝑘=4
, 𝑆={4}
 meaning 𝑎4=32
 must divisible by 4
.
When 𝑘=5
, 𝑆={5}
 meaning 𝑎5=125
 must divisible by 5
.
When 𝑘=6
, 𝑆={6}
 meaning 𝑎6=54
 must divisible by 6
.
The array 𝑎=[10,6,15,32,125,54]
 satisfies all of the above conditions. Hence, 𝑎
 is a valid array.
*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // vector<int> v(n);
    // For every k in 1..n, the sum of all a[j] such that j % k == 0 is
    // divisible by k. a[i] = LCM(1..n) / i;

    /*Set each a[i] = lcm(1..n) / i but rescaled to be in range [1, 1e5].

    To avoid big values, we instead set:

    cpp
    Copy
    Edit
    a[i] = i * lcm
    for some lcm that is divisible by all 1..n. Choose:

    cpp
    Copy
    Edit
    lcm = n!
    We don't really compute factorial — just ensure each a[i] is divisible by i.

    So instead:

    ✅ Final Construction Rule (Simple and Always Works):
    cpp
    Copy
    Edit
    a[i] = i * n

             */

    // cout the array
    for (int i = 0; i < n; i++)
      cout << i * n << " ";
    cout << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1983/328355249

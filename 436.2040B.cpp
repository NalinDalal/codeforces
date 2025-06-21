/*B. Paint a Strip
time limit per test1 second
memory limit per test256 megabytes
You have an array of zeros 𝑎1,𝑎2,…,𝑎𝑛
 of length 𝑛
.

You can perform two types of operations on it:

Choose an index 𝑖
 such that 1≤𝑖≤𝑛
 and 𝑎𝑖=0
, and assign 1
 to 𝑎𝑖
;
Choose a pair of indices 𝑙
 and 𝑟
 such that 1≤𝑙≤𝑟≤𝑛
, 𝑎𝑙=1
, 𝑎𝑟=1
, 𝑎𝑙+…+𝑎𝑟≥⌈𝑟−𝑙+12⌉
, and assign 1
 to 𝑎𝑖
 for all 𝑙≤𝑖≤𝑟
.
What is the minimum number of operations of the first type needed to make all
elements of the array equal to one?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The only line of each test case contains one integer 𝑛
 (1≤𝑛≤105
) — the length of the array.

Note that there is no limit on the sum of 𝑛
 over all test cases.

Output
For each test case, print one integer — the minimum number of needed operations
of first type.

Example
InputCopy
4
1
2
4
20
OutputCopy
1
2
2
4
Note
In the first test case, you can perform an operation of the 1
st type with 𝑖=1
.

In the second test case, you can perform the following sequence of operations:

Operation of 1
st type, 𝑖=1
. After performing this operation, the array will look like this: [1,0]
.
Operation of 1
st type, 𝑖=2
. After performing this operation, the array will look like this: [1,1]
.
The sequence of operations in the second test case
In the third test case, you can perform the following sequence of operations:

Operation of 1
st type, 𝑖=1
. After performing this operation, the array will look like this: [1,0,0,0]
.
Operation of 1
st type, 𝑖=4
. After performing this operation, the array will look like this: [1,0,0,1]
.
Operation of 2
nd type, 𝑙=1
, 𝑟=4
. On this segment, 𝑎𝑙+…+𝑎𝑟=𝑎1+𝑎2+𝑎3+𝑎4=2
, which is not less than ⌈𝑟−𝑙+12⌉=2
. After performing this operation, the array will look like this: [1,1,1,1]
.
The sequence of operations in the third test case



*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 1, last = 1;
    while (last < n) {
      cnt++;
      last = 2 * last + 2;
    }
    cout << cnt << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2040/325397034

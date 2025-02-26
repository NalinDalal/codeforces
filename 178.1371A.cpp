/* A. Magical Sticks
time limit per test1 second
memory limit per test256 megabytes
A penguin Rocher has 𝑛
 sticks. He has exactly one stick with length 𝑖
 for all 1≤𝑖≤𝑛
.

He can connect some sticks. If he connects two sticks that have lengths 𝑎
 and 𝑏
, he gets one stick with length 𝑎+𝑏
. Two sticks, that were used in the operation disappear from his set and the new
connected stick appears in his set and can be used for the next connections.

He wants to create the maximum number of sticks that have the same length. It is
not necessary to make all sticks have the same length, some sticks can have the
other length. How many sticks with the equal length he can create?

Input
The input consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases. Next 𝑡 lines contain
descriptions of test cases.

For each test case, the only line contains a single integer 𝑛
 (1≤𝑛≤109
).

Output
For each test case, print a single integer  — the answer to the problem.

Example
InputCopy
4
1
2
3
4
OutputCopy
1
1
2
2
Note
In the third case, he can connect two sticks with lengths 1
 and 2
 and he will get one stick with length 3
. So, he will have two sticks with lengths 3
.

In the fourth case, he can connect two sticks with lengths 1
 and 3
 and he will get one stick with length 4
. After that, he will have three sticks with lengths {2,4,4}
, so two sticks have the same length, and one stick has the other length.


*/
#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int ans = (n + 1) / 2;
    std::cout << ans << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1371/307969771

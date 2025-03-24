/*B. Everyone Loves Tres
time limit per test1 second
memory limit per test256 megabytes
There are 3 heroes and 3 villains, so 6 people in total.
Given a positive integer 𝑛
. Find the smallest integer whose decimal representation has length 𝑛
 and consists only of 3
s and 6
s such that it is divisible by both 33
 and 66
. If no such integer exists, print −1
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤500
) — the number of test cases.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤500
) — the length of the decimal representation.

Output
For each test case, output the smallest required integer if such an integer
exists and −1 otherwise.

Example
InputCopy
6
1
2
3
4
5
7
OutputCopy
-1
66
-1
3366
36366
3336366
Note
For 𝑛=1, no such integer exists as neither 3 nor 6 is divisible by 33.
For 𝑛=2, 66 consists only of 6s and it is divisible by both 33 and 66.
For 𝑛=3, no such integer exists. Only 363 is divisible by 33, but it is not
divisible by 66. For 𝑛=4, 3366 and 6666 are divisible by both 33 and 66, and
3366 is the smallest.*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string res = "-1";
    if (n == 1 || n == 3)
      res = "-1";
    // n is length of no, consist only of 3s and 6s
    // cout n such that it is divisible both by 33,66
    // else cout -1
    else if (n % 2) {
      res = std::string(n - 5, '3') + "36366";
    } else {
      res = std::string(n - 2, '3') + "66";
    }
    std::cout << res << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2035/312135466

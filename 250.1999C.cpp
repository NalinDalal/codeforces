/*C. Showering
time limit per test2 seconds
memory limit per test256 megabytes
As a computer science student, Alex faces a hard challenge — showering. He tries
to shower daily, but despite his best efforts there are always challenges. He
takes 𝑠 minutes to shower and a day only has 𝑚 minutes!

He already has 𝑛
 tasks planned for the day. Task 𝑖
 is represented as an interval (𝑙𝑖
, 𝑟𝑖)
, which means that Alex is busy and can not take a shower in that time interval
(at any point in time strictly between 𝑙𝑖 and 𝑟𝑖
). No two tasks overlap.

Given all 𝑛
 time intervals, will Alex be able to shower that day? In other words, will Alex
have a free time interval of length at least 𝑠
?


In the first test case, Alex can shower for the first 3
 minutes of the day and not miss any of the tasks.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains three integers 𝑛
, 𝑠
, and 𝑚
 (1≤𝑛≤2⋅105
; 1≤𝑠,𝑚≤109
) — the number of time intervals Alex already has planned, the amount of time
Alex takes to take a shower, and the amount of minutes a day has.

Then 𝑛
 lines follow, the 𝑖
-th of which contains two integers 𝑙𝑖
 and 𝑟𝑖
 (0≤𝑙𝑖<𝑟𝑖≤𝑚
) — the time interval of the 𝑖
-th task. No two tasks overlap.

Additional constraint on the input: 𝑙𝑖>𝑟𝑖−1
 for every 𝑖>1
.

The sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case output "YES" (without quotes) if Alex can take a shower for
that given test case, and "NO" (also without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes",
and "Yes" will be recognized as a positive response).

Example
InputCopy
4
3 3 10
3 5
6 8
9 10
3 3 10
1 2
3 5
6 7
3 3 10
1 2
3 5
6 8
3 4 10
1 2
6 7
8 9
OutputCopy
YES
YES
NO
YES
*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, s, m;
    std::cin >> n >> s >> m;
    int prev = 0;
    bool res = false;
    for (int p = 0; p < n; p++) {
      int left, right;
      std::cin >> left >> right;
      if (prev + s <= left) {
        res = true;
      }
      prev = right;
    }

    if (prev + s <= m) {
      res = true;
    }
    std::cout << (res ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1999/311661846

/*A. Energy Crystals
time limit per test2 seconds
memory limit per test512 megabytes
There are three energy crystals numbered 1
, 2
, and 3
; let's denote the energy level of the 𝑖
-th crystal as 𝑎𝑖
. Initially, all of them are discharged, meaning their energy levels are equal
to 0 . Each crystal needs to be charged to level 𝑥 (exactly 𝑥 , not greater).

In one action, you can increase the energy level of any one crystal by any
positive amount; however, the energy crystals are synchronized with each other,
so an action can only be performed if the following condition is met afterward:

for each pair of crystals 𝑖
, 𝑗
, it must hold that 𝑎𝑖≥⌊𝑎𝑗2⌋
.
What is the minimum number of actions required to charge all the crystals?

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The only line of each test case contains a single integer 𝑥
 (1≤𝑥≤109
).

Output
For each test case, output a single integer — the minimum number of actions
required to charge all energy crystals to level 𝑥
.

Example
InputCopy
7
1
5
14
2025
31415
536870910
1000000000
OutputCopy
3
7
9
23
31
59
61
Note
In the first test case, one possible sequence of actions is:

[0,0,0]→[1,0,0]→[1,0,1]→[1,1,1]

One of the possible sequences of actions in the second test case is:

[0,0,0]→[1,0,0]→[1,1,0]→[1,1,2]→[3,1,2]→[3,5,2]→[5,5,2]→[5,5,5]
*/
#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x;
    std::cin >> x;
    int g = 1, cnt = 0;
    while (g < x) {
      g = 2 * g + 1;
      ++cnt;
    }
    int ans = 2 * cnt + 3;
    std::cout << ans << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2111/328169421

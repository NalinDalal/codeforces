/*C. Joyboard
time limit per test1 second
memory limit per test256 megabytes
Chaneka, a gamer kid, invented a new gaming controller called joyboard.
Interestingly, the joyboard she invented can only be used to play one game.

The joyboard has a screen containing 𝑛+1
 slots numbered from 1
 to 𝑛+1
 from left to right. The 𝑛+1
 slots are going to be filled with an array of non-negative integers
[𝑎1,𝑎2,𝑎3,…,𝑎𝑛+1] . Chaneka, as the player, must assign 𝑎𝑛+1 with an integer
between 0 and 𝑚 inclusive. Then, for each 𝑖 from 𝑛 to 1 , the value of 𝑎𝑖 will
be equal to the remainder of dividing 𝑎𝑖+1 (the adjacent value to the right) by
𝑖 . In other words, 𝑎𝑖=𝑎𝑖+1mod𝑖
.

Chaneka wants it such that after every slot is assigned with an integer, there
are exactly 𝑘 distinct values in the entire screen (among all 𝑛+1 slots). How
many valid ways are there for assigning a non-negative integer into slot 𝑛+1
?

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤2⋅104
) — the number of test cases. The following lines contain the description of
each test case.

The only line of each test case contains three integers 𝑛
, 𝑚
, and 𝑘
 (1≤𝑛≤109
; 0≤𝑚≤109
; 1≤𝑘≤𝑛+1
) — there are 𝑛+1
 slots, the integer assigned in slot 𝑛+1
 must not be bigger than 𝑚
, and there should be exactly 𝑘
 distinct values.

Output
For each test case, output a line containing an integer representing the number
of valid ways for assigning a non-negative integer into slot 𝑛+1
.

Example
InputCopy
4
4 6 3
2 0 1
265 265 265
3 10 2
OutputCopy
2
1
0
5
Note
In the first test case, one of the 2
 possible ways for Chaneka is to choose 𝑎𝑛+1=6
. If she does that, then:

𝑎4=𝑎5mod4=6mod4=2
𝑎3=𝑎4mod3=2mod3=2
𝑎2=𝑎3mod2=2mod2=0
𝑎1=𝑎2mod1=0mod1=0
𝑎=[0,0,2,2,6]
There are 3
 distinct values.
In the second test case, the 1
 possible way for Chaneka is to choose 𝑎𝑛+1=0
. If she does that, then 𝑎=[0,0,0]
. There is only 1
 distinct value.

In the third test case, there is no possible way for assigning a non-negative
integer into slot 𝑛+1
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n, m, k;
    cin >> n >> m >> k;
    long res = 0;

    if (k > 3) {
      res = 0;
    } else if (k == 1) {
      res = 1;
    } else if (k == 2) {
      res = min(m, m / n + n - 1);
    } else { // k == 3
      res = m - (m / n) - n + 1;
      if (res < 0)
        res = 0;
    }

    cout << res << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1877/346361869

/*B. Replacement
time limit per test1 second
memory limit per test256 megabytes
You have a binary string∗
 𝑠
 of length 𝑛
, and Iris gives you another binary string 𝑟
 of length 𝑛−1
.

Iris is going to play a game with you. During the game, you will perform 𝑛−1
 operations on 𝑠
. In the 𝑖
-th operation (1≤𝑖≤𝑛−1
):

First, you choose an index 𝑘
 such that 1≤𝑘≤|𝑠|−1
 and 𝑠𝑘≠𝑠𝑘+1
. If it is impossible to choose such an index, you lose;
Then, you replace 𝑠𝑘𝑠𝑘+1
 with 𝑟𝑖
. Note that this decreases the length of 𝑠
 by 1
.
If all the 𝑛−1
 operations are performed successfully, you win.

Determine whether it is possible for you to win this game.

∗
A binary string is a string where each character is either 𝟶
 or 𝟷
.

Input
Each test contains multiple test cases. The first line of the input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤105
) — the length of 𝑠
.

The second line contains the binary string 𝑠
 of length 𝑛
 (𝑠𝑖=𝟶
 or 𝟷
).

The third line contains the binary string 𝑟
 of length 𝑛−1
 (𝑟𝑖=𝟶
 or 𝟷
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, print "YES" (without quotes) if you can win the game, and
"NO" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
2
11
0
2
01
1
4
1101
001
6
111110
10000
6
010010
11010
8
10010010
0010010
OutputCopy
NO
YES
YES
NO
YES
NO
Note
In the first test case, you cannot perform the first operation. Thus, you lose
the game.

In the second test case, you can choose 𝑘=1
 in the only operation, and after that, 𝑠
 becomes equal to 𝟷
. Thus, you win the game.

In the third test case, you can perform the following operations:
𝟷𝟷𝟶⎯⎯⎯⎯𝟷−→−−𝑟1=𝟶𝟷𝟶𝟷⎯⎯⎯⎯−→−−𝑟2=𝟶𝟷𝟶⎯⎯⎯⎯−→−−𝑟3=𝟷𝟷
.
*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::string r;
    std::cin >> r;
    long a(0), z(0);
    for (long p = 0; p < s.size(); p++) {
      z += (s[p] == '0');
      a += (s[p] == '1');
    }

    bool res(true);
    for (long p = 0; p < n - 1 && res; p++) {
      if (!z || !a) {
        res = false;
      }
      if (r[p] == '0') {
        --a;
      } else {
        --z;
      }
    }

    std::cout << (res ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2029/338154606

/*C. Action Figures
time limit per test2.5 seconds
memory limit per test512 megabytes
There is a shop that sells action figures near Monocarp's house. A new set of
action figures will be released shortly; this set contains 𝑛 figures, the 𝑖 -th
figure costs 𝑖 coins and is available for purchase from day 𝑖 to day 𝑛
.

For each of the 𝑛
 days, Monocarp knows whether he can visit the shop.

Every time Monocarp visits the shop, he can buy any number of action figures
which are sold in the shop (of course, he cannot buy an action figure that is
not yet available for purchase). If Monocarp buys at least two figures during
the same day, he gets a discount equal to the cost of the most expensive figure
he buys (in other words, he gets the most expensive of the figures he buys for
free).

Monocarp wants to buy exactly one 1
-st figure, one 2
-nd figure, ..., one 𝑛
-th figure from the set. He cannot buy the same figure twice. What is the
minimum amount of money he has to spend?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (1≤𝑛≤4⋅105
) — the number of figures in the set (and the number of days);
the second line contains a string 𝑠
 (|𝑠|=𝑛
, each 𝑠𝑖
 is either 0 or 1). If Monocarp can visit the shop on the 𝑖
-th day, then 𝑠𝑖
 is 1; otherwise, 𝑠𝑖
 is 0.
Additional constraints on the input:

in each test case, 𝑠𝑛
 is 1, so Monocarp is always able to buy all figures during the 𝑛
-th day;
the sum of 𝑛
 over all test cases does not exceed 4⋅105
.
Output
For each test case, print one integer — the minimum amount of money Monocarp has
to spend.

Example
InputCopy
4
1
1
6
101101
7
1110001
5
11111
OutputCopy
1
8
18
6
Note
In the first test case, Monocarp buys the 1
-st figure on the 1
-st day and spends 1
 coin.

In the second test case, Monocarp can buy the 1
-st and the 3
-rd figure on the 3
-rd day, the 2
-nd and the 4
-th figure on the 4
-th day, and the 5
-th and the 6
-th figure on the 6
-th day. Then, he will spend 1+2+5=8
 coins.

In the third test case, Monocarp can buy the 2
-nd and the 3
-rd figure on the 3
-rd day, and all other figures on the 7
-th day. Then, he will spend 1+2+4+5+6=18
 coins.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0, c = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (c >= i) {
        ans += i + 1;
        c--;
        continue;
        ;
      }
      if (s[i] == '1')
        c++;

      else {
        ans += i + 1;
        c--;
        if (c < 0)
          c = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2026/339015758

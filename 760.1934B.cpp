/*B. Yet Another Coin Problem
time limit per test1 second
memory limit per test256 megabytes
You have 5
 different types of coins, each with a value equal to one of the first 5
 triangular numbers: 1
, 3
, 6
, 10
, and 15
. These coin types are available in abundance. Your goal is to find the minimum
number of these coins required such that their total value sums up to exactly 𝑛
.

We can show that the answer always exists.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤109
) — the target value.

Output
For each test case, output a single number — the minimum number of coins
required.

Example
InputCopy
14
1
2
3
5
7
11
12
14
16
17
18
20
98
402931328
OutputCopy
1
2
1
3
2
2
2
3
2
3
2
2
8
26862090
Note
In the first test case, for 𝑛=1
, the answer is 1
 since only one 1
 value coin is sufficient. 1=1⋅1
.

In the fourth test case, for 𝑛=5
, the answer is 3
, which can be achieved using two 1
 value coins and one 3
 value coin. 5=2⋅1+1⋅3
.

In the seventh test case, for 𝑛=12
, the answer is 2
, which can be achieved using two 6
 value coins.

In the ninth test case, for 𝑛=16
, the answer is 2
, which can be achieved using one 1
 value coin and one 15
 value coin or using one 10
 value coin and one 6
 value coin. 16=1⋅1+1⋅15=1⋅6+1⋅10
.
*/

#include <iostream>
#include <vector>
using namespace std;

long f(long n) {
  if (n < 0)
    return 1e9;

  long cnt = 0;
  cnt += (n / 15);
  n %= 15;
  cnt += (n / 6);
  n %= 6;
  cnt += (n / 3);
  n %= 3;
  cnt += n;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;

  while (t--) {
    long n;
    cin >> n;

    long zero_tens = f(n);
    long one_tens = 1 + f(n - 10);
    long two_tens = 2 + f(n - 20);

    long ans = min(zero_tens, min(one_tens, two_tens));
    cout << ans << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1934/342867002

/*A. Coin Transformation
time limit per test2 seconds
memory limit per test512 megabytes
Initially, you have a coin with value 𝑛
. You can perform the following operation any number of times (possibly zero):

transform one coin with value 𝑥
, where 𝑥
 is greater than 3
 (𝑥>3
), into two coins with value ⌊𝑥4⌋
.
What is the maximum number of coins you can have after performing this operation
any number of times?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of one line containing one integer 𝑛
 (1≤𝑛≤1018
).

Output
For each test case, print one integer — the maximum number of coins you can have
after performing the operation any number of times.

Example
InputCopy
4
1
5
16
1000000000000000000
OutputCopy
1
2
4
536870912
Note
In the first example, you have a coin of value 1
, and you can't do anything with it. So, the answer is 1
.

In the second example, you can transform a coin of value 5 into two coins with
value 1.

In the third example, you can transform a coin of value 16 into two coins with
value 4. Each of the resulting coins can be transformed into two coins with
value 1.

 */

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    // if x>3 then brk into 2 coins of value floor(x/4)
    // return max no of coin you can have
    long long ans = 1;
    while (n > 3) {
      ans *= 2;
      n = n / 4;
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/contest/2043/submission/322122695

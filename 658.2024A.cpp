/*A. Profitable Interest Rate
time limit per test1 second
memory limit per test256 megabytes
Alice has 𝑎
 coins. She can open a bank deposit called "Profitable", but the minimum amount
required to open this deposit is 𝑏 coins.

There is also a deposit called "Unprofitable", which can be opened with any
amount of coins. Alice noticed that if she opens the "Unprofitable" deposit with
𝑥 coins, the minimum amount required to open the "Profitable" deposit decreases
by 2𝑥 coins. However, these coins cannot later be deposited into the
"Profitable" deposit.

Help Alice determine the maximum number of coins she can deposit into the
"Profitable" deposit if she first deposits some amount of coins (possibly 0 )
into the "Unprofitable" deposit. If Alice can never open the "Profitable"
deposit, output 0
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

A single line of each test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤109
) — the number of coins Alice has and the initial minimum amount required to
open the "Profitable" deposit.

Output
For each test case, output a single integer — the maximum number of coins that
Alice can deposit into the "Profitable" deposit. If Alice can never open the
"Profitable" deposit, output 0
.

Example
InputCopy
5
10 5
7 9
5 100
1 1
1 2
OutputCopy
10
5
0
1
0
Note
In the first test case, 𝑎≥𝑏
, so Alice can immediately open the "Profitable" deposit with all 10
 coins.

In the second test case, Alice can open the "Unprofitable" deposit with 2
 coins. Then she will have 5
 coins left, but the minimum amount required to open the "Profitable" deposit
will decrease by 4 coins, making it equal to 5 coins. Thus, Alice will be able
to open the "Profitable" deposit with 5 coins.

In the third test case, Alice will not be able to open the "Profitable" deposit.
*/

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    // Total coins = a, minimum required coins = b
    // Unprofitable coins reduce profitable coins by 2x if there are x
    // unprofitable coins Unprofitable coins cannot be deposited into profitable
    // coins Goal: maximize profitable coins after adjustment, output 0 if
    // impossible

    // Observation:

    // 1. If total coins a >= minimum required b:
    //      - We can satisfy the requirement without any adjustment
    //      - Maximum profitable coins = a

    // 2. If total coins a < b, but 2*a >= b:
    //      - We can still satisfy minimum b by adjusting with unprofitable
    //      coins
    //      - Maximum profitable coins = 2*a - b

    // 3. If 2*a < b:
    //      - Impossible to satisfy minimum required coins
    //      - Maximum profitable coins = 0
    int ans = 0;
    if (a >= b) {
      ans = a;
    } else if (2 * a >= b) {
      ans = 2 * a - b;
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2024/336942958

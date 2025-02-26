/* A. Collecting Coins
time limit per test2 seconds
memory limit per test256 megabytes
Polycarp has three sisters: Alice, Barbara, and Cerene. They're collecting
coins. Currently, Alice has 𝑎 coins, Barbara has 𝑏 coins and Cerene has 𝑐 coins.
Recently Polycarp has returned from the trip around the world and brought 𝑛
coins.

He wants to distribute all these 𝑛 coins between his sisters in such a way that
the number of coins Alice has is equal to the number of coins Barbara has and is
equal to the number of coins Cerene has. In other words, if Polycarp gives 𝐴
coins to Alice, 𝐵 coins to Barbara and 𝐶 coins to Cerene (𝐴+𝐵+𝐶=𝑛), then
𝑎+𝐴=𝑏+𝐵=𝑐+𝐶.

Note that A, B or C (the number of coins Polycarp gives to Alice, Barbara and
Cerene correspondingly) can be 0.

Your task is to find out if it is possible to distribute all 𝑛 coins between
sisters in a way described above.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤104) — the number of
test cases.

The next 𝑡 lines describe test cases. Each test case is given on a new line and
consists of four space-separated integers 𝑎,𝑏,𝑐 and 𝑛 (1≤𝑎,𝑏,𝑐,𝑛≤108) — the
number of coins Alice has, the number of coins Barbara has, the number of coins
Cerene has and the number of coins Polycarp has.

Output
For each test case, print "YES" if Polycarp can distribute all 𝑛 coins between
his sisters and "NO" otherwise.

Example
InputCopy
5
5 3 2 8
100 101 102 105
3 2 1 100000000
10 20 15 14
101 101 101 3
OutputCopy
YES
YES
NO
NO
YES

*/

#include <algorithm>
#include <iostream>
using namespace std;
/*Find the maximum of a, b, and c (let’s call it maxVal).
Calculate the total extra coins required to make a, b, and c all equal to
maxVal. Check if the remaining coins (n) can be evenly distributed among three
numbers.*/
bool cond(int a, int b, int c, int n) {
  int maxVal = max({a, b, c});
  int totalRequired =
      3 * maxVal - (a + b + c); // Coins needed to make all equal

  if (n >= totalRequired && (n - totalRequired) % 3 == 0) {
    return true;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    // a+A=b+B=c+C
    // A+B+C=n

    // cout YES if all n coins can be distributed to a,b,c
    // else cout NO
    // A,B or C can be 0

    if (cond(a, b, c, n)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1294/307967664

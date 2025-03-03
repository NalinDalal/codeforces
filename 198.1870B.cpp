/*B. Grab the Candies
time limit per test1 second
memory limit per test256 megabytes
Mihai and Bianca are playing with bags of candies. They have a row 𝑎
 of 𝑛
 bags of candies. The 𝑖
-th bag has 𝑎𝑖
 candies. The bags are given to the players in the order from the first bag to
the 𝑛 -th bag.

If a bag has an even number of candies, Mihai grabs the bag. Otherwise, Bianca
grabs the bag. Once a bag is grabbed, the number of candies in it gets added to
the total number of candies of the player that took it.

Mihai wants to show off, so he wants to reorder the array so that at any moment
(except at the start when they both have no candies), Mihai will have strictly
more candies than Bianca. Help Mihai find out if such a reordering exists.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the number of bags in the array.

The second line of each test case contains 𝑛
 space-separated integers 𝑎𝑖
 (1≤𝑎𝑖≤100
) — the number of candies in each bag.

Output
For each test case, output "YES" (without quotes) if such a reordering exists,
and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
3
4
1 2 3 4
4
1 1 1 2
3
1 4 3
OutputCopy
YES
NO
NO
Note
In the first test case, Mihai can reorder the array as follows: [4,1,2,3]
. Then the process proceeds as follows:

the first bag has 4
 candies, which is even, so Mihai takes it — Mihai has 4
 candies, and Bianca has 0
.
the second bag has 1
 candies, which is odd, so Bianca takes it — Mihai has 4
 candies, and Bianca has 1
.
the third bag has 2
 candies, which is even, so Mihai takes it — Mihai has 6
 candies, and Bianca has 1
.
the fourth bag has 3
 candies, which is odd, so Bianca takes it — Mihai has 6
 candies, and Bianca has 4
.
Since Mihai always has more candies than Bianca, this reordering works.

*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    std::vector<int> a(n);
    for (int p = 0; p < n; p++) {
      cin >> a[p];
    }
    std::vector<int> b(m);
    for (int p = 0; p < m; p++) {
      cin >> b[p];
    }

    int A = 0;
    for (int p = 0; p < n; p++) {
      A ^= a[p];
    }
    if (n % 2) {
      long mx = A;
      for (int p = 0; p < m; p++) {
        mx |= b[p];
      }
      cout << A << " " << mx << endl;

    } else {
      long mn = A;
      for (long p = 0; p < m; p++) {
        mn &= ~b[p];
      }
      cout << mn << " " << A << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1870/308764640

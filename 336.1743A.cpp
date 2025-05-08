/* A. Password
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp has forgotten the password to his mobile phone. The password consists
of 4 digits from 0 to 9 (note that it can start with the digit 0
).

Monocarp remembers that his password had exactly two different digits, and each
of these digits appeared exactly two times in the password. Monocarp also
remembers some digits which were definitely not used in the password.

You have to calculate the number of different sequences of 4
 digits that could be the password for Monocarp's mobile phone (i. e. these
sequences should meet all constraints on Monocarp's password).

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤200
) — the number of testcases.

The first line of each testcase contains a single integer 𝑛
 (1≤𝑛≤8
) — the number of digits for which Monocarp remembers that they were not used in
the password.

The second line contains 𝑛
 different integers 𝑎1,𝑎2,…𝑎𝑛
 (0≤𝑎𝑖≤9
) representing the digits that were not used in the password. Note that the
digits 𝑎1,𝑎2,…,𝑎𝑛 are given in ascending order.

Output
For each testcase, print one integer — the number of different 4
-digit sequences that meet the constraints.

Example
InputCopy
2
8
0 1 2 4 5 6 8 9
1
8
OutputCopy
6
216
Note
In the first example, all possible passwords are: "3377", "3737", "3773",
"7337", "7373", "7733".


*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    int r = 10 - n;
    cout << 3 * r * (r - 1) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1743/318817120

/* B. Balanced Array
time limit per test1 second
memory limit per test256 megabytes
You are given a positive integer 𝑛, it is guaranteed that 𝑛 is even (i.e.
divisible by 2).

You want to construct the array 𝑎 of length 𝑛 such that:

The first 𝑛2 elements of 𝑎 are even (divisible by 2);
the second 𝑛2 elements of 𝑎 are odd (not divisible by 2);
all elements of 𝑎 are distinct and positive;
the sum of the first half equals to the sum of the second half
(∑𝑖=1𝑛2𝑎𝑖=∑𝑖=𝑛2+1𝑛𝑎𝑖). If there are multiple answers, you can print any. It is
not guaranteed that the answer exists.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤104) — the number of
test cases. Then 𝑡 test cases follow.

The only line of the test case contains one integer 𝑛 (2≤𝑛≤2⋅105) — the length
of the array. It is guaranteed that that 𝑛 is even (i.e. divisible by 2).

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105
(∑𝑛≤2⋅105).

Output
For each test case, print the answer — "NO" (without quotes), if there is no
suitable answer for the given test case or 'YES' in the first line and any
suitable array 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) satisfying conditions from the problem
statement on the second line.

Example
InputCopy
5
2
4
6
8
10
OutputCopy
NO
YES
2 4 1 5
NO
YES
2 4 6 8 1 3 5 11
NO
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 4) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int p = 1; 2 * p <= n; p++) {
      cout << 2 * p << " ";
    }
    for (int p = 0; p + 1 < n / 2; p++) {
      cout << 2 * p + 1 << endl;
    }
    cout << 3 * n / 2 - 1 << endl;
    // printf("%ld\n", 3 * n / 2 - 1);
  }
}
// sub: https://codeforces.com/problemset/submission/1343/306443394

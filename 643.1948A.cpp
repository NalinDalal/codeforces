/*A. Special Characters
time limit per test2 seconds
memory limit per test256 megabytes
You are given an integer 𝑛
.

Your task is to build a string of uppercase Latin letters. There must be exactly
𝑛 special characters in this string. Let's call a character special if it is
equal to exactly one of its neighbors.

For example, there are 6
 special characters in the AAABAACC string (at positions: 1
, 3
, 5
, 6
, 7
 and 8
).

Print any suitable string or report that there is no such string.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤50
) — the number of test cases.

The only line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
).

Output
For each test case, print the answer as follows:

if there is no suitable string, print one line containing the string NO;
otherwise, print two lines. The first line should contain the string YES; on the
second line print a string of length at most 200 — the answer itself (it can be
shown that if some answers exist, then there is an answer of length at most 200
). If there are several solutions, print any of them.
Example
InputCopy
3
6
1
2
OutputCopy
YES
AAABAACC
NO
YES
MM
*/

/*buils a string with n special chars
A special character is one that matches at least one of its neighbors.

"AAABAACC" → special characters are at positions 1,3,5,6,7,8 → 6 specials.

string like 'AA','BB' produce special chars
hence n must always be even

else no

read n
if(n%2) -> "NO"
else ->Construct a string using alternating "BB" and "AA" n/2 times.
*/
#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    if (n % 2) {
      std::cout << "NO" << std::endl;
      continue;
    }
    std::cout << "YES" << std::endl;
    for (long p = 0; 2 * p < n; p++) {
      std::cout << ((p % 2) ? "AA" : "BB");
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1948/336346007

/*A. Verify Password
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp is working on his new site, and the current challenge is to make the
users pick strong passwords.

Monocarp decided that strong passwords should satisfy the following conditions:

password should consist only of lowercase Latin letters and digits;
there should be no digit that comes after a letter (so, after each letter, there
is either another letter or the string ends); all digits should be sorted in the
non-decreasing order; all letters should be sorted in the non-decreasing order.
Note that it's allowed for the password to have only letters or only digits.

Monocarp managed to implement the first condition, but he struggles with the
remaining ones. Can you help him to verify the passwords?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of testcases.

The first line of each testcase contains a single integer 𝑛
 (1≤𝑛≤20
) — the length of the password.

The second line contains a string, consisting of exactly 𝑛
 characters. Each character is either a lowercase Latin letter or a digit.

Output
For each testcase, print "YES" if the given password is strong and "NO"
otherwise.

Example
InputCopy
5
4
12ac
5
123wa
9
allllmost
5
ac123
6
011679
OutputCopy
YES
NO
YES
NO
YES
Note
In the second testcase, the letters are not sorted in the non-decreasing order.

In the fourth testcase, there is a digit that comes after a letter — digit '1'
after a letter 'c'.
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
    bool inc(true);
    for (long p = 1; inc && p < n; p++) {
      if (s[p - 1] > s[p]) {
        inc = false;
      }
    }

    std::cout << (inc ? "YES" : "NO") << std::endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1976/330389266

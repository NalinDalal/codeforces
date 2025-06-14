/*B. Not Quite a Palindromic String
time limit per test2 seconds
memory limit per test256 megabytes
Vlad found a binary string∗
 𝑠
 of even length 𝑛
. He considers a pair of indices (𝑖,𝑛−𝑖+1
), where 1≤𝑖<𝑛−𝑖+1
, to be good if 𝑠𝑖=𝑠𝑛−𝑖+1
 holds true.

For example, in the string '010001' there is only 1
 good pair, since 𝑠1≠𝑠6
, 𝑠2≠𝑠5
, and 𝑠3=𝑠4
. In the string '0101' there are no good pairs.

Vlad loves palindromes, but not too much, so he wants to rearrange some
characters of the string so that there are exactly 𝑘 good pairs of indices.

Determine whether it is possible to rearrange the characters in the given string
so that there are exactly 𝑘 good pairs of indices (𝑖,𝑛−𝑖+1
).

∗
A string 𝑠
 is called binary if it consists only of the characters '0' and '1'

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤2⋅105
, 0≤𝑘≤𝑛2
, 𝑛
 is even) — the length of the string and the required number of good pairs.

The second line of each test case contains a binary string 𝑠
 of length 𝑛
.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if there is a way to rearrange the characters
of the string so that there are exactly 𝑘 good pairs, otherwise output "NO".

You may output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
6
6 2
000000
2 1
01
4 1
1011
10 2
1101011001
10 1
1101011001
2 1
11
OutputCopy
NO
NO
YES
NO
YES
YES


*/
#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    long a(0), z(0);
    for (long p = 0; p < s.size(); p++) {
      z += (s[p] == '0');
      a += (s[p] == '1');
    }

    const long d = n / 2 - k;
    bool possible((z >= d) && (a >= d) && ((a - d) % 2 == 0) &&
                  ((z - d) % 2 == 0));
    std::cout << (possible ? "YES" : "NO") << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2114/324329928

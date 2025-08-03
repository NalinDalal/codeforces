/*C. Kevin and Binary Strings
time limit per test2 seconds
memory limit per test256 megabytes
Kevin discovered a binary string 𝑠
 that starts with 1 in the river at Moonlit River Park and handed it over to
you. Your task is to select two non-empty substrings∗ of 𝑠 (which can be
overlapped) to maximize the XOR value of these two substrings.

The XOR of two binary strings 𝑎
 and 𝑏
 is defined as the result of the ⊕
 operation applied to the two numbers obtained by interpreting 𝑎
 and 𝑏
 as binary numbers, with the leftmost bit representing the highest value. Here,
⊕ denotes the bitwise XOR operation.

The strings you choose may have leading zeros.

∗
A string 𝑎
 is a substring of a string 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) characters from the
beginning and several (possibly, zero or all) characters from the end.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤103
).

The only line of each test case contains a binary string 𝑠
 that starts with 1 (1≤|𝑠|≤5000
).

It is guaranteed that the sum of |𝑠|
 over all test cases doesn't exceed 5000
.

Output
For each test case, output four integers 𝑙1,𝑟1,𝑙2,𝑟2
 (1≤𝑙1≤𝑟1≤|𝑠|
, 1≤𝑙2≤𝑟2≤|𝑠|
) — in the case the two substrings you selected are 𝑠𝑙1𝑠𝑙1+1…𝑠𝑟1
 and 𝑠𝑙2𝑠𝑙2+1…𝑠𝑟2
.

If there are multiple solutions, print any of them.

Example
InputCopy
5
111
1000
10111
11101
1100010001101
OutputCopy
2 2 1 3
1 3 1 4
1 5 1 4
3 4 1 5
1 13 1 11
Note
In the first test case, we can choose 𝑠2=𝟷
 and 𝑠1𝑠2𝑠3=𝟷𝟷𝟷
, and 𝟷⊕𝟷𝟷𝟷=𝟷𝟷𝟶
. It can be proven that it is impossible to obtain a larger result.
Additionally, 𝑙1=3 , 𝑟1=3 , 𝑙2=1 , 𝑟2=3 is also a valid solution.

In the second test case, 𝑠1𝑠2𝑠3=𝟷𝟶𝟶
, 𝑠1𝑠2𝑠3𝑠4=𝟷𝟶𝟶𝟶
, the result is 𝟷𝟶𝟶⊕𝟷𝟶𝟶𝟶=𝟷𝟷𝟶𝟶
, which is the maximum.
*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    size_t a(0), z(0);
    bool fz(0);
    size_t n = s.size();
    for (size_t p = 0; p < n; p++) {
      if (s[p] == '0') {
        ++z;
        fz = true;
      } else if (fz) {
        break;
      } else {
        ++a;
      }
    }

    long shift = (a < z ? a : z);
    // Need to cover the first stretch of zeros; if the first stretch of ones
    // is longer than that, we need tro truncate
    size_t start = a + 1 - shift;
    start = (start < n ? start : n);
    size_t stop = n - shift;
    std::cout << "1 " << n << " " << start << " " << stop << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2048/332187608

/*A. Ideal Generator
time limit per test1 second
memory limit per test256 megabytes
We call an array 𝑎
, consisting of 𝑘
 positive integers, palindromic if [𝑎1,𝑎2,…,𝑎𝑘]=[𝑎𝑘,𝑎𝑘−1,…,𝑎1]
. For example, the arrays [1,2,1]
 and [5,1,1,5]
 are palindromic, while the arrays [1,2,3]
 and [21,12]
 are not.

We call a number 𝑘
 an ideal generator if any integer 𝑛
 (𝑛≥𝑘
) can be represented as the sum of the elements of a palindromic array of length
exactly 𝑘 . Each element of the array must be greater than 0
.

For example, the number 1
 is an ideal generator because any natural number 𝑛
 can be generated using the array [𝑛]
. However, the number 2
 is not an ideal generator — there is no palindromic array of length 2
 that sums to 3
.

Determine whether the given number 𝑘
 is an ideal generator.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first and only line of each test case contains one integer 𝑘
 (1≤𝑘≤1000
).

Output
For each number 𝑘
, you need to output the word "YES" if it is an ideal generator, or "NO"
otherwise.

You may output "Yes" and "No" in any case (for example, the strings "yES",
"yes", and "Yes" will be recognized as a positive answer).

Example
InputCopy
5
1
2
3
73
1000
OutputCopy
YES
NO
YES
YES
NO
*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int k;
    std::cin >> k;
    std::cout << k % 2 ? "YES" : "NO";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2093/316413671

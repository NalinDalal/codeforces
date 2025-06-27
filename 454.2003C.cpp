/*C. Turtle and Good Pairs
time limit per test2 seconds
memory limit per test256 megabytes
Turtle gives you a string 𝑠
, consisting of lowercase Latin letters.

Turtle considers a pair of integers (𝑖,𝑗)
 (1≤𝑖<𝑗≤𝑛
) to be a pleasant pair if and only if there exists an integer 𝑘
 such that 𝑖≤𝑘<𝑗
 and both of the following two conditions hold:

𝑠𝑘≠𝑠𝑘+1
;
𝑠𝑘≠𝑠𝑖
 or 𝑠𝑘+1≠𝑠𝑗
.
Besides, Turtle considers a pair of integers (𝑖,𝑗)
 (1≤𝑖<𝑗≤𝑛
) to be a good pair if and only if 𝑠𝑖=𝑠𝑗
 or (𝑖,𝑗)
 is a pleasant pair.

Turtle wants to reorder the string 𝑠
 so that the number of good pairs is maximized. Please help him!

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the string.

The second line of each test case contains a string 𝑠
 of length 𝑛
, consisting of lowercase Latin letters.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the string 𝑠
 after reordering so that the number of good pairs is maximized. If there are
multiple answers, print any of them.

Example
InputCopy
5
3
abc
5
edddf
6
turtle
8
pppppppp
10
codeforces
OutputCopy
acb
ddedf
urtlet
pppppppp
codeforces
Note
In the first test case, (1,3)
 is a good pair in the reordered string. It can be seen that we can't reorder
the string so that the number of good pairs is greater than 1 . bac and cab can
also be the answer.

In the second test case, (1,2)
, (1,4)
, (1,5)
, (2,4)
, (2,5)
, (3,5)
 are good pairs in the reordered string. efddd can also be the answer.



*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  const int B = 26;

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<long> f(B);
    for (char x : s) {
      ++f[x - 'a'];
    }

    std::string res("");
    while (res.size() < n) {
      for (int p = 0; p < B; p++) {
        if (f[p] <= 0) {
          continue;
        }
        res += ('a' + p);
        --f[p];
      }
    }

    std::cout << res << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2003/326245104

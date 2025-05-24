/* D. Remove Two Letters
time limit per test2 seconds
memory limit per test256 megabytes
Dmitry has a string 𝑠
, consisting of lowercase Latin letters.

Dmitry decided to remove two consecutive characters from the string 𝑠
 and you are wondering how many different strings can be obtained after such an
operation.

For example, Dmitry has a string "aaabcc". You can get the following different
strings: "abcc"(by deleting the first two or second and third characters),
"aacc"(by deleting the third and fourth characters),"aaac"(by deleting the
fourth and the fifth character) and "aaab" (by deleting the last two).

Input
The first line of input data contains a single integer 𝑡
 (1≤𝑡≤104
) — number of test cases.

The descriptions of the test cases follow.

The first line of the description of each test case contains an integer 𝑛
 (3≤𝑛≤2⋅105
).

The second line of the description of each test case contains a string 𝑠
 of length 𝑛
 consisting of lowercase Latin letters.

It is guaranteed that the sum of 𝑛
 for all test cases does not exceed 2⋅105
.

Output
For each test case print one integer — the number of distinct strings that can
be obtained by removing two consecutive letters.

Example
InputCopy
7
6
aaabcc
10
aaaaaaaaaa
6
abcdef
7
abacaba
6
cccfff
4
abba
5
ababa
OutputCopy
4
1
5
3
3
3
1
Note
The first example is explained in the statement.

In the third example, the following strings are obtained: "cdef", "adef",
"abef", "abcf", "abcd".

In the seventh example, any deletion will result in the string "aba".


*/

#include <iostream>
using namespace std;
// remove 2 consecutive letter, how many diff string xan be obtained
// just remove 2 letter, move on, get the string, push to set
// atlast return the size of set
// to contain memory limit -> Use string_view instead of copying strings; Hash
// the resulting strings instead of storing them
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = n - 1;
    for (int p = 2; p < n; p++) {
      cnt -= (s[p] == s[p - 2]);
    }
    cout << cnt << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1800/321006903

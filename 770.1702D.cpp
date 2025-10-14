/*D. Not a Cheap String
time limit per test2 seconds
memory limit per test256 megabytes
Let 𝑠
 be a string of lowercase Latin letters. Its price is the sum of the indices of
letters (an integer between 1 and 26) that are included in it. For example, the
price of the string abca is 1+2+3+1=7
.

The string 𝑤
 and the integer 𝑝
 are given. Remove the minimal number of letters from 𝑤
 so that its price becomes less than or equal to 𝑝
 and print the resulting string. Note that the resulting string may be empty.
You can delete arbitrary letters, they do not have to go in a row. If the price
of a given string 𝑤 is less than or equal to 𝑝 , then nothing needs to be
deleted and 𝑤 must be output.

Note that when you delete a letter from 𝑤
, the order of the remaining letters is preserved. For example, if you delete
the letter e from the string test, you get tst.

Input
The first line of input contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases in the test. The following are descriptions of 𝑡
 test cases.

Each case consists of two lines.

The first of them is the string 𝑤
, it is non-empty and consists of lowercase Latin letters. Its length does not
exceed 2⋅105
.

The second line contains an integer 𝑝
 (1≤𝑝≤5200000
).

It is guaranteed that the sum of string lengths 𝑤
 over all test cases does not exceed 2⋅105
.

Output
Output exactly 𝑡
 rows, the 𝑖
-th of them should contain the answer to the 𝑖
-th set of input data. Print the longest string that is obtained from 𝑤
 by deleting letters such that its price is less or equal to 𝑝
. If there are several answers, then output any of them.

Note that the empty string  — is one of the possible answers. In this case, just
output an empty string.

Example
InputCopy
5
abca
2
abca
6
codeforces
1
codeforces
10
codeforces
100
OutputCopy
aa
abc

cdc
codeforces
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    long target;
    std::cin >> target;

    long total(0);
    std::vector<std::pair<long, long>> w(s.size());
    for (long p = 0; p < s.size(); p++) {
      w[p] = std::make_pair(s[p] - 'a' + 1, p);
      total += w[p].first;
    }
    sort(w.rbegin(), w.rend());

    std::vector<bool> v(s.size(), 1);
    for (long p = 0; (target < total) && p < s.size(); p++) {
      total -= w[p].first;
      v[w[p].second] = 0;
    }

    for (long p = 0; p < s.size(); p++) {
      if (!v[p]) {
        continue;
      }
      std::cout << s[p];
    }

    std::cout << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1702/343657559

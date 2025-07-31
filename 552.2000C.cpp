/*C. Numeric String Template
time limit per test2 seconds
memory limit per test256 megabytes
Kristina has an array 𝑎
, called a template, consisting of 𝑛
 integers. She also has 𝑚
 strings, each consisting only of lowercase Latin letters. The strings are
numbered from 1 to 𝑚 . She wants to check which strings match the template.

A string 𝑠
 is considered to match the template if all of the following conditions are
simultaneously satisfied:

The length of the string 𝑠
 is equal to the number of elements in the array 𝑎
.
The same numbers from 𝑎
 correspond to the same symbols from 𝑠
. So, if 𝑎𝑖=𝑎𝑗
, then 𝑠𝑖=𝑠𝑗
 for (1≤𝑖,𝑗≤𝑛
).
The same symbols from 𝑠
 correspond to the same numbers from 𝑎
. So, if 𝑠𝑖=𝑠𝑗
, then 𝑎𝑖=𝑎𝑗
 for (1≤𝑖,𝑗≤𝑛
).
In other words, there must be a one-to-one correspondence between the characters
of the string and the elements of the array. For example, if 𝑎 = [3,5,2,1,3
], then the string "abfda" matches the template, while the string "afbfa" does
not, since the character "f" corresponds to both numbers 1 and 5
.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The following descriptions are for the test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of elements in the array 𝑎
.

The second line of each test case contains exactly 𝑛
 integers 𝑎𝑖
 (−109≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

The third line of each test case contains a single integer 𝑚
 (1≤𝑚≤2⋅105
) — the number of strings to check for template matching.

Following are 𝑚
 strings, each containing a non-empty string 𝑠𝑗
 (1≤|𝑠𝑗|≤2⋅105
), consisting of lowercase Latin letters.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
, and that the sum of the lengths of all strings does not exceed 2⋅105
.

Output
For each test case, output 𝑚
 lines. On the 𝑖
-th line (1≤𝑖≤𝑚
) output:

"YES", if the string with index 𝑖
 matches the template;
"NO" otherwise.
You may output the answer in any case (for example, the strings "yEs", "yes",
"Yes", and "YES" will be recognized as a positive answer).

Example
InputCopy
3
5
3 5 2 1 3
2
abfda
afbfa
2
1 2
3
ab
abc
aa
4
5 -3 5 -3
4
aaaa
bcbc
aba
cbcb
OutputCopy
YES
NO
YES
NO
NO
NO
YES
NO
YES
Note
The first test case is explained in the problem statement.
*/

#include <iostream>
#include <map>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      std::cin >> a[p];
    }
    long m;
    std::cin >> m;
    while (m--) {
      std::map<long, char> numtochar;
      std::map<char, long> chartonum;
      std::string s;
      std::cin >> s;
      if (s.size() != n) {
        std::cout << "NO" << std::endl;
        continue;
      }
      bool res(true);
      for (long p = 0; res && p < s.size(); p++) {
        long f(a[p]);
        char g(s[p]);
        if (numtochar.count(f) ^ chartonum.count(g)) {
          res = false;
        }
        if (!numtochar.count(f)) {
          numtochar[f] = g;
          chartonum[g] = f;
        } else if (numtochar[f] != g || chartonum[g] != f) {
          res = false;
        }
      }
      std::cout << (res ? "YES" : "NO") << std::endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2000/331687159

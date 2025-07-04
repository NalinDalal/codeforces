/*B. Above the Clouds
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑠
 of length 𝑛
, consisting of lowercase letters of the Latin alphabet. Determine whether there
exist three non-empty strings 𝑎 , 𝑏 , and 𝑐 such that:

𝑎+𝑏+𝑐=𝑠
, meaning the concatenation∗
 of strings 𝑎
, 𝑏
, and 𝑐
 equals 𝑠
.
The string 𝑏
 is a substring†
 of the string 𝑎+𝑐
, which is the concatenation of strings 𝑎
 and 𝑐
.
∗
Concatenation of strings 𝑎
 and 𝑏
 is defined as the string 𝑎+𝑏=𝑎1𝑎2…𝑎𝑝𝑏1𝑏2…𝑏𝑞
, where 𝑝
 and 𝑞
 are the lengths of strings 𝑎
 and 𝑏
, respectively. For example, the concatenation of the strings "code" and
"forces" is "codeforces".

†
A string 𝑎
 is a substring of a string 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) characters from the
beginning and several (possibly, zero or all) characters from the end.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤105
) — the length of the string 𝑠
.

The second line of each test case contains the string 𝑠
 of length 𝑛
, consisting of lowercase letters of the Latin alphabet.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output "Yes" if there exist three non-empty strings 𝑎
, 𝑏
, and 𝑐
 that satisfy the conditions, and "No" otherwise.

You may output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

Example
InputCopy
12
3
aaa
3
aba
3
aab
4
abca
4
abba
4
aabb
5
abaca
5
abcda
5
abcba
6
abcbbf
6
abcdaa
3
abb
OutputCopy
Yes
No
Yes
No
Yes
Yes
Yes
No
Yes
Yes
Yes
Yes
Note
In the first test case, there exist unique non-empty strings 𝑎
, 𝑏
, and 𝑐
 such that 𝑎+𝑏+𝑐=𝑠
. These are the strings 𝑎=
 "a", 𝑏=
 "a", and 𝑐=
 "a". The concatenation of strings 𝑎
 and 𝑐
 equals 𝑎+𝑐=
 "aa". The string 𝑏
 is a substring of this string.

In the sixth test case, one can choose 𝑎=
 "a", 𝑏=
 "ab", and 𝑐=
 "b". The concatenation of strings 𝑎
 and 𝑐
 equals 𝑎+𝑐=
 "ab". The string 𝑏
 is a substring of this string.

In the seventh test case, one can choose 𝑎=
 "ab", 𝑏=
 "a", and 𝑐=
 "ca". The concatenation of strings 𝑎
 and 𝑐
 equals 𝑎+𝑐=
 "abca". The string 𝑏
 is a substring of this string.



*/

#include <iostream>
#include <vector>

int main() {

  const int B = 26;
  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<bool> v(B, 0);
    v[s[0] - 'a'] = 1;
    v[s.back() - 'a'] = 1;

    bool possible(false);
    for (long p = 1; !possible && p < s.size() - 1; p++) {
      int x = s[p] - 'a';
      if (v[x]) {
        possible = true;
      }
      v[x] = 1;
    }

    std::cout << (possible ? "YES" : "NO") << std::endl;
  }
}

// sub: https://codeforces.com/problemset/submission/2121/327380149

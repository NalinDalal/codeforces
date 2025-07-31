/*B. Symmetric Encoding
time limit per test2 seconds
memory limit per test256 megabytes
Polycarp has a string 𝑠
, which consists of lowercase Latin letters. He encodes this string using the
following algorithm:

first, he constructs a new auxiliary string 𝑟
, which consists of all distinct letters of the string 𝑠
, written in alphabetical order;
then the encoding happens as follows: each character in the string 𝑠
 is replaced by its symmetric character from the string 𝑟
 (the first character of the string 𝑟
 will be replaced by the last, the second by the second from the end, and so
on). For example, encoding the string 𝑠
="codeforces" happens as follows:

the string 𝑟
 is obtained as "cdefors";
the first character 𝑠1
='c' is replaced by 's';
the second character 𝑠2
='o' is replaced by 'e';
the third character 𝑠3
='d' is replaced by 'r';
...
the last character 𝑠10
='s' is replaced by 'c'.
The string 𝑟
 and replacements for 𝑠
="codeforces".
Thus, the result of encoding the string 𝑠
="codeforces" is the string "serofedsoc".

Write a program that performs decoding — that is, restores the original string 𝑠
 from the encoding result.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the string 𝑏
.

The second line of each test case contains a string 𝑏
 of length 𝑛
, consisting of lowercase Latin letters — the result of encoding the original
string 𝑠
.

It is guaranteed that the sum of the values of 𝑛
 over all test cases in the test does not exceed 2⋅105
.

Output
For each test case, output the string 𝑠
 from which the encoding result 𝑏
 was obtained.

Example
InputCopy
5
10
serofedsoc
3
ttf
9
tlrhgmaoi
1
w
15
hnndledmnhlttin
OutputCopy
codeforces
fft
algorithm
w
meetinthemiddle



*/

// given a encoded string s
// return the original string
// encoding logic:
//   - write the original string in alphabetical order{w/o repetitions}
//   - each character in the string 𝑠 is replaced by its symmetric character
//   from the string r
// codeforces: cdefors
//   - replace c by s
//   - replace d by r
//   - replace e by o
//
// given converted string, return original string

#include <bits/stdc++.h>
using namespace std;

string sol(string s) {
  unordered_set<char> uset(s.begin(), s.end());
  vector<char> alpha(uset.begin(), uset.end());
  sort(alpha.begin(), alpha.end());

  string r(alpha.begin(), alpha.end());
  reverse(r.begin(), r.end());

  unordered_map<char, char> revMap;
  for (int i = 0; i < alpha.size(); ++i) {
    revMap[r[i]] = alpha[i];
  }

  string ans;
  for (char c : s) {
    ans += revMap[c];
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << sol(s) << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1974/331685012

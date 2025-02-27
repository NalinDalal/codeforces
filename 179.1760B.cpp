/* B. Atilla's Favorite Problem
time limit per test1 second
memory limit per test256 megabytes
In order to write a string, Atilla needs to first learn all letters that are
contained in the string.

Atilla needs to write a message which can be represented as a string 𝑠
. He asks you what is the minimum alphabet size required so that one can write
this message.

The alphabet of size 𝑥
 (1≤𝑥≤26
) contains only the first 𝑥
 Latin letters. For example an alphabet of size 4
 contains only the characters 𝚊
, 𝚋
, 𝚌
 and 𝚍
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the length of the string.

The second line of each test case contains a string 𝑠
 of length 𝑛
, consisting of lowercase Latin letters.

Output
For each test case, output a single integer — the minimum alphabet size required
to so that Atilla can write his message 𝑠
.

Example
InputCopy
5
1
a
4
down
10
codeforces
3
bcf
5
zzzzz
OutputCopy
1
23
19
6
26
Note
For the first test case, Atilla needs to know only the character 𝚊
, so the alphabet of size 1
 which only contains 𝚊
 is enough.

For the second test case, Atilla needs to know the characters 𝚍
, 𝚘
, 𝚠
, 𝚗
. The smallest alphabet size that contains all of them is 23
 (such alphabet can be represented as the string 𝚊𝚋𝚌𝚍𝚎𝚏𝚐𝚑𝚒𝚓𝚔𝚕𝚖𝚗𝚘𝚙𝚚𝚛𝚜𝚝𝚞𝚟𝚠
).


*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // just sort the string ans check for the index of last char
    // return the index of last char
    sort(s.begin(), s.end());
    // after sorting, check what is last char
    int last = s[n - 1] - 'a';
    if (last < 26)
      cout << last + 1 << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1760/308156671

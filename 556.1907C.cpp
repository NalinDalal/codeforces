/*C. Removal of Unattractive Pairs
time limit per test1 second
memory limit per test256 megabytes
Vlad found a string 𝑠
 consisting of 𝑛
 lowercase Latin letters, and he wants to make it as short as possible.

To do this, he can remove any pair of adjacent characters from 𝑠
 any number of times, provided they are different. For example, if 𝑠
=racoon, then by removing one pair of characters he can obtain the strings coon,
roon, raon, and raco, but he cannot obtain racn (because the removed letters
were the same) or rcon (because the removed letters were not adjacent).

What is the minimum length Vlad can achieve by applying any number of deletions?

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Descriptions of the test cases follow.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the string 𝑠
.

The second line of each test case contains the string 𝑠
 consisting of 𝑛
 lowercase Latin letters.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single number—the minimum length of the string 𝑠
, after removing pairs of adjacent characters with different values.

Example
InputCopy
10
4
aabc
5
abaca
10
avbvvcvvvd
7
abcdefg
5
dabbb
8
aacebeaa
7
bbbbacc
6
dacfcc
6
fdfcdc
9
dbdcfbbdc
OutputCopy
0
1
2
1
1
0
1
0
0
1
Note
In the first test case of the example, you need to act as follows: "aabc" →
 "ac" →
 "". Note that with a different order of deletions, the string will not become
empty.



*/

// remove 2 adjacent letter, but they must not be same
// so racoon - coon, roon, raon, raco
// but not racn, rcon
// return min acheiveable length after removing pairs of adjacent characters
// with different values.

/*s = "racoon"

Step by step:
r → stack: r
a ≠ r → pop r → stack:
c ≠ a → can't pop → push c → stack: c
o ≠ c → pop c → stack:
o = top → push o → stack: o
n ≠ o → pop o → stack:

Final stack: empty → result = 0
*/

/*
    author    : MishkatIT
    created   : Sunday 2023-12-10-23.48.57
*/

#include <bits/stdc++.h>
#define fio                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';

using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;

int main() {
  fio;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int mxOccur = 0;
    vector<int> freq(26);
    for (auto &i : str) {
      freq[i - 'a']++;
      mxOccur = max(mxOccur, freq[i - 'a']);
    }
    if (mxOccur > n / 2) {
      cout << mxOccur - (n - mxOccur) << '\n';
    } else {
      cout << (n & 1) << '\n';
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1907/331917915

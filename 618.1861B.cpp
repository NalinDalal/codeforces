/*B. Two Binary Strings
time limit per test2 seconds
memory limit per test256 megabytes
You are given two strings 𝑎
 and 𝑏
 of equal length, consisting of only characters 0 and/or 1; both strings start
with character 0 and end with character 1.

You can perform the following operation any number of times (possibly zero):

choose one of the strings and two equal characters in it; then turn all
characters between them into those characters. Formally, you choose one of these
two strings (let the chosen string be 𝑠
), then pick two integers 𝑙
 and 𝑟
 such that 1≤𝑙<𝑟≤|𝑠|
 and 𝑠𝑙=𝑠𝑟
, then replace every character 𝑠𝑖
 such that 𝑙<𝑖<𝑟
 with 𝑠𝑙
.

For example, if the chosen string is 010101, you can transform it into one of
the following strings by applying one operation:

000101 if you choose 𝑙=1
 and 𝑟=3
;
000001 if you choose 𝑙=1
 and 𝑟=5
;
010001 if you choose 𝑙=3
 and 𝑟=5
;
010111 if you choose 𝑙=4
 and 𝑟=6
;
011111 if you choose 𝑙=2
 and 𝑟=6
;
011101 if you choose 𝑙=2
 and 𝑟=4
.
You have to determine if it's possible to make the given strings equal by
applying this operation any number of times.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤2000
)  — the number of test cases.

Each test case consists of two lines:

the first line contains the string 𝑎
 (2≤|𝑎|≤5000
), consisting of only characters 0 and/or 1.
the second line contains the string 𝑏
 (2≤|𝑏|≤5000
), consisting of only characters 0 and/or 1.
Additional constraints on the input:

in each test case, |𝑎|=|𝑏|
 (the strings have equal length);
in each test case, both strings start with 0 and end with 1;
the total length of all strings 𝑎
 in all test cases does not exceed 5000
.
Output
For each test case, print YES if it is possible to make the strings equal.
Otherwise, print NO. You can print each letter in any register.

Example
InputCopy
7
01010001
01110101
01001
01001
000101
010111
00001
01111
011
001
001001
011011
010001
011011
OutputCopy
YES
YES
YES
NO
NO
NO
YES
Note
In the first test case, we can perform the following operations:

choose the string 𝑎
, 𝑙=2
, 𝑟=4
; after this operation, 𝑎
 is 01110001, 𝑏
 is 01110101;
choose the string 𝑏
, 𝑙=5
, 𝑟=7
; after this operation, 𝑎
 is 01110001, 𝑏
 is 01110001.
In the second test case, the strings are already equal.

In the third test case, we can perform the following operations:

choose the string 𝑎
, 𝑙=4
, 𝑟=6
; after this operation, 𝑎
 is 000111, 𝑏
 is 010111;
choose the string 𝑏
, 𝑙=1
, 𝑟=3
; after this operation, 𝑎
 is 000111, 𝑏
 is 000111;
In the fourth and fifth test cases, it's impossible to make the given strings
equal.
*/

/* If you have two 0s, you can "flood" the substring between them with 0s.

If you have two 1s, you can flood that substring with 1s.
every contiguous interval that contains both ends of the same character can be
turned into a block of that character.

1. You can turn any interval between two 0s into all 0s.

2. You can turn any interval between two 1s into all 1s.

3. Therefore, if a string contains both 0 and 1 at least once (which it does,
since it starts with 0 and ends with 1), you can reshape it arbitrarily into a
sequence of alternating segments of 0s and 1s.


For each position i, check whether (a[i] != a[i+1]) == (b[i] != b[i+1]).
If for all i, this holds, answer = YES, else NO.

1. For each test case:
    - Read a and b.
    - For each index i from 0 to n-2:
        - If (a[i] != a[i+1]) != (b[i] != b[i+1]), then answer = NO.

if(a[i] == b[i] == '0' and a[i+1] == b[i+1] == '1') ans=yes;
Also if a == b initially, answer is YES.
2. Otherwise NO.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int n = a.size();

    if (a == b) {
      cout << "YES\n";
      continue;
    }

    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == '0' && b[i] == '0' && a[i + 1] == '1' && b[i + 1] == '1') {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1861/334976600

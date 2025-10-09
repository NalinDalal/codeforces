/*C1. Message Transmission Error (easy version)
This is a simplified version of the problem. It differs from the difficult one
only in its constraints.

At the Berland State University, the local network between servers does not
always operate without errors. When transmitting two identical messages
consecutively, an error may occur, resulting in the two messages merging into
one. In this merging, the end of the first message coincides with the beginning
of the second. Of course, the merging can only occur at identical characters.
The length of the merging must be a positive number less than the length of the
message text.

For example, when transmitting two messages "abrakadabra" consecutively, it is
possible that it will be transmitted with the described type of error, resulting
in a message like "abrakadabrabrakadabra" or "abrakadabrakadabra' (in the first
case, the merging occurred at one character, and in the second case, at four).

Given the received message t, determine if it is possible that this is the
result of an error of the described type in the operation of the local network,
and if so, determine a possible value of s.

A situation where two messages completely overlap each other should not be
considered an error. For example, if the received message is "abcd", it should
be considered that there is no error in it. Similarly, simply appending one
message after another is not a sign of an error. For instance, if the received
message is "abcabc", it should also be considered that there is no error in it.

Input
The input consists of a single non-empty string t, consisting of lowercase
letters of the Latin alphabet. The length of the string t does not exceed 100
characters.

Output
If the message t cannot contain an error, output "NO" (without quotes) in a
single line of output.

Otherwise, in the first line, output "YES" (without quotes), and in the next
line, output the string s — a possible message that could have led to the error.
If there are multiple possible answers, any of them is acceptable.

Examples
InputCopy
abrakadabrabrakadabra
OutputCopy
YES
abrakadabra
InputCopy
acacacaca
OutputCopy
YES
acaca
InputCopy
abcabc
OutputCopy
NO
InputCopy
abababab
OutputCopy
YES
ababab
InputCopy
tatbt
OutputCopy
NO
Note
In the second example, a suitable answer could also be the string "acacaca".



*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string t;
  cin >> t;
  int n = t.size();

  for (int len_s = 1; len_s < n; ++len_s) {
    int k = 2 * len_s - n;
    if (k <= 0 || k >= len_s)
      continue;

    string s = t.substr(0, len_s);
    if (s.substr(0, k) == s.substr(len_s - k) && s + s.substr(k) == t) {
      cout << "YES\n" << s << "\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2010/342675401

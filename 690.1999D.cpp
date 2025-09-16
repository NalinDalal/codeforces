/*D. Slavic's Exam
time limit per test2 seconds
memory limit per test256 megabytes
Slavic has a very tough exam and needs your help in order to pass it. Here is
the question he is struggling with:

There exists a string 𝑠
, which consists of lowercase English letters and possibly zero or more "?".

Slavic is asked to change each "?" to a lowercase English letter such that
string 𝑡 becomes a subsequence (not necessarily continuous) of the string 𝑠
.

Output any such string, or say that it is impossible in case no string that
respects the conditions exists.

Input
The first line contains a single integer 𝑇
 (1≤𝑇≤104
) — the number of test cases.

The first line of each test case contains a single string 𝑠
 (1≤|𝑠|≤2⋅105
, and 𝑠
 consists only of lowercase English letters and "?"-s)  – the original string
you have.

The second line of each test case contains a single string 𝑡
 (1≤|𝑡|≤|𝑠|
, and 𝑡
 consists only of lowercase English letters)  – the string that should be a
subsequence of string 𝑠
.

The sum of |𝑠|
 over all test cases doesn't exceed 2⋅105
, where |𝑥|
 denotes the length of the string 𝑥
.

Output
For each test case, if no such string exists as described in the statement,
output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output one line — the string
that respects all conditions.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes",
and "Yes" will be recognized as a positive response).

If multiple answers are possible, you can output any of them.

Example
InputCopy
5
?????
xbx
ab??e
abcde
ayy?x
a
ab??e
dac
paiu
mom
OutputCopy
YES
xabax
YES
abcde
YES
ayyyx
NO
NO


*/

// t is substr of s
// given s and t
// s has `?`, change them to some lowercase letter
// so that t becomes substr of s
// if possible cout<<"YES"<<endl; and corresponding string in next line
// else cout<<"NO"<<endl
// we are breaking on 1st valid match
// The jury test cases rely on last possible match (not just first).
// Instead of breaking at the first match, store the last valid index, and after
// the loop, construct the answer from there.

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    std::string s, u;
    std::cin >> s >> u;
    long idx(0);
    for (long p = 0; p < s.size(); p++) {
      if (s[p] == u[idx]) {
        ++idx;
      } else if (s[p] == '?') {
        s[p] = (idx < u.size() ? u[idx++] : 'a');
      }
    }

    if (idx >= u.size()) {
      std::cout << "YES\n" << s << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1999/338852082

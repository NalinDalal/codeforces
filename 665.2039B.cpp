/*B. Shohag Loves Strings
time limit per test1 second
memory limit per test256 megabytes
For a string 𝑝
, let 𝑓(𝑝)
 be the number of distinct non-empty substrings∗
 of 𝑝
.

Shohag has a string 𝑠
. Help him find a non-empty string 𝑝
 such that 𝑝
 is a substring of 𝑠
 and 𝑓(𝑝)
 is even or state that no such string exists.

∗
A string 𝑎
 is a substring of a string 𝑏
 if 𝑎
 can be obtained from 𝑏
 by deletion of several (possibly, zero or all) characters from the beginning
and several (possibly, zero or all) characters from the end.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first and only line of each test case contains a string 𝑠
 (1≤|𝑠|≤105
) consisting of lowercase English letters.

It is guaranteed that the sum of the length of 𝑠
 over all test cases doesn't exceed 3⋅105
.

Output
For each test case, print a non-empty string that satisfies the conditions
mentioned in the statement, or −1 if no such string exists. If there are
multiple solutions, output any.

Example
InputCopy
5
dcabaac
a
youknowwho
codeforces
bangladesh
OutputCopy
abaa
-1
youknowwho
eforce
bang
Note
In the first test case, we can set 𝑝=
 abaa because it is a substring of 𝑠
 and the distinct non-empty substrings of 𝑝
 are a, b, aa, ab, ba, aba, baa and abaa, so it has a total of 8
 distinct substrings which is even.

In the second test case, we can only set 𝑝=
 a but it has one distinct non-empty substring but this number is odd, so not
valid.

In the third test case, the whole string contains 52
 distinct non-empty substrings, so the string itself is a valid solution.
*/

// f(p)=non empty substr of p
// given string s, find p such that p=substr(s) && f(p)%2==0
// if exists, return p
// else return -1
/*f(p)=l(l+1)/2
 f(p) is even when L % 4 == 0 or L % 4 == 3
            if(s[i]==s[i+1])ans=substr(s,i,i+2);
            else if(s[i]==s[i+1] && s[i]==s[i+2])ans=sunstr(s,i,i+3);
            else s='-1'
            */

#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string ans = "-1";

    for (long i = 1; i < (long)s.size(); i++) {
      // Case 1: Two equal consecutive chars → valid p of length 2
      if (s[i - 1] == s[i]) {
        ans = s.substr(i - 1, 2);
        break;
      }
      // Case 2: Three distinct consecutive chars → valid p of length 3
      else if (i > 1 && s[i - 2] != s[i - 1] && s[i - 2] != s[i] &&
               s[i - 1] != s[i]) {
        ans = s.substr(i - 2, 3);
        break;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2039/337211060

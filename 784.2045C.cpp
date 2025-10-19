/*C. Saraga
time limit per test1 second
memory limit per test1024 megabytes
The word saraga is an abbreviation of sarana olahraga, an Indonesian term for a
sports facility. It is created by taking the prefix sara of the word sarana and
the suffix ga of the word olahraga. Interestingly, it can also be created by the
prefix sa of the word sarana and the suffix raga of the word olahraga.

An abbreviation of two strings 𝑆
 and 𝑇
 is interesting if there are at least two different ways to split the
abbreviation into two non-empty substrings such that the first substring is a
prefix of 𝑆 and the second substring is a suffix of 𝑇
.

You are given two strings 𝑆
 and 𝑇
. You want to create an interesting abbreviation of strings 𝑆
 and 𝑇
 with minimum length, or determine if it is impossible to create an interesting
abbreviation.

Input
The first line consists of a string 𝑆
 (1≤|𝑆|≤200000
).

The second line consists of a string 𝑇
 (1≤|𝑇|≤200000
).

Both strings 𝑆
 and 𝑇
 only consist of lowercase English letters.

Output
If it is impossible to create an interesting abbreviation, output -1.

Otherwise, output a string in a single line representing an interesting
abbreviation of strings 𝑆 and 𝑇 with minimum length. If there are multiple
solutions, output any of them.

Examples
InputCopy
sarana
olahraga
OutputCopy
saga
InputCopy
berhiber
wortelhijau
OutputCopy
berhijau
InputCopy
icpc
icpc
OutputCopy
icpc
InputCopy
icpc
jakarta
OutputCopy
-1
Note
Explanation for the sample input/output #1

You can split saga into s and aga, or sa and ga. The abbreviation saraga is
interesting, but saga has a smaller length.

Explanation for the sample input/output #2

The abbreviation belhijau is also interesting with minimum length, so it is
another valid solution.
*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t;

  long v[26] = {0};
  for (long p = 1; p < s.size(); p++) {
    if (v[s[p] - 'a'] > 0) {
      continue;
    }
    v[s[p] - 'a'] = p;
  }

  std::string res = "-1";
  bool found = false;
  for (long p = t.size() - 2; p >= 0; p--) {
    if (v[t[p] - 'a'] <= 0) {
      continue;
    }
    long tstlen = v[t[p] - 'a'] + t.size() - p;
    if (!found || tstlen < res.size()) {
      found = true;
      res = s.substr(0, v[t[p] - 'a']) + t.substr(p);
    }
  }

  std::cout << res << std::endl;

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2045/344623504

/*B. Notepad#
time limit per test3 seconds
memory limit per test256 megabytes
You want to type the string 𝑠
, consisting of 𝑛
 lowercase Latin letters, using your favorite text editor Notepad#.

Notepad# supports two kinds of operations:

append any letter to the end of the string;
copy a continuous substring of an already typed string and paste this substring
to the end of the string. Can you type string 𝑠 in strictly less than 𝑛
 operations?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The first line of each testcase contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the string 𝑠
.

The second line contains a string 𝑠
, consisting of 𝑛
 lowercase Latin letters.

The sum of 𝑛
 doesn't exceed 2⋅105
 over all testcases.

Output
For each testcase, print "YES" if you can type string 𝑠
 in strictly less than 𝑛
 operations. Otherwise, print "NO".

Example
InputCopy
6
10
codeforces
8
labacaba
5
uohhh
16
isthissuffixtree
1
x
4
momo
OutputCopy
NO
YES
NO
YES
NO
YES
Note
In the first testcase, you can start with typing "codef" (5
 operations), then copy "o" (1
 operation) from an already typed part, then finish with typing "rces" (4
 operations). That will be 10
 operations, which is not strictly less than 𝑛
. There exist other ways to type "codeforces". However, no matter what you do,
you can't do less than 𝑛 operations.

In the second testcase, you can type "labac" (5
 operations), then copy "aba" (1
 operation), finishing the string in 6
 operations.
*/
#include <iostream>
#include <set>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::set<std::string> dc;
    bool res(false);
    std::string last("");
    for (long p = 0; !res && p + 1 < s.size(); p++) {
      std::string u = s.substr(p, 2);
      if (dc.count(u) && last != u) {
        res = true;
      } else {
        dc.insert(u);
        last = (last != u) ? u : "";
      }
    }

    std::cout << (res ? "YES" : "NO") << std::endl;
  }
}

// sub: https://codeforces.com/problemset/submission/1766/332187365

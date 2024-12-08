// link: https://codeforces.com/problemset/problem/112/A
// rating: 800

/* A. Petya and Strings
time limit per test2 seconds
memory limit per test256 megabytes
Little Petya loves presents. His mum bought him two strings of the same size for
his birthday. The strings consist of uppercase and lowercase Latin letters. Now
Petya wants to compare those two strings lexicographically. The letters' case
does not matter, that is an uppercase letter is considered equivalent to the
corresponding lowercase letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. The strings' lengths range
from 1 to 100 inclusive. It is guaranteed that the strings are of the same
length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second
string is less than the first one, print "1". If the strings are equal, print
"0". Note that the letters' case is not taken into consideration when the
strings are compared.

Examples:

1.Input
aaaa
aaaA
Output
0

2. Input
abs
Abz
Output
-1

3. Input
abcdefg
AbCdEfF
Output
1

Note: If you want more formal information about the lexicographical order (also
known as the "dictionary order" or "alphabetical order"), you can visit the
following site: http://en.wikipedia.org/wiki/Lexicographical_order
*/

#include <algorithm>
#include <cctype> // For std::tolower
#include <iostream>
#include <string>
using namespace std;

/*take input as s1, s2 convert to lowercase well either lowercase or uppercase
   s1, s2 any char of s1<any char of s2 print - 1 any char of s1> any char of s2
            print 1 all char of s1 == s2 print 0

        so we can do such that bydeafualt we can return 0,
    but if any of the char goes up or down then we return -1 or 1*/

/* Wrong approach
int main() {
  string s1, s2;
  cin >> s1 >> s2;

  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

  // first of all compare length
  if (s1.size() < s2.size()) {
    cout << -1 << endl;
    return 0;
  } else if (s1.size() > s2.size()) {
    cout << 1 << endl;
    return 0;
  }

  // compare strings lexicographically
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i])
      cout << (s1[i] < s2[i] ? -1 : 1) << endl;
  }
  return 0;
}

*/

#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower
#include <iostream>

using namespace std;

// 1. take input of s1, s2
// convert both string to lowercase using std::tolower
// if s1<s2 print -1
// if s1>s2 print 1
// if s1=s2 print 0
// else print 0
int main() {
  string s1, s2;
  cin >> s1 >> s2;

  // Convert both strings to lowercase for case-insensitive comparison
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

  // Compare lexicographically
  if (s1 < s2) {
    cout << -1 << endl;
  } else if (s1 > s2) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}

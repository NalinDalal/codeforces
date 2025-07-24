/*A. Entertainment in MAC
time limit per test1 second
memory limit per test256 megabytes
Congratulations, you have been accepted to the Master's Assistance Center!
However, you were extremely bored in class and got tired of doing nothing, so
you came up with a game for yourself.

You are given a string 𝑠
 and an even integer 𝑛
. There are two types of operations that you can apply to it:

Add the reversed string 𝑠
 to the end of the string 𝑠
 (for example, if 𝑠=
 cpm, then after applying the operation 𝑠=
 cpmmpc).
Reverse the current string 𝑠
 (for example, if 𝑠=
 cpm, then after applying the operation 𝑠=
 mpc).
It is required to determine the lexicographically smallest†
 string that can be obtained after applying exactly 𝑛
 operations. Note that you can apply operations of different types in any order,
but you must apply exactly 𝑛 operations in total.

†
A string 𝑎
 is lexicographically smaller than a string 𝑏
 if and only if one of the following holds:

𝑎
 is a prefix of 𝑏
, but 𝑎≠𝑏
;
in the first position where 𝑎
 and 𝑏
 differ, the string 𝑎
 has a letter that appears earlier in the alphabet than the corresponding letter
in 𝑏
.
Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single even integer 𝑛
 (2≤𝑛≤109
) — the number of operations applied to the string 𝑠
.

The second line of each test case contains a single string 𝑠
 (1≤|𝑠|≤100
), consisting of lowercase English letters, — the string to which the operations
are applied.

Output
For each test case, output a single line — the lexicographically smallest string
that can be obtained after applying exactly 𝑛 operations.

Example
InputCopy
5
4
cpm
2
grib
10
kupitimilablodarbuz
1000000000
capybara
6
abacaba
OutputCopy
cpm
birggrib
kupitimilablodarbuz
arabypaccapybara
abacaba
Note
In the first test case, you can apply the operation of the second type (i.e.,
reverse the string 𝑠 ) 4 times. Then the string 𝑠 will remain equal to cpm.

In the second test case, you can do the following:

Apply the operation of the second type, after which 𝑠
 will become equal to birg.
Apply operation of the first type (i.e., add the reversed string 𝑠
 to the end of the string 𝑠
), after which 𝑠
 will become equal to birggrib.
*/

// 2 types of opr:
// s-> s+rev(s)
// or s-> rev(s)
// find lexicographically smallest string after n operations
// a is lexicographically smaller than b if
//   - a is prefix of b, but not equal
//   - say both diff at ith pos, then a[i]<b[i]
// 1. Try all possible sequences of n operations made up of both allowed types.
// 2. For each sequence, simulate and keep track of the minimum.

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*string sol(string s, int n) {
  set<string> curr;
  curr.insert(s);

  while (n--) {
    // apply operations n times
    set<string> next;
    for (auto str : curr) {
      string revStr = str;
      reverse(revStr.begin(), revStr.end());

      next.insert(revStr);       // operation 2
      next.insert(str + revStr); // operation 1
    }
    curr = move(next); // prune for next round
  }
  return *curr.begin(); // smallest lex string
}
*/

// if string is small, than reverse, so no need
// so chars also need tobe small with length
// if n is even, if s<rev(s)-> reverse it n times{remains same}
// if s>rev(s)->leave
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n; // n is even
    string s;
    cin >> s;
    std::string rev(s);
    std::reverse(rev.begin(), rev.end());
    std::string a(s), b(rev + s);
    std::cout << (a < b ? a : b) << std::endl;
  }
  return 0;
}

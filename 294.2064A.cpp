/* A. Brogramming Contest
time limit per test1 second
memory limit per test256 megabytes
One day after waking up, your friend challenged you to a brogramming contest. In
a brogramming contest, you are given a binary string∗ 𝑠 of length 𝑛 and an
initially empty binary string 𝑡 . During a brogramming contest, you can make
either of the following moves any number of times:

remove some suffix†
 from 𝑠
 and place it at the end of 𝑡
, or
remove some suffix from 𝑡
 and place it at the end of 𝑠
.
To win the brogramming contest, you must make the minimum number of moves
required to make 𝑠 contain only the character 𝟶 and 𝑡 contain only the character
𝟷 . Find the minimum number of moves required. ∗ A binary string is a string
consisting of characters 𝟶 and 𝟷
.

†
A string 𝑎
 is a suffix of a string 𝑏
 if 𝑎
 can be obtained from deletion of several (possibly, zero or all) elements from
the beginning of 𝑏
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤100
) — the number of test cases.

The first line of each test case is an integer 𝑛
 (1≤𝑛≤1000
) — the length of the string 𝑠
.

The second line of each test case contains the binary string 𝑠
.

The sum of 𝑛
 across all test cases does not exceed 1000
.

Output
For each testcase, output the minimum number of moves required.

Example
InputCopy
5
5
00110
4
1111
3
001
5
00000
3
101
OutputCopy
2
1
1
0
3
Note
An optimal solution to the first test case is as follows:

𝑠=𝟶𝟶𝟷𝟷𝟶
, 𝑡=
 empty string.
𝑠=𝟶𝟶
, 𝑡=𝟷𝟷𝟶
.
𝑠=𝟶𝟶𝟶
, 𝑡=𝟷𝟷
.
It can be proven that there is no solution using less than 2
 moves.

In the second test case, you have to move the whole string from 𝑠
 to 𝑡
 in one move.

In the fourth test case, you don't have to do any moves.


*/

// so basically, do like this:
// 1. from behind first occurrence of 0 in s, move till 1 is encountered, move
// it to t
// 2. then from behind first occurrence of 1 in s, move till 0 is encountered.
// collect it somewhere
// 3. then from behind 1st occurrence of 0 in s, move till 1 is encountered,
// move it to t
// repeat till all are sorted
// return total moves

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt(2 * (s[0] == '1') - (s.back() == '1'));
    for (int p = 1; p < n; p++) {
      cnt += 2 * (s[p - 1] == '0' && s[p] == '1');
    }
    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2064/315658128

/* B. Shifts and Sorting
time limit per test2 seconds
memory limit per test256 megabytes
Let's define a cyclic shift of some string 𝑠
 as a transformation from 𝑠1𝑠2…𝑠𝑛−1𝑠𝑛
 into 𝑠𝑛𝑠1𝑠2…𝑠𝑛−1
. In other words, you take one last character 𝑠𝑛
 and place it before the first character while moving all other characters to
the right.

You are given a binary string 𝑠
 (a string consisting of only 0-s and/or 1-s).

In one operation, you can choose any substring 𝑠𝑙𝑠𝑙+1…𝑠𝑟
 (1≤𝑙<𝑟≤|𝑠|
) and cyclically shift it. The cost of such operation is equal to 𝑟−𝑙+1
 (or the length of the chosen substring).

You can perform the given operation any number of times. What is the minimum
total cost to make 𝑠 sorted in non-descending order?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first and only line of each test case contains a binary string 𝑠
 (2≤|𝑠|≤2⋅105
; 𝑠𝑖∈
 {0, 1}) — the string you need to sort.

Additional constraint on the input: the sum of lengths of strings over all test
cases doesn't exceed 2⋅105
.

Output
For each test case, print the single integer — the minimum total cost to make
string sorted using operation above any number of times.

Example
InputCopy
5
10
0000
11000
101011
01101001
OutputCopy
2
0
9
5
11
Note
In the first test case, you can choose the whole string and perform a cyclic
shift: 10 → 01. The length of the substring is 2 , so the cost is 2
.

In the second test case, the string is already sorted, so you don't need to
perform any operations.

In the third test case, one of the optimal strategies is the next:

choose substring [1,3]
: 11000 →
 01100;
choose substring [2,4]
: 01100 →
 00110;
choose substring [3,5]
: 00110 →
 00011.
The total cost is 3+3+3=9
.*/

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    long long cnt(0), a(0);
    for (long p = 0; p < s.size(); p++) {
      if (s[p] == '0') {
        cnt += (a > 0) * (a + 1);
      } else {
        ++a;
      }
    }
    std::cout << cnt << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1969/323362588

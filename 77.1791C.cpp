/* https://codeforces.com/problemset/problem/1791/C

C. Prepend and Append
time limit per test1 second
memory limit per test256 megabytes
Timur initially had a binary string† 𝑠 (possibly of length 0). He performed the
following operation several (possibly zero) times:

Add 𝟶 to one end of the string and 𝟷 to the other end of the string. For
example, starting from the string 𝟷𝟶𝟷𝟷, you can obtain either 𝟶𝟷𝟶𝟷𝟷𝟷 or 𝟷𝟷𝟶𝟷𝟷𝟶
.
You are given Timur's final string. What is the length of the shortest possible
string he could have started with? † A binary string is a string (possibly the
empty string) whose characters are either 𝟶 or 𝟷.

Input
The first line of the input contains an integer 𝑡 (1≤𝑡≤100) — the number of
testcases.

The first line of each test case contains an integer 𝑛 (1≤𝑛≤2000) — the length
of Timur's final string.

The second line of each test case contains a string 𝑠 of length 𝑛 consisting of
characters 𝟶 or 𝟷, denoting the final string.

Output
For each test case, output a single nonnegative integer — the shortest possible
length of Timur's original string. Note that Timur's original string could have
been empty, in which case you should output 0.

Example
InputCopy
9
3
100
4
0111
5
10101
6
101010
7
1010110
1
1
2
10
2
11
10
1011011010
OutputCopy
1
2
5
0
3
1
0
2
4
Note
In the first test case, the shortest possible string Timur started with is 𝟶,
and he performed the following operation: 𝟶→𝟷𝟶𝟶.

In the second test case, the shortest possible string Timur started with is 𝟷𝟷,
and he performed the following operation: 𝟷𝟷→𝟶𝟷𝟷𝟷.

In the third test case, the shortest possible string Timur started with is
𝟷𝟶𝟷𝟶𝟷, and he didn't perform any operations.

In the fourth test case, the shortest possible string Timur started with is the
empty string (which we denote by 𝜀), and he performed the following operations:
𝜀→𝟷𝟶→𝟶𝟷𝟶𝟷→𝟷𝟶𝟷𝟶𝟷𝟶.

In the fifth test case, the shortest possible string Timur started with is 𝟷𝟶𝟷,
and he performed the following operations: 𝟷𝟶𝟷→𝟶𝟷𝟶𝟷𝟷→𝟷𝟶𝟷𝟶𝟷𝟷𝟶.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution() {
  int n;
  cin >> n; // length of string
  string s;
  cin >> s;
  /* if (s.empty()) {
     return 0;
   }

   // i think we need to remove the first 2 and last 2 character of the string
   // return the shortest length of the original string
   string s1(s.substr(2, s.size() - 4));
   return s1.size();*/

  int l = 0, r = n - 1;
  // Remove matching pairs from the ends
  while (l < r &&
         ((s[l] == '0' && s[r] == '1') || (s[l] == '1' && s[r] == '0'))) {
    l++;
    r--;
  }
  // Length of the remaining core
  int ans = r - l + 1;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1791/301281581

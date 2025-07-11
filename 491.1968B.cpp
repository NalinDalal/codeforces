/*B. Prefiquence
time limit per test2 seconds
memory limit per test256 megabytes
You are given two binary strings 𝑎
 and 𝑏
. A binary string is a string consisting of the characters '0' and '1'.

Your task is to determine the maximum possible number 𝑘
 such that a prefix of string 𝑎
 of length 𝑘
 is a subsequence of string 𝑏
.

A sequence 𝑎
 is a subsequence of a sequence 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) elements.

Input
The first line consists of a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤2⋅105
) — the length of string 𝑎
 and the length of string 𝑏
, respectively.

The second line of each test case contains a binary string 𝑎
 of length 𝑛
.

The third line of each test case contains a binary string 𝑏
 of length 𝑚
.

It is guaranteed that the sum of values 𝑛
 over all test cases does not exceed 2⋅105
. Similarly, the sum of values 𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single number — the maximum 𝑘
, such that the first 𝑘
 characters of 𝑎
 form a subsequence of 𝑏
.

Example
InputCopy
6
5 4
10011
1110
3 3
100
110
1 3
1
111
4 4
1011
1111
3 5
100
11010
3 1
100
0
OutputCopy
2
2
1
1
3
0
Note
In the first example, the string '10
' is a subsequence of '1110
' but the string '100
' is not. So the answer is 2
.

In the fifth example, 𝑎
='100
', 𝑏
='11010
', whole string 𝑎
 is a subsequence of string 𝑏
. So the answer is 3
.

In the sixth example, string 𝑏
 does not contain '1
' so the answer is 0
.



*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, m;
    std::cin >> n >> m;
    std::string a, b;
    std::cin >> a >> b;
    long idx = 0, cnt = 0;
    for (long p = 0; p < b.size(); p++) {
      if (b[p] == a[idx]) {
        ++cnt;
        ++idx;
      }
      if (idx >= a.size()) {
        break;
      }
    }

    std::cout << cnt << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1968/328556859

/*B. Square or Not
time limit per test2 seconds
memory limit per test256 megabytes
A beautiful binary matrix is a matrix that has ones on its edges and zeros
inside.

Examples of four beautiful binary matrices.
Today, Sakurako was playing with a beautiful binary matrix of size 𝑟×𝑐
 and created a binary string 𝑠
 by writing down all the rows of the matrix, starting from the first and ending
with the 𝑟 -th. More formally, the element from the matrix in the 𝑖 -th row and
𝑗 -th column corresponds to the ((𝑖−1)∗𝑐+𝑗) -th element of the string.

You need to check whether the beautiful matrix from which the string 𝑠
 was obtained could be squared. In other words, you need to check whether the
string 𝑠 could have been build from a square beautiful binary matrix (i.e., one
where 𝑟=𝑐
).

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the string.

The second line of each test case contains the string 𝑠
 of length 𝑛
. The string is always the result of writing out the strings of a beautiful
matrix.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
Print "Yes", if the original matrix could have been square, and "No" otherwise.

Example
InputCopy
5
2
11
4
1111
9
111101111
9
111111111
12
111110011111
OutputCopy
No
Yes
Yes
No
No
Note
For the second test case, string 1111 can be obtained from the matrix:

1
1
1
1
For the third test case, string 111101111 can be obtained from the matrix:

1
1
1
1
0
1
1
1
1
There is no square matrix in the fourth case, such that the string can be
obtained from it.



*/

#include <iostream>
#include <map>

int main() {

  std::map<long, long> msqrt;
  for (long p = 1; p <= 1000; p++) {
    msqrt[p * p] = p;
  }

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (!msqrt.count(s.size())) {
      std::cout << "No" << std::endl;
      continue;
    }

    long sz = msqrt[s.size()];
    bool possible(true);
    for (long row = 0; possible && row < sz; row++) {
      for (long col = 0; possible && col < sz; col++) {
        bool digit = (s[row * sz + col] == '1');
        bool edge = (row == 0 || row == sz - 1 || col == 0 || col == sz - 1);
        if (edge ^ digit) {
          possible = false;
        }
      }
    }

    std::cout << (possible ? "Yes" : "No") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2008/325104807

/*B. Fibonacci Cubes
time limit per test2 seconds
memory limit per test512 megabytes
There are 𝑛
 Fibonacci cubes, where the side of the 𝑖
-th cube is equal to 𝑓𝑖
, where 𝑓𝑖
 is the 𝑖
-th Fibonacci number.

In this problem, the Fibonacci numbers are defined as follows:

𝑓1=1
𝑓2=2
𝑓𝑖=𝑓𝑖−1+𝑓𝑖−2
 for 𝑖>2
There are also 𝑚
 empty boxes, where the 𝑖
-th box has a width of 𝑤𝑖
, a length of 𝑙𝑖
, and a height of ℎ𝑖
.

For each of the 𝑚
 boxes, you need to determine whether all the cubes can fit inside that box. The
cubes must be placed in the box following these rules:

The cubes can only be stacked in the box such that the sides of the cubes are
parallel to the sides of the box; Every cube must be placed either on the bottom
of the box or on top of other cubes in such a way that all space below the cube
is occupied; A larger cube cannot be placed on top of a smaller cube. Input Each
test consists of several test cases. The first line contains a single integer 𝑡
 (1≤𝑡≤103
) — the number of test cases. The description of the test cases follows.

In the first line of each test case, there are two integers 𝑛
 and 𝑚
 (2≤𝑛≤10,1≤𝑚≤2⋅105
) — the number of cubes and the number of empty boxes.

The next 𝑚
 lines of each test case contain 3
 integers 𝑤𝑖
, 𝑙𝑖
, and ℎ𝑖
 (1≤𝑤𝑖,𝑙𝑖,ℎ𝑖≤150
) — the dimensions of the 𝑖
-th box.

Additional constraints on the input:

The sum of 𝑚
 across all test cases does not exceed 2⋅105
.
Output
For each test case, output a string of length 𝑚
, where the 𝑖
-th character is equal to "1" if all 𝑛
 cubes can fit into the 𝑖
-th box; otherwise, the 𝑖
-th character is equal to "0".

Example
InputCopy
2
5 4
3 1 2
10 10 10
9 8 13
14 7 20
2 6
3 3 3
1 2 1
2 1 2
3 2 2
2 3 1
3 2 4
OutputCopy
0010
100101
Note
In the first test case, only one box is suitable. The cubes can be placed in it
as follows:

*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, m;
    std::cin >> n >> m;
    long f(1), g(1);
    for (long p = 2; p <= n + 1; p++) {
      long x = f;
      f = g;
      g += x;
    }
    std::string s(m, '0');
    for (long p = 0; p < m; p++) {
      long a, b, c;
      std::cin >> a >> b >> c;
      long d = (a > b ? a : b);
      d = (d > c ? d : c);
      s[p] += (a >= f && b >= f && c >= f && d >= g);
    }

    std::cout << s << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2111/324438660

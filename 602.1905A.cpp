/*A. Constructive Problems
time limit per test1 second
memory limit per test256 megabytes
Gridlandia has been hit by flooding and now has to reconstruct all of it's
cities. Gridlandia can be described by an 𝑛×𝑚 matrix.

Initially, all of its cities are in economic collapse. The government can choose
to rebuild certain cities. Additionally, any collapsed city which has at least
one vertically neighboring rebuilt city and at least one horizontally
neighboring rebuilt city can ask for aid from them and become rebuilt without
help from the government. More formally, collapsed city positioned in (𝑖,𝑗) can
become rebuilt if both of the following conditions are satisfied:

At least one of cities with positions (𝑖+1,𝑗)
 and (𝑖−1,𝑗)
 is rebuilt;
At least one of cities with positions (𝑖,𝑗+1)
 and (𝑖,𝑗−1)
 is rebuilt.
If the city is located on the border of the matrix and has only one horizontally
or vertically neighbouring city, then we consider only that city.


Illustration of two possible ways cities can be rebuilt by adjacent aid. White
cells are collapsed cities, yellow cells are initially rebuilt cities (either by
the government or adjacent aid), and orange cells are rebuilt cities after
adjacent aid. The government wants to know the minimum number of cities it has
to rebuild such that after some time all the cities can be rebuild.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The only line of each test case contains two integers 𝑛
 and 𝑚
 (2≤𝑛,𝑚≤100
) — the sizes of Gridlandia.

Output
For each test case, output a single integer — the minimum number of cities the
government needs to rebuild.

Example
InputCopy
3
2 2
5 7
3 2
OutputCopy
2
7
3
Note
In the first test case, it's enough for the government to rebuild cities (1,2)
 and (2,1)
.

In the second test case, it's enough for the government to rebuild cities (1,4)
, (2,2)
, (3,1)
, (3,6)
, (4,3)
, (5,5)
, (5,7)
.
*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::cout << (n > m ? n : m) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1905/334210351

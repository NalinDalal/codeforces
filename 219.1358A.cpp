/*A. Park Lighting
time limit per test2 seconds
memory limit per test256 megabytes
Due to the coronavirus pandemic, city authorities obligated citizens to keep a
social distance. The mayor of the city Semyon wants to light up Gluharniki park
so that people could see each other even at night to keep the social distance.

The park is a rectangular table with 𝑛 rows and 𝑚 columns, where the cells of
the table are squares, and the boundaries between the cells are streets.
External borders are also streets. Every street has length 1. For example, park
with 𝑛=𝑚=2 has 12 streets.

You were assigned to develop a plan for lighting the park. You can put lanterns
in the middle of the streets. The lamp lights two squares near it (or only one
square if it stands on the border of the park).

The park sizes are: 𝑛=4, 𝑚=5. The lighted squares are marked yellow. Please note
that all streets have length 1. Lanterns are placed in the middle of the
streets. In the picture not all the squares are lit. Semyon wants to spend the
least possible amount of money on lighting but also wants people throughout the
park to keep a social distance. So he asks you to find the minimum number of
lanterns that are required to light all the squares.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases
in the input. Then 𝑡 test cases follow.

Each test case is a line containing two integers 𝑛, 𝑚 (1≤𝑛,𝑚≤104) — park sizes.

Output
Print 𝑡 answers to the test cases. Each answer must be a single integer — the
minimum number of lanterns that are required to light all the squares.

Example
InputCopy
5
1 1
1 3
2 2
3 3
5 3
OutputCopy
1
2
2
5
8
Note
Possible optimal arrangement of the lanterns for the 2-nd test case of input
data example:

Possible optimal arrangement of the lanterns for the 3-rd test case of input
data example:


*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int result = (n * m + 1) / 2;
    cout << result << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1358/310368511

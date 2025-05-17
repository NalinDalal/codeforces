/* A. Shape Perimeter
time limit per test1 second
memory limit per test256 megabytes
There is an 𝑚
 by 𝑚
 square stamp on an infinite piece of paper. Initially, the bottom-left corner
of the square stamp is aligned with the bottom-left corner of the paper. You are
given two integer sequences 𝑥 and 𝑦 , each of length 𝑛 . For each step 𝑖 from 1
 to 𝑛
, the following happens:

Move the stamp 𝑥𝑖
 units to the right and 𝑦𝑖
 units upwards.
Press the stamp onto the paper, leaving an 𝑚
 by 𝑚
 colored square at its current position.
Note that the elements of sequences 𝑥
 and 𝑦
 have a special constraint: 1≤𝑥𝑖,𝑦𝑖≤𝑚−1
.

Note that you do not press the stamp at the bottom-left corner of the paper.
Refer to the notes section for better understanding.

It can be proven that after all the operations, the colored shape on the paper
formed by the stamp is a single connected region. Find the perimeter of this
colored shape.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛≤100
, 2≤𝑚≤100
) — the number of operations performed and the side length of the square stamp.

The 𝑖
-th of the next 𝑛
 lines contains two integers 𝑥𝑖
 and 𝑦𝑖
 (1≤𝑥𝑖,𝑦𝑖≤𝑚−1
) — the distance that the stamp will be moved right and up during the 𝑖
-th operation, respectively.

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, output a single integer representing the perimeter of the
colored shape on the paper.

Example
InputCopy
3
4 3
1 1
2 2
2 1
1 2
1 2
1 1
6 7
3 6
1 1
3 1
6 6
5 4
6 1
OutputCopy
32
8
96
Note
In the first example, the stamp has a side length of 3
 and is pressed 4
 times at coordinates (1,1)
, (3,3)
, (5,4)
, and (6,6)
. The piece of paper looks like that afterwards:



Here, the square formed by the first press is colored blue, the second red, the
third green, and the fourth purple. The combined shape, whose perimeter we need
to calculate, looks like that:



From the diagram, it can be seen that this shape has a perimeter of 32
.
*/
/*
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int total = 4 * m;
    while (n--) {
      cin >> x >> y;
      total += 2 * (x + y);
    }
    cout << total << endl;
  }
  return 0;
}*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n, m;
    scanf("%ld %ld", &n, &m);
    long x, y;
    scanf("%ld %ld", &x, &y);
    long total(4 * m);
    while (--n) {
      scanf("%ld %ld", &x, &y);
      total += 2 * (x + y);
    }

    printf("%ld\n", total);
  }
}
// sub: https://codeforces.com/problemset/submission/2056/319988740

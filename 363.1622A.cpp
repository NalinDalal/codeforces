/*A. Construct a Rectangle
time limit per test2 seconds
memory limit per test256 megabytes
There are three sticks with integer lengths 𝑙1,𝑙2
 and 𝑙3
.

You are asked to break exactly one of them into two pieces in such a way that:

both pieces have positive (strictly greater than 0
) integer length;
the total length of the pieces is equal to the original length of the stick;
it's possible to construct a rectangle from the resulting four sticks such that
each stick is used as exactly one of its sides. A square is also considered a
rectangle.

Determine if it's possible to do that.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The only line of each testcase contains three integers 𝑙1,𝑙2,𝑙3
 (1≤𝑙𝑖≤108
) — the lengths of the sticks.

Output
For each testcase, print "YES" if it's possible to break one of the sticks into
two pieces with positive integer length in such a way that it's possible to
construct a rectangle from the resulting four sticks. Otherwise, print "NO".

You may print every letter in any case you want (so, for example, the strings
yEs, yes, Yes and YES are all recognized as a positive answer).

Example
InputCopy
4
6 1 5
2 5 2
2 4 2
5 5 4
OutputCopy
YES
NO
YES
YES
Note
In the first testcase, the first stick can be broken into parts of length 1
 and 5
. We can construct a rectangle with opposite sides of length 1
 and 5
.

In the second testcase, breaking the stick of length 2
 can only result in sticks of lengths 1,1,2,5
, which can't be made into a rectangle. Breaking the stick of length 5
 can produce results 2,3
 or 1,4
 but neither of them can't be put into a rectangle.

In the third testcase, the second stick can be broken into parts of length 2
 and 2
. The resulting rectangle has opposite sides 2
 and 2
 (which is a square).

In the fourth testcase, the third stick can be broken into parts of length 2
 and 2
. The resulting rectangle has opposite sides 2
 and 5
.


*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    bool res = false;
    if (a == b + c || b == a + c || c == a + b) {
      res = true;
    }
    if ((a % 2 == 0 && b == c) || (b % 2 == 0 && a == c) ||
        (c % 2 == 0 && a == b)) {
      res = true;
    }
    cout << (res ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1622/320752207

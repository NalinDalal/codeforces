/* A. C+=
time limit per test2 seconds
memory limit per test512 megabytes
Leo has developed a new programming language C+=. In C+=, integer variables can
only be changed with a "+=" operation that adds the right-hand side value to the
left-hand side variable. For example, performing "a += b" when a = 2 , b = 3
 changes the value of a to 5
 (the value of b does not change).

In a prototype program Leo has two integer variables a and b, initialized with
some positive values. He can perform any number of operations "a += b" or "b +=
a". Leo wants to test handling large integers, so he wants to make the value of
either a or b strictly greater than a given value 𝑛 . What is the smallest
number of operations he has to perform?

Input
The first line contains a single integer 𝑇
 (1≤𝑇≤100
) — the number of test cases.

Each of the following 𝑇
 lines describes a single test case, and contains three integers 𝑎,𝑏,𝑛
 (1≤𝑎,𝑏≤𝑛≤109
) — initial values of a and b, and the value one of the variables has to exceed,
respectively.

Output
For each test case print a single integer — the smallest number of operations
needed. Separate answers with line breaks.

Example
InputCopy
2
1 2 3
5 4 100
OutputCopy
2
7
Note
In the first case we cannot make a variable exceed 3
 in one operation. One way of achieving this in two operations is to perform "b
+= a" twice.


*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    // operation: "a+=b" equals "a=a+b"
    // no of operation to make either a or b grater than n
    while (a <= n && b <= n) {
      if (a < b) {
        a += b;

      } else {
        b += a;
      }
      ans++;
    }

    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1368/310225383

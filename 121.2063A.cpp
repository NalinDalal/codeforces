/* https://codeforces.com/problemset/problem/2063/A

A. Minimal Coprime
time limit per test1 second
memory limit per test256 megabytes
Today, Little John used all his savings to buy a segment. He wants to build a
house on this segment. A segment of positive integers [𝑙,𝑟] is called coprime if
𝑙 and 𝑟 are coprime∗.

A coprime segment [𝑙,𝑟] is called minimal coprime if it does not contain† any
coprime segment not equal to itself. To better understand this statement, you
can refer to the notes.

Given [𝑙,𝑟], a segment of positive integers, find the number of minimal coprime
segments contained in [𝑙,𝑟].

∗Two integers 𝑎 and 𝑏 are coprime if they share only one positive common
divisor. For example, the numbers 2 and 4 are not coprime because they are both
divided by 2 and 1, but the numbers 7 and 9 are coprime because their only
positive common divisor is 1.

†
A segment [𝑙′,𝑟′] is contained in the segment [𝑙,𝑟] if and only if 𝑙≤𝑙′≤𝑟′≤𝑟.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤100). The description of the test cases follows.

The only line of each test case consists of two integers 𝑙 and 𝑟 (1≤𝑙≤𝑟≤109).

Output
For each test case, output the number of minimal coprime segments contained in
[𝑙,𝑟], on a separate line.

Example
InputCopy
6
1 2
1 10
49 49
69 420
1 1
9982 44353
OutputCopy
1
9
0
351
1
34371
Note
On the first test case, the given segment is [1,2]. The segments contained in
[1,2] are as follows. [1,1]: This segment is coprime, since the numbers 1 and 1
are coprime, and this segment does not contain any other segment inside. Thus,
[1,1] is minimal coprime. [1,2]: This segment is coprime. However, as it
contains [1,1], which is also coprime, [1,2] is not minimal coprime. [2,2]: This
segment is not coprime because 2 and 2 share 2 positive common divisors: 1
and 2. Therefore, the segment [1,2] contains 1 minimal coprime segment.


*/
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    // printf("%ld\n", b - a + (a == b && a == 1));
    cout << (r - l + (l == r && l == 1)) << endl;
    // return number of minimal coprime segments b/w l and r inclusive
    // coprime condition: gcd(l,r)=1
    //[l1,r1] is minimal coprime if l<=l1<=r1<=r

    // Iterate over all possible pairs (l1, r1) where l <= l1 <= r1 <= r
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2063/305502400

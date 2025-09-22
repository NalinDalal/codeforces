/*E. Triple Operations
time limit per test1 second
memory limit per test256 megabytes
On the board Ivy wrote down all integers from 𝑙
 to 𝑟
, inclusive.

In an operation, she does the following:

pick two numbers 𝑥
 and 𝑦
 on the board, erase them, and in their place write the numbers 3𝑥
 and ⌊𝑦3⌋
. (Here ⌊∙⌋
 denotes rounding down to the nearest integer).
What is the minimum number of operations Ivy needs to make all numbers on the
board equal 0 ? We have a proof that this is always possible.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The only line of each test case contains two integers 𝑙
 and 𝑟
 (1≤𝑙<𝑟≤2⋅105
).

Output
For each test case, output a single integer — the minimum number of operations
needed to make all numbers on the board equal 0
.

Example
InputCopy
4
1 3
2 4
199999 200000
19 84
OutputCopy
5
6
36
263
Note
In the first test case, we can perform 5
 operations as follows:
1,2,3−→−−−−−𝑥=1,𝑦=23,0,3−→−−−−−𝑥=0,𝑦=31,0,3−→−−−−−𝑥=0,𝑦=31,0,1−→−−−−−𝑥=0,𝑦=10,0,1−→−−−−−𝑥=0,𝑦=10,0,0.
*/

/*algo:
(t--){
x,y
write from x to y inclusive

then do as asked
choose x,y;
x=3*x
y=round(y/3)
}
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<long> v(200007); // same as 2e5 + 7

  for (long p = 1; p < (long)v.size(); p++) {
    v[p] = 1 + v[p / 3];
  }
  for (long p = 1; p < (long)v.size(); p++) {
    v[p] += v[p - 1];
  }

  long t;
  cin >> t;
  while (t--) {
    long a, b;
    cin >> a >> b;
    long res = v[b] - 2 * v[a - 1] + v[a];
    cout << res << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1999/339825601

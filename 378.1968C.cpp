/* C. Assembly via Remainders
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑥2,𝑥3,…,𝑥𝑛
. Your task is to find any array 𝑎1,…,𝑎𝑛
, where:

1≤𝑎𝑖≤109
 for all 1≤𝑖≤𝑛
.
𝑥𝑖=𝑎𝑖mod𝑎𝑖−1
 for all 2≤𝑖≤𝑛
.
Here 𝑐mod𝑑
 denotes the remainder of the division of the integer 𝑐
 by the integer 𝑑
. For example 5mod2=1
, 72mod3=0
, 143mod14=3
.

Note that if there is more than one 𝑎
 which satisfies the statement, you are allowed to find any.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤500)
 — the number of elements in 𝑎
.

The second line of each test case contains 𝑛−1
 integers 𝑥2,…,𝑥𝑛
 (1≤𝑥𝑖≤500)
 — the elements of 𝑥
.

It is guaranteed that the sum of values 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case output any 𝑎1,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) which satisfies the statement.

Example
InputCopy
5
4
2 4 1
3
1 1
6
4 2 5 1 2
2
500
3
1 5
OutputCopy
3 5 4 9
2 5 11
5 14 16 5 11 24
501 500
2 7 5
Note
In the first test case 𝑎=[3,5,4,9]
 satisfies the conditions, because:

𝑎2mod𝑎1=5mod3=2=𝑥2
;
𝑎3mod𝑎2=4mod5=4=𝑥3
;
𝑎4mod𝑎3=9mod4=1=𝑥4
;

*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long x;
    cin >> x;

    long a = 1501;
    cout << a - x << " " << a << " ";

    for (long p = 2; p < n; ++p) {
      cin >> x;
      a += x;
      cout << a << " ";
    }
    cout << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1968/321857774

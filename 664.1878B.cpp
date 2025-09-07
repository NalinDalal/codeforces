/*B. Aleksa and Stack
time limit per test2 seconds
memory limit per test256 megabytes
After the Serbian Informatics Olympiad, Aleksa was very sad, because he didn't
win a medal (he didn't know stack), so Vasilije came to give him an easy
problem, just to make his day better.

Vasilije gave Aleksa a positive integer 𝑛
 (𝑛≥3
) and asked him to construct a strictly increasing array of size 𝑛
 of positive integers, such that

3⋅𝑎𝑖+2
 is not divisible by 𝑎𝑖+𝑎𝑖+1
 for each 𝑖
 (1≤𝑖≤𝑛−2
).
Note that a strictly increasing array 𝑎
 of size 𝑛
 is an array where 𝑎𝑖<𝑎𝑖+1
 for each 𝑖
 (1≤𝑖≤𝑛−1
).
Since Aleksa thinks he is a bad programmer now, he asked you to help him find
such an array.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of test cases
follows.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤2⋅105
) — the number of elements in array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers 𝑎1,𝑎2,𝑎3,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

It can be proved that the solution exists for any 𝑛
. If there are multiple solutions, output any of them.

Example
InputCopy
3
3
6
7
OutputCopy
6 8 12
7 11 14 20 22 100
9 15 18 27 36 90 120
Note
In the first test case, 𝑎1=6
, 𝑎2=8
, 𝑎3=12
, so 𝑎1+𝑎2=14
 and 3⋅𝑎3=36
, so 3⋅𝑎3
 is not divisible by 𝑎1+𝑎2
.
*/

// 3*a[i+2] must not be divisible by a[i]+a[i+1]
// a[i]<a[i+1] for 1<=i<=n-1
// return element of array
#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    for (long p = 0; p < n; p++) {
      cout << (2 * p + 1) << " ";
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1878/337210576

/*A. Bazoka and Mocha's Array
time limit per test1 second
memory limit per test256 megabytes
Mocha likes arrays, so before her departure, Bazoka gave her an array 𝑎
 consisting of 𝑛
 positive integers as a gift.

Now Mocha wants to know whether array 𝑎
 could become sorted in non-decreasing order after performing the following
operation some (possibly, zero) times:

Split the array into two parts — a prefix and a suffix, then swap these two
parts. In other words, let 𝑎=𝑥+𝑦 . Then, we can set 𝑎:=𝑦+𝑥 . Here + denotes the
array concatenation operation. For example, if 𝑎=[3,1,4,1,5] , we can choose
𝑥=[3,1] and 𝑦=[4,1,5] , satisfying 𝑎=𝑥+𝑦 . Then, we can set 𝑎:=𝑦+𝑥=[4,1,5,3,1]
. We can also choose 𝑥=[3,1,4,1,5]
 and 𝑦=[]
, satisfying 𝑎=𝑥+𝑦
. Then, we can set 𝑎:=𝑦+𝑥=[3,1,4,1,5]
. Note that we are not allowed to choose 𝑥=[3,1,1]
 and 𝑦=[4,5]
, neither are we allowed to choose 𝑥=[1,3]
 and 𝑦=[5,1,4]
, as both these choices do not satisfy 𝑎=𝑥+𝑦
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤1000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤50
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
) — the elements of array 𝑎
.

Output
For each test case, output "Yes" if 𝑎
 could become non-decreasing after performing the operation any number of times,
and output "No" if not.

You can output "Yes" and "No" in any case (for example, strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive response).

Example
InputCopy
3
6
1 1 4 5 1 4
5
7 9 2 2 3
3
1 2 3
OutputCopy
No
Yes
Yes
Note
In the first test case, it can be proven that 𝑎
 cannot become non-decreasing after performing the operation any number of
times.

In the second test case, we can perform the following operations to make 𝑎
 sorted in non-decreasing order:

Split the array into two parts: 𝑥=[7]
 and 𝑦=[9,2,2,3]
, then swap these two parts. The array will become 𝑦+𝑥=[9,2,2,3,7]
.
Split the array into two parts: 𝑥=[9]
 and 𝑦=[2,2,3,7]
, then swap these two parts. The array will become 𝑦+𝑥=[2,2,3,7,9]
, which is non-decreasing.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    vector<long> v(n);
    for (long p = 0; p < n; p++) {
      cin >> v[p];
    }
    long idx(0);
    for (long p = 1; p < n; p++) {
      if (v[p - 1] > v[p]) {
        idx = p;
      }
    }
    long prev = v[idx];
    bool ans(true);
    for (long p = 1; ans && p < n; p++) {
      long q = (p + idx) % n;
      if (prev > v[q]) {
        ans = false;
      }
      prev = v[q];
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1975/329287813

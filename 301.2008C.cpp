/*C. Longest Good Array
time limit per test2 seconds
memory limit per test256 megabytes
Today, Sakurako was studying arrays. An array 𝑎
 of length 𝑛
 is considered good if and only if:

the array 𝑎
 is increasing, meaning 𝑎𝑖−1<𝑎𝑖
 for all 2≤𝑖≤𝑛
;
the differences between adjacent elements are increasing, meaning
𝑎𝑖−𝑎𝑖−1<𝑎𝑖+1−𝑎𝑖 for all 2≤𝑖<𝑛
.
Sakurako has come up with boundaries 𝑙
 and 𝑟
 and wants to construct a good array of maximum length, where 𝑙≤𝑎𝑖≤𝑟
 for all 𝑎𝑖
.

Help Sakurako find the maximum length of a good array for the given 𝑙
 and 𝑟
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The only line of each test case contains two integers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤109
).

Output
For each test case, output a single integer  — the length of the longest good
array Sakurako can form given 𝑙 and 𝑟
.

Example
InputCopy
5
1 2
1 5
2 2
10 20
1 1000000000
OutputCopy
2
3
1
5
44721
Note
For 𝑙=1
 and 𝑟=5
, one possible array could be (1,2,5)
. It can be proven that an array of length 4
 does not exist for the given 𝑙
 and 𝑟
.

For 𝑙=2
 and 𝑟=2
, the only possible array is (2)
.

For 𝑙=10
 and 𝑟=20
, the only possible array is (10,11,13,16,20).*/
#include <cstdio>
typedef long long ll;

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll dist = b - a;
    ll left(1), right(dist + 7), res(1);
    while (left <= right) {
      ll mid = (left + right) / 2;
      ll tst = mid * (mid - 1) / 2;
      if (tst <= dist) {
        res = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    printf("%lld\n", res);
  }
}
// sub: https://codeforces.com/problemset/submission/2008/316178731

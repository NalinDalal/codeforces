/* D. Array and GCD
time limit per test2 seconds
memory limit per test512 megabytes
You are given an integer array 𝑎
 of size 𝑛
.

You can perform the following operations any number of times (possibly, zero):

pay one coin and increase any element of the array by 1
 (you must have at least 1
 coin to perform this operation);
gain one coin and decrease any element of the array by 1
.
Let's say that an array is ideal if both of the following conditions hold:

each element of the array is at least 2
;
for each pair of indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤𝑛
; 𝑖≠𝑗
) the greatest common divisor (GCD) of 𝑎𝑖
 and 𝑎𝑗
 is equal to 1
. If the array has less than 2
 elements, this condition is automatically satisfied.
Let's say that an array is beautiful if it can be transformed into an ideal
array using the aforementioned operations, provided that you initially have no
coins. If the array is already ideal, then it is also beautiful.

The given array is not necessarily beautiful or ideal. You can remove any
elements from it (including removing the entire array or not removing anything
at all). Your task is to calculate the minimum number of elements you have to
remove (possibly, zero) from the array 𝑎 to make it beautiful.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤4⋅105
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (2≤𝑎𝑖≤109
).

Additional constraint on the input: the sum of 𝑛
 over all test cases doesn't exceed 4⋅105
.

Output
For each test case, print a single integer — the minimum number of elements you
have to remove (possibly, zero) from the array 𝑎 to make it beautiful.

Example
InputCopy
5
3
5 5 5
4
2 3 2 4
1
3
3
2 100 2
5
2 4 2 11 2
OutputCopy
0
2
0
0
1
Note
In the first example, you don't need to delete any elements, because the array
is already beautiful. It can be transformed into an ideal array as follows:
[5,5,5]→[4,5,5]→[4,4,5]→[4,3,5] (you end up with 3 coins).

In the second example, you need to remove 2
 elements so that the array becomes beautiful. If you leave the elements [2,3]
 and delete the other elements, then the given array is already ideal (and
therefore, beautiful).

In the third example, you don't need to delete any elements because the array is
already ideal (and thus, beautiful).

In the fourth example, the array is beautiful. It can be transformed into an
ideal array as follows: [2,100,2]→[2,99,2]→[2,99,3]→[2,98,3]→[2,97,3] (you end
up with 2 coins).


*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll B = 7e6;
  vector<bool> zb(B, true);
  zb[0] = zb[1] = false;
  for (ll p = 2; p * p < B; ++p) {
    if (!zb[p])
      continue;
    for (ll q = p * 2; q < B; q += p) {
      zb[q] = false;
    }
  }

  vector<ll> w(1, 0);
  for (ll p = 0; p < B; ++p) {
    if (!zb[p])
      continue;
    w.push_back(w.back() + p);
  }

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    for (ll i = 1; i < n; ++i) {
      v[i] += v[i - 1];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
      if (v[i] < w[i + 1]) {
        ans = n - i;
        break;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2104/318069611

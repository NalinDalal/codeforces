/*B. Make Equal
time limit per test2 seconds
memory limit per test256 megabytes
There are 𝑛
 containers of water lined up, numbered from left to right from 1
 to 𝑛
. Each container can hold any amount of water; initially, the 𝑖
-th container contains 𝑎𝑖
 units of water. The sum of 𝑎𝑖
 is divisible by 𝑛
.

You can apply the following operation any (possibly zero) number of times: pour
any amount of water from the 𝑖 -th container to the 𝑗 -th container, where 𝑖
 must be less than 𝑗
 (i.e. 𝑖<𝑗
). Any index can be chosen as 𝑖
 or 𝑗
 any number of times.

Determine whether it is possible to make the amount of water in all containers
the same using this operation.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of containers with water.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the amounts of water in the containers. It is guaranteed that the sum of 𝑎𝑖
 in each test case does not exceed 2⋅109
. Also, the sum of 𝑎𝑖
 is divisible by 𝑛
.

It is guaranteed that the sum of 𝑛
 over all test cases in the input does not exceed 2⋅105
.

Output
Output 𝑡
 lines, each of which is the answer to the corresponding test case. As the
answer, output "YES" if it is possible to make the amount of water in all
containers the same using the described operation. Otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
6
1
43
2
1 3
5
4 5 2 1 3
3
1 2 3
7
4 5 5 0 6 4 4
7
6 5 5 1 3 4 4
OutputCopy
YES
NO
YES
NO
NO
YES
Note
In the third test case of the example (𝑎=[4,5,2,1,3]
), you can proceed as follows:

pour 1
 unit of water from the first vessel to the fourth, then 𝑎=[3,5,2,2,3]
;
pour 1
 unit of water from the second vessel to the third, then 𝑎=[3,4,3,2,3]
;
pour 1
 unit of water from the second vessel to the fourth, then 𝑎=[3,3,3,3,3]
.
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    for (ll p = 0; p < n; p++) {
      cin >> a[p];
      s += a[p];
    }

    ll g = s / n;
    bool possible = true;
    ll cur = 0;
    for (ll p = 0; possible && p < n; p++) {
      cur += (a[p] - g);
      if (cur < 0)
        possible = false;
    }

    cout << (possible ? "YES\n" : "NO\n");
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1931/337901982

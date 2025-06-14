/*B. Perfecto
time limit per test1.5 seconds
memory limit per test256 megabytes

A permutation 𝑝
 of length 𝑛
∗
 is perfect if, for each index 𝑖
 (1≤𝑖≤𝑛
), it satisfies the following:

The sum of the first 𝑖
 elements 𝑝1+𝑝2+…+𝑝𝑖
 is not a perfect square†
.
You would like things to be perfect. Given a positive integer 𝑛
, find a perfect permutation of length 𝑛
, or print −1
 if none exists.

∗
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

†
A perfect square is an integer that is the square of an integer, e.g., 9=32
 is a perfect square, but 8
 and 14
 are not.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first and only line of each test case contains a single integer 𝑛
 (1≤𝑛≤5⋅105
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 106
.

Output
For each test case:

If no solution exists, print a single integer −1
.
Otherwise, print 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 — the perfect permutation you find.
If there are multiple solutions, print any of them.

Example
InputCopy
3
1
4
5
OutputCopy
-1
2 4 1 3
5 1 4 3 2
Note
In the first test case, there is only one permutation with length 𝑛=1
 that is 𝑝=[1]
, which is [48;52;178;1768;2848tnot perfect:

𝑝1=1=𝑥2
 for 𝑥=1
.
In the second test case, one possible perfect permutation with length 𝑛=4
 is 𝑝=[2,4,1,3]
:

𝑝1=2≠𝑥2
;
𝑝1+𝑝2=2+4=6≠𝑥2
;
𝑝1+𝑝2+𝑝3=2+4+1=7≠𝑥2
;
𝑝1+𝑝2+𝑝3+𝑝4=2+4+1+3=10≠𝑥2
.
In the third test case, one possible perfect permutation with length 𝑛=5
 is 𝑝=[5,1,4,3,2]
:

𝑝1=5≠𝑥2
;
𝑝1+𝑝2=5+1=6≠𝑥2
;
𝑝1+𝑝2+𝑝3=5+1+4=10≠𝑥2
;
𝑝1+𝑝2+𝑝3+𝑝4=5+1+4+3=13≠𝑥2
;
𝑝1+𝑝2+𝑝3+𝑝4+𝑝5=5+1+4+3+2=15≠𝑥2
.


*/

#include <cstdio>
#include <set>
#include <vector>
typedef long long ll;

int main() {

  std::set<ll> ssq;
  for (ll p = 1; p <= 5e5; p++) {
    ssq.insert(p * p);
  }

  ll t;
  scanf("%lld", &t);
  while (t--) {
    ll n;
    scanf("%lld", &n);
    if (ssq.count(n * (n + 1) / 2)) {
      puts("-1");
      continue;
    }

    std::vector<ll> v(n, -1);
    ll cs(0);
    for (ll p = 0; p < n; p++) {
      if (v[p] < 0) {
        ll cur = p + 1;
        if (ssq.count(cs + cur)) {
          v[p] = cur + 1;
          v[p + 1] = cur;
        } else {
          v[p] = cur;
        }
      }
      cs += v[p];
    }

    for (ll p = 0; p < n; p++) {
      printf("%lld ", v[p]);
    }
    puts("");
  }
}
// sub: https://codeforces.com/problemset/submission/2071/324330062

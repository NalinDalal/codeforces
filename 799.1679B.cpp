/*B. Stone Age Problem
time limit per test2 seconds
memory limit per test256 megabytes
Once upon a time Mike and Mike decided to come up with an outstanding problem
for some stage of ROI (rare olympiad in informatics). One of them came up with a
problem prototype but another stole the idea and proposed that problem for
another stage of the same olympiad. Since then the first Mike has been waiting
for an opportunity to propose the original idea for some other contest... Mike
waited until this moment!

You are given an array 𝑎
 of 𝑛
 integers. You are also given 𝑞
 queries of two types:

Replace 𝑖
-th element in the array with integer 𝑥
.
Replace each element in the array with integer 𝑥
.
After performing each query you have to calculate the sum of all elements in the
array.

Input
The first line contains two integers 𝑛
 and 𝑞
 (1≤𝑛,𝑞≤2⋅105
) — the number of elements in the array and the number of queries, respectively.

The second line contains 𝑛
 integers 𝑎1,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — elements of the array 𝑎
.

Each of the following 𝑞
 lines contains a description of the corresponding query. Description begins
with integer 𝑡 (𝑡∈{1,2} ) which denotes a type of the query:

If 𝑡=1
, then two integers 𝑖
 and 𝑥
 are following (1≤𝑖≤𝑛
, 1≤𝑥≤109
) — position of replaced element and it's new value.
If 𝑡=2
, then integer 𝑥
 is following (1≤𝑥≤109
) — new value of each element in the array.
Output
Print 𝑞
 integers, each on a separate line. In the 𝑖
-th line print the sum of all elements in the array after performing the first 𝑖
 queries.

Example
InputCopy
5 5
1 2 3 4 5
1 1 5
2 10
1 5 11
1 4 1
2 1
OutputCopy
19
50
51
42
5
Note
Consider array from the example and the result of performing each query:

Initial array is [1,2,3,4,5]
.
After performing the first query, array equals to [5,2,3,4,5]
. The sum of all elements is 19
.
After performing the second query, array equals to [10,10,10,10,10]
. The sum of all elements is 50
.
After performing the third query, array equals to [10,10,10,10,11
]. The sum of all elements is 51
.
After performing the fourth query, array equals to [10,10,10,1,11]
. The sum of all elements is 42
.
After performing the fifth query, array equals to [1,1,1,1,1]
. The sum of all elements is 5
.
*/
#include <iostream>
#include <set>
#include <vector>

typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll n, q;
  std::cin >> n >> q;

  ll sum = 0, reset = -1;
  std::set<ll> s;
  std::vector<ll> a(n);

  for (ll p = 0; p < n; p++) {
    std::cin >> a[p];
    sum += a[p];
    s.insert(p);
  }

  for (ll p = 0; p < q; p++) {
    ll t;
    std::cin >> t;

    if (t == 1) {
      ll idx, x;
      std::cin >> idx >> x;
      --idx;
      sum += (s.count(idx) ? (x - a[idx]) : (x - reset));
      a[idx] = x;
      s.insert(idx);
    } else if (t == 2) {
      ll x;
      std::cin >> x;
      reset = x;
      s.clear();
      sum = n * x;
    }

    std::cout << sum << "\n";
  }
}
// sub: https://codeforces.com/problemset/submission/1679/345801638

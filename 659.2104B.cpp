/*B. Move to the End
time limit per test2 seconds
memory limit per test512 megabytes
You are given an array 𝑎
 consisting of 𝑛
 integers.

For every integer 𝑘
 from 1
 to 𝑛
, you have to do the following:

choose an arbitrary element of 𝑎
 and move it to the right end of the array (you can choose the last element,
then the array won't change); print the sum of 𝑘 last elements of 𝑎
;
move the element you've chosen on the first step to its original position
(restore the original array 𝑎
).
For every 𝑘
, you choose the element which you move so that the value you print is the
maximum possible.

Calculate the value you print for every 𝑘
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (1≤𝑛≤2⋅105
);
the second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).
Additional constraint on the input: the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print 𝑛
 integers. The 𝑖
-th of these integers should be equal to the maximum value you can print if 𝑘=𝑖
.

Example
InputCopy
4
7
13 5 10 14 8 15 13
6
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1
42
2
7 5
OutputCopy
15 28 42 50 63 73 78
1000000000 2000000000 3000000000 4000000000 5000000000 6000000000
42
7 12
Note
Let's consider the first test case from the statement:

when 𝑘=1
, you can move the 6
-th element to the end, the array becomes [13,5,10,14,8,13,15]
, and the value you print is 15
;
when 𝑘=2
, you can move the 6
-th element to the end, the array becomes [13,5,10,14,8,13,15]
, and the value you print is 13+15=28
;
when 𝑘=3
, you can move the 4
-th element to the end, the array becomes [13,5,10,8,15,13,14]
, and the value you print is 15+13+14=42
;
when 𝑘=4
, you can move the 5
-th element to the end, the array becomes [13,5,10,14,15,13,8]
, and the value you print is 14+15+13+8=50
;
when 𝑘=5
, you can move the 1
-st element to the end, the array becomes [5,10,14,8,15,13,13]
, and the value you print is 14+8+15+13+13=63
;
when 𝑘=6
, you can move the 1
-st element to the end, the array becomes [5,10,14,8,15,13,13]
, and the value you print is 10+14+8+15+13+13=73
;
when 𝑘=7
, you can move the 6
-th element to the end, the array becomes [13,5,10,14,8,13,15]
, and the value you print is 13+5+10+14+8+13+15=78
.
*/

#include <iostream>
#include <vector>
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll t;
  std::cin >> t;
  while (t--) {
    ll n;
    std::cin >> n;
    std::vector<ll> v(n), mv(n), sv(n);
    for (ll p = 0; p < n; p++)
      std::cin >> v[p];

    // prefix max
    mv[0] = v[0];
    for (ll p = 1; p < n; p++)
      mv[p] = std::max(mv[p - 1], v[p]);

    // suffix sum
    sv[n - 1] = v[n - 1];
    for (ll p = n - 2; p >= 0; p--)
      sv[p] = sv[p + 1] + v[p];

    for (ll p = n - 1; p >= 0; p--) {
      ll result = mv[p] + ((p + 1 < n) ? sv[p + 1] : 0);
      std::cout << result << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2104/336943157

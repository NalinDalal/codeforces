/*
C. Good Prefixes
time limit per test2 seconds
memory limit per test256 megabytes
Alex thinks some array is good if there exists some element that can be
represented as the sum of all other elements (the sum of all other elements is 0
 if there are no other elements). For example, the array [1,6,3,2]
 is good since 1+3+2=6
. Furthermore, the array [0]
 is also good. However, the arrays [1,2,3,4]
 and [1]
 are not good.

Alex has an array 𝑎1,𝑎2,…,𝑎𝑛
. Help him count the number of good non-empty prefixes of the array 𝑎
. In other words, count the number of integers 𝑖
 (1≤𝑖≤𝑛
) such that the length 𝑖
 prefix (i.e. 𝑎1,𝑎2,…,𝑎𝑖
) is good.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of elements in the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of good non-empty
prefixes of the array 𝑎
.

Example
InputCopy
7
1
0
1
1
4
1 1 2 0
5
0 1 2 1 4
7
1 1 0 3 5 2 12
7
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 294967296
10
0 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1000000000 589934592 OutputCopy
1
0
3
3
4
1
2
Note
In the fourth test case, the array has five prefixes:

prefix [0]
 is a good array, as mentioned in the statement;
prefix [0,1]
 is not a good array, since 0≠1
;
prefix [0,1,2]
 is not a good array, since 0≠1+2
, 1≠0+2
 and 2≠0+1
;
prefix [0,1,2,1]
 is a good array, since 2=0+1+1
;
prefix [0,1,2,1,4]
 is a good array, since 4=0+1+2+1
.
As you can see, three of them are good, so the answer is 3
.


*/

#include <iostream>
typedef long long ll;

int main() {
  ll t;
  std::cin >> t;
  while (t--) {
    ll n;
    std::cin >> n;
    ll cs = 0, mx = -1, cnt = 0;
    for (ll p = 0; p < n; p++) {
      ll x;
      std::cin >> x;
      mx = (mx > x ? mx : x);
      cs += x;
      cnt += (cs == 2 * mx);
    }
    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1985/329713182

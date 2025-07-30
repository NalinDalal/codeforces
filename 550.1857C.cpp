/*C. Assembly via Minimums
time limit per test2 seconds
memory limit per test256 megabytes
Sasha has an array 𝑎
 of 𝑛
 integers. He got bored and for all 𝑖
, 𝑗
 (𝑖<𝑗
), he wrote down the minimum value of 𝑎𝑖
 and 𝑎𝑗
. He obtained a new array 𝑏
 of size 𝑛⋅(𝑛−1)2
.

For example, if 𝑎=
 [2,3,5,1
], he would write [min(2,3),min(2,5),min(2,1),min(3,5),min(3,1),𝑚𝑖𝑛(5,1)
] =
 [2,2,1,3,1,1
].

Then, he randomly shuffled all the elements of the array 𝑏
.

Unfortunately, he forgot the array 𝑎
, and your task is to restore any possible array 𝑎
 from which the array 𝑏
 could have been obtained.

The elements of array 𝑎
 should be in the range [−109,109]
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤200
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤103
) — the length of array 𝑎
.

The second line of each test case contains 𝑛⋅(𝑛−1)2
 integers 𝑏1,𝑏2,…,𝑏𝑛⋅(𝑛−1)2
 (−109≤𝑏𝑖≤109
) — the elements of array 𝑏
.

It is guaranteed that the sum of 𝑛
 over all tests does not exceed 103
 and for each array 𝑏
 in the test, there exists an original array.

Output
For each test case, output any possible array 𝑎
 of length 𝑛
.

Example
InputCopy
5
3
1 3 1
2
10
4
7 5 3 5 3 3
5
2 2 2 2 2 2 2 2 2 2
5
3 0 0 -2 0 -2 0 0 -2 -2
OutputCopy
1 3 3
10 10
7 5 3 12
2 2 2 2 2
0 -2 0 3 5
Note
In the first sample, Sasha chose the array [1,3,3]
, then the array 𝑏
 will look like [min(𝑎1,𝑎2)=1,min(𝑎1,𝑎3)=1,min(𝑎2,𝑎3)=3]
, after shuffling its elements, the array can look like [1,3,1]
.

In the second sample, there is only one pair, so the array [10,10]
 is suitable. Another suitable array could be [15,10]
*/
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    long m = n * (n - 1) / 2;
    std::vector<long> v(m);
    for (long p = 0; p < m; p++) {
      std::cin >> v[p];
    }
    std::sort(v.begin(), v.end());
    long idx = 0, step = n - 1;
    std::vector<long> g;
    while (idx < m) {
      g.push_back(v[idx]);
      idx += step;
      --step;
    }
    g.push_back(g.back());
    for (long p = 0; p < n; p++) {
      std::cout << g[p] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1857/331524279

/*D. Plus Minus Permutation
time limit per test1 second
memory limit per test256 megabytes
You are given 3
 integers — 𝑛
, 𝑥
, 𝑦
. Let's call the score of a permutation†
 𝑝1,…,𝑝𝑛
 the following value:

(𝑝1⋅𝑥+𝑝2⋅𝑥+…+𝑝⌊𝑛𝑥⌋⋅𝑥)−(𝑝1⋅𝑦+𝑝2⋅𝑦+…+𝑝⌊𝑛𝑦⌋⋅𝑦)

In other words, the score of a permutation is the sum of 𝑝𝑖
 for all indices 𝑖
 divisible by 𝑥
, minus the sum of 𝑝𝑖
 for all indices 𝑖
 divisible by 𝑦
.

You need to find the maximum possible score among all permutations of length 𝑛
.

For example, if 𝑛=7
, 𝑥=2
, 𝑦=3
, the maximum score is achieved by the permutation [2,6⎯⎯,1⎯⎯,7⎯⎯,5,4⎯⎯⎯⎯,3]
 and is equal to (6+7+4)−(1+4)=17−5=12
.

†
 A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in any order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (the number 2
 appears twice in the array) and [1,3,4]
 is also not a permutation (𝑛=3
, but the array contains 4
).

Input
The first line of input contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Then follows the description of each test case.

The only line of each test case description contains 3
 integers 𝑛
, 𝑥
, 𝑦
 (1≤𝑛≤109
, 1≤𝑥,𝑦≤𝑛
).

Output
For each test case, output a single integer — the maximum score among all
permutations of length 𝑛
.

Example
InputCopy
8
7 2 3
12 6 3
9 1 9
2 2 2
100 20 50
24 4 6
1000000000 5575 25450
4 4 1
OutputCopy
12
-3
44
0
393
87
179179179436104
-6
Note
The first test case is explained in the problem statement above.

In the second test case, one of the optimal permutations will be
[12,11,2⎯⎯,4,8,9⎯⎯⎯⎯,10,6,1⎯⎯,5,3,7⎯⎯⎯⎯] . The score of this permutation is
(9+7)−(2+9+1+7)=−3 . It can be shown that a score greater than −3 can not be
achieved. Note that the answer to the problem can be negative.

In the third test case, the score of the permutation will be (𝑝1+𝑝2+…+𝑝9)−𝑝9
. One of the optimal permutations for this case is [9,8,7,6,5,4,3,2,1]
, and its score is 44
. It can be shown that a score greater than 44
 can not be achieved.

In the fourth test case, 𝑥=𝑦
, so the score of any permutation will be 0
.
*/

#include <iostream>
typedef long long ll;

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    ll n, x, y;
    std::cin >> n >> x >> y;

    ll lcm = (x / gcd(x, y)) * y;

    ll nx = (n / lcm) * (lcm / x - 1) + (n % lcm) / x;
    ll ny = (n / lcm) * (lcm / y - 1) + (n % lcm) / y;

    ll plus = nx * (2 * n - nx + 1) / 2;
    ll minus = ny * (ny + 1) / 2;

    std::cout << (plus - minus) << '\n';
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1872/332740504

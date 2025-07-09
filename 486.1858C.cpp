/*C. Yet Another Permutation Problem
time limit per test2 seconds
memory limit per test256 megabytes
Alex got a new game called "GCD permutations" as a birthday present. Each round
of this game proceeds as follows:

First, Alex chooses a permutation†
 𝑎1,𝑎2,…,𝑎𝑛
 of integers from 1
 to 𝑛
.
Then, for each 𝑖
 from 1
 to 𝑛
, an integer 𝑑𝑖=gcd(𝑎𝑖,𝑎(𝑖mod𝑛)+1)
 is calculated.
The score of the round is the number of distinct numbers among 𝑑1,𝑑2,…,𝑑𝑛
.
Alex has already played several rounds so he decided to find a permutation
𝑎1,𝑎2,…,𝑎𝑛 such that its score is as large as possible.

Recall that gcd(𝑥,𝑦)
 denotes the greatest common divisor (GCD) of numbers 𝑥
 and 𝑦
, and 𝑥mod𝑦
 denotes the remainder of dividing 𝑥
 by 𝑦
.

†
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

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of one line containing a single integer 𝑛
 (2≤𝑛≤105
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case print 𝑛
 distinct integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the permutation with the largest possible score.

If there are several permutations with the maximum possible score, you can print
any one of them.

Example
InputCopy
4
5
2
7
10
OutputCopy
1 2 4 3 5
1 2
1 2 3 6 4 5 7
1 2 3 4 8 5 10 6 9 7
Note
In the first test case, Alex wants to find a permutation of integers from 1
 to 5
. For the permutation 𝑎=[1,2,4,3,5]
, the array 𝑑
 is equal to [1,2,1,1,1]
. It contains 2
 distinct integers. It can be shown that there is no permutation of length 5
 with a higher score.

In the second test case, Alex wants to find a permutation of integers from 1
 to 2
. There are only two such permutations: 𝑎=[1,2]
 and 𝑎=[2,1]
. In both cases, the array 𝑑
 is equal to [1,1]
, so both permutations are correct.

In the third test case, Alex wants to find a permutation of integers from 1
 to 7
. For the permutation 𝑎=[1,2,3,6,4,5,7]
, the array 𝑑
 is equal to [1,1,3,2,1,1,1]
. It contains 3
 distinct integers so its score is equal to 3
. It can be shown that there is no permutation of integers from 1
 to 7
 with a score higher than 3
.
*/

#include <iostream>
#include <set>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++)
      s.insert(i);
    while (!s.empty()) {
      int x = *s.begin();
      while (s.count(x)) {
        cout << x << " ";
        s.erase(x);
        x *= 2;
      }
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1858/328169898

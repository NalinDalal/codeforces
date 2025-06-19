/*B. Outstanding Impressionist
time limit per test1 second
memory limit per test256 megabytes
If it was so, then let's make it a deal...
— MayDay, Gentleness
Even after copying the paintings from famous artists for ten years,
unfortunately, Eric is still unable to become a skillful impressionist painter.
He wants to forget something, but the white bear phenomenon just keeps hanging
over him.

Eric still remembers 𝑛
 pieces of impressions in the form of an integer array. He records them as
𝑤1,𝑤2,…,𝑤𝑛 . However, he has a poor memory of the impressions. For each 1≤𝑖≤𝑛 ,
he can only remember that 𝑙𝑖≤𝑤𝑖≤𝑟𝑖
.

Eric believes that impression 𝑖
 is unique if and only if there exists a possible array 𝑤1,𝑤2,…,𝑤𝑛
 such that 𝑤𝑖≠𝑤𝑗
 holds for all 1≤𝑗≤𝑛
 with 𝑗≠𝑖
.

Please help Eric determine whether impression 𝑖
 is unique for every 1≤𝑖≤𝑛
, independently for each 𝑖
. Perhaps your judgment can help rewrite the final story.

Input
Each test contains multiple test cases. The first line of the input contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of test
cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of impressions.

Then 𝑛
 lines follow, the 𝑖
-th containing two integers 𝑙𝑖
 and 𝑟𝑖
 (1≤𝑙𝑖≤𝑟𝑖≤2⋅𝑛
) — the minimum possible value and the maximum possible value of 𝑤𝑖
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a binary string 𝑠
 of length 𝑛
: for each 1≤𝑖≤𝑛
, if impression 𝑖
 is unique, 𝑠𝑖=𝟷
; otherwise, 𝑠𝑖=𝟶
. Do not output spaces.

Example
InputCopy
5
2
1 1
1 1
4
1 3
1 3
1 3
1 3
6
3 6
2 2
1 2
1 1
3 4
2 2
7
3 4
4 4
4 4
1 3
2 5
1 4
2 2
3
4 5
4 4
5 5
OutputCopy
00
1111
100110
1001111
011
Note
In the first test case, the only possible array 𝑤
 is [1,1]
, making neither impression 1
 nor 2
 unique (since 𝑤1=𝑤2
).

In the second test case, all impressions can be made unique:

For 𝑖=1
, we can set 𝑤
 to [1,3,2,3]
, in which 𝑤1≠𝑤2
, 𝑤1≠𝑤3
, and 𝑤1≠𝑤4
;
For 𝑖=2
, we can set 𝑤
 to [2,3,1,2]
, in which 𝑤2≠𝑤1
, 𝑤2≠𝑤3
, and 𝑤2≠𝑤4
;
For 𝑖=3
, we can set 𝑤
 to [1,1,3,1]
;
For 𝑖=4
, we can set 𝑤
 to [2,3,3,1]
.
In the third test case, for 𝑖=4
, we can set 𝑤
 to [3,2,2,1,3,2]
. Thus, impression 4
 is unique.



*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    std::vector<long> vl(n), vr(n);
    std::set<long> fs, gs;

    for (long p = 0; p < n; p++) {
      std::cin >> vl[p] >> vr[p];
      if (vl[p] == vr[p]) {
        if (fs.count(vl[p])) {
          gs.insert(vl[p]);
        } else {
          fs.insert(vl[p]);
        }
      }
    }

    std::vector<long> dv(fs.begin(), fs.end());

    for (long p = 0; p < n; p++) {
      if (vl[p] == vr[p]) {
        std::cout << (gs.count(vl[p]) ? '0' : '1');
      } else {
        auto ita = std::lower_bound(dv.begin(), dv.end(), vl[p]);
        auto itb = std::lower_bound(dv.begin(), dv.end(), vr[p]);
        std::cout << ((fs.count(vl[p]) && fs.count(vr[p]) &&
                       (itb - ita == vr[p] - vl[p]))
                          ? '0'
                          : '1');
      }
    }

    std::cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2053/325105873

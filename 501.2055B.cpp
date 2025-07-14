/*B. Crafting
time limit per test1 second
memory limit per test256 megabytes

As you'd expect, Florida is home to many bizarre magical forces, and Florida Man
seeks to tame them. There are 𝑛 different types of magical materials, numbered
from 1 to 𝑛 . Initially, you have 𝑎𝑖 units of material 𝑖 for each 𝑖 from 1 to 𝑛
. You are allowed to perform the following operation:

Select a material 𝑖
 (where 1≤𝑖≤𝑛
). Then, spend 1
 unit of every other material 𝑗
 (in other words, 𝑗≠𝑖
) to gain 1
 unit of material 𝑖
. More formally, after selecting material 𝑖
, update array 𝑎
 as follows: 𝑎𝑖:=𝑎𝑖+1
, and 𝑎𝑗:=𝑎𝑗−1
 for all 𝑗
 where 𝑗≠𝑖
 and 1≤𝑗≤𝑛
. Note that all 𝑎𝑗
 must remain non-negative, i.e. you cannot spend resources you do not have.
You are trying to craft an artifact using these materials. To successfully craft
the artifact, you must have at least 𝑏𝑖 units of material 𝑖 for each 𝑖 from 1 to
𝑛 . Determine if it is possible to craft the artifact by performing the
operation any number of times (including zero).

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the number of types of materials.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the amount of each material 𝑖
 that you currently hold.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (0≤𝑏𝑖≤109
) — the amount of each material 𝑖
 needed to produce the artifact.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single line containing either "YES" or "NO",
representing whether or not the artifact can be crafted.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
3
4
0 5 5 1
1 4 4 0
3
1 1 3
2 2 1
2
1 10
3 3
OutputCopy
YES
NO
YES
Note
In the first test case, perform an operation on material 1
. After doing so, we will have exactly the required resources: 1
 unit of material 1
, and 4
 units each of materials 2
 and 3
.

In the second test case, it can be shown that no matter how the operations are
performed, it is impossible to craft the artifact.

In the third test case, we can perform the operation on material 1
 twice. After these operations, we will have 3
 units of material 1
 and 8
 units of material 2
, which is more than enough to craft the artifact.
*/

#include <iostream>
#include <vector>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> dv(n);
    for (long p = 0; p < n; p++) {
      std::cin >> dv[p];
    }
    bool ans(true);
    long diff(0);
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      dv[p] -= x;
      if (dv[p] < 0) {
        if (diff) {
          ans = false;
        } else {
          diff = dv[p];
        }
      }
    }

    for (long p = 0; ans && p < n; p++) {
      if (dv[p] < 0) {
        continue;
      }
      if (dv[p] + diff < 0) {
        ans = false;
      }
    }

    std::cout << (ans ? "YES" : "NO") << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2055/328939233

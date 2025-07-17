/*D. Turtle Tenacity: Continual Mods
time limit per test2 seconds
memory limit per test256 megabytes
Given an array 𝑎1,𝑎2,…,𝑎𝑛
, determine whether it is possible to rearrange its elements into 𝑏1,𝑏2,…,𝑏𝑛
, such that 𝑏1mod𝑏2mod…mod𝑏𝑛≠0
.

Here 𝑥mod𝑦
 denotes the remainder from dividing 𝑥
 by 𝑦
. Also, the modulo operations are calculated from left to right. That is,
𝑥mod𝑦mod𝑧=(𝑥mod𝑦)mod𝑧 . For example, 2024mod1000mod8=(2024mod1000)mod8=24mod8=0
.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤105
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

The sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if it is possible, "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
8
6
1 2 3 4 5 6
5
3 3 3 3 3
3
2 2 3
5
1 1 2 3 7
3
1 2 2
3
1 1 2
6
5 2 10 10 10 2
4
3 6 9 3
OutputCopy
YES
NO
YES
NO
YES
NO
YES
NO
Note
In the first test case, rearranging the array into 𝑏=[1,2,3,4,5,6]
 (doing nothing) would result in 1mod2mod3mod4mod5mod6=1
. Hence it is possible to achieve the goal.

In the second test case, the array 𝑏
 must be equal to [3,3,3,3,3]
, which would result in 3mod3mod3mod3mod3=0
. Hence it is impossible to achieve the goal.

In the third test case, rearranging the array into 𝑏=[3,2,2]
 would result in 3mod2mod2=1
. Hence it is possible to achieve the goal.

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long mn = 1e9 + 7, cnt = 0;
    vector<long> a(n);
    for (long p = 0; p < n; p++) {
      cin >> a[p];
      if (a[p] < mn) {
        mn = a[p];
        cnt = 1;
      } else if (a[p] == mn) {
        ++cnt;
      }
    }

    if (cnt == 1) {
      cout << "YES" << endl;
      continue;
    }

    bool sm = false;
    for (long p = 0; !sm && p < n; p++) {
      if (a[p] % mn) {
        sm = true;
      }
    }

    cout << (sm ? "YES" : "NO") << endl;
  }
}

// sub: https://codeforces.com/problemset/submission/1933/329288592

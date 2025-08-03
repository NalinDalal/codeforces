/*B. Robin Hood and the Major Oak
time limit per test1 second
memory limit per test256 megabytes
In Sherwood, the trees are our shelter, and we are all children of the forest.
The Major Oak in Sherwood is known for its majestic foliage, which provided
shelter to Robin Hood and his band of merry men and women.

The Major Oak grows 𝑖𝑖
 new leaves in the 𝑖
-th year. It starts with 1
 leaf in year 1
.

Leaves last for 𝑘
 years on the tree. In other words, leaves grown in year 𝑖
 last between years 𝑖
 and 𝑖+𝑘−1
 inclusive.

Robin considers even numbers lucky. Help Robin determine whether the Major Oak
will have an even number of leaves in year 𝑛
.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of two integers 𝑛
, 𝑘
 (1≤𝑛≤109
, 1≤𝑘≤𝑛
) — the requested year and the number of years during which the leaves remain.

Output
For each test case, output one line, "YES" if in year 𝑛
 the Major Oak will have an even number of leaves and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
1 1
2 1
2 2
3 2
4 4
OutputCopy
NO
YES
NO
NO
YES
Note
In the first test case, there is only 1
 leaf.

In the second test case, 𝑘=1
, so in the 2
-nd year there will be 22=4
 leaves.

In the third test case, 𝑘=2
, so in the 2
-nd year there will be 1+22=5
 leaves.

In the fourth test case, 𝑘=2
, so in the 3
-rd year there will be 22+33=4+27=31
 leaves.
*/

/*i^i leaf grows in ith year
start with 1 leaf in yr 1
leaves last for k year
so leave for ith yr takes i+k-1 yr to die
find if leaves will be even in year n

so year n=sum of i^i for all i from max(1, n - k + 1) to n.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long l = ((k + (n % 2)) / 2) % 2;

    cout << (l == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2014/332186477

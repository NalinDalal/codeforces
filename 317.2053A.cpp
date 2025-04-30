/* A. Tender Carpenter
time limit per test1 second
memory limit per test256 megabytes
I would use a firework to announce, a wave to bid farewell, and a bow to say
thanks: bygones are bygones; not only on the following path will I be walking
leisurely and joyfully, but also the footsteps won't halt as time never leaves
out flowing; for in the next year, we will meet again. — Cocoly1990, Goodbye
2022 In his dream, Cocoly would go on a long holiday with no worries around him.
So he would try out for many new things, such as... being a carpenter. To learn
it well, Cocoly decides to become an apprentice of Master, but in front of him
lies a hard task waiting for him to solve.

Cocoly is given an array 𝑎1,𝑎2,…,𝑎𝑛
. Master calls a set of integers 𝑆
 stable if and only if, for any possible 𝑢
, 𝑣
, and 𝑤
 from the set 𝑆
 (note that 𝑢
, 𝑣
, and 𝑤
 do not necessarily have to be pairwise distinct), sticks of length 𝑢
, 𝑣
, and 𝑤
 can form a non-degenerate triangle∗
.

Cocoly is asked to partition the array 𝑎
 into several (possibly, 1
 or 𝑛
) non-empty continuous subsegments†
, such that: for each of the subsegments, the set containing all the elements in
it is stable.

Master wants Cocoly to partition 𝑎
 in at least two different‡
 ways. You have to help him determine whether it is possible.

∗
A triangle with side lengths 𝑥
, 𝑦
, and 𝑧
 is called non-degenerate if and only if:

𝑥+𝑦>𝑧
,
𝑦+𝑧>𝑥
, and
𝑧+𝑥>𝑦
.
†
A sequence 𝑏
 is a subsegment of a sequence 𝑐
 if 𝑏
 can be obtained from 𝑐
 by the deletion of several (possibly, zero or all) elements from the beginning
and several (possibly, zero or all) elements from the end.

‡
Two partitions are considered different if and only if at least one of the
following holds:

the numbers of continuous subsegments split in two partitions are different;
there is an integer 𝑘
 such that the lengths of the 𝑘
-th subsegment in two partitions are different.
Input
Each test contains multiple test cases. The first line of the input contains a
single integer 𝑡 (1≤𝑡≤200 ) — the number of test cases. The description of test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤200
) — the length of the array 𝑎
.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤105
) — the elements in the array 𝑎
.

Output
For each test case, print 𝚈𝙴𝚂
 if there are at least two ways to partition 𝑎
, and 𝙽𝙾
 otherwise.

You can output the answer in any case (upper or lower). For example, the strings
𝚢𝙴𝚜 , 𝚢𝚎𝚜 , 𝚈𝚎𝚜 , and 𝚈𝙴𝚂 will be recognized as positive responses.

Example
InputCopy
5
4
2 3 5 7
4
115 9 2 28
5
8 4 1 6 2
6
1 5 4 1 4 7
2
100000 100000
OutputCopy
YES
NO
NO
YES
YES
Note
In the first test case, here are two possible partitions:

[2,3],[5,7]
, since
[2,3]
 is stable because sticks of lengths (2,2,2),(2,2,3),(2,3,3),(3,3,3)
 respectively can all form non-degenerate triangles.
[5,7]
 is stable because sticks of lengths (5,5,5),(5,5,7),(5,7,7),(7,7,7)
 respectively can all form non-degenerate triangles.
and [2],[3,5],[7]
, since
[2]
 is stable because sticks of lengths (2,2,2)
 respectively can form a non-degenerate triangle.
[3,5]
 is stable because sticks of lengths (3,3,3),(3,3,5),(3,5,5),(5,5,5)
 respectively can all form non-degenerate triangles.
[7]
 is stable because sticks of lengths (7,7,7)
 respectively can form a non-degenerate triangle.
Note that some other partitions also satisfy the constraints, such as
[2],[3],[5],[7] and [2],[3],[5,7]
.

In the second test case, Cocoly can only partition each element as a single
subsegment, resulting in [115],[9],[2],[28] . Since we only have one possible
partition, the answer is 𝙽𝙾
.

In the third test case, please note that the partition [8,4],[1],[6],[2]
 does not satisfy the constraints, because {8,4}
 is not a stable set: sticks of lengths 4
, 4
, and 8
 cannot form a non-degenerate triangle.


*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int prev = -1;
    bool res = false;

    for (int p = 0; p < n; ++p) {
      int x;
      cin >> x;
      if (p > 0 && (x < 2 * prev) && (prev < 2 * x)) {
        res = true;
      }
      prev = x;
    }

    cout << (res ? "YES" : "NO") << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2053/317808529

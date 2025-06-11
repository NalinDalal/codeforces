/*B. Variety is Discouraged
time limit per test1.5 seconds
memory limit per test256 megabytes
Define the score of an arbitrary array 𝑏
 to be the length of 𝑏
 minus the number of distinct elements in 𝑏
. For example:

The score of [1,2,2,4]
 is 1
, as it has length 4
 and only 3
 distinct elements (1
, 2
, 4
).
The score of [1,1,1]
 is 2
, as it has length 3
 and only 1
 distinct element (1
).
The empty array has a score of 0
.
You have an array 𝑎
. You need to remove some non-empty contiguous subarray from 𝑎
 at most once.

More formally, you can do the following at most once:

pick two integers 𝑙
, 𝑟
 where 1≤𝑙≤𝑟≤𝑛
, and
delete the contiguous subarray [𝑎𝑙,…,𝑎𝑟]
 from 𝑎
 (that is, replace 𝑎
 with [𝑎1,…,𝑎𝑙−1,𝑎𝑟+1,…,𝑎𝑛]
).
Output an operation such that the score of 𝑎
 is maximum; if there are multiple answers, output one that minimises the final
length of 𝑎 after the operation. If there are still multiple answers, you may
output any of them.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The first line of each testcase contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array 𝑎
.

The second line of each testcase contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

The sum of 𝑛
 across all testcases does not exceed 2⋅105
.

Output
For each testcase, if you wish to not make a move, output 0
.

Otherwise, output two integers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤𝑛
), representing the left and right bound of the removed subarray.

The removed subarray should be chosen such that the score is maximized, and over
all such answers choose any of them that minimises the final length of the
array.

Example
InputCopy
3
1
1
5
1 1 1 1 1
4
2 1 3 2
OutputCopy
1 1
0
2 3
Note
In the first testcase, we have two options:

do nothing: the score of [1]
 is 1−1=0
.
remove the subarray with 𝑙=1
, 𝑟=1
: we remove the only element, and we get an empty array with score 0
.
Therefore, the maximum score possible is 0
. However, since we need to additionally minimise the final length of the array,
we must output the second option with 𝑙=𝑟=1 . Note that the first option of
doing nothing is incorrect, since it has a longer final length. In the second
testcase, no subarray is selected, so after which 𝑎 is still [1,1,1,1,1] . This
has length 5 and 1 distinct element, so it has a score of 5−1=4 . This can be
proven to be a shortest array which maximises the score.

In the third testcase, the subarray selected is [2,1,3,2]
, after which 𝑎
 becomes [2,2]
. This has length 2
 and 1
 distinct element, so it has a score of 2−1=1
. This can be proven to be a shortest array which maximises the score.



*/

#include <cstdio>
#include <set>
#include <vector>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    std::vector<long> v(n);
    std::set<long> singles, dupes;
    for (long p = 0; p < n; p++) {
      scanf("%ld", &v[p]);
      if (dupes.count(v[p])) {
        continue;
      } else if (singles.count(v[p])) {
        dupes.insert(v[p]);
        singles.erase(v[p]);
      } else {
        singles.insert(v[p]);
      }
    }

    long crl(-1), mxlen(-1);
    long left(-1), right(-1);
    for (long p = 0; p < n; p++) {
      if (singles.count(v[p])) {
        if (crl < 0) {
          crl = p;
        }
        if (p - crl + 1 > mxlen) {
          mxlen = p - crl + 1;
          left = crl + 1;
          right = p + 1;
        }
      } else {
        crl = -1;
      }
    }

    if (left < 0) {
      puts("0");
    } else {
      printf("%ld %ld\n", left, right);
    }
  }
}
// sub: https://codeforces.com/problemset/submission/2064/323901433

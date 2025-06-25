/*A. Guess the Maximum
time limit per test1 second
memory limit per test256 megabytes
Alice and Bob came up with a rather strange game. They have an array of integers
𝑎1,𝑎2,…,𝑎𝑛 . Alice chooses a certain integer 𝑘 and tells it to Bob, then the
following happens:

Bob chooses two integers 𝑖
 and 𝑗
 (1≤𝑖<𝑗≤𝑛
), and then finds the maximum among the integers 𝑎𝑖,𝑎𝑖+1,…,𝑎𝑗
;
If the obtained maximum is strictly greater than 𝑘
, Alice wins, otherwise Bob wins.
Help Alice find the maximum 𝑘
 at which she is guaranteed to win.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤5⋅104
) — the number of elements in the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5⋅104
.

Output
For each test case, output one integer — the maximum integer 𝑘
 at which Alice is guaranteed to win.

Example
InputCopy
6
4
2 4 1 7
5
1 2 3 4 5
2
1 1
3
37 8 16
5
10 10 10 10 9
10
3 12 9 5 2 3 2 9 8 2
OutputCopy
3
1
0
15
9
2
Note
In the first test case, all possible subsegments that Bob can choose look as
follows: [2,4],[2,4,1],[2,4,1,7],[4,1],[4,1,7],[1,7] . The maximums on the
subsegments are respectively equal to 4,4,7,4,7,7 . It can be shown that 3 is
the largest integer such that any of the maximums will be strictly greater than
it.

In the third test case, the only segment that Bob can choose is [1,1]
. So the answer is 0
.



*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    long prev;
    scanf("%ld", &prev);
    long mx(1e9 + 7);
    for (long p = 1; p < n; p++) {
      long x;
      scanf("%ld", &x);
      long cur = (x > prev ? x : prev);
      mx = (mx < cur ? mx : cur);
      prev = x;
    }

    printf("%ld\n", mx - 1);
  }
}

// sub: https://codeforces.com/problemset/submission/1979/325959836

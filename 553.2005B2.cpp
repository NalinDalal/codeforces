/*B2. The Strict Teacher (Hard Version)
time limit per test1.5 seconds
memory limit per test256 megabytes
This is the hard version of the problem. The only differences between the two
versions are the constraints on 𝑚 and 𝑞 . In this version, 𝑚,𝑞≤105 . You can
make hacks only if both versions of the problem are solved.

Narek and Tsovak were busy preparing this round, so they have not managed to do
their homework and decided to steal David's homework. Their strict teacher
noticed that David has no homework and now wants to punish him. She hires other
teachers to help her catch David. And now 𝑚 teachers together are chasing him.
Luckily, the classroom is big, so David has many places to hide.

The classroom can be represented as a one-dimensional line with cells from 1
 to 𝑛
, inclusive.

At the start, all 𝑚
 teachers and David are in distinct cells. Then they make moves. During each
move

David goes to an adjacent cell or stays at the current one.
Then, each of the 𝑚
 teachers simultaneously goes to an adjacent cell or stays at the current one.
This continues until David is caught. David is caught if any of the teachers
(possibly more than one) is located in the same cell as David. Everyone sees
others' moves, so they all act optimally.

Your task is to find how many moves it will take for the teachers to catch David
if they all act optimally.

Acting optimally means the student makes his moves in a way that maximizes the
number of moves the teachers need to catch him; and the teachers coordinate with
each other to make their moves in a way that minimizes the number of moves they
need to catch the student.

Also, as Narek and Tsovak think this task is easy, they decided to give you 𝑞
 queries on David's position.

Input
In the first line of the input, you are given a single integer 𝑡
 (1≤𝑡≤105
) — the number of test cases. The description of each test case follows.

In the first line of each test case, you are given three integers 𝑛
, 𝑚
, and 𝑞
 (3≤𝑛≤109
, 1≤𝑚,𝑞≤105
) — the number of cells on the line, the number of teachers, and the number of
queries.

In the second line of each test case, you are given 𝑚
 distinct integers 𝑏1,𝑏2,…,𝑏𝑚
 (1≤𝑏𝑖≤𝑛
) — the cell numbers of the teachers.

In the third line of each test case, you are given 𝑞
 integers 𝑎1,𝑎2,…,𝑎𝑞
 (1≤𝑎𝑖≤𝑛
) — David's cell number for every query.

It is guaranteed that for any 𝑖
, 𝑗
 such that 1≤𝑖≤𝑚
 and 1≤𝑗≤𝑞
, 𝑏𝑖≠𝑎𝑗
.

It is guaranteed that the sum of values of 𝑚
 over all test cases does not exceed 2⋅105
.

It is guaranteed that the sum of values of 𝑞
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑞
 lines, the 𝑖
-th of them containing the answer of the 𝑖
-th query.

Example
InputCopy
2
8 1 1
6
3
10 3 3
1 4 8
2 3 10
OutputCopy
5
1
1
2
Note
In the only query of the first example, the student can run to cell 1
. It will take the teacher five moves to reach from cell 6
 to cell 1
, so the answer is 5
.

In the second query of the second example, the student can just stay at cell 3
. The teacher, initially located in cell 4
, can reach cell 3
 in one move. Therefore, the answer is 1
.



*/
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;

  while (t--) {
    long n, m, q;
    std::cin >> n >> m >> q;

    std::vector<long> b(m);
    for (long p = 0; p < m; p++) {
      std::cin >> b[p];
    }

    std::sort(b.begin(), b.end());

    while (q--) {
      long a;
      std::cin >> a;

      auto it = std::upper_bound(b.begin(), b.end(), a);
      long pos = it - b.begin();
      long res = 0;

      if (pos == 0) {
        res = b[0] - 1;
      } else if (pos == m) {
        res = n - b.back();
      } else {
        res = (b[pos] - b[pos - 1]) / 2;
      }

      std::cout << res << '\n';
    }
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2005/331687311

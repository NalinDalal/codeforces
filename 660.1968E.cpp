/*E. Cells Arrangement
time limit per test2 seconds
memory limit per test256 megabytes
You are given an integer 𝑛
. You choose 𝑛
 cells (𝑥1,𝑦1),(𝑥2,𝑦2),…,(𝑥𝑛,𝑦𝑛)
 in the grid 𝑛×𝑛
 where 1≤𝑥𝑖≤𝑛
 and 1≤𝑦𝑖≤𝑛
.

Let 
 be the set of distinct Manhattan distances between any pair of cells. Your task
is to maximize the size of  . Examples of sets and their construction are
given in the notes.

If there exists more than one solution, you are allowed to output any.

Manhattan distance between cells (𝑥1,𝑦1)
 and (𝑥2,𝑦2)
 equals |𝑥1−𝑥2|+|𝑦1−𝑦2|
.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤50
) — the number of test cases.

Each of the following 𝑡
 lines contains a single integer 𝑛
 (2≤𝑛≤103
).

Output
For each test case, output 𝑛
 points which maximize the size of 
. It is not necessary to output an empty line at the end of the answer for each
test case.

Example
InputCopy
5
2
3
4
5
6
OutputCopy
1 1
1 2

2 1
2 3
3 1

1 1
1 3
4 3
4 4

1 1
1 3
1 4
2 1
5 5

1 4
1 5
1 6
5 2
5 5
6 1
Note
In the first testcase we have 𝑛=2
. One of the possible arrangements is:

The arrangement with cells located in (1,1)
 and (1,2)
.
In this case ={|1−1|+|1−1|,|1−1|+|2−2|,|1−1|+|1−2|}={0,0,1}={0,1}
. Hence, the size of 
 is 2
. It can be shown that it is the greatest possible answer.
In the second testcase we have 𝑛=3
. The optimal arrangement is:

The arrangement with cells located in (2,1)
, (2,3)
 and (3,1)
.

={|2−2|+|1−1|,|2−2|+|3−3|,|3−3|+|1−1|,|2−2|+|1−3|,|2−3|+|1−1|,|2−3|+|3−1|}
={0,0,0,2,1,3}
={0,1,2,3}
.

For 𝑛=4
 a possible arrangement is:


For 𝑛=5
 a possible arrangement is:


For 𝑛=6
 a possible arrangement is:

*/

#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    for (long p = 1; p <= n - 2; p++) {
      std::cout << p << " " << p << "\n";
    }
    std::cout << n - 1 << " " << n << "\n";
    std::cout << n << " " << n << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/contest/1968/submission/336943417

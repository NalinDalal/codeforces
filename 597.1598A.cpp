/*B. Groups
time limit per test4 seconds
memory limit per test256 megabytes
𝑛
 students attended the first meeting of the Berland SU programming course (𝑛
 is even). All students will be divided into two groups. Each group will be
attending exactly one lesson each week during one of the five working days
(Monday, Tuesday, Wednesday, Thursday and Friday), and the days chosen for the
groups must be different. Furthermore, both groups should contain the same
number of students.

Each student has filled a survey in which they told which days of the week are
convenient for them to attend a lesson, and which are not.

Your task is to determine if it is possible to choose two different week days to
schedule the lessons for the group (the first group will attend the lesson on
the first chosen day, the second group will attend the lesson on the second
chosen day), and divide the students into two groups, so the groups have equal
sizes, and for each student, the chosen lesson day for their group is
convenient.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

Then the descriptions of 𝑡
 testcases follow.

The first line of each testcase contains one integer 𝑛
 (2≤𝑛≤1000
) — the number of students.

The 𝑖
-th of the next 𝑛
 lines contains 5
 integers, each of them is 0
 or 1
. If the 𝑗
-th integer is 1
, then the 𝑖
-th student can attend the lessons on the 𝑗
-th day of the week. If the 𝑗
-th integer is 0
, then the 𝑖
-th student cannot attend the lessons on the 𝑗
-th day of the week.

Additional constraints on the input: for each student, at least one of the days
of the week is convenient, the total number of students over all testcases
doesn't exceed 105
.

Output
For each testcase print an answer. If it's possible to divide the students into
two groups of equal sizes and choose different days for the groups so each
student can attend the lesson in the chosen day of their group, print "YES"
(without quotes). Otherwise, print "NO" (without quotes).

Example
InputCopy
2
4
1 0 0 1 0
0 1 0 0 1
0 0 0 1 0
0 1 0 1 0
2
0 0 0 1 0
0 0 0 1 0
OutputCopy
YES
NO
Note
In the first testcase, there is a way to meet all the constraints. For example,
the first group can consist of the first and the third students, they will
attend the lessons on Thursday (the fourth day); the second group can consist of
the second and the fourth students, and they will attend the lessons on Tuesday
(the second day).

In the second testcase, it is impossible to divide the students into groups so
they attend the lessons on different days.
*/

#include <iostream>
#include <map>
#include <vector>

int main() {
  const int D = 5;
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::map<std::pair<long, long>, long> first, second, both, neither;
    for (long row = 0; row < n; row++) {
      std::vector<int> f(D, 0);
      for (long p = 0; p < D; p++) {
        std::cin >> f[p];
      }
      for (long u = 0; u < D; u++) {
        for (long v = u + 1; v < D; v++) {
          std::pair<long, long> combo = std::make_pair(u, v);
          if (f[u] && f[v]) {
            ++both[combo];
          } else if (f[u]) {
            ++first[combo];
          } else if (f[v]) {
            ++second[combo];
          } else {
            ++neither[combo];
          }
        }
      }
    }

    bool possible = false;
    for (long u = 0; !possible && u < D; u++) {
      for (long v = u + 1; !possible && v < D; v++) {
        std::pair<long, long> combo = std::make_pair(u, v);
        if (neither[combo] > 0) {
          continue;
        }
        if (first[combo] + both[combo] >= n / 2 &&
            second[combo] + both[combo] >= n / 2) {
          possible = true;
          break;
        }
      }
    }

    std::cout << (possible ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1598/334000471

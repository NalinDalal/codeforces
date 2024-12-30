// https://codeforces.com/problemset/problem/750/A
/* A. New Year and Hurry

Limak is going to participate in a contest on the last day of the 2016. The
contest will start at 20:00 and will last four hours, exactly until midnight.
There will be n problems, sorted by difficulty, i.e. problem 1 is the easiest
and problem n is the hardest. Limak knows it will take him 5·i minutes to solve
the i-th problem.

Limak's friends organize a New Year's Eve party and Limak wants to be there at
midnight or earlier. He needs k minutes to get there from his house, where he
will participate in the contest first.

How many problems can Limak solve if he wants to make it to the party?

Input
The only line of the input contains two integers n and k (1 ≤ n ≤ 10,
1 ≤ k ≤ 240) — the number of the problems in the contest and the number of
minutes Limak needs to get to the party from his house.

Output
Print one integer, denoting the maximum possible number of problems Limak can
solve so that he could get to the party at midnight or earlier.

Examples
InputCopy
3 222
OutputCopy
2
InputCopy
4 190
OutputCopy
4
InputCopy
7 1
OutputCopy
7
Note
In the first sample, there are 3 problems and Limak needs 222 minutes to get to
the party. The three problems require 5, 10 and 15 minutes respectively. Limak
can spend 5 + 10 = 15 minutes to solve first two problems. Then, at 20:15 he can
leave his house to get to the party at 23:57 (after 222 minutes). In this
scenario Limak would solve 2 problems. He doesn't have enough time to solve 3
problems so the answer is 2.

In the second sample, Limak can solve all 4 problems in 5 + 10 + 15 + 20 = 50
minutes. At 20:50 he will leave the house and go to the party. He will get there
exactly at midnight.

In the third sample, Limak needs only 1 minute to get to the party. He has
enough time to solve all 7 problems.

*/

// n problems, k minutes to get to party
// ith problem takes 5*i minutes
// max problem that can be solved

#include <iostream>
using namespace std;

int main() {
  int n, k, totalMinutes = 240;
  cin >> n >> k;
  totalMinutes = totalMinutes - k;
  int problemsSolved = 0, time = 0;
  for (int i = 1; i <= n; i++) {
    time += 5 * i;
    if (time <= totalMinutes) {
      problemsSolved++; // Increment problems solved if time permits
    } else {
      break; // Stop if there's no more time to solve the next problem
    }
  }

  cout << problemsSolved << endl;
  return 0;
}

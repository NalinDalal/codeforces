/* https://codeforces.com/problemset/problem/432/A
A. Choosing Teams
time limit per test1 second
memory limit per test256 megabytes
The Saratov State University Olympiad Programmers Training Center (SSU OPTC) has
n students. For each student you know the number of times he/she has
participated in the ACM ICPC world programming championship. According to the
ACM ICPC rules, each person can participate in the world championship at most 5
times.

The head of the SSU OPTC is recently gathering teams to participate in the world
championship. Each team must consist of exactly three people, at that, any
person cannot be a member of two or more teams. What maximum number of teams can
the head make if he wants each team to participate in the world championship
with the same members at least k times?

Input
The first line contains two integers, n and k (1 ≤ n ≤ 2000; 1 ≤ k ≤ 5). The
next line contains n integers: y1, y2, ..., yn (0 ≤ yi ≤ 5), where yi shows the
number of times the i-th person participated in the ACM ICPC world championship.

Output
Print a single number — the answer to the problem.

Examples
InputCopy
5 2
0 4 5 1 0
OutputCopy
1
InputCopy
6 4
0 1 2 3 4 5
OutputCopy
0
InputCopy
6 5
0 0 0 0 0 0
OutputCopy
2
Note
In the first sample only one team could be made: the first, the fourth and the
fifth participants.

In the second sample no teams could be created.

In the third sample two teams could be created. Any partition into two teams
fits.*/

#include <iostream>

int main() {
  // arr[i] is no of times i-th person has participated
  // person can participate atmost 5 times
  // 1 team - 3 person
  // 1 person - 1 team only at a time
  // maximum number of teams can the head make if he wants each team to
  // participate in the world championship with the same members at least k
  // times arr[i]>=k{constraint given} k is expereince -> 1<=k<=5

  // return max of team to make so that each team has atleast k times
  // experience k is input given in testcase
  const int MAX = 5;
  const int MEMBERS = 3;
  int n, k;
  std::cin >> n >> k;
  int allowed = MAX - k;

  int count(0);
  for (int p = 0; p < n; p++) {
    int temp;
    std::cin >> temp;
    count += (temp <= allowed);
  }
  std::cout << count / MEMBERS << std::endl;

  return 0;
}
// sub: https://codeforces.com/problemset/submission/432/306066956

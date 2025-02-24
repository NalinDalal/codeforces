/*B. Honest Coach
time limit per test2 seconds
memory limit per test256 megabytes
There are 𝑛
 athletes in front of you. Athletes are numbered from 1
 to 𝑛
 from left to right. You know the strength of each athlete — the athlete number
𝑖 has the strength 𝑠𝑖
.

You want to split all athletes into two teams. Each team must have at least one
athlete, and each athlete must be exactly in one team.

You want the strongest athlete from the first team to differ as little as
possible from the weakest athlete from the second team. Formally, you want to
split the athletes into two teams 𝐴 and 𝐵 so that the value |max(𝐴)−min(𝐵)| is
as small as possible, where max(𝐴) is the maximum strength of an athlete from
team 𝐴 , and min(𝐵) is the minimum strength of an athlete from team 𝐵
.

For example, if 𝑛=5
 and the strength of the athletes is 𝑠=[3,1,2,6,4]
, then one of the possible split into teams is:

first team: 𝐴=[1,2,4]
,
second team: 𝐵=[3,6]
.
In this case, the value |max(𝐴)−min(𝐵)|
 will be equal to |4−3|=1
. This example illustrates one of the ways of optimal split into two teams.

Print the minimum value |max(𝐴)−min(𝐵)|
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases in the input. Then 𝑡
 test cases follow.

Each test case consists of two lines.

The first line contains positive integer 𝑛
 (2≤𝑛≤50
) — number of athletes.

The second line contains 𝑛
 positive integers 𝑠1,𝑠2,…,𝑠𝑛
 (1≤𝑠𝑖≤1000
), where 𝑠𝑖
 — is the strength of the 𝑖
-th athlete. Please note that 𝑠
 values may not be distinct.

Output
For each test case print one integer — the minimum value of |max(𝐴)−min(𝐵)|
 with the optimal split of all athletes into two teams. Each of the athletes
must be a member of exactly one of the two teams.

Example
InputCopy
5
5
3 1 2 6 4
6
2 1 3 2 4 3
4
7 9 3 1
2
1 1000
3
100 150 200
OutputCopy
1
0
2
999
50
Note
The first test case was explained in the statement. In the second test case, one
of the optimal splits is 𝐴=[2,1] , 𝐵=[3,2,4,3] , so the answer is |2−2|=0
.



*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    // differ strongest from A with weakest from B to be as small as possible
    int diff = 0;
    int mn = v.back() + 7;
    for (int i = 1; i < n; i++) {
      int diff = v[i] - v[i - 1];
      mn = (mn < diff) ? mn : diff;
    }
    cout << mn << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1360/307561851

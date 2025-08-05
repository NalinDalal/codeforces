/*C. Rudolf and the Another Competition
time limit per test1 second
memory limit per test256 megabytes
Rudolf has registered for a programming competition that will follow the rules
of ICPC. The rules imply that for each solved problem, a participant gets 1
 point, and also incurs a penalty equal to the number of minutes passed from the
beginning of the competition to the moment of solving the problem. In the final
table, the participant with the most points is ranked higher, and in case of a
tie in points, the participant with the lower penalty is ranked higher.

In total, 𝑛
 participants have registered for the competition. Rudolf is a participant with
index 1 . It is known that 𝑚 problems will be proposed. And the competition will
last ℎ minutes.

A powerful artificial intelligence has predicted the values 𝑡𝑖,𝑗
, which represent the number of minutes it will take for the 𝑖
-th participant to solve the 𝑗
-th problem.

Rudolf realized that the order of solving problems will affect the final result.
For example, if ℎ=120 , and the times to solve problems are [20,15,110
], then if Rudolf solves the problems in the order:

3,1,2
, then he will only solve the third problem and get 1
 point and 110
 penalty.
1,2,3
, then he will solve the first problem after 20
 minutes from the start, the second one after 20+15=35
 minutes, and he will not have time to solve the third one. Thus, he will get 2
 points and 20+35=55
 penalty.
2,1,3
, then he will solve the second problem after 15
 minutes from the start, the first one after 15+20=35
 minutes, and he will not have time to solve the third one. Thus, he will get 2
 points and 15+35=50
 penalty.
Rudolf became interested in what place he will take in the competition if each
participant solves problems in the optimal order based on the predictions of the
artificial intelligence. It will be assumed that in case of a tie in points and
penalty, Rudolf will take the best place.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains three integers 𝑛,𝑚,ℎ
 (1≤𝑛⋅𝑚≤2⋅105,1≤ℎ≤106
) — the number of participants, the number of problems, and the duration of the
competition, respectively.

Then there are 𝑛
 lines, each containing 𝑚
 integers 𝑡𝑖,𝑗
 (1≤𝑡𝑖,𝑗≤106
) — the number of minutes it will take for the 𝑖
-th participant to solve the 𝑗
-th problem.

The sum of 𝑛⋅𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer — Rudolf's place in the final table if all
participants solve problems in the optimal order.

Example
InputCopy
5
3 3 120
20 15 110
90 90 100
40 40 40
2 1 120
30
30
1 3 120
10 20 30
3 2 27
8 9
10 7
10 8
3 3 15
7 2 6
7 5 4
1 9 8
OutputCopy
2
1
1
2
1
Note
In the first example, Rudolf will get 2
 points and 50
 penalty minutes. The second participant will solve only one problem and get 1
 point and 90
 penalty minutes. And the third participant will solve all 3
 problems and get 3
 points and 240
 penalty minutes. Thus, Rudolf will take the second place.

In the second example, both participants will get 1
 point and 30
 penalty minutes. In case of a tie in points, Rudolf gets the better position,
so he will take the first place.

In the third example, Rudolf is the only participant, so he will take the first
place.

In the fourth example, all participants can solve two problems with penalty of
25=8+(8+9) , 24=7+(7+10) and 26=8+(8+10) , respectively, thanks to the penalty,
the second participant gets the first place, and Rudolf gets the second.
*/

#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll t;
  std::cin >> t;

  while (t--) {
    ll n, m, h;
    std::cin >> n >> m >> h;

    std::vector<ll> v(m);
    for (ll p = 0; p < m; ++p) {
      std::cin >> v[p];
    }

    std::sort(v.begin(), v.end());

    ll ct = 0, ms = 0, mp = 0;
    for (ll p = 0; p < m; ++p) {
      ct += v[p];
      if (ct > h)
        break;
      ++ms;
      mp += ct;
    }

    ll ans = 1; // Team 0 is always counted

    for (ll idx = 1; idx < n; ++idx) {
      for (ll p = 0; p < m; ++p) {
        std::cin >> v[p];
      }

      std::sort(v.begin(), v.end());

      ct = 0;
      ll cnt = 0, penalty = 0;
      for (ll p = 0; p < m; ++p) {
        ct += v[p];
        if (ct > h)
          break;
        ++cnt;
        penalty += ct;
      }

      if (cnt < ms)
        continue;
      else if (cnt > ms)
        ++ans;
      else if (penalty < mp)
        ++ans;
    }

    std::cout << ans << '\n';
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1846/332449256

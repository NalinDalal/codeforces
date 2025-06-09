/* A. Soccer
time limit per test1 second
memory limit per test256 megabytes
Dima loves watching soccer. In such a game, the score on the scoreboard is
represented as 𝑥 : 𝑦 , where 𝑥 is the number of goals of the first team, and 𝑦
 is the number of goals of the second team. At any given time, only one team can
score a goal, so the score 𝑥 : 𝑦 can change to either (𝑥+1) : 𝑦 , or 𝑥 : (𝑦+1)
.

While watching a soccer game, Dima was distracted by very important matters, and
after some time, he returned to watching the game. Dima remembers the score
right before he was distracted, and the score right after he returned. Given
these two scores, he wonders the following question. Is it possible that, while
Dima was not watching the game, the teams never had an equal score?

It is guaranteed that at neither of the two time points Dima remembers the teams
had equal scores. However, it is possible that the score did not change during
his absence.

Help Dima and answer the question!

Input
Each test consists of several test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers 𝑥1,𝑦1
 (0≤𝑥1,𝑦1≤109
, 𝑥1≠𝑦1
) — the score before Dima was distracted.

The second line of each test case contains two integers 𝑥2,𝑦2
 (𝑥1≤𝑥2≤109
, 𝑦1≤𝑦2≤109
, 𝑥2≠𝑦2
) — the score when Dima returned.

Output
For each test case, output "YES" without quotes if it is possible, that the
teams never had a tie while Dima was away, otherwise output "NO" without quotes.

You can output each letter in any case (for example, the strings "yEs", "yes",
"Yes", and "YES" will be recognized as a positive answer).

Example
InputCopy
6
1 0
5 0
1 2
3 2
1 2
4 5
1 2
4 3
1 2
1 2
998244353 0
1000000000 999999999
OutputCopy
YES
NO
YES
NO
YES
YES
Note
In the first test case, the score before Dima left was 1
 : 0
. When he leaves, the first team scores several goals in a row until the score
becomes 5 : 0 , so the answer is YES.

In the second test case, the score could only change as follows:

1
 : 2
2
 : 2
3
 : 2
In this scenario, there is a moment when the teams have an equal score, so the
answer is NO.

In the third test case, one of the possible developments is:

1
 : 2
1
 : 3
2
 : 3
2
 : 4
2
 : 5
3
 : 5
4
 : 5
In this scenario, there was no time when the score was equal, so the answer is
YES.



*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long long x1, y1, x2, y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    puts((x1 - y1) * (x2 - y2) > 0 ? "YES" : "NO");
    // x2,y2 is score when dima returned
    //  YES if teams never had a tie while Dima was away,
    // else NO
  }
}
// sub: https://codeforces.com/problemset/submission/1982/323579226

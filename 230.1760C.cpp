/*C. Advantage
time limit per test2 seconds
memory limit per test256 megabytes
There are 𝑛
 participants in a competition, participant 𝑖
 having a strength of 𝑠𝑖
.

Every participant wonders how much of an advantage they have over the other best
participant. In other words, each participant 𝑖 wants to know the difference
between 𝑠𝑖 and 𝑠𝑗 , where 𝑗 is the strongest participant in the competition, not
counting 𝑖 (a difference can be negative).

So, they ask you for your help! For each 𝑖
 (1≤𝑖≤𝑛
) output the difference between 𝑠𝑖
 and the maximum strength of any participant other than participant 𝑖
.

Input
The input consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the array.

The following line contains 𝑛
 space-separated positive integers 𝑠1
, 𝑠2
, ..., 𝑠𝑛
 (1≤𝑠𝑖≤109
) — the strengths of the participants.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 space-separated integers. For each 𝑖
 (1≤𝑖≤𝑛
) output the difference between 𝑠𝑖
 and the maximum strength of any other participant.

Example
InputCopy
5
4
4 7 3 5
2
1 2
5
1 2 3 4 5
3
4 9 4
4
4 4 4 4
OutputCopy
-3 2 -4 -2
-1 1
-4 -3 -2 -1 1
-5 5 -5
0 0 0 0
Note
For the first test case:

The first participant has a strength of 4
 and the largest strength of a participant different from the first one is 7
, so the answer for the first participant is 4−7=−3
.
The second participant has a strength of 7
 and the largest strength of a participant different from the second one is 5
, so the answer for the second participant is 7−5=2
.
The third participant has a strength of 3
 and the largest strength of a participant different from the third one is 7
, so the answer for the third participant is 3−7=−4
.
The fourth participant has a strength of 5
 and the largest strength of a participant different from the fourth one is 7
, so the answer for the fourth participant is 5−7=−2
.*/
#include <cstdio>
#include <vector>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    std::vector<long> v(n);
    long mxa(0), mxb(0);
    for (long p = 0; p < n; p++) {
      scanf("%ld", &v[p]);
      if (v[p] >= mxa) {
        mxb = mxa;
        mxa = v[p];
      } else if (v[p] > mxb) {
        mxb = v[p];
      }
    }

    for (long p = 0; p < n; p++) {
      printf("%ld ", v[p] - ((v[p] == mxa) ? mxb : mxa));
    }
    puts("");
  }
}
// sub: https://codeforces.com/problemset/submission/1760/310723075

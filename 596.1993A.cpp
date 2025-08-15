/*A. Question Marks
time limit per test1 second
memory limit per test256 megabytes
Tim is doing a test consisting of 4𝑛
 questions; each question has 4
 options: 'A', 'B', 'C', and 'D'. For each option, there are exactly 𝑛
 correct answers corresponding to that option — meaning there are 𝑛
 questions with the answer 'A', 𝑛
 questions with the answer 'B', 𝑛
 questions with the answer 'C', and 𝑛
 questions with the answer 'D'.

For each question, Tim wrote his answer on the answer sheet. If he could not
figure out the answer, he would leave a question mark '?' for that question.

You are given his answer sheet of 4𝑛
 characters. What is the maximum number of correct answers Tim can get?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤100
).

The second line of each test case contains a string 𝑠
 of 4𝑛
 characters (𝑠𝑖∈{𝙰,𝙱,𝙲,𝙳,?}
) — Tim's answers for the questions.

Output
For each test case, print a single integer — the maximum score that Tim can
achieve.

Example
InputCopy
6
1
ABCD
2
AAAAAAAA
2
AAAABBBB
2
????????
3
ABCABCABCABC
5
ACADC??ACAC?DCAABC?C
OutputCopy
4
2
4
0
9
13
Note
In the first test case, there is exactly one question with each answer 'A', 'B',
'C', and 'D'; so it's possible that Tim gets all his answers correct.

In the second test case, there are only two correct answers 'A' which makes him
get exactly 2 points in any case.

In the third test case, Tim can get at most 2
 correct answers with option 'A' and 2
 correct answers with option 'B'. For example, he would get 4
 points if the answers were 'AACCBBDD'.

In the fourth test case, he refuses to answer any question at all, which makes
him get 0 points.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans;

    // see string is of length 4n
    // there are total 4n questions
    // now n question have A, n have B, n jave C, and n have D
    // so thereforce ans becomes 4n
    //?-> ans not deduced
    // well what if we do like are there
    // ans is max score achieved
    int a = 0, b = 0, c = 0, d = 0;
    for (int p = 0; p < s.size(); p++) {
      a += (s[p] == 'A');
      b += (s[p] == 'B');
      c += (s[p] == 'C');
      d += (s[p] == 'D');
    }
    ans = (a < n ? a : n) + (b < n ? b : n) + (c < n ? c : n) + (d < n ? d : n);
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1993/334000313

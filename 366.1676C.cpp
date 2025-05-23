/* C. Most Similar Words
time limit per test2 seconds
memory limit per test256 megabytes
You are given 𝑛
 words of equal length 𝑚
, consisting of lowercase Latin alphabet letters. The 𝑖
-th word is denoted 𝑠𝑖
.

In one move you can choose any position in any single word and change the letter
at that position to the previous or next letter in alphabetical order. For
example:

you can change 'e' to 'd' or to 'f';
'a' can only be changed to 'b';
'z' can only be changed to 'y'.
The difference between two words is the minimum number of moves required to make
them equal. For example, the difference between "best" and "cost" is 1+10+0+0=11
.

Find the minimum difference of 𝑠𝑖
 and 𝑠𝑗
 such that (𝑖<𝑗)
. In other words, find the minimum difference over all possible pairs of the 𝑛
 words.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. The description of test cases follows.

The first line of each test case contains 2
 integers 𝑛
 and 𝑚
 (2≤𝑛≤50
, 1≤𝑚≤8
) — the number of strings and their length respectively.

Then follows 𝑛
 lines, the 𝑖
-th of which containing a single string 𝑠𝑖
 of length 𝑚
, consisting of lowercase Latin letters.

Output
For each test case, print a single integer — the minimum difference over all
possible pairs of the given strings.

Example
InputCopy
6
2 4
best
cost
6 3
abb
zba
bef
cdu
ooo
zzz
2 7
aaabbbc
bbaezfe
3 2
ab
ab
ab
2 8
aaaaaaaa
zzzzzzzz
3 1
a
u
y
OutputCopy
11
8
35
0
200
4
Note
For the second test case, one can show that the best pair is ("abb","bef"),
which has difference equal to 8 , which can be obtained in the following way:
change the first character of the first string to 'b' in one move, change the
second character of the second string to 'b' in 3 moves and change the third
character of the second string to 'b' in 4 moves, thus making in total 1+3+4=8
 moves.

For the third test case, there is only one possible pair and it can be shown
that the minimum amount of moves necessary to make the strings equal is 35
.

For the fourth test case, there is a pair of strings which is already equal, so
the answer is 0
.


*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    // n - no of string
    // m - length of string
    // basically traverse both the array, compare their chars step by step
    // then basically find diff b/w two strings by comparing chars
    // return the min diff
    // say play each as potential
    // For each candidate string, calculate the maximum Hamming distance with
    // the other n-1 strings.

    // Return the candidate with the smallest maximum Hamming distance.
    std::vector<std::string> v(n);
    for (long p = 0; p < n; p++) {
      std::cin >> v[p];
    }

    long mn(1e9);
    for (long p = 0; p < n; p++) {
      for (long q = p + 1; q < n; q++) {
        long dist(0);
        for (long u = 0; u < m; u++) {
          long x = v[p][u] - v[q][u];
          dist += (x < 0 ? -x : x);
        }

        mn = (dist < mn) ? dist : mn;
      }
    }

    std::cout << mn << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1676/320878721

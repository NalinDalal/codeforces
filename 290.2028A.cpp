/* A. Alice's Adventures in "Chess"
time limit per test1 second
memory limit per test256 megabytes
Alice is trying to meet up with the Red Queen in the countryside! Right now,
Alice is at position (0,0) , and the Red Queen is at position (𝑎,𝑏) . Alice can
only move in the four cardinal directions (north, east, south, west).

More formally, if Alice is at the point (𝑥,𝑦)
, she will do one of the following:

go north (represented by N), moving to (𝑥,𝑦+1)
;
go east (represented by E), moving to (𝑥+1,𝑦)
;
go south (represented by S), moving to (𝑥,𝑦−1)
; or
go west (represented by W), moving to (𝑥−1,𝑦)
.
Alice's movements are predetermined. She has a string 𝑠
 representing a sequence of moves that she performs from left to right. Once she
reaches the end of the sequence, she repeats the same pattern of moves forever.

Can you help Alice figure out if she will ever meet the Red Queen?

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains three integers 𝑛
, 𝑎
, 𝑏
 (1≤𝑛
, 𝑎
, 𝑏≤10
) — the length of the string and the initial coordinates of the Red Queen.

The second line contains a string 𝑠
 of length 𝑛
 consisting only of the characters N, E, S, or W.

Output
For each test case, output a single string "YES" or "NO" (without the quotes)
denoting whether Alice will eventually meet the Red Queen.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
2 2 2
NE
3 2 2
NNE
6 2 1
NNEESW
6 10 10
NNEESW
3 4 2
NEE
4 5 5
NEWS
OutputCopy
YES
NO
YES
YES
YES
NO
Note
In the first test case, Alice follows the path
(0,0)−→𝙽(0,1)−→𝙴(1,1)−→𝙽(1,2)−→𝙴(2,2)
.

In the second test case, Alice can never reach the Red Queen.



*/
#include <iostream>

bool check(long x, long y, long a, long b, long xt, long yt) {
  if (xt == 0 && yt == 0) {
    return x == a && y == b;
  } else if (xt == 0) {
    return (x == a && (b - y) % yt == 0 && (b - y) / yt > 0);
  } else if (yt == 0) {
    return (y == b && (a - x) % xt == 0 && (a - x) / xt > 0);
  } else {
    return (a - x) % xt == 0 && (b - y) % yt == 0 && (a - x) / xt >= 0 &&
           (a - x) / xt == (b - y) / yt;
  }
}

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    long xt(0), yt(0);
    for (long p = 0; p < s.size(); p++) {
      if (s[p] == 'N') {
        ++yt;
      } else if (s[p] == 'S') {
        --yt;
      } else if (s[p] == 'E') {
        ++xt;
      } else if (s[p] == 'W') {
        --xt;
      }
    }

    long x(0), y(0);
    bool ans(check(0, 0, a, b, xt, yt));
    for (long p = 0; p < s.size() && !ans; p++) {
      if (s[p] == 'N') {
        ++y;
      } else if (s[p] == 'S') {
        --y;
      } else if (s[p] == 'E') {
        ++x;
      } else if (s[p] == 'W') {
        --x;
      }
      if (check(x, y, a, b, xt, yt)) {
        ans = true;
      }
    }

    std::cout << (ans ? "YES" : "NO") << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2028/314950468

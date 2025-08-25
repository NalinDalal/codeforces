/*B. Chess Tournament
time limit per test2 seconds
memory limit per test256 megabytes
A chess tournament will be held soon, where 𝑛
 chess players will take part. Every participant will play one game against
every other participant. Each game ends in either a win for one player and a
loss for another player, or a draw for both players.

Each of the players has their own expectations about the tournament, they can be
one of two types:

a player wants not to lose any game (i. e. finish the tournament with zero
losses); a player wants to win at least one game. You have to determine if there
exists an outcome for all the matches such that all the players meet their
expectations. If there are several possible outcomes, print any of them. If
there are none, report that it's impossible.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤200
) — the number of test cases.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤50
) — the number of chess players.

The second line contains the string 𝑠
 (|𝑠|=𝑛
; 𝑠𝑖∈{1,2}
). If 𝑠𝑖=1
, then the 𝑖
-th player has expectations of the first type, otherwise of the second type.

Output
For each test case, print the answer in the following format:

In the first line, print NO if it is impossible to meet the expectations of all
players.

Otherwise, print YES, and the matrix of size 𝑛×𝑛
 in the next 𝑛
 lines.

The matrix element in the 𝑖
-th row and 𝑗
-th column should be equal to:

+, if the 𝑖
-th player won in a game against the 𝑗
-th player;
-, if the 𝑖
-th player lost in a game against the 𝑗
-th player;
=, if the 𝑖
-th and 𝑗
-th players' game resulted in a draw;
X, if 𝑖=𝑗
.
Example
InputCopy
3
3
111
2
21
4
2122
OutputCopy
YES
X==
=X=
==X
NO
YES
X--+
+X++
+-X-
--+X
*/

#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<long> next(n);
    long idx(-1), first(-1);
    long twos(0);
    for (long p = 0; p < s.size(); p++) {
      if (s[p] != '2') {
        continue;
      }
      ++twos;
      if (idx < 0) {
        idx = p;
        first = p;
      } else {
        next[idx] = p;
        idx = p;
      }
    }
    if (first >= 0) {
      next[idx] = first;
    }

    if (twos == 1 || twos == 2) {
      std::cout << "NO" << std::endl;
      continue;
    }

    std::vector<std::string> res(n, std::string(n, ' '));
    for (long row = 0; row < n; row++) {
      for (long col = 0; col < n; col++) {
        char cur('=');
        if (row == col) {
          cur = 'X';
        } else if (s[row] == '2' && s[col] == '2' && next[row] == col) {
          cur = '+';
        } else if (s[row] == '2' && s[col] == '2' && next[col] == row) {
          cur = '-';
        }
        res[row][col] = cur;
      }
    }

    std::cout << "YES" << std::endl;
    for (long p = 0; p < n; p++) {
      std::cout << res[p] << std::endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1569/335442082

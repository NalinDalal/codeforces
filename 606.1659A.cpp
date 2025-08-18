/*A. Red Versus Blue
time limit per test1 second
memory limit per test256 megabytes
Team Red and Team Blue competed in a competitive FPS. Their match was streamed
around the world. They played a series of 𝑛 matches.

In the end, it turned out Team Red won 𝑟
 times and Team Blue won 𝑏
 times. Team Blue was less skilled than Team Red, so 𝑏
 was strictly less than 𝑟
.

You missed the stream since you overslept, but you think that the match must
have been neck and neck since so many people watched it. So you imagine a string
of length 𝑛 where the 𝑖 -th character denotes who won the 𝑖 -th match  — it is R
if Team Red won or B if Team Blue won. You imagine the string was such that the
maximum number of times a team won in a row was as small as possible. For
example, in the series of matches RBBRRRB, Team Red won 3 times in a row, which
is the maximum.

You must find a string satisfying the above conditions. If there are multiple
answers, print any.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
)  — the number of test cases.

Each test case has a single line containing three integers 𝑛
, 𝑟
, and 𝑏
 (3≤𝑛≤100
; 1≤𝑏<𝑟≤𝑛
, 𝑟+𝑏=𝑛
).

Output
For each test case, output a single line containing a string satisfying the
given conditions. If there are multiple answers, print any.

Examples
InputCopy
3
7 4 3
6 5 1
19 13 6
OutputCopy
RBRBRBR
RRRBRR
RRBRRBRRBRRBRRBRRBR
InputCopy
6
3 2 1
10 6 4
11 6 5
10 9 1
10 8 2
11 9 2
OutputCopy
RBR
RRBRBRBRBR
RBRBRBRBRBR
RRRRRBRRRR
RRRBRRRBRR
RRRBRRRBRRR
Note
The first test case of the first example gives the optimal answer for the
example in the statement. The maximum number of times a team wins in a row in
RBRBRBR is 1 . We cannot minimize it any further.

The answer for the second test case of the second example is RRBRBRBRBR. The
maximum number of times a team wins in a row is 2 , given by RR at the
beginning. We cannot minimize the answer any further.

*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, r, b;
    std::cin >> n >> r >> b;
    long d = r / (b + 1);
    long m = r % (b + 1);

    for (long p = 0; p <= b; p++) {
      for (long u = 0; u < d + (p < m); u++) {
        std::cout << "R";
      }
      if (p < b) {
        std::cout << "B";
      }
    }

    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1659/334332246

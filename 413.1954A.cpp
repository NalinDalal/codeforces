/* A. Painting the Ribbon
time limit per test2 seconds
memory limit per test512 megabytes
Alice and Bob have bought a ribbon consisting of 𝑛
 parts. Now they want to paint it.

First, Alice will paint every part of the ribbon into one of 𝑚
 colors. For each part, she can choose its color arbitrarily.

Then, Bob will choose at most 𝑘
 parts of the ribbon and repaint them into the same color (he chooses the
affected parts and the color arbitrarily).

Bob would like all parts to have the same color. However, Alice thinks that this
is too dull, so she wants to paint the ribbon in such a way that Bob cannot make
all parts have the same color.

Is it possible to paint the ribbon in such a way?

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of one line containing three integers 𝑛
, 𝑚
 and 𝑘
 (1≤𝑚,𝑘≤𝑛≤50
) — the number of parts, the number of colors and the number of parts Bob can
repaint, respectively.

Output
For each test case, print YES if Alice can paint the ribbon so that Bob cannot
make all parts have the same color. Otherwise, print NO.

You can print every letter in any register. For example, Yes, yes, yEs will all
be recognized as positive answer.

Example
InputCopy
5
1 1 1
5 1 1
5 2 1
5 2 2
5 5 3
OutputCopy
NO
NO
YES
NO
YES
Note
In the first test case, a ribbon consists of 1
 part. So all its parts will always have the same color.

In the second test case, there is only 1
 color.

In the third test case, Alice can paint the ribbon as follows: [1,2,1,2,1]
. It's impossible to change the color of at most 1
 part so that all parts have the same color.

In the fourth test case, no matter how Alice paints the ribbon, Bob will always
be able to repaint 2 parts so that all parts have the same color.

In the fifth test case, Alice can paint the ribbon as follows: [1,2,3,4,5]
. It's impossible to change the color of at most 3
 parts so that all parts have the same color.


*/

#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m, k;
    std::cin >> n >> m >> k;
    int need = (m - 1) * (n / m) + (n % m > 0) * (n % m - 1);
    std::cout << (k < need ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1954/324245580

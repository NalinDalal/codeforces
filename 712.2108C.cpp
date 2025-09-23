/*C. Neo's Escape
time limit per test2 seconds
memory limit per test256 megabytes

Neo wants to escape from the Matrix. In front of him are 𝑛
 buttons arranged in a row. Each button has a weight given by an integer:
𝑎1,𝑎2,…,𝑎𝑛
.

Neo is immobilized, but he can create and move clones. This means he can perform
an unlimited number of actions of the following two types in any order:

Create a clone in front of a specific button.
Move an existing clone one position to the left or right.
As soon as a clone is in front of another button that has not yet been
pressed—regardless of whether he was created or moved — he immediately presses
it. If the button has already been pressed, a clone does nothing — buttons can
only be pressed once.

For Neo to escape, he needs to press all the buttons in such an order that the
sequence of their weights is non-increasing — that is, if 𝑏1,𝑏2,…,𝑏𝑛 are the
weights of the buttons in the order they are pressed, then it must hold that
𝑏1≥𝑏2≥⋯≥𝑏𝑛
.

Your task is to determine the minimum number of clones that Neo needs to create
in order to press all the buttons in a valid order.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of buttons.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the weights of the buttons.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the minimum number of clones that need
to be created to press all the buttons in a valid order.

Example
InputCopy
4
5
4 3 2 1 5
3
1 1 1
6
7 8 1 5 9 2
10
1 7 9 7 1 10 2 10 10 7
OutputCopy
2
1
2
3
Note
In the first test case, Neo can act as follows:

Create a clone in front of the fifth button (with weight 5
).
Create a clone in front of the first button (with weight 4
).
Move the second clone from the first button to the second (with weight 3
).
Move the second clone from the second button to the third (with weight 2
).
Move the first clone from the fifth button to the fourth (with weight 1
).
Thus, the sequence of button presses will be 5→4→3→2→1
, which meets the requirement. It can be shown that the number of clones created
is the smallest possible. In the second test case, Neo can act as follows:

Create a clone in front of the second button (with weight 1
).
Move the clone from the second button to the third (with weight 1
).
Move the clone from the third button to the second (already pressed).
Move the clone from the second button to the first (with weight 1
).
Thus, the sequence of button presses will be 1→1→1
.
*/

#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<long> v;

    v.push_back(-1);
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      if (v.back() == x)
        continue;
      v.push_back(x);
    }
    v.push_back(-1);

    long cnt = 0;
    for (long p = 1; p + 1 < v.size(); p++) {
      if (v[p - 1] < v[p] && v[p] > v[p + 1])
        cnt++;
    }

    std::cout << cnt << "\n";
  }
}
// sub: https://codeforces.com/problemset/submission/2108/339970257

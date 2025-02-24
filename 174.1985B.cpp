/* B. Maximum Multiple Sum
time limit per test1 second
memory limit per test256 megabytes
Given an integer 𝑛, find an integer 𝑥 such that:2≤𝑥≤𝑛.
The sum of multiples of 𝑥 that are less than or equal to 𝑛 is maximized.
Formally, 𝑥+2𝑥+3𝑥+⋯+𝑘𝑥 where 𝑘𝑥≤n is maximized over all possible values of 𝑥.
Input
The first line contains 𝑡 (1≤𝑡≤100) — the number of test cases.

Each test case contains a single integer 𝑛 (2≤𝑛≤100).

Output
For each test case, output an integer, the optimal value of 𝑥. It can be shown
there is only one unique answer.

Example
InputCopy
2
3
15
OutputCopy
3
2
Note
For 𝑛=3, the possible values of 𝑥 are 2 and 3. The sum of all multiples of 2
less than or equal to 𝑛 is just 2, and the sum of all multiples of 3 less than
or equal to 𝑛 is 3. Therefore, 3 is the optimal value of 𝑥.

For 𝑛=15, the optimal value of 𝑥 is 2. The sum of all multiples of 2 less than
or equal to 𝑛 is 2+4+6+8+10+12+14=56, which can be proven to be the maximal over
all other possible values of 𝑥.*/

#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n == 3 ? 3 : 2) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1985/307562628

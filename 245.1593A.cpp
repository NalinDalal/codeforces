/*A. Elections
time limit per test1 second
memory limit per test256 megabytes
The elections in which three candidates participated have recently ended. The
first candidate received 𝑎 votes, the second one received 𝑏 votes, the third one
received 𝑐 votes. For each candidate, solve the following problem: how many
votes should be added to this candidate so that he wins the election (i.e. the
number of votes for this candidate was strictly greater than the number of votes
for any other candidate)?

Please note that for each candidate it is necessary to solve this problem
independently, i.e. the added votes for any candidate do not affect the
calculations when getting the answer for the other two candidates.

Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases. Then
𝑡 test cases follow.

Each test case consists of one line containing three integers 𝑎, 𝑏, and 𝑐
(0≤𝑎,𝑏,𝑐≤109).

Output
For each test case, output in a separate line three integers 𝐴, 𝐵, and 𝐶
(𝐴,𝐵,𝐶≥0) separated by spaces — the answers to the problem for the first,
second, andthird candidate, respectively.

Example
InputCopy
5
0 0 0
10 75 15
13 13 17
1000 0 0
0 1000000000 0
OutputCopy
1 1 1
66 0 61
5 5 0
0 1001 1001
1000000001 0 1000000001


*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    // how much votes should be added to a candidat so that he wins the election
    int mx = max(a, max(b, c));
    bool tie = (((a == mx) + (b == mx) + (c == mx)) > 1);
    // Output the converted numbers
    int c_a = (a == mx) ? tie : (mx - a + 1);
    int c_b = (b == mx) ? tie : (mx - b + 1);
    int c_c = (c == mx) ? tie : (mx - c + 1);

    cout << c_a << " " << c_b << " " << c_c << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1593/311480307

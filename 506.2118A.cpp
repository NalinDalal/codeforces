/*A. Equal Subsequences
time limit per test1 second
memory limit per test256 megabytes
We call a bitstring∗
 perfect if it has the same number of 𝟷𝟶𝟷
 and 𝟶𝟷𝟶
 subsequences†
. Construct a perfect bitstring of length 𝑛
 where the number of 𝟷
 characters it contains is exactly 𝑘
.

It can be proven that the construction is always possible. If there are multiple
solutions, output any of them.

∗
A bitstring is a string consisting only of the characters 𝟶
 and 𝟷
.

†
A sequence 𝑎
 is a subsequence of a string 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly zero or all) characters.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤100
, 0≤𝑘≤𝑛
) — the size of the bitstring and the number of 𝟷
 characters in the bitstring.

Output
For each test case, output the constructed bitstring. If there are multiple
solutions, output any of them.

Example
InputCopy
5
4 2
5 3
5 5
6 2
1 1
OutputCopy
1010
10110
11111
100010
1
Note
In the first test case, the number of 𝟷𝟶𝟷
 and 𝟶𝟷𝟶
 subsequences is the same, both being 1
, and the sequence contains exactly two 𝟷
 characters.

In the second test case, the number of 𝟷𝟶𝟷
 and 𝟶𝟷𝟶
 subsequences is the same, both being 2
, and the sequence contains exactly three 𝟷
 characters.

In the third test case, the number of 𝟷𝟶𝟷
 and 𝟶𝟷𝟶
 subsequences is the same, both being 0
, and the sequence contains exactly five 𝟷
 characters.
*/

/*You're given:

- A bitstring of length n, with exactly k ones ('1's).

- You must construct a perfect bitstring, defined as:

    The number of subsequences "101" and "010" must be equal.

- Each test case gives n and k.

Goal: For each test case, construct such a string and print it.


*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << std::string(n - k, '0') << std::string(k, '1') << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2118/329191375

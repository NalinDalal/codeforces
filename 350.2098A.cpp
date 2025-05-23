/* A. Vadim's Collection
time limit per test1 second
memory limit per test256 megabytes
We call a phone number a beautiful if it is a string of 10
 digits, where the 𝑖
-th digit from the left is at least 10−𝑖
. That is, the first digit must be at least 9
, the second at least 8
, …
, with the last digit being at least 0
.

For example, 9988776655 is a beautiful phone number, while 9099999999 is not,
since the second digit, which is 0 , is less than 8
.

Vadim has a beautiful phone number. He wants to rearrange its digits in such a
way that the result is the smallest possible beautiful phone number. Help Vadim
solve this problem.

Please note that the phone numbers are compared as integers.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The only line of each test case contains a single string 𝑠
 of length 10
, consisting of digits. It is guaranteed that 𝑠
 is a beautiful phone number.

Output
For each test case, output a single string of length 10
 — the smallest possible beautiful phone number that Vadim can obtain.

Example
InputCopy
4
9999999999
9988776655
9988776650
9899999999
OutputCopy
9999999999
9876556789
9876567890
9899999999
Note
In the first test case, for the first phone number 9999999999, regardless of the
rearrangement of digits, the same phone number is obtained.

In the second test case, for the phone number 9988776655, it can be proven that
9876556789 is the smallest phone number that can be obtained by rearranging the
digits.


*/

#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int v[10] = {0};
    for (int i = 0; i < s.size(); i++)
      ++v[s[i] - '0'];

    string w(s);
    for (int i = 0; i < s.size(); i++) {
      for (int u = 9 - i; u < 10; u++) {
        if (!v[u]) {
          continue;
        }
        w[i] = '0' + u;
        --v[u];
        break;
      }
    }
    cout << w << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2098/319860580

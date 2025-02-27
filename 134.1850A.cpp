/* A. To My Critics
time limit per test1 second
memory limit per test256 megabytes
Suneet has three digits 𝑎
, 𝑏
, and 𝑐
.

Since math isn't his strongest point, he asks you to determine if you can choose
any two digits to make a sum greater or equal to 10
.

Output "YES" if there is such a pair, and "NO" otherwise.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The only line of each test case contains three digits 𝑎
, 𝑏
, 𝑐
 (0≤𝑎,𝑏,𝑐≤9
).

Output
For each test case, output "YES" if such a pair exists, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
5
8 1 2
4 4 5
9 9 9
0 0 0
8 5 3
OutputCopy
YES
NO
YES
NO
YES
Note
For the first test case, by choosing the digits 8
 and 2
 we can obtain a sum of 8+2=10
 which satisfies the condition, thus the output should be "YES".

For the second test case, any combination of chosen digits won't be at least 10
, thus the output should be "NO" (note that we can not choose the digit on the
same position twice).

For the third test case, any combination of chosen digits will have a sum equal
to 18 , thus the output should be "YES".


*/

#include <iostream>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 10 || b + c >= 10 || c + a >= 10)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1850/306069321

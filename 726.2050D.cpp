/*D. Digital string maximization
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑠
, consisting of digits from 0
 to 9
. In one operation, you can pick any digit in this string, except for 0
 or the leftmost digit, decrease it by 1
, and then swap it with the digit left to the picked.

For example, in one operation from the string 1023
, you can get 1103
 or 1022
.

Find the lexicographically maximum string you can obtain after any number of
operations.

Input
The first line of the input consists of an integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

Each test case consists of a single line consisting of a digital string 𝑠
 (1≤|𝑠|≤2⋅105
), where |𝑠|
 denotes the length of 𝑠
. The string does not contain leading zeroes.

It is guaranteed that the sum of |𝑠|
 of all test cases doesn't exceed 2⋅105
.

Output
For each test case, print the answer on a separate line.

Example
InputCopy
6
19
1709
11555
51476
9876543210
5891917899
OutputCopy
81
6710
33311
55431
9876543210
7875567711
Note
In the first example, the following sequence of operations is suitable: 19→81
.

In the second example, the following sequence of operations is suitable:
1709→1780→6180→6710
.

In the fourth example, the following sequence of operations is suitable:
51476→53176→53616→53651→55351→55431
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> digits(s.size());
    for (int i = 0; i < s.size(); i++) // n
      digits[i] = s[i] - '0';

    for (int i = 1; i < s.size(); i++) // n
    {
      int copy_i = i;
      while (copy_i >= 1 && digits[copy_i] > 0 &&
             digits[copy_i] > digits[copy_i - 1] + 1) // 10
      {
        int val = digits[copy_i];
        digits[copy_i] = digits[copy_i - 1];
        digits[copy_i - 1] = val - 1;
        if (copy_i > 1)
          copy_i--;
        else
          break;
      }
    } // n * 10
    string res = "";
    for (int d : digits)
      res += to_string(d);
    cout << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2050/340914442

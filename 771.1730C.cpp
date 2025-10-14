/*C. Minimum Notation
time limit per test1 second
memory limit per test256 megabytes
You have a string 𝑠
 consisting of digits from 0
 to 9
 inclusive. You can perform the following operation any (possibly zero) number
of times:

You can choose a position 𝑖
 and delete a digit 𝑑
 on the 𝑖
-th position. Then insert the digit min(𝑑+1,9)
 on any position (at the beginning, at the end or in between any two adjacent
digits). What is the lexicographically smallest string you can get by performing
these operations?

A string 𝑎
 is lexicographically smaller than a string 𝑏
 of the same length if and only if the following holds:

in the first position where 𝑎
 and 𝑏
 differ, the string 𝑎
 has a smaller digit than the corresponding digit in 𝑏
.
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then the test cases follow.

Each test case consists of a single line that contains one string 𝑠
 (1≤|𝑠|≤2⋅105
) — the string consisting of digits. Please note that 𝑠
 is just a string consisting of digits, so leading zeros are allowed.

It is guaranteed that the sum of lengths of 𝑠
 over all test cases does not exceed 2⋅105
.

Output
Print a single string — the minimum string that is possible to obtain.

Example
InputCopy
4
04829
9
01
314752277691991
OutputCopy
02599
9
01
111334567888999
Note
In the first test case:

Delete 8
 and insert 9
 at the end of the notation. The resulting notation is 04299
.
Delete 4
 and insert 5
 in the 3
-rd position of the notation. The resulting notation is 02599
.
Nothing needs to be done in the second and third test cases.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();

    int last = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] < s[i - 1])
        last = i;
    }

    for (int i = last - 1; i >= 0; --i) {
      if (s[i] > s[last])
        s[i] = min(s[i] + 1, int('9')); // ✅ cast to int
      else
        last = i;
    }

    sort(s.begin(), s.end());
    cout << s << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1730/343658628

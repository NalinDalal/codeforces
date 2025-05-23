/* A. Div. 7
time limit per test2 seconds
memory limit per test512 megabytes
You are given an integer 𝑛
. You have to change the minimum number of digits in it in such a way that the
resulting number does not have any leading zeroes and is divisible by 7
.

If there are multiple ways to do it, print any of them. If the given number is
already divisible by 7 , leave it unchanged.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤990
) — the number of test cases.

Then the test cases follow, each test case consists of one line containing one
integer 𝑛 (10≤𝑛≤999
).

Output
For each test case, print one integer without any leading zeroes — the result of
your changes (i. e. the integer that is divisible by 7 and can be obtained by
changing the minimum possible number of digits in 𝑛
).

If there are multiple ways to apply changes, print any resulting number. If the
given number is already divisible by 7 , just print it.

Example
InputCopy
3
42
23
377
OutputCopy
42
28
777
Note
In the first test case of the example, 42
 is already divisible by 7
, so there's no need to change it.

In the second test case of the example, there are multiple answers — 28, 21
or 63.

In the third test case of the example, other possible answers are 357, 371 and
378. Note that you cannot print 077 or 77.



*/
#include <iostream>
#include <string>

using namespace std;

int transform(int n) {
  // transform the no so that it is divisible by 7
  // keep the size as it is if possible
  // check how much is remainder, now subtract that much from the number
  // return the updated number, logic may nit work
  // better approach: Try all values from n - (n % 10) to n + (9 - n % 10) and
  // return the first one divisible by 7 and same digit length.
  int digits = to_string(n).size();
  int base = n - (n % 10); // change only the last digit

  for (int i = 0; i < 10; ++i) {
    int candidate = base + i;
    if (candidate % 7 == 0 && to_string(candidate).size() == digits) {
      return candidate;
    }
  }
  return n; // fallback, though it should never hit this
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 7)
      cout << transform(n) << endl;
    else
      cout << n << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1633/320876765

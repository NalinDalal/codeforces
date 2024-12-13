/* A. Nearly Lucky Number
time limit per test2 seconds
memory limit per test256 megabytes
Petya loves lucky numbers. We all know that lucky numbers are the positive
integers whose decimal representations contain only the lucky digits 4 and 7.
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Unfortunately, not all numbers are lucky. Petya calls a number nearly lucky if
the number of lucky digits in it is a lucky number. He wonders whether number n
is a nearly lucky number.

Input
The only line contains an integer n (1 ≤ n ≤ 1018).
Please do not use the %lld specificator to read or write 64-bit numbers in С++.
It is preferred to use the cin, cout streams or the %I64d specificator.

Output
Print on the single line "YES" if n is a nearly lucky number. Otherwise, print
"NO" (without the quotes).

Examples
Input: 40047
Output: NO

Input: 7747774
Output: YES

Input: 1000000000000000000
Output: NO

Note
In the first sample there are 3 lucky digits (first one and last two), so the
answer is "NO". In the second sample there are 7 lucky digits, 7 is lucky
number, so the answer is "YES". In the third sample there are no lucky digits,
so the answer is "NO".
*/

// what to do:
// 1. convert the given number to string
// 2. find the number of lucky digits.A lucky digit is defined as '4' or '7'. We
// count these digits.
// 3. if count itself is a lucky number then print "YES", else print "NO"
#include <iostream>
#include <string>

using namespace std;

bool isLucky(int num) {
  string s = to_string(num);
  for (char c : s) {
    if (c != '4' && c != '7') {
      return false;
    }
  }
  return true;
}

int main() {
  string n;
  cin >> n;

  int luckyCount = 0;

  // Count the lucky digits in the number
  for (char digit : n) {
    if (digit == '4' || digit == '7') {
      luckyCount++;
    }
  }

  // Check if the luckyCount is a lucky number
  if (isLucky(luckyCount)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
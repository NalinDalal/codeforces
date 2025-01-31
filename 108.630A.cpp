/* https://codeforces.com/problemset/problem/630/A
A. Again Twenty Five!
time limit per test0.5 seconds
memory limit per test64 megabytes
The HR manager was disappointed again. The last applicant failed the interview
the same way as 24 previous ones. "Do I give such a hard task?" — the HR manager
thought. "Just raise number 5 to the power of n and get last two digits of the
number. Yes, of course, n can be rather big, and one cannot find the power using
a calculator, but we need people who are able to think, not just follow the
instructions."

Could you pass the interview in the machine vision company in IT City?

Input
The only line of the input contains a single integer n (2 ≤ n ≤ 2·1018) — the
power in which you need to raise number 5.

Output
Output the last two digits of 5n without spaces between them.

Examples
InputCopy
2
OutputCopy
25

*/

#include <iostream>
using namespace std;

// Function to perform modular exponentiation
int sol(int base, int exponent, int modulus) {
  int result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    base = (base * base) % modulus;
    exponent /= 2;
  }
  return result;
}
int main() {
  int n;
  cin >> n;
  // raise 5 to pwer of n
  // get last two digits
  // get the required num, get the last 2 digit using mod
  int ans = sol(5, n, 100);
  cout << ans % 100 + ans % 10;
  return 0;
}

// well coded at site one:
int main2() {
  int n;
  std::cin >> n;
  std::cout << 25 << std::endl;
  return 0;
}
// sol:https://codeforces.com/problemset/submission/630/303825327

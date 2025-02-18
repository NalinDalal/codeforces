/* A. Boring Apartments
time limit per test1 second
memory limit per test256 megabytes
There is a building consisting of 10 000 apartments numbered from 1 to 10 000,
inclusive.

Call an apartment boring, if its number consists of the same digit. Examples of
boring apartments are 11,2,777,9999 and so on.

Our character is a troublemaker, and he calls the intercoms of all boring
apartments, till someone answers the call, in the following order:

First he calls all apartments consisting of digit 1, in increasing order
(1,11,111,1111). Next he calls all apartments consisting of digit 2, in
increasing order (2,22,222,2222)And so on. The resident of the boring apartment
𝑥 answers the call, and our character stops calling anyone further.

Our character wants to know how many digits he pressed in total and your task is
to help him to count the total number of keypresses.

For example, if the resident of boring apartment 22 answered, then our character
called apartments with numbers 1,11,111,1111,2,22 and the total number of digits
he pressed is 1+2+3+4+1+2=13.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤36) — the number of test
cases.

The only line of the test case contains one integer 𝑥 (1≤𝑥≤9999) — the apartment
number of the resident who answered the call. It is guaranteed that 𝑥 consists
of the same digit.

Output
For each test case, print the answer: how many digits our character pressed in
total.

Example
InputCopy
4
22
9999
1
777
OutputCopy
13
90
1
66

*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x;
    std::cin >> x;
    int ans = 10 * ((x % 10) - 1) + (x / 1 > 0) + 2 * (x / 10 > 0) +
              3 * (x / 100 > 0) + 4 * (x / 1000 > 0);
    std::cout << ans << std::endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1433/306775975

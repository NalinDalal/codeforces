/*C. Long Multiplication
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integers 𝑥
 and 𝑦
 of the same length, consisting of digits from 1
 to 9
.

You can perform the following operation any number of times (possibly zero):
swap the 𝑖 -th digit in 𝑥 and the 𝑖 -th digit in 𝑦
.

For example, if 𝑥=73
 and 𝑦=31
, you can swap the 2
-nd digits and get 𝑥=71
 and 𝑦=33
.

Your task is to maximize the product of 𝑥
 and 𝑦
 using the aforementioned operation any number of times. If there are multiple
answers, print any of them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains a single integer 𝑥
 (1≤𝑥<10100
).

The second line of each test case contains a single integer 𝑦
 (1≤𝑦<10100
).

Additional constraint on input: the integers 𝑥
 and 𝑦
 consist only of digits from 1
 to 9
.

Output
For each test case, print two lines — the first line should contain the number 𝑥
 after performing the operations; similarly, the second line should contain the
number 𝑦 after performing the operations. If there are multiple answers, print
any of them.

Example
InputCopy
3
73
31
2
5
3516
3982
OutputCopy
71
33
5
2
3912
3586


*/

#include <iostream>
#include <string>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    std::string x, y;
    std::cin >> x >> y;

    bool diff(false);
    for (long p = 0; p < x.size(); p++) {
      if (x[p] == y[p]) {
        continue;
      } else if (!diff) {
        diff = true;
        if (x[p] < y[p]) {
          char tmp = x[p];
          x[p] = y[p];
          y[p] = tmp;
        }
      } else if (x[p] > y[p]) {
        char tmp = x[p];
        x[p] = y[p];
        y[p] = tmp;
      }
    }

    std::cout << x << std::endl << y << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1954/327264809

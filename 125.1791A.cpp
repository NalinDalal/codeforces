/* https://codeforces.com/problemset/problem/1791/A
A. Codeforces Checking
time limit per test1 second
memory limit per test256 megabytes
Given a lowercase Latin character (letter), check if it appears in the string
𝚌𝚘𝚍𝚎𝚏𝚘𝚛𝚌𝚎𝚜.

Input
The first line of the input contains an integer 𝑡 (1≤𝑡≤26) — the number of test
cases.

The only line of each test case contains a character 𝑐 — a single lowercase
Latin character (letter).

Output
For each test case, output "YES" (without quotes) if 𝑐 satisfies the condition,
and "NO" (without quotes) otherwise. You can output the answer in any case (for
example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a
positive answer).

Example
InputCopy
10
a
b
c
d
e
f
g
h
i
j
OutputCopy
NO
NO
YES
YES
YES
YES
NO
NO
NO
NO


*/
#include <iostream>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    char c;
    std::cin >> c;

    // check if c appears in string 'codeforces'
    // if yes, print 'YES'
    // else print 'NO'
    if (c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'f' || c == 'r' ||
        c == 's')
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1791/305783018

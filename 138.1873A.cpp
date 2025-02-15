/* A. Short Sort
time limit per test1 second
memory limit per test256 megabytes
There are three cards with letters 𝚊, 𝚋, 𝚌 placed in a row in some order. You
can do the following operation at most once: Pick two cards, and swap them.Is it
possible that the row becomes 𝚊𝚋𝚌 after the operation? Output "YES" if it is
possible, and "NO" otherwise.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤6) — the number of test cases.

The only line of each test case contains a single string consisting of each of
the three characters 𝚊, 𝚋, and 𝚌 exactly once, representing the cards.

Output
For each test case, output "YES" if you can make the row 𝚊𝚋𝚌 with at most one
operation, or "NO" otherwise. You can output the answer in any case (for
example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a
positive answer).

Example
InputCopy
6
abc
acb
bac
bca
cab
cba
OutputCopy
YES
YES
YES
NO
NO
YES
Note
In the first test case, we don't need to do any operations, since the row is
already 𝚊𝚋𝚌.

In the second test case, we can swap 𝚌 and 𝚋: 𝚊𝚌𝚋→𝚊𝚋𝚌.

In the third test case, we can swap 𝚋 and 𝚊: 𝚋𝚊𝚌→𝚊𝚋𝚌.

In the fourth test case, it is impossible to make 𝚊𝚋𝚌 using at most one
operation.
*/

#include <iostream>
#include <string>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;

    // cout yes if abc can be made with only 0/1 operation
    // else cout no
    if (s == "bca" || s == "cab")
      std::cout << "NO" << std::endl;
    else
      std::cout << "YES" << std::endl;

    // all instances of abc-> abc,acb,bac,bca,cab,cba
    // else wle->abc,acb,bac,bca,
    // bca,cab
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1873/306169961

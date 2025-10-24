/*C. Bracket Sequence Deletion
time limit per test2 seconds
memory limit per test256 megabytes
You are given a bracket sequence consisting of 𝑛
 characters '(' and/or )'. You perform several operations with it.

During one operation, you choose the shortest prefix of this string (some amount
of first characters of the string) that is good and remove it from the string.

The prefix is considered good if one of the following two conditions is
satisfied:

this prefix is a regular bracket sequence;
this prefix is a palindrome of length at least two.
A bracket sequence is called regular if it is possible to obtain a correct
arithmetic expression by inserting characters '+' and '1' into this sequence.
For example, sequences (())(), () and (()(())) are regular, while )(, (() and
(()))( are not.

The bracket sequence is called palindrome if it reads the same back and forth.
For example, the bracket sequences )), (( and )(() are palindromes, while
bracket sequences (), )( and ))( are not palindromes.

You stop performing the operations when it's not possible to find a good prefix.
Your task is to find the number of operations you will perform on the given
string and the number of remaining characters in the string.

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The next 2𝑡
 lines describe test cases.

The first line of the test case contains one integer 𝑛
 (1≤𝑛≤5⋅105
) — the length of the bracket sequence.

The second line of the test case contains 𝑛
 characters '(' and/or ')' — the bracket sequence itself.

It is guaranteed that the sum of 𝑛
 over all test cases do not exceed 5⋅105
 (∑𝑛≤5⋅105
).

Output
For each test case, print two integers 𝑐
 and 𝑟
 — the number of operations you will perform on the given bracket sequence and
the number of characters that remain in the string after performing all
operations.

Example
InputCopy
5
2
()
3
())
4
((((
5
)((()
6
)((()(
OutputCopy
1 0
1 1
2 0
1 0
1 1
*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    long cnt(0), rem(n);
    std::string cur("");
    for (long p = 0; p < n; p++) {
      cur += s[p];
      if (cur == "()" || (cur.size() > 1 && cur.back() == cur[0])) {
        ++cnt;
        rem -= cur.size();
        cur = "";
      }
    }

    std::cout << cnt << " " << rem << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1657/345438005

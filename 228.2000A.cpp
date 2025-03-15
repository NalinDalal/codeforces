/*A. Primary Task
time limit per test1 second
memory limit per test256 megabytes
Dmitry wrote down 𝑡
 integers on the board, and that is good. He is sure that he lost an important
integer 𝑛 among them, and that is bad.

The integer 𝑛
 had the form 10^x
 (𝑥≥2
), where the symbol '^
' denotes exponentiation.. Something went wrong, and Dmitry missed the symbol '^
' when writing the important integer. For example, instead of the integer 105
, he would have written 105
, and instead of 1019
, he would have written 1019
.

Dmitry wants to understand which of the integers on the board could have been
the important integer and which could not.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤104
) — the number of integers on the board.

The next 𝑡
 lines each contain an integer 𝑎
 (1≤𝑎≤10000
) — the next integer from the board.

Output
For each integer on the board, output "YES" if it could have been the important
integer and "NO" otherwise.

You may output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
7
100
1010
101
105
2033
1019
1002
OutputCopy
NO
YES
NO
YES
NO
YES
NO

*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string x;
    std::cin >> x;
    bool res = (x.size() > 2) && (x[0] == '1') && (x[1] == '0') &&
               (x[2] != '0') && (x != "101");
    std::cout << (res ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2000/310721661

/* A. Creating Words
time limit per test1 second
memory limit per test256 megabytes
Matthew is given two strings 𝑎 and 𝑏, both of length 3. He thinks it's
particularly funny to create two new words by swapping the first character of 𝑎
with the first character of 𝑏. He wants you to output 𝑎 and 𝑏 after the swap.

Note that the new words may not necessarily be different.

Input
The first line contains 𝑡 (1≤𝑡≤100)  — the number of test cases.
The first and only line of each test case contains two space-separated strings,
𝑎 and 𝑏, both of length 3. The strings only contain lowercase Latin letters.

Output
For each test case, after the swap, output 𝑎 and 𝑏, separated by a space.

Example
InputCopy
6
bit set
cat dog
hot dog
uwu owo
cat cat
zzz zzz
OutputCopy
sit bet
dat cog
dot hog
owu uwo
cat cat
zzz zzz
*/
#include <iostream>
using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {
    std::string x, y;
    std::cin >> x >> y;
    char c = x[0];
    x[0] = y[0];
    y[0] = c;
    std::cout << x << " " << y << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1985/306444941

/* A. Yogurt Sale
time limit per test1 second
memory limit per test256 megabytes
The price of one yogurt at the "Vosmiorochka" store is 𝑎 burles, but there is a
promotion where you can buy two yogurts for 𝑏 burles.

Maxim needs to buy exactly 𝑛 yogurts. When buying two yogurts, he can choose to
buy them at the regular price or at the promotion price.

What is the minimum amount of burles Maxim should spend to buy 𝑛 yogurts?

Input
The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first and only line of each test case contains three integers 𝑛, 𝑎, and 𝑏
(1≤𝑛≤100, 1≤𝑎,𝑏≤30) — the number of yogurts Maxim wants to buy, the price for
one yogurt, and the price for two yogurts on promotion.

Output
For each test case, print in a separate line the minimum cost of buying 𝑛
yogurts at "Vosmiorochka".

Example
InputCopy
4
2 5 9
3 5 9
3 5 11
4 5 11
OutputCopy
9
14
15
20
Note
In the third test case of the example, it is more advantageous to buy three
yogurts for 15 burles than two for 11 and one for 5.

In the fourth test case of the example, you need to buy four yogurts, each for 5
burles.
*/

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    int d = (2 * a < b ? (2 * a) : b);
    std::cout << (n / 2) * d + (n % 2) * a << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1955/308391677

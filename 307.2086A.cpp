/*A. Cloudberry Jam
time limit per test2 seconds
memory limit per test512 megabytes
The most valuable berry of the Karelian forests is cloudberry. To make jam from
cloudberries, you take equal amounts of berries and sugar and cook them. Thus,
if you have 2 kg of berries, you need 2 kg of sugar. However, from 2 kg of
berries and 2 kg of sugar, you will not get 4 kg of jam, as one might expect,
but only 3 kg, since some of the jam evaporates during cooking. Specifically,
during standard cooking, exactly a quarter (or 25% ) of the jam evaporates.

How many kilograms of cloudberries are needed to prepare 𝑛
 3
-kilogram jars of jam?


Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The following lines describe
the test cases.

Each test case contains a single integer 𝑛
 (1≤𝑛≤108
) — the number of jars of jam that need to be prepared.

Output
For each test case, output a single integer — the amount of berries needed for
the jam in kilograms.

Example
InputCopy
2
1
3
OutputCopy
2
6
Note
For the test case 1
, explanations are given in the text of the statement — to prepare 1
 jar of jam, you need 2
 kilograms of cloudberries.

Consider the test case 2
: if we take 6
 kilograms of berries and 6
 kilograms of sugar, we get (6+6)⋅3/4=9
 kilograms of jam; which gives 93=3
 jars of jam.
*/

#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    // 2 kg of berries need 2 kg sugar
    // but 2 kg berries and 2 kg sugar doesn't makes 4kg jam
    // it makes 3kg jam as 1/4th get evaporates

    // n is no of jars to be prepared
    // o/p amt of jerries needed
    // given k-> output is k/4
    // 2*x*3/4=n
    // value of n/3 is given
    // 6*x/4=n
    // n/3=2*x/4
    // n/3=x/2
    // x=2*n/3
    // 2kg berr+2kg sug-> 3 kg jam
    // 2kg berr->3kg jam
    // 1 kg jam-> 2/3 kg berr
    // 3kg jam-> 2 kg berr
    // n no of 3kg jam jar-> 2*n
    cout << 2 * n << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2086/316637196

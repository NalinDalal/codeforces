/* C. Simple Repetition
time limit per test1 second
memory limit per test256 megabytes
Pasha loves prime numbers∗
! Once again, in his attempts to find a new way to generate prime numbers, he
became interested in an algorithm he found on the internet:

To obtain a new number 𝑦
, repeat 𝑘
 times the decimal representation of the number 𝑥
 (without leading zeros).
For example, for 𝑥=52
 and 𝑘=3
, we get 𝑦=525252
, and for 𝑥=6
 and 𝑘=7
, we get 𝑦=6666666
.

Pasha really wants the resulting number 𝑦
 to be prime, but he doesn't yet know how to check the primality of numbers
generated by this algorithm. Help Pasha and tell him whether 𝑦 is prime!

∗
An integer 𝑥
 is considered prime if it has exactly 2
 distinct divisors: 1
 and 𝑥
. For example, 13
 is prime because it has only 2
 divisors: 1
 and 13
. Note that the number 1
 is not prime, as it has only one divisor.

Input
Each test consists of several sets of input data. The first line contains a
single integer 𝑡 (1≤𝑡≤100 ) — the number of sets of input data. The following
lines describe the sets of input data.

The first and only line of each data set contains two integers: 𝑥
 and 𝑘
 (1≤𝑥≤109
, 1≤𝑘≤7
).

Output
For each set of input data, output «YES» (without quotes) if the resulting
number 𝑦 will be prime, and «NO» otherwise.

You may output «Yes» and «No» in any case (for example, the strings «yES»,
«yes», and «Yes» will be recognized as positive answers).

Example
InputCopy
4
52 3
6 7
7 1
1 7
OutputCopy
NO
NO
YES
NO

*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, k;
    cin >> x >> k;
    if (x == 1) {
      cout << (k == 2 ? "Yes" : "No") << endl;
      continue;
    } else if (k > 1) {
      cout << "NO" << endl;
      continue;
    }

    bool ans = true;

    for (int p = 2; p * p <= x; p++) {
      if (x % p) {
        continue;
      }
      ans = false;
      break;
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2093/316766272

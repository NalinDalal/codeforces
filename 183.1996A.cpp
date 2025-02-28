/* A. Legs
time limit per test2 seconds
memory limit per test256 megabytes
It's another beautiful day on Farmer John's farm.

After Farmer John arrived at his farm, he counted 𝑛 legs. It is known only
chickens and cows live on the farm, and a chicken has 2 legs while a cow has 4.

What is the minimum number of animals Farmer John can have on his farm assuming
he counted the legs of all animals?

Input
The first line contains single integer 𝑡 (1≤𝑡≤103) — the number of test cases.

Each test case contains an integer 𝑛 (2≤𝑛≤2⋅103, 𝑛 is even).

Output
For each test case, output an integer, the minimum number of animals Farmer John
can have on his farm.

Example
Input
3
2
6
8
Output
1
2
2
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // return minimum no of animals
    // chicken-2 legs
    // cow-4 legs
    cout << ((n / 4) + (n % 4) / 2) << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1996/308386351

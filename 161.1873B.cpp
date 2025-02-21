/* B. Good Kid
time limit per test1 second
memory limit per test256 megabytes
Slavic is preparing a present for a friend's birthday. He has an array 𝑎 of 𝑛
digits and the present will be the product of all these digits. Because Slavic
is a good kid who wants to make the biggest product possible, he wants to add 1
to exactly one of his digits.

What is the maximum product Slavic can make?

Input
The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤9) — the
number of digits.

The second line of each test case contains 𝑛 space-separated integers 𝑎𝑖
(0≤𝑎𝑖≤9) — the digits in the array.

Output
For each test case, output a single integer — the maximum product Slavic can
make, by adding 1 to exactly one of his digits.

Example
InputCopy
4
4
2 2 1 2
3
0 1 2
5
4 3 2 3 4
9
9 9 9 9 9 9 9 9 9
OutputCopy
16
2
432
430467210

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);

    long long prod = 1;
    int min_val = 10, zero_count = 0;

    for (int i = 0; i < n; i++) {
      cin >> a[i];

      if (a[i] == 0) {
        zero_count++;
        continue;
      }

      prod *= a[i];
      if (a[i] < min_val) {
        min_val = a[i];
      }
    }

    if (zero_count > 1) {
      cout << "0\n";
    } else if (zero_count == 1) {
      cout << prod << "\n";
    } else {
      cout << (prod * (min_val + 1) / min_val) << "\n";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1873/307174432
/*

        long long prod(1); int m(10), z(0);
        for(long p = 0; p < n; p++){
            long x; scanf("%ld", &x);
            if(x == 0){++z; continue;}
            prod *= x;
            if(x < m){m = x;}
        }

        if(z > 1){puts("0");}
        else if(z == 1){printf("%lld\n", prod);}
        else{printf("%lld\n", prod * (m + 1) / m);}
    }

}*/

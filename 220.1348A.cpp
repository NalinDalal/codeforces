/*A. Phoenix and Balance
time limit per test2 seconds
memory limit per test256 megabytes
Phoenix has 𝑛 coins with weights 21,22,…,2𝑛. He knows that 𝑛 is even.

He wants to split the coins into two piles such that each pile has exactly 𝑛2
coins and the difference of weights between the two piles is minimized.
Formally, let 𝑎 denote the sum of weights in the first pile, and 𝑏 denote the
sum of weights in the second pile. Help Phoenix minimize |𝑎−𝑏|, the absolute
value of 𝑎−𝑏.

Input
The input consists of multiple test cases. The first line contains an integer 𝑡
(1≤𝑡≤100) — the number of test cases.

The first line of each test case contains an integer 𝑛 (2≤𝑛≤30; 𝑛 is even) — the
number of coins that Phoenix has.

Output
For each test case, output one integer — the minimum possible difference of
weights between the two piles.

Example
InputCopy
2
2
4
OutputCopy
2
6
Note
In the first test case, Phoenix has two coins with weights 2 and 4. No matter
how he divides the coins, the difference will be 4−2=2.

In the second test case, Phoenix has four coins of weight 2, 4, 8, and 16. It is
optimal for Phoenix to place coins with weights 2 and 16 in one pile, and coins
with weights 4 and 8 in another pile. The difference is (2+16)−(4+8)=6.
*/

/*#include <iostream>

using namespace std;
int main() {
  int t, n, a[10000];
  ;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // so coins are: 2,4,8,16....2^n
    // split into two pile such that each pile has n/2 coin
    // and pile1.wt-pile2.wt is minimized
    int ans = 0, sum1 = 0, sum2 = 0, div = 0, k = 0;
    for (int i = 1; i <= n; i++) {
      a[k++] = pow(2, i);
    }

    //        if(n==2){
    //            cout<<2<<endl;
    //            continue;
    //        }
    div = n / 2;
    sum1 = a[n - 1];
    for (int i = 0; i <= div - 2; i++) {
      sum1 += a[i];
    }
    for (int i = div - 1; i < n - 1; i++) {
      sum2 += a[i];
    }
    //        cout<<sum1<<" "<<sum2<<endl;
    ans = abs(sum1 - sum2);
    cout << ans << endl;
  }
  return 0;
}*/

#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int t, n, a[10000];
  cin >> t;
  while (t--) {
    long long int ans = 0, sum1 = 0, sum2 = 0;
    int div = 0;
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++) {
      a[k++] = pow(2, i);
    }

    div = n / 2;
    sum1 = a[n - 1];
    for (int i = 0; i <= div - 2; i++) {
      sum1 += a[i];
    }
    for (int i = div - 1; i < n - 1; i++) {
      sum2 += a[i];
    }
    ans = abs(sum1 - sum2);
    cout << ans << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1348/310370035

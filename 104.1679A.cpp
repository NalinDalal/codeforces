/* https://codeforces.com/problemset/problem/1679/A

A. AvtoBus
time limit per test1 second
memory limit per test256 megabytes
Spring has come, and the management of the AvtoBus bus fleet has given the order
to replace winter tires with summer tires on all buses.

You own a small bus service business and you have just received an order to
replace 𝑛 tires. You know that the bus fleet owns two types of buses: with two
axles (these buses have 4 wheels) and with three axles (these buses have 6
 wheels).

You don't know how many buses of which type the AvtoBus bus fleet owns, so you
wonder how many buses the fleet might have. You have to determine the minimum
and the maximum number of buses that can be in the fleet if you know that the
total number of wheels for all buses is 𝑛
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The following lines contain description of test
cases.

The only line of each test case contains one integer 𝑛
 (1≤𝑛≤1018
) — the total number of wheels for all buses.

Output
For each test case print the answer in a single line using the following format.

Print two integers 𝑥
 and 𝑦
 (1≤𝑥≤𝑦
) — the minimum and the maximum possible number of buses that can be in the bus
fleet.

If there is no suitable number of buses for the given 𝑛
, print the number −1
 as the answer.

Example
InputCopy
4
4
7
24
998244353998244352
OutputCopy
1 1
-1
4 6
166374058999707392 249561088499561088
Note
In the first test case the total number of wheels is 4
. It means that there is the only one bus with two axles in the bus fleet.

In the second test case it's easy to show that there is no suitable number of
buses with 7 wheels in total.

In the third test case the total number of wheels is 24
. The following options are possible:

Four buses with three axles.
Three buses with two axles and two buses with three axles.
Six buses with two axles.
So the minimum number of buses is 4
 and the maximum number of buses is 6
.


*/

/*#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    if (n < 4 || n % 2) {
      std::cout << -1 << std::endl;
      continue;
    }
    n /= 2;
    int minOps = (n + 2) / 3; // Minimum operations
    int maxOps = n / 2;       // Maximum operations

    std::cout << minOps << " " << maxOps << std::endl;
  }
  return 0;
}*/
#include <cstdio>
typedef long long ll;

int main() {

  ll t;
  scanf("%lld", &t);
  while (t--) {
    ll n;
    scanf("%lld", &n);
    if (n < 4 || n % 2) {
      puts("-1");
      continue;
    }
    n /= 2;
    printf("%lld %lld\n", ((n + 2) / 3), (n / 2));
  }
}

// sub: https://codeforces.com/problemset/submission/1679/303377738

/*B. Digits
time limit per test1 second
memory limit per test256 megabytes
Artem wrote the digit 𝑑
 on the board exactly 𝑛!
 times in a row. So, he got the number 𝑑𝑑𝑑𝑑𝑑𝑑…𝑑𝑑𝑑
 (exactly 𝑛!
 digits).

Now he is curious about which odd digits from 1
 to 9
 divide the number written on the board.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. The next 𝑡
 test cases follow.

Each test case consists of a single line containing two integers 𝑛
 and 𝑑
 (2≤𝑛≤109
, 1≤𝑑≤9
).

Output
For each test case, output the odd digits in ascending order that divide the
number written on the board.

Example
InputCopy
3
2 6
7 1
8 5
OutputCopy
1 3
1 3 7 9
1 3 5 7 9
Note
The factorial of a positive integer 𝑛
 (𝑛!
) is the product of all integers from 1
 to 𝑛
. For example, the factorial of 5
 is 1⋅2⋅3⋅4⋅5=120
.
*/
/*

cin>>t
(t--){
cin>>n>>d
digit d written n! times, so string is:
s='dddddddddd.....d'(n! times)

convert s to integer or long long, in this case
then divide by all odd num from 1 to 9

output all odd num that divode s
we will push them into vector and then travser and log them
}
*/
#include <bits/stdc++.h>
using namespace std;

// compute n! mod m (small m like 3, 9, 6)
int factorial_mod(int n, int m) {
  long long res = 1;
  for (int i = 2; i <= n; i++) {
    res = (res * i) % m;
    if (res == 0)
      return 0; // shortcut
  }
  return (int)res;
}

// fast exponentiation: a^b mod m
long long modpow(long long a, long long b, long long m) {
  long long res = 1 % m;
  a %= m;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;

    vector<int> ans;
    ans.push_back(1); // 1 always divides

    // divisibility by 3
    if ((1LL * d * factorial_mod(n, 3)) % 3 == 0) {
      ans.push_back(3);
    }

    // divisibility by 5
    if (d == 0 || d == 5) {
      ans.push_back(5);
    }

    // divisibility by 7
    {
      int fact_mod6 = factorial_mod(n, 6); // since 10^6 ≡ 1 mod 7
      long long pow10 = modpow(10, fact_mod6, 7);
      // repunit(n!) ≡ ((10^(n!) - 1) * inv9) mod 7
      // inverse of 9 mod 7 = 4
      long long repunit = ((pow10 - 1 + 7) % 7) * 4 % 7;
      if ((1LL * d * repunit) % 7 == 0) {
        ans.push_back(7);
      }
    }

    // divisibility by 9
    if ((1LL * d * factorial_mod(n, 9)) % 9 == 0) {
      ans.push_back(9);
    }

    // print results
    for (int x : ans)
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2043/340562809

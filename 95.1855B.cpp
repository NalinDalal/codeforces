/* https://codeforces.com/problemset/problem/1855/B
B. Longest Divisors Interval

Given a positive integer 𝑛, find the maximum size of an interval [𝑙,𝑟] of
positive integers such that, for every 𝑖 in the interval (i.e., 𝑙≤𝑖≤𝑟), 𝑛 is a
multiple of 𝑖.

Given two integers 𝑙≤𝑟, the size of the interval [𝑙,𝑟] is 𝑟−𝑙+1 (i.e., it
coincides with the number of integers belonging to the interval).

Input
The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases.

The only line of the description of each test case contains one integer 𝑛
(1≤𝑛≤1018).

Output
For each test case, print a single integer: the maximum size of a valid
interval.

Example
InputCopy
10
1
40
990990
4204474560
169958913706572972
365988220345828080
387701719537826430
620196883578129853
864802341280805662
1000000000000000000
OutputCopy
1
2
3
6
4
22
3
1
2
2
Note
In the first test case, a valid interval with maximum size is [1,1] (it's valid
because 𝑛=1 is a multiple of 1) and its size is 1. In the second test case, a
valid interval with maximum size is [4,5] (it's valid because 𝑛=40 is a multiple
of 4 and 5) and its size is 2. In the third test case, a valid interval with
maximum size is [9,11]. In the fourth test case, a valid interval with maximum
size is [8,13]. In the seventh test case, a valid interval with maximum size is
[327869,327871].
*/

/*#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // for i in range(l,r), l<=r
    // n is multiple of i
    // print size of interval, size=r-l+1
    /*ll n; scanf("%lld", &n);
        ll cnt(1);
        for(ll p = 2; n % p == 0 && p <= n; p++){++cnt;}
        printf("%lld\n", cnt);*/
/*
    int cnt(1);
    for (int p = 2; n % p == 0 && p <= n; p++) {
      ++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}*/
#include <cstdio>
typedef long long ll;

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    ll n;
    // cin>>n;
    scanf("%lld", &n);
    ll cnt(1);
    for (ll p = 2; n % p == 0 && p <= n; p++) {
      ++cnt;
    }
    printf("%lld\n", cnt);
    // cout<<cnt<<endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1855/302784011

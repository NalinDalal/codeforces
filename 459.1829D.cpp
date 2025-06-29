/* D. Gold Rush
time limit per test2 seconds
memory limit per test256 megabytes
Initially you have a single pile with 𝑛
 gold nuggets. In an operation you can do the following:

Take any pile and split it into two piles, so that one of the resulting piles has exactly twice as many gold nuggets as the other. (All piles should have an integer number of nuggets.)

One possible move is to take a pile of size 6
 and split it into piles of sizes 2
 and 4
, which is valid since 4
 is twice as large as 2
.

Can you make a pile with exactly 𝑚
 gold nuggets using zero or more operations?
Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The only line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤107
) — the starting and target pile sizes, respectively.

Output
For each test case, output "YES" if you can make a pile of size exactly 𝑚
, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
11
6 4
9 4
4 2
18 27
27 4
27 2
27 10
1 1
3 1
5 1
746001 2984004
OutputCopy
YES
YES
NO
NO
YES
YES
NO
YES
YES
NO
NO
Note
The first test case is pictured in the statement. We can make a pile of size 4
.

In the second test case, we can perform the following operations: {9}→{6,3}→{4,2,3}
. The pile that is split apart is colored red before each operation.

In the third test case, we can't perform a single operation.

In the fourth test case, we can't end up with a larger pile than we started with.


*/

#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long t;
    std::cin >> t;
    while (t--) {
        ll n, m;
        std::cin >> n >> m;

        ll g = gcd(m, n);
        n /= g;
        m /= g;

        long fn = 0;
        while (n % 3 == 0) {
            ++fn;
            n /= 3;
        }

        long fm = 0;
        while (m % 2 == 0) {
            ++fm;
            m /= 2;
        }

        if (n == 1 && m == 1 && fm <= fn) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
//sub: https://codeforces.com/problemset/submission/1829/326483876

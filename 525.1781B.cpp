/*B. Going to the Cinema
time limit per test2 seconds
memory limit per test512 megabytes
A company of 𝑛
 people is planning a visit to the cinema. Every person can either go to the cinema or not. That depends on how many other people will go. Specifically, every person 𝑖
 said: "I want to go to the cinema if and only if at least 𝑎𝑖
 other people will go, not counting myself". That means that person 𝑖
 will become sad if:

they go to the cinema, and strictly less than 𝑎𝑖
 other people go; or
they don't go to the cinema, and at least 𝑎𝑖
 other people go.
In how many ways can a set of people going to the cinema be chosen so that nobody becomes sad?

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤104
). The description of the test cases follows.

Each test case consists of two lines. The first line contains a single integer 𝑛
 (2≤𝑛≤2⋅105
) — the number of people in the company.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤𝑛−1
) — integers from peoples' claims.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the number of different ways to choose a set of people going to the cinema so that nobody becomes sad.

Example
InputCopy
4
2
1 1
7
0 1 2 3 4 5 6
8
6 0 3 3 6 7 2 7
5
3 0 0 3 3
OutputCopy
2
1
3
2
Note
In the first test case, both people want to go to the cinema if and only if the other person goes. There are two valid options: either both people go, or neither of them goes. However, if just one of them goes, both will be sad.

In the second test case, everyone has to go to the cinema. In any other case, someone will be sad.

In the third test case, there are three valid options: person number 2
 goes to the cinema; or persons with indices 2,3,4,7
 go; or all eight people go.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long t;
    std::cin >> t;

    while (t--) {
        long n;
        std::cin >> n;

        std::vector<long> a(n);
        for (long& x : a) {
            std::cin >> x;
        }

        std::sort(a.begin(), a.end());

        long cnt = 0;
        for (long p = 0; p <= n; p++) {
            bool leftOk = (p == 0 || a[p - 1] < p);
            bool rightOk = (p == n || a[p] > p);
            if (leftOk && rightOk) {
                cnt++;
            }
        }

        std::cout << cnt << '\n';
    }

    return 0;
}

//sub: https://codeforces.com/problemset/submission/1781/330390286

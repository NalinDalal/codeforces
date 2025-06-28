/*B. Olya and Game with Arrays
time limit per test1 second
memory limit per test256 megabytes
Artem suggested a game to the girl Olya. There is a list of 𝑛
 arrays, where the 𝑖
-th array contains 𝑚𝑖≥2
 positive integers 𝑎𝑖,1,𝑎𝑖,2,…,𝑎𝑖,𝑚𝑖
.

Olya can move at most one (possibly 0
) integer from each array to another array. Note that integers can be moved from one array only once, but integers can be added to one array multiple times, and all the movements are done at the same time.

The beauty of the list of arrays is defined as the sum ∑𝑛𝑖=1min𝑚𝑖𝑗=1𝑎𝑖,𝑗
. In other words, for each array, we find the minimum value in it and then sum up these values.

The goal of the game is to maximize the beauty of the list of arrays. Help Olya win this challenging game!

Input
Each test consists of multiple test cases. The first line contains a single integer 𝑡
 (1≤𝑡≤25000
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤25000
) — the number of arrays in the list.

This is followed by descriptions of the arrays. Each array description consists of two lines.

The first line contains a single integer 𝑚𝑖
 (2≤𝑚𝑖≤50000
) — the number of elements in the 𝑖
-th array.

The next line contains 𝑚𝑖
 integers 𝑎𝑖,1,𝑎𝑖,2,…,𝑎𝑖,𝑚𝑖
 (1≤𝑎𝑖,𝑗≤109
) — the elements of the 𝑖
-th array.

It is guaranteed that the sum of 𝑚𝑖
 over all test cases does not exceed 50000
.

Output
For each test case, output a single line containing a single integer — the maximum beauty of the list of arrays that Olya can achieve.

Example
InputCopy
3
2
2
1 2
2
4 3
1
3
100 1 6
3
4
1001 7 1007 5
3
8 11 6
2
2 9
OutputCopy
5
1
19
Note
In the first test case, we can move the integer 3
 from the second array to the first array. Then the beauty is min(1,2,3)+min(4)=5
. It can be shown that this is the maximum possible beauty.

In the second test case, there is only one array, so regardless of the movements, the beauty will be min(100,1,6)=1
.



*/
#include <iostream>
#include <vector>
#include <utility>
#include <limits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long t;
    std::cin >> t;
    while (t--) {
        long n;
        std::cin >> n;

        std::vector<std::pair<long, long>> v(n);
        long idx = -1;
        long gmn = std::numeric_limits<long>::max();
        long gsmn = std::numeric_limits<long>::max();

        for (long p = 0; p < n; ++p) {
            long m;
            std::cin >> m;

            long mn = std::numeric_limits<long>::max();
            long smn = std::numeric_limits<long>::max();

            for (long q = 0; q < m; ++q) {
                long x;
                std::cin >> x;
                if (x <= mn) {
                    smn = mn;
                    mn = x;
                } else if (x < smn) {
                    smn = x;
                }
            }

            v[p] = std::make_pair(mn, smn);
            gmn = std::min(gmn, mn);
            if (smn < gsmn) {
                gsmn = smn;
                idx = p;
            }
        }

        long long sum = 0;
        for (long p = 0; p < n; ++p) {
            sum += (p != idx) ? v[p].second : gmn;
        }

        std::cout << sum << '\n';
    }
}
//sub: https://codeforces.com/problemset/submission/1859/326439449

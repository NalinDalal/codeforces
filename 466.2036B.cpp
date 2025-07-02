/*B. Startup
time limit per test2 seconds
memory limit per test256 megabytes
Arseniy came up with another business plan — to sell soda from a vending machine! For this, he purchased a machine with 𝑛
 shelves, as well as 𝑘
 bottles, where the 𝑖
-th bottle is characterized by the brand index 𝑏𝑖
 and the cost 𝑐𝑖
.

You can place any number of bottles on each shelf, but all bottles on the same shelf must be of the same brand.

Arseniy knows that all the bottles he puts on the shelves of the machine will be sold. Therefore, he asked you to calculate the maximum amount he can earn.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛,𝑘≤2⋅105
), where 𝑛
 is the number of shelves in the machine, and 𝑘
 is the number of bottles available to Arseniy.

The next 𝑘
 lines contain two integers 𝑏𝑖
 and 𝑐𝑖
 (1≤𝑏𝑖≤𝑘,1≤𝑐𝑖≤1000
) — the brand and cost of the 𝑖
-th bottle.

It is also guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
 and that the sum of 𝑘
 across all test cases also does not exceed 2⋅105
.

Output
For each test case, output one integer — the maximum amount that Arseniy can earn.

Example
InputCopy
4
3 3
2 6
2 7
1 15
1 3
2 6
2 7
1 15
6 2
1 7
2 5
190000 1
1 1000
OutputCopy
28
15
12
1000
Note
In the first test case, Arseniy has 3
 shelves in the vending machine. He can place, for example, two bottles of the brand 2
 on the first shelf and a bottle of the brand 1
 on the second shelf. Then the total cost of the bottles would be 6+7+15=28
.

In the second test case, he has only one shelf. It is not difficult to show that the optimal option is to place a bottle of the brand 1
 on it. Then the total cost will be 15
.

In the third test case, he has as many as 6
 shelves, so he can place all available bottles with a total cost of 7+5=12
.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;

int main() {
    ll t; std::cin >> t;
    while (t--) {
        ll n, k; std::cin >> n >> k;
        std::map<ll, ll> m;
        for (ll p = 0; p < k; p++) {
            ll b, c; std::cin >> b >> c;
            m[b] += c;
        }

        std::vector<ll> v;
        for (std::map<ll, ll>::iterator it = m.begin(); it != m.end(); it++) {
            v.push_back(it->second);
        }
        sort(v.rbegin(), v.rend());
        ll total(0);
        for (ll p = 0; p < v.size() && p < n; p++) {
            total += v[p];
        }
        std::cout << total << std::endl;
    }
}
//sub: https://codeforces.com/problemset/submission/2036/327084946

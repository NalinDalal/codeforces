/*B. Kar Salesman
time limit per test1 second
memory limit per test256 megabytes
Karel is a salesman in a car dealership. The dealership has 𝑛
 different models of cars. There are 𝑎𝑖
 cars of the 𝑖
-th model. Karel is an excellent salesperson and can convince customers to buy
up to 𝑥 cars (of Karel's choice), as long as the cars are from different models.

Determine the minimum number of customers Karel has to bring in to sell all the
cars.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤5⋅105
; 1≤𝑥≤10
) — the number of different models of cars and the maximum number of cars Karel
can convince a customer to buy.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the number of cars of each model.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 5⋅105
.

Output
For each test case, output the minimum possible number of customers needed to
sell all the cars.

Example
InputCopy
4
3 2
3 1 2
3 3
2 1 3
5 3
2 2 1 9 2
7 4
2 5 3 3 5 2 5
OutputCopy
3
3
9
7
Note
For the first case, Karel only needs to lure in 3
 customers. He will convince the customers to buy the following models of cars:

Customer 1
 buys 2
 cars with model 1
 and 3
.
Customer 2
 buys 2
 cars with model 1
 and 2
.
Customer 3
 buys 2
 cars with model 1
 and 3
.
For the second case, Karel only needs to lure in 3
 customers. He will convince the customers to buy the following models of cars:

Customer 1
 buys 2
 cars with model 1
 and 3
.
Customer 2
 buys 3
 cars with model 1
, 2
 and 3
.
Customer 3
 buys 1
 car with model 3
.
*/

#include <iostream>
typedef long long ll;

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    ll n, x;
    std::cin >> n >> x;
    ll sa = 0, mxa = 0;
    for (ll p = 0; p < n; p++) {
      ll a;
      std::cin >> a;
      sa += a;
      mxa = (mxa > a ? mxa : a);
    }

    ll res((sa + x - 1) / x);
    res = (res > mxa ? res : mxa);
    std::cout << res << std::endl;
  }
  return 0;
  // PROOF: Make a grid of res rows and x columns;
  // Start populating it starting with the first element, then the second etc
  // Since res >= max(a) then there will be no row with the same element
}
// sub: https://codeforces.com/problemset/submission/2022/324579363

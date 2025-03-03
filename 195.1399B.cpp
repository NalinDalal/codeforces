/*B. Gifts Fixing
time limit per test1 second
memory limit per test256 megabytes
You have 𝑛
 gifts and you want to give all of them to children. Of course, you don't want
to offend anyone, so all gifts should be equal between each other. The 𝑖 -th
gift consists of 𝑎𝑖 candies and 𝑏𝑖 oranges.

During one move, you can choose some gift 1≤𝑖≤𝑛
 and do one of the following operations:

eat exactly one candy from this gift (decrease 𝑎𝑖
 by one);
eat exactly one orange from this gift (decrease 𝑏𝑖
 by one);
eat exactly one candy and exactly one orange from this gift (decrease both 𝑎𝑖
 and 𝑏𝑖
 by one).
Of course, you can not eat a candy or orange if it's not present in the gift (so
neither 𝑎𝑖 nor 𝑏𝑖 can become less than zero).

As said above, all gifts should be equal. This means that after some sequence of
moves the following two conditions should be satisfied: 𝑎1=𝑎2=⋯=𝑎𝑛 and
𝑏1=𝑏2=⋯=𝑏𝑛 (and 𝑎𝑖 equals 𝑏𝑖 is not necessary).

Your task is to find the minimum number of moves required to equalize all the
given gifts.

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. Then 𝑡
 test cases follow.

The first line of the test case contains one integer 𝑛
 (1≤𝑛≤50
) — the number of gifts. The second line of the test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
), where 𝑎𝑖
 is the number of candies in the 𝑖
-th gift. The third line of the test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤109
), where 𝑏𝑖
 is the number of oranges in the 𝑖
-th gift.

Output
For each test case, print one integer: the minimum number of moves required to
equalize all the given gifts.

Example
InputCopy
5
3
3 5 6
3 2 3
5
1 2 3 4 5
5 4 3 2 1
3
1 1 1
2 2 2
6
1 1000000000 1000000000 1000000000 1000000000 1000000000
1 1 1 1 1 1
3
10 12 8
7 5 4
OutputCopy
6
16
0
4999999995
7
Note
In the first test case of the example, we can perform the following sequence of
moves:

choose the first gift and eat one orange from it, so 𝑎=[3,5,6]
 and 𝑏=[2,2,3]
;
choose the second gift and eat one candy from it, so 𝑎=[3,4,6]
 and 𝑏=[2,2,3]
;
choose the second gift and eat one candy from it, so 𝑎=[3,3,6]
 and 𝑏=[2,2,3]
;
choose the third gift and eat one candy and one orange from it, so 𝑎=[3,3,5]
 and 𝑏=[2,2,2]
;
choose the third gift and eat one candy from it, so 𝑎=[3,3,4]
 and 𝑏=[2,2,2]
;
choose the third gift and eat one candy from it, so 𝑎=[3,3,3]
 and 𝑏=[2,2,2]
.

*/
// totalMoves needed to equalise all the gifts
// one move->ai=ai-1 or bi=bi-1 or decrease both ai,bi by 1
// Calculate absolute differences

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> v1(n);
    vector<ll> v2(n);
    ll mina = 1e9 + 7, minb = 1e9 + 7;

    for (ll i = 0; i < n; i++) {
      cin >> v1[i];
      mina = min(mina, v1[i]);
    }
    for (ll i = 0; i < n; i++) {
      cin >> v2[i];
      minb = min(minb, v2[i]);
    }

    ll totalMoves = 0;
    for (ll p = 0; p < n; p++) {
      ll x = v1[p] - mina;
      ll y = v2[p] - minb;
      totalMoves += max(x, y);
    }

    cout << totalMoves << '\n';
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1399/308756056

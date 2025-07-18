/*B. Vaccination
time limit per test2 seconds
memory limit per test512 megabytes
Ethan runs a vaccination station to help people combat the seasonal flu. He
analyses the historical data in order to develop an optimal strategy for vaccine
usage.

Consider there are 𝑛
 patients coming to the station on a particular day. The 𝑖
-th patient comes at the moment 𝑡𝑖
. We know that each of these patients can be asked to wait for no more than 𝑤
 time moments. That means the 𝑖
-th patient can get vaccine at moments 𝑡𝑖,𝑡𝑖+1,…,𝑡𝑖+𝑤
.

Vaccines come in packs, each pack consists of 𝑘
 doses. Each patient needs exactly one dose. Packs are stored in a special
fridge. After a pack is taken out of the fridge and opened, it can no longer be
put back. The lifetime of the vaccine outside the fridge is 𝑑 moments of time.
Thus, if the pack was taken out of the fridge and opened at moment 𝑥 , its doses
can be used to vaccinate patients at moments 𝑥,𝑥+1,…,𝑥+𝑑 . At moment 𝑥+𝑑+1 all
the remaining unused doses of this pack are thrown away.

Assume that the vaccination station has enough staff to conduct an arbitrary
number of operations at every moment of time. What is the minimum number of
vaccine packs required to vaccinate all 𝑛 patients?

Input
The first line of the input contains the number of test cases 𝑡
 (1≤𝑡≤104
). Then follow 𝑡
 descriptions of the test cases.

The first line of each test case contains four integers 𝑛
, 𝑘
, 𝑑
 and 𝑤
 (1≤𝑛,𝑘≤2⋅105
, 0≤𝑑,𝑤≤106
). They are the number of patients, the number of doses per vaccine pack, the
number of moments of time the vaccine can live outside the fridge, and the
number of moments of time each of the patients can wait, respectively.

The second line of each test case contains a non-decreasing sequence 𝑡1,𝑡2,…,𝑡𝑛
 (0≤𝑡1≤𝑡2≤…≤𝑡𝑛≤106
). The 𝑖
-th element of this sequence is the moment when the 𝑖
-th patient comes to the vaccination station.

It is guaranteed that the sum of 𝑛
 over all test cases won't exceed 2⋅105
.

Output
Output one integer, the minimum number of vaccine packs required to vaccinate
all 𝑛 patients.

Example
InputCopy
5
6 3 5 3
1 2 3 10 11 18
6 4 0 0
3 3 3 3 3 4
9 10 2 2
0 1 2 3 4 5 6 7 8
3 10 3 6
10 20 30
5 5 4 4
0 2 4 6 8
OutputCopy
2
3
2
3
1
Note
In the first example, the first pack can be opened at moment 1
 to vaccinate patient 1
. The vaccine is durable enough to be used at moments 2
 and 3
 for patients 2
 and 3
, respectively. Then the staff needs to ask patients 4
 and 5
 to wait for moment 13
. At moment 13
 the staff opens the second vaccine pack and serves patients 4
 and 5
. Finally, the last patient comes at moment 18
 and immediately gets the last dose of the second pack while it is still fine.

In the second example, the vaccine should be used exactly at the moment it is
taken out of the fridge. Moreover, all the patients want to be served at exactly
the same moment they come. That means the staff needs to open two packs at
moment 3 and use five doses on patients 1 , 2 , 3 , 4 , and 5 . There will be
three doses left ouf of these two packs but they can't be used for patient 6 .
When patient 6 comes at moment 4 the staff needs to open a new pack just to use
only one dose out of it.
*/

#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, k, d, w;
    std::cin >> n >> k >> d >> w;
    long cnt = 0, rem = 0, exp = -1;
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      if (rem <= 0 || exp < x) {
        ++cnt;
        rem = k - 1;
        exp = x + w + d;
      } else {
        --rem;
      }
    }
    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1804/329584984

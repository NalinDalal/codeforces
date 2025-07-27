/*B. Battle Cows
time limit per test1 second
memory limit per test256 megabytes
The HU - Shireg Shireg
ඞ
There are 𝑛
 cows participating in a coding tournament. Cow 𝑖
 has a Cowdeforces rating of 𝑎𝑖
 (all distinct), and is initially in position 𝑖
. The tournament consists of 𝑛−1
 matches as follows:

The first match is between the cow in position 1
 and the cow in position 2
.
Subsequently, each match 𝑖
 is between the cow in position 𝑖+1
 and the winner of match 𝑖−1
.
In each match, the cow with the higher Cowdeforces rating wins and proceeds to
the next match. You are the owner of cow 𝑘 . For you, winning the tournament is
not important; rather, you want your cow to win in as many matches as possible.
As an acquaintance of the tournament organizers, you can ask them to swap the
position of your cow with another cow only once, or you can choose to do
nothing.

Find the maximum number of wins your cow can achieve.

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤105,1≤𝑘≤𝑛
) — the number of cows and your cow's index.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the Cowdeforces rating of the cows. It is guaranteed that 𝑎𝑖
's are pairwise different.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, print one integer: the maximum number of wins cow 𝑘
 can achieve if you choose to swap (or do nothing) optimally.

Example
InputCopy
3
6 1
12 10 14 11 8 3
6 5
7 2 727 10 12 13
2 2
1000000000 1
OutputCopy
1
2
0
Note
In the first test case, it is optimal to do nothing. Let 𝑎′
 be the Cowdeforces rating of the cows in the original order (with your cow's
rating bolded), then

Initially, 𝑎′=[12,10,14,11,8,3]
.
Your cow plays against the cow with Cowdeforces rating 10
 and wins. 𝑎′=[12,14,11,8,3]
.
Your cow plays against the cow with Cowdeforces rating 14
 and loses.
In total, your cow wins 1
 match.
In the second test case, it is optimal to swap your cow to position 3
. Then, let 𝑎′
 be the Cowdeforces rating of the cows in the order after the swap.

Initially, 𝑎′=[7,2,12,10,727,13]
.
The cow with Cowdeforces rating 7
 plays against the cow with Cowdeforces rating 2
 and wins. 𝑎′=[7,12,10,727,13]
.
The cow with Cowdeforces rating 7
 plays against your cow, and your cow wins. 𝑎′=[12,10,727,13]
.
Your cow plays against the cow with Cowdeforces rating 10
 and wins. 𝑎′=[12,727,13]
.
Your cow plays against the cow with Cowdeforces rating 727
 and loses.
In total, your cow wins 2
 matches.
*/
#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      std::cin >> a[p];
    }
    long b = a[--k];
    long first = n, second = n;
    for (long p = 0; p < n; p++) {
      if (a[p] > b && first == n) {
        first = p;
      } else if (a[p] > b) {
        second = p;
        break;
      }
    }

    long resA = first - 1;
    long resB = (second < k ? second : k) - first - (first == 0);
    std::cout << (resA > resB ? resA : resB) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1951/331076335

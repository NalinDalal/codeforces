/*B. Berland Music
time limit per test2 seconds
memory limit per test256 megabytes
Berland Music is a music streaming service built specifically to support Berland
local artist. Its developers are currently working on a song recommendation
module.

So imagine Monocarp got recommended 𝑛
 songs, numbered from 1
 to 𝑛
. The 𝑖
-th song had its predicted rating equal to 𝑝𝑖
, where 1≤𝑝𝑖≤𝑛
 and every integer from 1
 to 𝑛
 appears exactly once. In other words, 𝑝
 is a permutation.

After listening to each of them, Monocarp pressed either a like or a dislike
button. Let his vote sequence be represented with a string 𝑠 , such that 𝑠𝑖=0
 means that he disliked the 𝑖
-th song, and 𝑠𝑖=1
 means that he liked it.

Now the service has to re-evaluate the song ratings in such a way that:

the new ratings 𝑞1,𝑞2,…,𝑞𝑛
 still form a permutation (1≤𝑞𝑖≤𝑛
; each integer from 1
 to 𝑛
 appears exactly once);
every song that Monocarp liked should have a greater rating than every song that
Monocarp disliked (formally, for all 𝑖,𝑗 such that 𝑠𝑖=1 and 𝑠𝑗=0 , 𝑞𝑖>𝑞𝑗 should
hold). Among all valid permutations 𝑞 find the one that has the smallest value
of ∑𝑖=1𝑛|𝑝𝑖−𝑞𝑖| , where |𝑥| is an absolute value of 𝑥
.

Print the permutation 𝑞1,𝑞2,…,𝑞𝑛
. If there are multiple answers, you can print any of them.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The first line of each testcase contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of songs.

The second line of each testcase contains 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 (1≤𝑝𝑖≤𝑛
) — the permutation of the predicted ratings.

The third line contains a single string 𝑠
, consisting of 𝑛
 characters. Each character is either a 0
 or a 1
. 0
 means that Monocarp disliked the song, and 1
 means that he liked it.

The sum of 𝑛
 over all testcases doesn't exceed 2⋅105
.

Output
For each testcase, print a permutation 𝑞
 — the re-evaluated ratings of the songs. If there are multiple answers such
that ∑𝑖=1𝑛|𝑝𝑖−𝑞𝑖| is minimum possible, you can print any of them.

Example
InputCopy
3
2
1 2
10
3
3 1 2
111
8
2 3 1 8 5 4 7 6
01110001
OutputCopy
2 1
3 1 2
1 6 5 8 3 2 4 7
Note
In the first testcase, there exists only one permutation 𝑞
 such that each liked song is rating higher than each disliked song: song 1
 gets rating 2
 and song 2
 gets rating 1
. ∑𝑖=1𝑛|𝑝𝑖−𝑞𝑖|=|1−2|+|2−1|=2
.

In the second testcase, Monocarp liked all songs, so all permutations could
work. The permutation with the minimum sum of absolute differences is the
permutation equal to 𝑝 . Its cost is 0
.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  const long M = 1e7;

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::vector<std::pair<long, long>> v(n);
    for (long p = 0; p < n; p++) {
      std::cin >> v[p].first;
      v[p].second = p;
    }
    std::string s;
    std::cin >> s;
    for (long p = 0; p < n; p++) {
      v[p].first += M * (s[p] - '0');
    }
    sort(v.begin(), v.end());
    std::vector<long> w(n, 0);
    for (long p = 0; p < n; p++) {
      w[v[p].second] = p + 1;
    }
    for (long p = 0; p < n; p++) {
      std::cout << w[p] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1622/334210489

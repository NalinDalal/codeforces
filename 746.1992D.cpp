/*D. Test of Love
time limit per test2 seconds
memory limit per test256 megabytes
ErnKor is ready to do anything for Julen, even to swim through
crocodile-infested swamps. We decided to test this love. ErnKor will have to
swim across a river with a width of 1 meter and a length of 𝑛 meters.

The river is very cold. Therefore, in total (that is, throughout the entire swim
from 0 to 𝑛+1 ) ErnKor can swim in the water for no more than 𝑘 meters. For the
sake of humanity, we have added not only crocodiles to the river, but also logs
on which he can jump. Our test is as follows:

Initially, ErnKor is on the left bank and needs to reach the right bank. They
are located at the 0 and 𝑛+1 meters respectively. The river can be represented
as 𝑛 segments, each with a length of 1 meter. Each segment contains either a log
'L', a crocodile 'C', or just water 'W'. ErnKor can move as follows:

If he is on the surface (i.e., on the bank or on a log), he can jump forward for
no more than 𝑚 (1≤𝑚≤10 ) meters (he can jump on the bank, on a log, or in the
water). If he is in the water, he can only swim to the next river segment (or to
the bank if he is at the 𝑛 -th meter). ErnKor cannot land in a segment with a
crocodile in any way. Determine if ErnKor can reach the right bank.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains three numbers 𝑛,𝑚,𝑘
 (0≤𝑘≤2⋅105
, 1≤𝑛≤2⋅105
, 1≤𝑚≤10
) — the length of the river, the distance ErnKor can jump, and the number of
meters ErnKor can swim without freezing.

The second line of each test case contains a string 𝑎
 of length 𝑛
. 𝑎𝑖
 denotes the object located at the 𝑖
-th meter. (𝑎𝑖∈{
'W','C','L'}
)

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if ErnKor can pass the test, and output "NO"
otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
6 2 0
LWLLLW
6 1 1
LWLLLL
6 1 1
LWLLWL
6 2 15
LWLLCC
6 10 0
CCCCCC
6 6 1
WCCCCW
OutputCopy
YES
YES
NO
NO
YES
YES
Note
Let's consider examples:

First example: We jump from the shore to the first log (0→1
), from the first log to the second (1→3
), from the second to the fourth (3→5
), and from the last log to the shore (5→7
). So, we have 0→1→3→5→7
. Since we did not encounter a crocodile and swam no more than k meters, the
answer is «YES». Second example: 0→1 , we jump into the water from the first log
(1→2
), swim a cell to the log (2⇝3
), 3→4→5→6→7
. Since we did not encounter a crocodile and swam no more than k meters, the
answer is «YES». In the third example, ErnKor needs to swim two cells 'W', but
can only swim one. Therefore, the answer is «NO». Sixth example: We jump from
the shore into the water (0→6 ) and swim one cell in the water (6⇝7
). Since we did not encounter a crocodile and swam no more than k meters, the
answer is «YES».
*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, m, k;
    std::cin >> n >> m >> k;
    std::string s;
    std::cin >> s;
    s = "L" + s + "L";
    std::vector<long> v;
    for (long p = 0; p < s.size(); p++) {
      if (s[p] == 'L') {
        v.push_back(p);
      }
    }
    bool possible(true);
    for (long p = 0; possible && p + 1 < v.size(); p++) {
      if (v[p] + m >= v[p + 1]) {
        continue;
      }
      long cur = v[p] + m;
      long nxt = v[p + 1];
      long dist = nxt - cur;
      if (dist <= k) {
        k -= dist;
      } else {
        possible = false;
        break;
      }
      for (long u = cur; u < nxt; u++) {
        if (s[u] == 'C') {
          possible = false;
          break;
        }
      }
    }

    std::cout << (possible ? "YES" : "NO") << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1992/341995294

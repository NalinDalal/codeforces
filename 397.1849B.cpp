/* B. Monsters
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp is playing yet another computer game. And yet again, his character is
killing some monsters. There are 𝑛 monsters, numbered from 1 to 𝑛 , and the 𝑖
-th of them has 𝑎𝑖
 health points initially.

Monocarp's character has an ability that deals 𝑘
 damage to the monster with the highest current health. If there are several of
them, the one with the smaller index is chosen. If a monster's health becomes
less than or equal to 0 after Monocarp uses his ability, then it dies.

Monocarp uses his ability until all monsters die. Your task is to determine the
order in which monsters will die.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤3⋅105
; 1≤𝑘≤109
) — the number of monsters and the damage which Monocarp's ability deals.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the initial health points of monsters.

The sum of 𝑛
 over all test cases doesn't exceed 3⋅105
.

Output
For each test case, print 𝑛
 integers — the indices of monsters in the order they die.

Example
InputCopy
3
3 2
1 2 3
2 3
1 1
4 3
2 8 3 5
OutputCopy
2 1 3
1 2
3 1 2 4
Note
In the first example, the health points change as follows:
[1,2,3⎯⎯]→[1,2⎯⎯,1]→[1⎯⎯,0,1]→[−1,0,1⎯⎯]→[−1,0,−1] . The monster that is going
to take damage the next time Monocarp uses his ability is underlined.

In the second example, the health points change as follows:
[1⎯⎯,1]→[−2,1⎯⎯]→[−2,−2]
.

In the third example, the health points change as follows:
[2,8⎯⎯,3,5]→[2,5⎯⎯,3,5]→[2,2,3,5⎯⎯]→[2,2,3⎯⎯,2]→[2⎯⎯,2,0,2]→[−1,2⎯⎯,0,2]→[−1,−1,0,2⎯⎯]→[−1,−1,0,−1]
.


*/

#include <algorithm>
#include <iostream>
#include <vector>

bool pairCompare(std::pair<long, long> a, std::pair<long, long> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  } else if (a.first == 0) {
    return true;
  } else if (b.first == 0) {
    return false;
  } else {
    return a.first > b.first;
  }
  // return true; // redundant
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;
    std::vector<std::pair<long, long>> a(n);

    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      a[p] = {x % k, p + 1};
    }

    std::sort(a.begin(), a.end(), pairCompare);

    for (long p = 0; p < n; p++) {
      std::cout << a[p].second << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1849/323276624

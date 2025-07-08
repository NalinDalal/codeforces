/*A. Two Friends
time limit per test2 seconds
memory limit per test256 megabytes
Monocarp wants to throw a party. He has 𝑛
 friends, and he wants to have at least 2
 of them at his party.

The 𝑖
-th friend's best friend is 𝑝𝑖
. All 𝑝𝑖
 are distinct, and for every 𝑖∈[1,𝑛]
, 𝑝𝑖≠𝑖
.

Monocarp can send invitations to friends. The 𝑖
-th friend comes to the party if both the 𝑖
-th friend and the 𝑝𝑖
-th friend receive an invitation (note that the 𝑝𝑖
-th friend doesn't have to actually come to the party). Each invitation is sent
to exactly one of the friends.

For example, if 𝑝=[3,1,2,5,4]
, and Monocarp sends invitations to the friends [1,2,4,5]
, then the friends [2,4,5]
 will come to the party. The friend 1
 won't come since his best friend didn't receive an invitation; the friend 3
 won't come since he didn't receive an invitation.

Calculate the minimum number of invitations Monocarp has to send so that at
least 2 friends come to the party.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤5000
) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛
 (2≤𝑛≤50
) — the number of friends;
the second line contains 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 (1≤𝑝𝑖≤𝑛
; 𝑝𝑖≠𝑖
; all 𝑝𝑖
 are distinct).
Output
Print one integer — the minimum number of invitations Monocarp has to send.

Example
InputCopy
3
5
3 1 2 5 4
4
2 3 4 1
2
2 1
OutputCopy
2
3
2
Note
In the first testcase, Monocarp can send invitations to friends 4
 and 5
. Both of them will come to the party since they are each other's best friends,
and both of them have invitations.

In the second testcase, Monocarp can send invitations to friends 1,2
 and 3
, for example. Then friends 1
 and 2
 will attend: friend 1
 and his best friend 2
 have invitations, friend 2
 and his best friend 3
 have invitations. Friend 3
 won't attend since his friend 4
 doesn't have an invitation. It's impossible to send invitations to fewer than 3
 friends in such a way that at least 2
 come.

In the third testcase, Monocarp can send invitations to both friends 1
 and 2
, and both of them will attend.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    vector<long> v(n + 1);
    for (long p = 1; p <= n; p++) {
      cin >> v[p];
    }
    long mncnt(3);
    for (long p = 1; p <= n; p++) {
      if (!v[p]) {
        continue;
      }
      long x(p), cnt(0);
      while (v[x]) {
        ++cnt;
        long y = v[x];
        v[x] = 0;
        x = y;
      }
      mncnt = (cnt < mncnt ? cnt : mncnt);
    }
    cout << mncnt << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1969/328049341

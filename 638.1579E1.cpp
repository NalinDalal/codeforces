/*E1. Permutation Minimization by Deque
time limit per test2 seconds
memory limit per test256 megabytes
In fact, the problems E1 and E2 do not have much in common. You should probably
think of them as two separate problems.

A permutation 𝑝
 of size 𝑛
 is given. A permutation of size 𝑛
 is an array of size 𝑛
 in which each integer from 1
 to 𝑛
 occurs exactly once. For example, [1,4,3,2]
 and [4,2,1,3]
 are correct permutations while [1,2,4]
 and [1,2,2]
 are not.

Let us consider an empty deque (double-ended queue). A deque is a data structure
that supports adding elements to both the beginning and the end. So, if there
are elements [1,5,2] currently in the deque, adding an element 4 to the
beginning will produce the sequence [4,1,5,2] , and adding same element to the
end will produce [1,5,2,4]
.

The elements of the permutation are sequentially added to the initially empty
deque, starting with 𝑝1 and finishing with 𝑝𝑛 . Before adding each element to
the deque, you may choose whether to add it to the beginning or the end.

For example, if we consider a permutation 𝑝=[3,1,2,4]
, one of the possible sequences of actions looks like this:

 1.	add 3
 to the end of the deque:	deque has a sequence [3]
 in it;
 2.	add 1
 to the beginning of the deque:	deque has a sequence [1,3]
 in it;
 3.	add 2
 to the end of the deque:	deque has a sequence [1,3,2]
 in it;
 4.	add 4
 to the end of the deque:	deque has a sequence [1,3,2,4]
 in it;
Find the lexicographically smallest possible sequence of elements in the deque
after the entire permutation has been processed.

A sequence [𝑥1,𝑥2,…,𝑥𝑛]
 is lexicographically smaller than the sequence [𝑦1,𝑦2,…,𝑦𝑛]
 if there exists such 𝑖≤𝑛
 that 𝑥1=𝑦1
, 𝑥2=𝑦2
, …
, 𝑥𝑖−1=𝑦𝑖−1
 and 𝑥𝑖<𝑦𝑖
. In other words, if the sequences 𝑥
 and 𝑦
 have some (possibly empty) matching prefix, and the next element of the
sequence 𝑥 is strictly smaller than the corresponding element of the sequence 𝑦
. For example, the sequence [1,3,2,4]
 is smaller than the sequence [1,3,4,2]
 because after the two matching elements [1,3]
 in the start the first sequence has an element 2
 which is smaller than the corresponding element 4
 in the second sequence.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The next 2𝑡
 lines contain descriptions of the test cases.

The first line of each test case description contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — permutation size. The second line of the description contains 𝑛
 space-separated integers 𝑝𝑖
 (1≤𝑝𝑖≤𝑛
; all 𝑝𝑖
 are all unique) — elements of the permutation.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
Print 𝑡
 lines, each line containing the answer to the corresponding test case. The
answer to a test case should contain 𝑛 space-separated integer numbers — the
elements of the lexicographically smallest permutation that is possible to find
in the deque after executing the described algorithm.

Example
InputCopy
5
4
3 1 2 4
3
3 2 1
3
3 1 2
2
1 2
2
2 1
OutputCopy
1 3 2 4
1 2 3
1 3 2
1 2
1 2
Note
One of the ways to get a lexicographically smallest permutation [1,3,2,4]
 from the permutation [3,1,2,4]
 (the first sample test case) is described in the problem statement.

*/
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    deque<long> d;

    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      if (d.empty() || x < d.front()) {
        d.push_front(x);
      } else {
        d.push_back(x);
      }
    }

    for (long p = 0; p < n; p++) {
      cout << d[p] << " ";
    }
    cout << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1579/336075979

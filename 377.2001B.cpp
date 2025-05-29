/* B. Generate Permutation
time limit per test1.5 seconds
memory limit per test256 megabytes
There is an integer sequence 𝑎
 of length 𝑛
, where each element is initially −1
.

Misuki has two typewriters where the first one writes letters from left to
right, with a pointer initially pointing to 1 , and another writes letters from
right to left with a pointer initially pointing to 𝑛
.

Misuki would choose one of the typewriters and use it to perform the following
operations until 𝑎 becomes a permutation of [1,2,…,𝑛]

write number: write the minimum positive integer that isn't present in the array
𝑎 to the element 𝑎𝑖 , 𝑖 is the position where the pointer points at. Such
operation can be performed only when 𝑎𝑖=−1
.
carriage return: return the pointer to its initial position (i.e. 1
 for the first typewriter, 𝑛
 for the second)
move pointer: move the pointer to the next position, let 𝑖
 be the position the pointer points at before this operation, if Misuki is using
the first typewriter, 𝑖:=𝑖+1 would happen, and 𝑖:=𝑖−1 otherwise. Such operation
can be performed only if after the operation, 1≤𝑖≤𝑛 holds. Your task is to
construct any permutation 𝑝 of length 𝑛 , such that the minimum number of
carriage return operations needed to make 𝑎=𝑝 is the same no matter which
typewriter Misuki is using.

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the
test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the permutation.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a line of 𝑛
 integers, representing the permutation 𝑝
 of length 𝑛
 such that the minimum number of carriage return operations needed to make 𝑎=𝑝
 is the same no matter which typewriter Misuki is using, or −1
 if it is impossible to do so.

If there are multiple valid permutations, you can output any of them.

Example
InputCopy
3
1
2
3
OutputCopy
1
-1
3 1 2
Note
In the first testcase, it's possible to make 𝑎=𝑝=[1]
 using 0
 carriage return operations.

In the second testcase, it is possible to make 𝑎=𝑝=[1,2]
 with the minimal number of carriage returns as follows:

If Misuki is using the first typewriter:

Write number: write 1
 to 𝑎1
, 𝑎
 becomes [1,−1]
Move pointer: move the pointer to the next position. (i.e. 2
)
Write number: write 2
 to 𝑎2
, 𝑎
 becomes [1,2]
If Misuki is using the second typewriter:

Move pointer: move the pointer to the next position. (i.e. 1
)
Write number: write 1
 to 𝑎1
, 𝑎
 becomes [1,−1]
Carriage return: return the pointer to 2
.
Write number: write 2
 to 𝑎2
, 𝑎
 becomes [1,2]
It can be proven that the minimum number of carriage returns needed to transform
𝑎 into 𝑝 when using the first typewriter is 0 and it is 1 when using the second
one, so this permutation is not valid.

Similarly, 𝑝=[2,1]
 is also not valid, so there is no solution for 𝑛=2
.

In the third testcase, it is possibile to make 𝑎=𝑝=[3,1,2]
 with 1
 carriage return with both the first and the second typewriter. It can be proven
that, for both typewriters, it is impossible to write 𝑝 with 0 carriage returns.

With the first typewriter it is possible to:

Move pointer: move the pointer to the next position. (i.e. 2
)
Write number: write 1
 to 𝑎2
, 𝑎
 becomes [−1,1,−1]
Move pointer: move the pointer to the next position. (i.e. 3
)
Write number: write 2
 to 𝑎3
, 𝑎
 becomes [−1,1,2]
Carriage return: return the pointer to 1
.
Write number: write 3
 to 𝑎1
, 𝑎
 becomes [3,1,2]
With the second typewriter it is possible to:

Move pointer: move the pointer to the next position. (i.e. 2
)
Write number: write 1
 to 𝑎2
, 𝑎
 becomes [−1,1,−1]
Carriage return: return the pointer to 3
.
Write number: write 2
 to 𝑎3
, 𝑎
 becomes [−1,1,2]
Move pointer: move the pointer to the next position. (i.e. 2
)
Move pointer: move the pointer to the next position. (i.e. 1
)
Write number: write 3
 to 𝑎1
, 𝑎
 becomes [3,1,2]

*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << "-1" << endl;
    } else {
      for (int i = 1; i < n; i += 2) {
        cout << i + 1 << " " << i << " ";
      }
      cout << n << endl;
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2001/321857624

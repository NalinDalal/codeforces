/*B. Hamon Odyssey
time limit per test1 second
memory limit per test256 megabytes
Jonathan is fighting against DIO's Vampire minions. There are 𝑛
 of them with strengths 𝑎1,𝑎2,…,𝑎𝑛
.

Denote (𝑙,𝑟)
 as the group consisting of the vampires with indices from 𝑙
 to 𝑟
. Jonathan realizes that the strength of any such group is in its weakest link,
that is, the bitwise AND. More formally, the strength level of the group (𝑙,𝑟)
 is defined as
𝑓(𝑙,𝑟)=𝑎𝑙&𝑎𝑙+1&𝑎𝑙+2&…&𝑎𝑟.
Here, &
 denotes the bitwise AND operation.

Because Jonathan would like to defeat the vampire minions fast, he will divide
the vampires into contiguous groups, such that each vampire is in exactly one
group, and the sum of strengths of the groups is minimized. Among all ways to
divide the vampires, he would like to find the way with the maximum number of
groups.

Given the strengths of each of the 𝑛
 vampires, find the maximum number of groups among all possible ways to divide
the vampires with the smallest sum of strengths.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of vampires.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the individual strength of each vampire.

The sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the maximum number of groups among
all possible ways to divide the vampires with the smallest sum of strengths.

Example
InputCopy
3
3
1 2 3
5
2 3 1 5 2
4
5 7 12 6
OutputCopy
1
2
1
Note
In the first test case, the optimal way is to take all the 𝑛
 vampires as a group. So, 𝑓(1,3)=1&2&3=0
.

In the second test case, the optimal way is to make 2
 groups, (2,3,1)
 and (5,2)
. So, 𝑓(1,3)+𝑓(4,5)=(2&3&1)+(5&2)=0+0=0
.
*/

/* You have an array a[1..n] and can divide it into contiguous groups.

Each group’s strength = bitwise AND of its elements.

You want:

Minimum total sum of strengths across groups.

Maximum number of groups that achieves that minimum sum.

Observation 1:
- The bitwise AND of numbers is monotone decreasing as you add more elements:
a_i & a_{i+1} & ... & a_j \le a_i

- If at any point the AND becomes 0, adding more elements cannot make it
negative. So splitting at 0s is safe.

Observation 2:
- The minimal sum is achieved when each group has AND = 0 whenever possible.
- So the goal becomes: split into as many groups as possible where the AND of
each group is 0.
*/

/*Algorithm
1. Initialize current_and = 0, groups = 0.

2. Iterate through the array:
    - current_and &= a[i] if starting new group; else current_and = a[i]
    ```cpp
        if(!cur){ ++cnt; cur = x; }
        else { cur &= x; }
    ```
    - If current_and == 0:
        - Increment groups
        - Start a new group with cur = x.
    - else:
        keep accumulating AND in cur


3. At the end, groups = maximum number of groups with minimal sum.
```cpp
cnt += (!cur);  // if last group AND is 0, count it
cnt += (!cnt);  // ensure at least 1 group
```
- cnt += (!cur) → if the last group ended with cur == 0, increment group count.
- cnt += (!cnt) → special case: if there was never a 0 AND (all ANDs non-zero),
make sure at least one group.

4. Print → maximum number of groups with minimal sum.
*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n;
    scanf("%ld", &n);
    long cur;
    scanf("%ld", &cur);
    long cnt(0);

    for (long p = 1; p < n; p++) {
      long x;
      scanf("%ld", &x);
      if (!cur) {
        ++cnt;
        cur = x;
      } else {
        cur &= x;
      }
    }

    cnt += (!cur);
    cnt += (!cnt);
    printf("%ld\n", cnt);
  }
}
// sub: https://codeforces.com/problemset/submission/1847/335537750

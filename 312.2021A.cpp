/* A. Meaning Mean
time limit per test1 second
memory limit per test256 megabytes
Pak Chanek has an array 𝑎
 of 𝑛
 positive integers. Since he is currently learning how to calculate the floored
average of two numbers, he wants to practice it on his array 𝑎
.

While the array 𝑎
 has at least two elements, Pak Chanek will perform the following three-step
operation:

Pick two different indices 𝑖
 and 𝑗
 (1≤𝑖,𝑗≤|𝑎|
; 𝑖≠𝑗
), note that |𝑎|
 denotes the current size of the array 𝑎
.
Append ⌊𝑎𝑖+𝑎𝑗2⌋
∗
 to the end of the array.
Remove elements 𝑎𝑖
 and 𝑎𝑗
 from the array and concatenate the remaining parts of the array.
For example, suppose that 𝑎=[5,4,3,2,1,1]
. If we choose 𝑖=1
 and 𝑗=5
, the resulting array will be 𝑎=[4,3,2,1,3]
. If we choose 𝑖=4
 and 𝑗=3
, the resulting array will be 𝑎=[5,4,1,1,2]
.

After all operations, the array will consist of a single element 𝑥
. Find the maximum possible value of 𝑥
 if Pak Chanek performs the operations optimally.

∗
⌊𝑥⌋
 denotes the floor function of 𝑥
, which is the greatest integer that is less than or equal to 𝑥
. For example, ⌊6⌋=6
, ⌊2.5⌋=2
, ⌊−3.6⌋=−4
 and ⌊𝜋⌋=3

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5000
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤50
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

Do note that the sum of 𝑛
 over all test cases is not bounded.

Output
For each test case, output a single integer: the maximum possible value of 𝑥
 after all numbers have been picked.

Example
InputCopy
3
5
1 7 8 4 5
3
2 6 5
5
5 5 5 5 5
OutputCopy
6
4
5
Note
In the first test case, the array is initially 𝑎=[1,7,8,4,5]
. Pak Chanek will perform the following operations:

Pick 𝑖=1
 and 𝑗=2
, then 𝑎=[8,4,5,4]
.
Pick 𝑖=3
 and 𝑗=2
, then 𝑎=[8,4,4]
.
Pick 𝑖=2
 and 𝑗=3
, then 𝑎=[8,4]
.
Pick 𝑖=1
 and 𝑗=2
, then 𝑎=[6]
.
After all the operations, the array consists of a single element 𝑥=6
. It can be proven that there is no series of operations that results in 𝑥
 greater than 6
 in the end.


*/

#include <iostream>
#include <set>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    std::multiset<long> ms;
    // take 2 indices i,j
    // append[ai+aj]/2 to end of vector
    // delete both a[i],a[j]
    // do till vector.size()!<2
    // return the max possible value of final element
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ms.insert(x);
    }
    while (ms.size() > 1) {
      int x = *ms.begin();
      ms.erase(ms.begin());
      int y = *ms.begin();
      ms.erase(ms.begin());
      ms.insert((x + y) / 2);
    }

    cout << *ms.begin() << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2021/317120650

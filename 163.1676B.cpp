/* B. Equal Candies
time limit per test1 second
memory limit per test256 megabytes
There are 𝑛
 boxes with different quantities of candies in each of them. The 𝑖
-th box has 𝑎𝑖
 candies inside.

You also have 𝑛
 friends that you want to give the candies to, so you decided to give each
friend a box of candies. But, you don't want any friends to get upset so you
decided to eat some (possibly none) candies from each box so that all boxes have
the same quantity of candies in them. Note that you may eat a different number
of candies from different boxes and you cannot add candies to any of the boxes.

What's the minimum total number of candies you have to eat to satisfy the
requirements?

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤50
) — the number of boxes you have.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤107
) — the quantity of candies in each box.

Output
For each test case, print a single integer denoting the minimum number of
candies you have to eat to satisfy the requirements.

Example
InputCopy
5
5
1 2 3 4 5
6
1000 1000 5 1000 1000 1000
10
1 2 3 5 1 2 7 9 13 5
3
8 8 8
1
10000000
OutputCopy
10
4975
38
0
0
Note
For the first test case, you can eat 1
 candy from the second box, 2
 candies from the third box, 3
 candies from the fourth box and 4
 candies from the fifth box. Now the boxes have [1,1,1,1,1]
 candies in them and you ate 0+1+2+3+4=10
 candies in total so the answer is 10
.

For the second test case, the best answer is obtained by making all boxes
contain 5 candies in them, thus eating 995+995+0+995+995+995=4975 candies in
total.


*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {

    int n;
    cin >> n;
    vector<int> v(n); // Create a vector to store n integers
    int s = 0, mn = 1e9;
    for (int i = 0; i < n; i++) {
      cin >> v[i];        // Read each integer into the vector
      s += v[i];          // Calculate sum of all elements
      mn = min(mn, v[i]); // Track the minimum value
    }
    int res = s - n * mn; // Calculate the result
    cout << res << endl;  // Output the result
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1676/307321497

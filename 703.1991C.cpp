/*C. Absolute Zero
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑎
 of 𝑛
 integers.

In one operation, you will perform the following two-step move:

Choose an integer 𝑥
 (0≤𝑥≤109
).
Replace each 𝑎𝑖
 with |𝑎𝑖−𝑥|
, where |𝑣|
 denotes the absolute value of 𝑣
.
For example, by choosing 𝑥=8
, the array [5,7,10]
 will be changed into [|5−8|,|7−8|,|10−8|]=[3,1,2]
.

Construct a sequence of operations to make all elements of 𝑎
 equal to 0
 in at most 40
 operations or determine that it is impossible. You do not need to minimize the
number of operations.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer −1
 if it is impossible to make all array elements equal to 0
 in at most 40
 operations.

Otherwise, output two lines. The first line of output should contain a single
integer 𝑘 (0≤𝑘≤40 ) — the number of operations. The second line of output should
contain 𝑘 integers 𝑥1,𝑥2,…,𝑥𝑘 (0≤𝑥𝑖≤109 ) — the sequence of operations, denoting
that on the 𝑖 -th operation, you chose 𝑥=𝑥𝑖
.

If there are multiple solutions, output any of them.

You do not need to minimize the number of operations.

Example
InputCopy
5
1
5
2
0 0
3
4 6 8
4
80 40 20 10
5
1 2 3 4 5
OutputCopy
1
5
0

3
6 1 1
7
60 40 20 10 30 25 5
-1
Note
In the first test case, we can perform only one operation by choosing 𝑥=5
, changing the array from [5]
 to [0]
.

In the second test case, no operations are needed because all elements of the
array are already 0
.

In the third test case, we can choose 𝑥=6
 to change the array from [4,6,8]
 to [2,0,2]
, then choose 𝑥=1
 to change it to [1,1,1]
, and finally choose 𝑥=1
 again to change the array into [0,0,0]
.

In the fourth test case, we can make all elements 0
 by following the operation sequence (60,40,20,10,30,25,5)
.

In the fifth test case, it can be shown that it is impossible to make all
elements 0 in at most 40 operations. Therefore, the output is −1
.
*/

/*(t--){
 cin>>n;cin>>vector<int> v(n);
 int ans=0;

vector<int> ansVec(n);
logic for ans and ansVec

In one operation, you will perform the following two-step move:

Choose an integer x (0≤x≤109).
Replace each ai with |ai−x|, where |a| denotes the absolute value of v.
For example, by choosing 𝑥=8, the array [5,7,10] will be changed into
[|5−8|,|7−8|,|10−8|]=[3,1,2].

Construct a sequence of operations to make all elements of a equal to 0 in at
most 40 operations or determine that it is impossible. You do not need to
minimize the number of operations.

Track whether the array contains odd numbers, even numbers, or both:

odd = true if any element is odd

even = true if any element is even

if(odd && even)cout<<-1<<endl;

 if(ans>40)cout<<-1<<endl;
 else{
 cout<<ans<<endl;
 for(int i=0;i<n;i++)cout<<ansVec[i]<<" ";
 }
 cout<<endl;
}

for each test case:
    read n
    read array a[0..n-1]

    odd = false
    even = false
    for each element in a:
        if element is odd:
            odd = true
        else:
            even = true

    if odd and even:
        output -1
        continue to next test case

    output 30 + (1 if even else 0)  // number of operations

    for i from 29 down to 0:
        output 2^i

    if even:
        output 1

    print newline

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);

    bool hasOdd = false, hasEven = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        hasEven = true;
      else
        hasOdd = true;
    }

    // Mixed parity -> impossible
    if (hasOdd && hasEven) {
      cout << -1 << "\n";
      continue;
    }

    // Number of operations
    int numOps = 30 + (hasEven ? 1 : 0);
    cout << numOps << "\n";

    // Output powers of 2 from 2^29 down to 2^0
    for (int i = 29; i >= 0; i--) {
      cout << (1LL << i) << " ";
    }

    // Extra 1 if all numbers are even
    if (hasEven)
      cout << "1";

    cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1991/339458386

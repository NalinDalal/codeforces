/*B. Medians
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎=[1,2,…,𝑛]
, where 𝑛
 is odd, and an integer 𝑘
.

Your task is to choose an odd positive integer 𝑚
 and to split 𝑎
 into 𝑚
 subarrays†
 𝑏1,𝑏2,…,𝑏𝑚
 such that:

Each element of the array 𝑎
 belongs to exactly one subarray.
For all 1≤𝑖≤𝑚
, |𝑏𝑖|
 is odd, i.e., the length of each subarray is odd.
median([median(𝑏1),median(𝑏2),…,median(𝑏𝑚)])=𝑘
, i.e., the median‡
 of the array of medians of all subarrays must equal 𝑘
. median(𝑐)
 denotes the median of the array 𝑐
.
†
A subarray of the array 𝑎
 of length 𝑛
 is the array [𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟]
 for some integers 1≤𝑙≤𝑟≤𝑛
.

‡
A median of the array of odd length is the middle element after the array is
sorted in non-decreasing order. For example: median([1,2,5,4,3])=3 ,
median([3,2,1])=2 , median([2,1,2,1,2,2,2])=2
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤5000 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛<2⋅105
, 𝑛
 is odd) — the length of array 𝑎
 and the desired median of the array of medians of all subarrays.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case:

If there is no suitable partition, output −1
 in a single line.
Otherwise, in the first line, output an odd integer 𝑚
 (1≤𝑚≤𝑛
), and in the second line, output 𝑚
 distinct integers 𝑝1,𝑝2,𝑝3,…,𝑝𝑚
 (1=𝑝1<𝑝2<𝑝3<…<𝑝𝑚≤𝑛
) — denoting the left borders of each subarray.
In detail, for a valid answer [𝑝1,𝑝2,…,𝑝𝑚]
:

𝑏1=[𝑎𝑝1,𝑎𝑝1+1,…,𝑎𝑝2−1]
𝑏2=[𝑎𝑝2,𝑎𝑝2+1,…,𝑎𝑝3−1]
…
𝑏𝑚=[𝑎𝑝𝑚,𝑎𝑝𝑚+1,…,𝑎𝑛]
.
If there are multiple solutions, you can output any of them.

Example
InputCopy
4
1 1
3 2
3 3
15 8
OutputCopy
1
1
3
1 2 3
-1
5
1 4 7 10 13
Note
In the first test case, the given partition has 𝑚=1
 and 𝑏1=[1]
. It is obvious that median([median([1])])=median([1])=1
.

In the second test case, the given partition has 𝑚=3
 and:

𝑏1=[1]
𝑏2=[2]
𝑏3=[3]
Therefore, median([median([1]),median([2]),median([3])])=median([1,2,3])=2
.

In the third test case, there is no valid partition for 𝑘=3
.

In the fourth test case, the given partition has 𝑚=5
 and:

𝑏1=[1,2,3]
𝑏2=[4,5,6]
𝑏3=[7,8,9]
𝑏4=[10,11,12]
𝑏5=[13,14,15]
Therefore,
median([median([1,2,3]),median([4,5,6]),median([7,8,9]),median([10,11,12]),median([13,14,15])])=median([2,5,8,11,14])=8
.




*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long n, k;
    scanf("%ld %ld", &n, &k);
    if (n == 1 && k == 1) {
      puts("1 1");
    } else if (k == 1 || k == n) {
      puts("-1");
    } else if (k % 2) {
      printf("3\n1 %ld %ld\n", k - 1, k + 2);
    } else {
      printf("3\n1 %ld %ld\n", k, k + 1);
    }
  }
}
// sub: https://codeforces.com/problemset/submission/2032/324990095

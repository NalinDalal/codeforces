/*B. Buying Lemonade
time limit per test1 second
memory limit per test256 megabytes
There is a vending machine that sells lemonade. The machine has a total of 𝑛
 slots. You know that initially, the 𝑖
-th slot contains 𝑎𝑖
 cans of lemonade. There are also 𝑛
 buttons on the machine, each button corresponds to a slot, with exactly one
button corresponding to each slot. Unfortunately, the labels on the buttons have
worn off, so you do not know which button corresponds to which slot.

When you press the button corresponding to the 𝑖
-th slot, one of two events occurs:

If there is a can of lemonade in the 𝑖
-th slot, it will drop out and you will take it. At this point, the number of
cans in the 𝑖 -th slot decreases by 1
.
If there are no cans of lemonade left in the 𝑖
-th slot, nothing will drop out.
After pressing, the can drops out so quickly that it is impossible to track from
which slot it fell. The contents of the slots are hidden from your view, so you
cannot see how many cans are left in each slot. The only thing you know is the
initial number of cans in the slots: 𝑎1,𝑎2,…,𝑎𝑛
.

Determine the minimum number of button presses needed to guarantee that you
receive at least 𝑘 cans of lemonade.

Note that you can adapt your strategy during the button presses based on whether
you received a can or not. It is guaranteed that there are at least 𝑘 cans of
lemonade in total in the machine. In other words, 𝑘≤𝑎1+𝑎2+…+𝑎𝑛
.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤2⋅105
, 1≤𝑘≤109
) — the number of slots in the machine and the required number of cans of
lemonade.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the number of cans in the slots.

It is guaranteed that 𝑘≤𝑎1+𝑎2+…+𝑎𝑛
, meaning there are at least 𝑘
 cans of lemonade in the machine.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum number of button
presses needed to guarantee that you receive at least 𝑘 cans of lemonade.

Example
InputCopy
5
2 1
1 1
2 2
1 2
3 4
2 1 3
10 50
1 1 3 8 8 9 12 13 27 27
2 1000000000
1000000000 500000000
OutputCopy
1
2
5
53
1000000000
Note
In the first test case, we can simply press the first button and receive one can
of lemonade.

In the second test case, we can press each button once and guarantee that we
receive 2 cans of lemonade. Note that if we simply press one button twice, we
might not be lucky, and that button could correspond to the first slot, in which
case we would only receive 1 can of lemonade for two presses.

In the third test case, one of the optimal strategies is as follows:

Press the first button twice. After the first press, a can of lemonade will
definitely drop out. Then there are two options:

If no can of lemonade drops after the second press, we know that this button
must correspond to the second slot, since 𝑎2=1 and 𝑎1,𝑎3>1 . Then we can press
the second button twice and the third button once. Since 𝑎1,𝑎3≥2 , we will
definitely receive three cans of lemonade for these three presses. Thus, after 5
 presses, we will have 4
 cans of lemonade.
If a can of lemonade drops after the second press, we can make one press on the
second button and one press on the third button. After each of these presses, we
will definitely receive a can of lemonade. Thus, after 4 presses, we will have 4
 cans of lemonade.
It can be shown that it is impossible to guarantee receiving 4
 cans of lemonade with only 4
 presses, so the answer is 5
.
*/

/*(t--){
 n,k;   //no of slots and required no of cans
 cin>>vector<int> v(n);

 sum of vector>=k

 you randomly press i, either the ith slots empties out or if already empty then
nothing

 after pressing acts out so fast impossible to tell from which it fell

 ans=min no of press to get atleast k cans
 k<=a1+a2+a3...+an

sort the vector in ascending to exhaust smaller slots

ans, and prev, prev tracks previous slot size during iteration.

diff = v[p] - prev: how many extra cans appear compared to the previous slot
size. (n - p) = number of slots still not processed (including current one). num
= diff * (n - p) = total additional presses you can spend while still making no
guaranteed progress


     if(k <= num){  //need at most k
        cnt += k;   //but can absorb atmost k
        break;
    }
    else{
        cnt += num + 1; //consume all num wasted press, +1 for 1 guaranteed can
        k -= num;   //to secure the rest
    }

cout<<ans<<endl;

  }
*/

#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll t;
  std::cin >> t;
  while (t--) {
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> v(n);
    for (ll p = 0; p < n; p++) {
      std::cin >> v[p];
    }

    std::sort(v.begin(), v.end());

    ll cnt = 0, prev = 0;
    for (ll p = 0; p < n; p++) {
      ll diff = v[p] - prev;
      prev = v[p];
      ll num = diff * (n - p);
      if (k <= num) {
        cnt += k;
        break;
      } else {
        cnt += num + 1;
        k -= num;
      }
    }

    std::cout << cnt << "\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/2024/339457432

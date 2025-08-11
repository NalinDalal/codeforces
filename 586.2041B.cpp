/*B. Bowling Frame
time limit per test1 second
memory limit per test1024 megabytes
Bowling is a national sport in Taiwan; everyone in the country plays the sport
on a daily basis since their youth. Naturally, there are a lot of bowling alleys
all over the country, and the competition between them is as intense as you can
imagine.

Maw-Shang owns one such bowling alley. To stand out from other competitors in
the industry and draw attention from customers, he decided to hold a special
event every month that features various unorthodox bowling rules. For the event
this month, he came up with a new version of the game called X-pin bowling. In
the traditional 10 -pin bowling game, a frame is built out of ten bowling pins
forming a triangular shape of side length four. The pin closest to the player
forms the first row, and the two pins behind it form the second row, and so on.
Unlike the standard version, the game of 𝑋 -pin bowling Maw-Shang designed
allows a much larger number of pins that form a larger frame. The following
figure shows a standard 10 -pin frame on the left, and on the right it shows a
21 -pin frame that forms a triangular shape of side length six which is allowed
in the game of 𝑋 -pin bowling.


Being the national sport, the government of Taiwan strictly regulates and
standardizes the manufacturing of bowling pins. There are two types of bowling
pins allowed, one in black and the other in white, and the bowling alley
Maw-Shang owns has 𝑤 white pins and 𝑏 black pins. To make this new game exciting
for the customers, Maw-Shang wants to build the largest possible frame from
these 𝑤+𝑏 pins. However, even though he is okay with using both colors in
building the frame, for aesthetic reasons, Maw-Shang still wants the colors of
the pins on the same row to be identical. For example, the following figure
shows two possible frames of side length six, but only the left one is
acceptable to Maw-Shang since the other one has white and black pins mixed in
the third row.


The monthly special event is happening in just a few hours. Please help
Maw-Shang calculate the side length of the largest frame that he can build from
his 𝑤+𝑏 pins!

Input
The first line of the input contains a single integer 𝑡
, the number of test cases. Each of the following 𝑡
 lines contains two integers 𝑤
 and 𝑏
, the number of white and black pins, respectively.

1≤𝑡≤100
0≤𝑤,𝑏≤109
Output
For each test case, output in a single line the side length 𝑘
 of the largest pin satisfying Maw-Shang's requirement you can build with the
given pins.

Example
InputCopy
4
1 2
3 2
3 3
12 0
OutputCopy
2
2
3
4
*/

#include <cmath>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long long w, b;
    std::cin >> w >> b;

    long double total = static_cast<long double>(w + b);
    long res = static_cast<long>((std::sqrt(1 + 8.0 * total) - 1) / 2.0);

    std::cout << res << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2041/333483272

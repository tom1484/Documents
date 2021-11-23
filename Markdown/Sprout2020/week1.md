# Sprout 2020 Algorithm - Week

**Author: 陳楚融**

## Problem 1

假設 $n\ (n > 1)$ 人時，存在一組關係，使任兩人之認識人數皆不同，令 $a_i$ 為第 $i\ (1 \leq i \leq n)$ 人之認識人數

因 $0 \leq a_i \leq n - 1$ ，共 $n$ 種可能，且根據假設， $n$ 項中兩兩不重複，得 $a_1\ \cdots\ a_n$ 必定與 $0\ \cdots\ n-1$ 一一對應

令 $a_1 = 0,\ a_n = n - 1$ ，表示沒有人認識第 $1$ 人，第 $n$ 人卻認識所有人，假設矛盾

得證必有兩人認識人數相同

## Problem 2

已知 $n = 3$ 時：
$$
3 ^ n + 4 ^ n = 91 < 5 ^ n = 125 \quad \cdots \quad (1)
$$
命題成立

假設 $n = k$ 時， $3 ^ k + 4 ^ k < 5 ^ k$ ，則 $n = k + 1$ 時：
$$
\begin{split}
3 ^ {k + 1} + 4 ^ {k + 1} &= 3 * 3 ^ k + 4 * 4 ^ k \\
&< 5 * (3 ^ k + 4 ^ k) < 5 * 5 ^ k \\
&= 5 ^ {k + 1}
\end{split}
\quad \cdots \quad (2)
$$
命題仍然成立

由 $(1),\ (2)$ ，以數學歸納法得證

## Problem 3

已知 $n = 4$ 時：
$$
3 ^ n = 81 > n ^ 3 = 64
\quad \cdots \quad(1)
$$
命題成立

假設 $n = k\ (k \geq 4)$ 時， $3 ^ k > k ^ 3$ ，則 $n = k + 1$ 時：
$$
\begin{split}
{3 ^ {k + 1}}\ &= \ {3 * 3 ^ k} \\
{(k + 1) ^ 3}\ &= \ {(\frac{k + 1}{k}) ^ 3 * k ^ 3}
\end{split}
$$
根據分數性質：
$$
\begin{split}
\frac{k + 1}{k} < \frac{k}{k - 1}, \quad k > 1
\end{split}
$$

又 $k = 4$ 時：
$$
(\frac{k + 1}{k}) ^ 3 < (\frac{k}{k - 1}) ^ 3 = \frac{64}{27} < 3
$$
因此：
$$
\begin{split}
3 * k ^ 3 &> (\frac{k + 1}{k}) ^ 3 * k ^ 3 \\
3^{k + 1} &> (k + 1) ^ 3
\end{split}
\quad \cdots \quad (2)
$$
命題仍然成立

由 $(1),\ (2)$ ，以數學歸納法得證

## Problem 4

令 $F(n)$ 為 $n \in \N$ 之總得分，已知 $n = 1$ 時：
$$
\begin{split}
F(n) &= 0 = \frac{1 ^ 2 - 1}{2} \\
&= \frac{n ^ 2 - n}{2}
\end{split}
\quad \cdots \quad (1)
$$
命題成立

假設 $n \geq 2$ ，可將 $n$ 拆成任意之 $a + b = n,\ a,\ b \geq 1$ ，此操作得 $a * b$ 分，再將 $a,\ b$ 拆至僅剩 $1$ 為止，分別會獲得分數 $F(a),\ F(b)$ ，得：
$$
\begin{split}
F(n) &= a * b + F(a) + F(b) \\
&= \frac{a ^ 2 - a + b ^ 2 - b}{2} + a * b \\
&= \frac{a ^ 2 + b ^ 2 + 2 * a * b - n}{2} \\
&= \frac{n ^ 2 - n}{2}
\end{split}
\quad \cdots \quad (2)
$$
由 $(1),\ (2)$ ，以數學歸納法得證

## Problem 5

對於一種可行的投票結果 $a_1\ \cdots\ a_n$ ，將其順序重組後仍然有解，故假設 $a_1\ \cdots\ a_n$ 為降冪排序，並令一序列 $B = [b_1 = 0\ \cdots\ b_n = 0]$

若 $b_j = i$ ，表示令第 $j$ 人投給第 $i$ 人

已知條件：
$$
\begin{split}
0 \leq a_i < n \quad \cdots \quad (1) \\
\sum_{i = 1} ^ {n} a_i = n \quad \cdots \quad (2)
\end{split}
$$
由 $(1),\ (2)$ 可知若不考慮不能投給自己之限制，所有人皆可恰投一票

先令 $b_2 = 1$ ，設 $a_1\ \cdots\ a_n$ 中不為 $0$ 之項目數量為 $p$ ，$B$ 中最後一個不為 $0$ 之項目編號為 $q$

對所有 $i\ (1 \leq i \leq p-1)$ ，依序將當前 $b_q\ \cdots\ b_{q + a_i - 1}$ 修改為 $i$  ，因：
$$
\begin{split}
q &= 2+\sum_{j = 1}^{i-1} a_j-1 = 1+\sum_{j = 1}^{i-1} a_j \\
&\geq 1+\sum_{j = 1}^{i-1} 1 = i
\end{split}
$$
得 $i \leq q$ ，故 $b_i \neq i$ ，第 $i\ (i > 1)$ 人必不投給自己，最後修改 $b_{n - a_p + 2}\ \cdots\ b_n,\ b_1$ 為 $p$

至此對於任意 $n\ (n > 1)$ 人之投票結果，構造出一合法投票方法

得證只要符合 $(1),\ (2)$ ，必為一可能的投票結果
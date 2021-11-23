## Sprout 2020 Algorithm - Week 2

**Author: 陳楚融**

### Problem 1

#### (1)

$$
\begin{split}
\lim_{n \to \infty} \frac{3n + 1}{n - 1} 
= \frac{\lim\limits_{n \to \infty} 3n + 1}{\lim\limits_{n \to \infty} n - 1}
= \frac{(\lim\limits_{n \to \infty} 3) * (\lim\limits_{n \to \infty} n + \frac{1}{3})}{\lim\limits_{n \to \infty} n - 1} 
= 3 * \frac{\lim\limits_{n \to \infty} n}{\lim\limits_{n \to \infty} n} 
= 3 * \lim_{n \to \infty} \frac{n}{n} = 3
\end{split}
$$

#### (2)

$$
\begin{split}
\lim_{n \to \infty} \frac{n}{n ^ 2 + 1} 
= \frac{\lim\limits_{n \to \infty} n}{\lim\limits_{n \to \infty} n ^ 2 + 1} 
= \frac{\lim\limits_{n \to \infty} n}{\lim\limits_{n \to \infty} n ^ 2}
= \lim_{n \to \infty} \frac{n}{n ^ 2} 
= \lim_{n \to \infty} \frac{1}{n} = 0
\end{split}
$$

#### (3)

$(1)$ 先證 $f(n) \in O(2 ^ n) \Longrightarrow f(n) \in O(2 ^ {n + 1})$ ：
$$
\begin{split}
&\because f(n) \in O(2 ^ n) \\
&\therefore \exists k \ge 0:\ \lim_{n \to \infty} \frac{f(n)}{2 ^ n} = k \\
&\therefore \lim_{n \to \infty} \frac{f(n)}{2 ^ {n + 1}} 
= \frac{\lim\limits_{n \to \infty} f(n)}{\lim\limits_{n \to \infty} 2 ^ {n + 1}}
= \frac{\lim\limits_{n \to \infty} f(n)}{2 * \lim\limits_{n \to \infty} 2 ^ n}
= \frac{k}{2} \quad \text{(仍為一常數)} \\
&\therefore f(n) \in O(2 ^ {n + 1})
\end{split}
$$
$(2)$ 再證 $f(n) \in O(2 ^ {n + 1}) \Longrightarrow f(n) \in O(2 ^ n)$ ：
$$
\begin{split}
&\because f(n) \in O(2 ^ {n + 1}) \\
&\therefore \exists k \ge 0:\ \lim_{n \to \infty} \frac{f(n)}{2 ^ {n + 1}} = k \\
&\therefore \lim_{n \to \infty} \frac{f(n)}{2 ^ n} 
= \frac{\lim\limits_{n \to \infty} f(n)}{\lim\limits_{n \to \infty} 2 ^ n}
= \frac{\lim\limits_{n \to \infty} f(n)}{\frac{1}{2} * \lim\limits_{n \to \infty} 2 ^ {n + 1}}
= 2 * k \quad \text{(仍為一常數)} \\
&\therefore f(n) \in O(2 ^ n)
\end{split}
$$
由 $(1),\ (2)$ ，得證 $f(n) \in O(2 ^ n) \iff f(n) \in O(2 ^ {n + 1})$

#### (4)

$(1)$ 先證 $f(n) \in O((n + 1)!) \Longrightarrow f(n) \in O(n!)$ ：
$$
\begin{split}
&\because f(n) \in O((n + 1)!) \\
&\therefore \exists k \ge 0:\ \lim_{n \to \infty} \frac{f(n)}{(n + 1)!} = k \\
&\therefore \lim_{n \to \infty} \frac{f(n)}{n!} 
= (\lim\limits_{n \to \infty} n + 1) * \frac{\lim\limits_{n \to \infty} f(n)}{\lim\limits_{n \to \infty} n!} 
= (\lim_{n \to \infty} n) * k  \quad \text{(不會收斂為一常數)}
\end{split}
$$
$(2)$ 若令 $f(n) = (n + 1)!$ ，則：
$$
\lim_{n \to \infty} \frac{f(n)}{n!} = \lim_{n \to \infty} n + 1 = \infty
$$
不會收斂為常數，因此 $f(n) \in O((n + 1)!) \Longrightarrow f(n) \in O(n!)$ 不成立，得證原命題不成立

#### (5)

若命題成立，則：
$$
\begin{split}
\exists k \ge 0:\ \lim_{n \to \infty} \frac{f(n)}{n} = k 
\Longrightarrow \exists j \ge 0:\ 
\lim_{n \to \infty} \frac{2 ^ {f(n)}}{2 ^ n} = j
\end{split}
\quad \cdots \quad (1)
$$
$$
\begin{split}
\lim_{n \to \infty} \frac{2 ^ {f(n)}}{2^n}
= \lim_{n \to \infty} 2 ^ {f(n) - n} 
= 2 ^ {\lim\limits_{n \to \infty} {f(n) - n}}
= 2 ^ {(k - 1) * \lim\limits_{n \to \infty} n}
\end{split}
$$



取 $f(n) = 2n \Longrightarrow k = 2$ ，則：
$$
\begin{split}
\lim_{n \to \infty} \frac{2 ^ {f(n)}}{2 ^ n}
= 2 ^ {(k - 1) * \lim\limits_{n \to \infty} n} 
= 2 ^ {\lim\limits_{n \to \infty} n} 
= \infty
\end{split}
$$
不會收斂為常數，與 $(1)$ 矛盾，得證命題不成立

### Problem 2

首先可將題目改寫為：
$$
\begin{split}
f(2 ^ n) = 
\begin{cases}
1 & ,\ n = 0 \\
2 * f(2 ^ {n - 1}) + 2 ^ {n + 1} & ,\ n \ge 1
\end{cases} \\
\end{split}
$$
證明 $\forall n \in \N,\ f(n) \le 3n * 2 ^ n$ 

當 $n = 0$ 時：
$$
\begin{split}
f(2 ^ 0) = 1 < 3 * 1 * 2 ^ 1 = 6 \quad \cdots \quad (1)
\end{split}
$$
當 $n \ge 1$ 時：
$$
\begin{split}
f(2 ^ n) &= 2 * f(2 ^ {n - 1}) + 2 ^ {n + 1} = 2 ^ 2 * f(2 ^ {n - 2}) + 2 * 2 ^ {n + 1} = \ \cdots \\
&= 2 ^ n + n * 2 ^ {n + 1} = (2n + 1) * 2 ^ n
\end{split}
$$

$$
\begin{split}
&3n * 2 ^ n - f(n) = (n - 1) * 2 ^ n \ge 0 \quad \cdots \quad (2)
\end{split}
$$

由 $(1),\ (2)$ ，得證命題成立

### Problem 3

令 $T(f(n))$ 為一棵將 $f(n)$ 作為根節點， $n ^ 2$ 為點權，左右子樹分別為 $T(f(\lfloor \frac{n}{2} \rfloor)),\ T(f(\lceil \frac{n}{2} \rceil))$ 的樹，令 $T(f(n))$ 中深度為 $i$ 的節點點權總和為 $S_i$ ，總節點數量為 $N_T$ ， 最大深度 $D = \lceil \log_2 n \rceil$ 

由上可得：
$$
\begin{split}
n = 2k,\ k \in \N 
&\Longrightarrow 
{\lfloor \frac{n}{2} \rfloor} ^ 2 + {\lceil \frac{n}{2} \rceil} ^ 2 
= \frac{n ^ 2}{2} \\
n = 2k + 1,\ k \in \N 
&\Longrightarrow 
{\lfloor \frac{n}{2} \rfloor} ^ 2 + {\lceil \frac{n}{2} \rceil} ^ 2 
= (\frac{n}{2} - \frac{1}{2}) ^ 2 + (\frac{n}{2} + \frac{1}{2}) ^ 2 
= \frac{n ^ 2}{2} + \frac{1}{2}
\end{split}
$$

$$
\begin{split}
f(n) = \sum_{i = 0}^{D} S_i = (\sum_{i = 0}^{D} \frac{n ^ 2}{2 ^ i}) &+ \frac{m}{2} 
= \frac{2 ^ {D + 1} - 1}{2 ^ D} * n ^ 2 + \frac{m}{2} \\
2n ^ 2 - 1 - f(n) &= \frac{n ^ 2}{2 ^ D}  - \frac{m}{2} - 1
\end{split}
$$

其中 $m$ 為非葉節點數量， $n > 1,\ D > 0$ 時，僅深度為 $i\ (i < D)$ 之節點可能有子節點

由於 $\lfloor \frac{n}{2} \rfloor + \lceil \frac{n}{2} \rceil = n$ ，故每一組兄弟節點至多有一個點權為奇數，因此：
$$
\begin{split}
&\ m \le \frac{(2 ^ D - 1) - 1}{2} + 1 = 2 ^ {D - 1},\ n \ge 2 ^ {D - 1} + 1 \\
\Longrightarrow 
&\ 2n ^ 2 - 1 - f(n) \ge \frac{n ^ 2}{2 ^ D} - 1 - 2 ^ {D - 2} \\
\ge &\ \frac{2 ^ {2D - 2} + 2 ^ D + 1}{2 ^ D} - 1 - 2 ^ {D - 2} = \frac{1}{2 ^ D} > 0
\quad \cdots \quad (1)
\end{split}
$$
$n = 1$ 時：
$$
\begin{split}
2 * 1 ^ 2 - 1 = 1 \ge n = 1 \Longrightarrow 1 ^ 2 = 1 \quad \cdots \quad (2)
\end{split}
$$
由 $(1),\ (2)$ ，得證 $f(n) \le 2n ^ 2 - 1$ 
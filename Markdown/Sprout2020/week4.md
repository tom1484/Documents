## Sprout 2020 Algorithm  - Week 4

**Author: 陳楚融**

### Problem 1

#### (a)

$$
\begin{split}
&\begin{split}
&\textcolor{red}ｍｉｓｓｉｓｓｉｐｐｉ \\
&\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍ\textcolor{red}ｉｓｓｉｓｓｉｐｐｉ \\
&　\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉ\textcolor{red}ｓｓｉｓｓｉｐｐｉ \\
&　　\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow \\
&\begin{split}
&ｍｉｓ\textcolor{red}ｓｉｓｓｉｐｐｉ \\
&　　ｓ\textcolor{red}ｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓ\textcolor{red}ｓｉｓｓｉｐｐｉ \\
&　　　\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓｓ\textcolor{red}ｉｓｓｉｐｐｉ \\
&　　　ｓ\textcolor{red}ｉｐ \\
\hline
\end{split} \rightarrow \\
&\begin{split}
&ｍｉｓｓｉ\textcolor{red}ｓｓｉｐｐｉ \\
&　　　ｓｉ\textcolor{red}ｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓｓ\textcolor{red}ｉｓｓｉｐｐｉ \\
&　　　　\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓｓｉ\textcolor{red}ｓｓｉｐｐｉ \\
&　　　　　\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow \\
&\begin{split}
&ｍｉｓｓｉｓ\textcolor{red}ｓｉｐｐｉ \\
&　　　　　ｓ\textcolor{red}ｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓｓｉｓ\textcolor{red}ｓｉｐｐｉ \\
&　　　　　　\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓｓｉｓｓ\textcolor{red}ｉｐｐｉ \\
&　　　　　　ｓ\textcolor{red}ｉｐ \\
\hline
\end{split} \rightarrow \\
&\begin{split}
&ｍｉｓｓｉｓｓｉ\textcolor{red}ｐｐｉ \\
&　　　　　　ｓｉ\textcolor{red}ｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓｓｉｓｓ\textcolor{red}ｉｐｐｉ \\
&　　　　　　　\textcolor{red}ｓｉｐ \\
\hline
\end{split} \rightarrow
\begin{split}
&ｍｉｓｓｉｓｓｉ\textcolor{red}ｐｐｉ \\
&　　　　　　　　\textcolor{red}ｓｉｐ \\
\hline
\end{split}
\end{split}
$$

共 $15$ 次

#### (b)

令 $A$ 為 $aa \cdots ax \cdots xx$ ，其中 $x$ 為任意字元，共 $10 ^ 3$ 個，每個皆不相同，長度 $len(A) = 10 ^ 6$ ， $B$ 為 $aaa \cdots aab$ ，長度 $len(B) = 5 * 10 ^ 5$ 

因 $B \notin A$ 且 $\forall i \in \N, i + len(B) - 2 < len(A) - 1000: \ B_{1, len(B) - 1} = A_{i, i + len(B) - 2}$ ，因此共有 $499,001$ 次匹配都需要比較 $len(B)$ 次

得至少比較 $len(B) * 499,001 = 250,000,500,000 > 10 ^ 9$ 次

#### (c)

令 $A$ 為 $ab \cdots abx \cdots xx$ ，其中 $x$ 為任意字元，共 $10 ^ 3$ 個，每個皆不相同且不為 $b$ 或 $a$ ，長度 $len(A) = 10 ^ 6$ ，$B$ 為 $ab \cdots abac$ 長度 $len(B) = 5 * 10 ^ 5$ 

因 $B \notin A$ 且當 $i$ 為奇數時 $\forall i \in \N, i + len(B) - 2 < len(A) - 1000: \ B_{1, len(B) - 1} \in A_{i,i + len(B) - 2}$ ，因此共有 $249,501$ 次匹配需要比較 $len(B)$ 次

得至少比較 $len(B) * 249,501= ‭124,750,500,000‬ > 10 ^ 9$ 次

### Problem 2

#### (a)

有顏色者為目前處理區間，橘色為將左右子區間合併完成之狀態
$$
\begin{split}
&[\textcolor{red}{1\ 8\ 5\ 3\ 2\ 6\ 4\ 7}] \rightarrow
[\textcolor{red}{1\ 8\ 5\ 3}\ 2\ 6\ 4\ 7] \rightarrow 
[\textcolor{red}{1\ 8}\ 5\ 3\ 2\ 6\ 4\ 7] \rightarrow 
[\textcolor{red}{1}\ 8\ 5\ 3\ 2\ 6\ 4\ 7] \rightarrow \\ 
&[1\ \textcolor{red}{8}\ 5\ 3\ 2\ 6\ 4\ 7] \rightarrow 
[\textcolor{orange}{1\ 8}\ 5\ 3\ 2\ 6\ 4\ 7] \rightarrow 
[1\ 8\ \textcolor{red}{5\ 3}\ 2\ 6\ 4\ 7] \rightarrow 
[1\ 8\ \textcolor{red}{5}\ 3\ 2\ 6\ 4\ 7] \rightarrow \\ 
&[1\ 8\ 5\ \textcolor{red}{3}\ 2\ 6\ 4\ 7] \rightarrow 
[1\ 8\ \textcolor{orange}{3\ 5}\ 2\ 6\ 4\ 7] \rightarrow 
[\textcolor{orange}{1\ 3\ 5\ 8}\ 2\ 6\ 4\ 7] \rightarrow 
[1\ 3\ 5\ 8\ \textcolor{red}{2\ 6\ 4\ 7}] \rightarrow \\ 
&[1\ 3\ 5\ 8\ \textcolor{red}{2\ 6}\ 4\ 7] \rightarrow 
[1\ 3\ 5\ 8\ \textcolor{red}{2}\ 6\ 4\ 7] \rightarrow 
[1\ 3\ 5\ 8\ 2\ \textcolor{red}{6}\ 4\ 7] \rightarrow 
[1\ 3\ 5\ 8\ \textcolor{orange}{2\ 6}\ 4\ 7] \rightarrow \\ 
&[1\ 3\ 5\ 8\ 2\ 6\ \textcolor{red}{4\ 7}] \rightarrow 
[1\ 3\ 5\ 8\ 2\ 6\ \textcolor{red}{4}\ 7] \rightarrow 
[1\ 3\ 5\ 8\ 2\ 6\ 4\ \textcolor{red}{7}] \rightarrow 
[1\ 3\ 5\ 8\ 2\ 6\ \textcolor{orange}{4\ 7}] \rightarrow \\  
&[1\ 3\ 5\ 8\ \textcolor{orange}{2\ 4\ 6\ 7}] \rightarrow 
[\textcolor{orange}{1\ 2\ 3\ 4\ 5\ 6\ 7\ 8}]
\end{split}
$$

#### (b)

有顏色者為目前處理區間，藍色為 $pivot$ ，$pivotIndex = (n - 1) / 2$，橘色為已分完堆之數字
$$
\begin{split}
&[\textcolor{red}{1\ 8\ 5}\ \textcolor{blue}3\ \textcolor{red}{2\ 6\ 4\ 7}] \rightarrow
[\textcolor{red}{1\ 8\ 5\ 7\ 2\ 6\ 4}\ \textcolor{blue}3] \rightarrow
[\textcolor{orange}{1\ 2\ 5\ 7\ 8\ 6\ 4}\ \textcolor{blue}3] \rightarrow
[\textcolor{orange}{1\ 2}\ \textcolor{blue}3\ \textcolor{orange}{7\ 8\ 6\ 4\ 5}] \rightarrow \\ 
&[\textcolor{blue}1\ \textcolor{red}2\ 3\ 7\ 8\ 6\ 4\ 5] \rightarrow 
[\textcolor{red}2\ \textcolor{blue}1\ 3\ 7\ 8\ 6\ 4\ 5] \rightarrow 
[\textcolor{orange}2\ \textcolor{blue}1\ 3\ 7\ 8\ 6\ 4\ 5] \rightarrow 
[\textcolor{blue}1\ \textcolor{orange}2\ 3\ 7\ 8\ 6\ 4\ 5] \rightarrow \\ 
&[1\ 2\ 3\ \textcolor{red}{7\ 8}\ \textcolor{blue}6\ \textcolor{red}{4\ 5}] \rightarrow 
[1\ 2\ 3\ \textcolor{red}{7\ 8\ 4\ 5}\ \textcolor{blue}6] \rightarrow 
[1\ 2\ 3\ \textcolor{orange}{4\ 5\ 7\ 8}\ \textcolor{blue}6] \rightarrow 
[1\ 2\ 3\ \textcolor{orange}{4\ 5}\ \textcolor{blue}6\ \textcolor{orange}{8\ 7}] \rightarrow \\ 
&[1\ 2\ 3\ \textcolor{blue}4\ \textcolor{red}5\ 6\ 8\ 7] \rightarrow 
[1\ 2\ 3\ \textcolor{red}5\ \textcolor{blue}4\ 6\ 8\ 7] \rightarrow 
[1\ 2\ 3\ \textcolor{orange}5\ \textcolor{blue}4\ 6\ 8\ 7] \rightarrow 
[1\ 2\ 3\ \textcolor{blue}4\ \textcolor{orange}5\ 6\ 8\ 7] \rightarrow \\ 
&[1\ 2\ 3\ 4\ 5\ 6\ \textcolor{blue}8\ \textcolor{red}7] \rightarrow 
[1\ 2\ 3\ 4\ 5\ 6\ \textcolor{red}7\ \textcolor{blue}8] \rightarrow 
[1\ 2\ 3\ 4\ 5\ 6\ \textcolor{orange}7\ \textcolor{blue}8] \rightarrow 
[1\ 2\ 3\ 4\ 5\ 6\ \textcolor{orange}7\ \textcolor{blue}8]
\end{split}
$$

#### (c)

藍色為目前處理區間，由左至右依序放入 $bucket$ ，橘色為從 $bucket$ 取出後之狀態
$$
\begin{split}
&[\textcolor{blue}{15\ 27\ 35\ 17\ 36\ 28\ 16}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[],\ 6:[26],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{27\ 35\ 17\ 36\ 28\ 16}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[15],\ 6:[26],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{35\ 17\ 36\ 28\ 16}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[15],\ 6:[26],\ 7:[27],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{17\ 36\ 28\ 16}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[15\ 35],\ 6:[26],\ 7:[27],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{36\ 28\ 16}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[15\ 35],\ 6:[26],\ 7:[27\ 17],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{28\ 16}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[15\ 35],\ 6:[26\ 36],\ 7:[27\ 17],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{16}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[15\ 35],\ 6:[26\ 36],\ 7:[27\ 17],\ 8:[28],\ 9:[] \\ 
&[\textcolor{blue}{}] \rightarrow \\ 
&0:[],\ 1:[],\ 2:[],\ 3:[],\ 4:[],\ 5:[15\ 35],\ 6:[26\ 36\ 16],\ 7:[27\ 17],\ 8:[28],\ 9:[] \\ \\ 
&[\textcolor{orange}{15\ 35\ 26\ 36\ 16\ 27\ 17\ 28}] \\ \\ 
&[\textcolor{blue}{35\ 26\ 36\ 16\ 27\ 17\ 28}] \rightarrow \\ 
&0:[],\ 1:[15],\ 2:[],\ 3:[],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{26\ 36\ 16\ 27\ 17\ 28}] \rightarrow \\ 
&0:[],\ 1:[15],\ 2:[],\ 3:[35],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{36\ 16\ 27\ 17\ 28}] \rightarrow \\ 
&0:[],\ 1:[15],\ 2:[26],\ 3:[35],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{16\ 27\ 17\ 28}] \rightarrow \\ 
&0:[],\ 1:[15],\ 2:[26],\ 3:[35\ 36],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{27\ 17\ 28}] \rightarrow \\ 
&0:[],\ 1:[15\ 16],\ 2:[26],\ 3:[35\ 36],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{17\ 28}] \rightarrow \\ 
&0:[],\ 1:[15\ 16],\ 2:[26\ 27],\ 3:[35\ 36],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{28}] \rightarrow \\ 
&0:[],\ 1:[15\ 16\ 17],\ 2:[26\ 27],\ 3:[35\ 36],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ 
&[\textcolor{blue}{}] \rightarrow \\ 
&0:[],\ 1:[15\ 16\ 17],\ 2:[26\ 27\ 28],\ 3:[35\ 36],\ 4:[],\ 5:[],\ 6:[],\ 7:[],\ 8:[],\ 9:[] \\ \\ 
&[\textcolor{orange}{15\ 16\ 17\ 26\ 27\ 28\ 35\ 36}]
\end{split}
$$





### Problem 3

#### (a)

##### 1. Merge sort

首先考慮合併時，若一子區間中有相同元素，必為連續出現，又因為若左右子區間內有相同元素，會優先放入屬於左子區間的，且同一區間中之元素也是由左而右放入新序列，因此僅考慮合併前、後時，是 **stable** ；並且任意長度超過 $1$ 之子區間皆為其子區間合併而成，且長度為 $1$ 之子區間是 **stable** ，得任意子區間對於排序前之原序列皆為 **stable** 

故 **Merge sort** 為 **stable**

##### 2. Quick sort

考慮一序列 $[3\ 3'\ 4]$ ，因 $pivot$ 之選取為隨機，因此以下排序過程為可能的：
$$
\begin{split}
&[\textcolor{blue}3\ \textcolor{red}{3'\ 4}] \rightarrow
[\textcolor{red}{4\ 3'}\ \textcolor{blue}3] \rightarrow
[\textcolor{orange}{3'\ 4}\ \textcolor{blue}3] \rightarrow
[\textcolor{orange}{3'}\ \textcolor{blue}3\ \textcolor{orange}{4}]
\end{split}
$$
得一反例證明 **Quick sort** 並非 **stable**

##### 3. Radix sort

由於元素由左至右放入其 $bucket$ 之末端，因此相同元素放入 $bucket$ 之操作為 **stable** ；提出來時是由 $bucket$ 之前端提出，放入序列末端，因此相同元素提出 $bucket$ 之操作也是 **stable** 

得 **Radix sort** 為 **stable**

#### (b)

在 $Data$ 中使用一變數 $pos$ ，計為該元素在序列中的位置，比較時若值相同則比較 $pos$ ，這樣相同值之元素間排序前兩元素 $pos$ 較小者會位於右側，排序後仍 $pos$ 較小者仍會位於右側，故為 **stable**





首先若有 $n$ 個 $C_i$ ，$n * C_i \ge C_{i+1}$ ，則此 $n$ 個硬幣可先換成 $n - \lfloor \frac{n * C_i}{C_{i + 1}} \rfloor$ 個 $C_i$ 與 $\lfloor \frac{n * C_i}{C_{i + 1}} \rfloor$ 個 $C_{i + 1}$ ，總數變少，且 $(n - \lfloor \frac{n * C_i}{C_{i + 1}} \rfloor) * C_i < C_{i+1}$ ，操作至無法替換以後， $n' * C_i < C_{i + 1} \quad \cdots \quad (1)$ 

接著對於任意 $C_i$ ，若想以面額小於 $C_i$ 之硬幣組合出，可先選擇所有其中最大者 $C_j$，設其總和 $T$ ， $T < C_i$ ，故需用小於 $C_j$ 之硬幣再組出 $C_i - T$ ，然而因 $C_i - T \ge C_j$ ，其中最大者 $C_j'$ 之總和仍小於目標，因此用上所有面額小於 $C_i$ 之硬幣無法組出 $C_i$ ，故無法再替換任何硬幣使總數變小，得操作後總數為最佳解 $\quad \cdots \quad (2)$

由於題目之選擇法滿足 $(1)$ ，因此得出之解滿足 $(2)$ ，故為最佳解
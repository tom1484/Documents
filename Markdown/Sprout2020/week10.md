# Sprout 2020 Algorithm  - Week 10

**Author: 陳楚融**

## Problem 1

### a

$$
(a, b, c) = (0, 1, 0) \\
(0 \or 1) \and (\neg 0 \or 0) \and (\neg 1 \or \neg 0) \and (\neg 0 \or 1 \or 0) = 1
$$

### b

$$
(a, b, c, d) = (0, 0, 0, 0) \\
(0 \or \neg 0) \and (\neg 0 \or 0) \and (\neg 0 \or 0) \and (\neg 0 \or \neg 0 \or \neg 0) \and (0 \or \neg 0 \or 0) = 1
$$

## Problem2

### a

首先由以下結果：
$$
\neg (a \or b \or c) = \neg a \and \neg (b \or c) = \neg a \and (\neg b \and \neg c) = \neg a \and \neg b \and \neg c \\
\neg (a \and b \and c) = \neg a \or \neg (b \and c) = \neg a \or (\neg b \or \neg c) = \neg a \or \neg b \or \neg c 
$$
得 De Morgan's laws 可推廣至多變數情況

若一 CNF 算式為 $f = (l_{11} \or l_{12} \or \cdots) \and (l_{21} \or \cdots) \and \cdots$ ，則依照 De Morgan's laws 有 $\neg f = (\neg l_{11} \and \neg l_{12} \and \cdots) \or (\neg l_{21} \and \cdots) \or \cdots$ 

### b

由於 CNF 中每個 clause 中皆不會有重複變數，因此必可以將某一 clause 中的所有 literal 設為 $F$ 使得該 clause 值為 $F$ ，於是 $f = F$ ，得所有 CNF 算式皆可為 $f = F$ ，時間複雜度為 $O(n)$ 

### c

由於每個 clause 中皆不會有重複變數，因此必可以將某一 clause 中的所有 literal 設為 $T$ 使得該 clause 值為 $T$ ，於是 $f = T$ ，得所有 DNF 算式皆可為 $f = T$ ，時間複雜度為 $O(n)$ 

### d

已知若一 CNF 算式為 $f$ ，可用 DNF 表示 $\neg f$ ，根據 Problem2.a 可知轉換複雜度為 $O(n)$ 

令 $P$ 問題為判斷 CNF 算式 $f$ 能否為 $T$ 、 $Q$ 問題為判斷 DNF 算式能否為 $F$ 

因為判斷 $f$ 能否為 $T$ 等價於判斷 $\neg f$ 能否為 $F$ ，因此可將 $P$ 問題線性歸約至 $Q$ 問題，已知 $P$ 問題不存在多項式複雜度的解，根據 week9 內容得 $Q$ 問題也不存在多項式複雜度的解

得證判斷 DNF 算式能否為 $F$ 不存在多項式複雜度的解，且因 $P$ 問題為 $NP-hard$ ，得判斷 DNF 算式能否為 $F$ 為 $NP-hard$  



### e

若任意布林運算式皆可以多項式時間轉為 CNF ，則欲判斷一個 DNF 可否為 $F$ 可先以多項式時間轉換其為 CNF 

接著根據 Problem2.b 可再用多項式時間判斷 CNF 可否為 $F$ ，得判斷一個 DNF 可否為 $F$ 有多項式複雜度的解，與 Problem2.d 矛盾，得證並非任意布林運算式皆可以多項式時間轉為 CNF

## Problem 3

令 $P$ 問題為判斷 DNF 算式 $f$ 能否為 $F$ 、 $Q$ 問題為判斷兩布林運算式是否不相等，欲證 $Q$ 問題為 $NP-hard$ ，可將 $P$ 問題規約至 $Q$ 

若 $P$ 之 DNF 算式 $f$ 中有一 clause $c_i$ ，當 $f$ 可能為 $F$ 時，必可能有 $f = F, c_i = F \Longrightarrow f \and \neg c_i = T$ ，得 $f \not = f \and \neg c_i$ ；當 $f$ 僅能為 $T$ 時， $f \and \neg c_i = T$ ，得 $f = \neg f \and \neg c_i$ 

欲解 $P$ 問題，可透過判斷兩運算式 $f,\ f \and \neg c_i$ 是否不相等，相等則 $P$ 問題解答為不可能；不相等則為可能

因此可將 $P$ 問題輸入轉為 $Q$ 問題輸入，需 $O(N)$ 複雜度，即將 $P$ 線性歸約至 $Q$ 

根據 Problem2.e ，$P$ 問題為 $NP-hard$ ，得證判斷兩布林運算式是否不相等為 $NP-hard$ 
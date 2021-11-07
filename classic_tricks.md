---
title: 關於那些經典技巧>w<
tags: MDOI
image: https://i.imgur.com/SyxOqpN.jpg
slideOptions:
    theme: moon
    transition: 'slide'
slide: data-background="https://i.imgur.com/SyxOqpN.jpg"
---

<style>
    body{
        background-attachment: fixed;
        background-repeat: no-repeat;
        background: -webkit-linear-gradient(left, #ffffff,rgba(51,51,51,0.3)), url("https://i.imgur.com/SyxOqpN.jpg") center no-repeat fixed;
    };
</style>


<!-- .slide: data-background="https://i.imgur.com/SyxOqpN.jpg" -->

<font color="black">
<font size=15><b>  關於那些經典技巧>w< </b></font>

<font size=13><b> 作者: iceylemon </b></font>

----

<font color="black">

<font size=8><b> 目錄 </b></font>

1. 語法
2. 暴力
3. 數論
4. 資料結構
5. 圖論
6. DP
7. 其他怪怪的東西

</font>

----

<font color="black">

<font size=8><b> 你應該要會的競程技能樹 </b></font>
</font>

----

<font color="black">

<font size=8><b> 時間複雜度 </b></font>

謹記在大部分的judge上面 $2\cdot 10^8$ 都是可以穩過的
$10^9$的話常數要小一點

| N 上限 | 複雜度 |
| -------- | -------- |
| $2\cdot 10^7$  | $O(N)$  |
| $10^6$ | $O(NlogN)$,$O(N^{\frac{4}{3}})$|
| $2\cdot 10^5$ | $O(N\sqrt{N}),O(Nlog^2N)$|
| $5\cdot 10^4$ | $O(N\sqrt{N}logN)$|
| $10^4$ | $O(N^2)$ |



</font>




---

<font color="black">

<font size=8><b> 語法 </b></font>

好的語法習慣帶你上天堂

</font>

----

<font color="black">

<font size=8><b> 1.浮點數 </b></font>

</font>

![](https://i.imgur.com/kZEghq4.jpg)

----

<font color="black">

<font size=8><b> 1.浮點數 </b></font>

</font>

```cpp=
const double eps = 1e-9;
double a = 0.1, b = 0.1;
if( fabs(a - b) < eps ) { // do something }
```

----

<font color="black">

<font size=8><b> 2.位運算 </b></font>

* 位運算取二的冪次請慎用，注意會不會爆int or long long

* 所有位運算請加上括號，除非你很清楚你在做什麼

```cpp=
int a = (1 << 19);
int b = (1LL << 60);
```

</font>

----

<font color="black">

<font size=8><b> 3.IO優化 </b></font>

**IMPORTANT!!!**

拜託加一下，以後哪一份code沒有IO優化我就bonk他

</font>

----

<font color="black">

<font size=8><b> 4.變數宣告 </b></font>

*Optional*

如果可以的話盡量把變數宣告在迴圈 or 函式最上面，可以方便debug

</font>

----

<font color="black">

<font size=8><b> 5.函式 </b></font>

*Optional*

當你的程式碼又臭又長的時候可以切出一些函式來寫

這樣除了可以方便debug之外也比較有易讀性

</font>

----

<font color="black">

<font size=8><b> 6.慎用位運算 </b></font>

*Optional*

</font>

---


<font color="black">

<font size=8><b> 暴力與枚舉 </b></font>

暴力不能解決所有問題，但是他可以解決有問題的人

</font>

----

<font color="black">

<font size=8><b> 目錄 </b></font>

* $O(n!)$
* $O(2^n)$
* $O(3^n)$
* MITM
* 打表
* 枚舉
* 其他小技巧

</font>

----

<font color="black">

<font size=8><b> $O(n!)$ </b></font>

$N\leq 10$ 的時候請考慮用他，他很棒

用法主要有兩種：
* next_permutation
* 開個東西記錄他(ex:set<vector<int>>)

[[例題 abc224 D]](https://atcoder.jp/contests/abc224/tasks/abc224_d)

</font>

----

<font color="black">

<font size=8><b> $O(2^n)$ </b></font>

$N\leq 20$ 的時候請考慮用他，他很棒

用法：
DFS，for迴圈枚舉bit，DP

可以搭配bitset或map去重

</font>

----

<font color="black">

<font size=8><b> $O(3^n)$ </b></font>

$N\leq 17$ 的時候請考慮用他，他很棒

就是加上枚舉子集的 $2^n$ 枚舉

</font>

----

<font color="black">

<font size=8><b> MITM </b></font>

$N\leq 40$ 的時候請考慮用他，他很棒

應該不用多說了，考試的時候不要忘記他就好

</font>

----

<font color="black">

<font size=8><b> 打表 </b></font>

打表是個很重要的技能，請一定要學會打表

打表的方式：手算小測資，DP，枚舉，比較慢的做法...

</font>

----

<font color="black">

<font size=8><b> 打表可以做什麼 </b></font>

1. 拿部分分 (Important)
2. 找規律，或許可以推成正解

</font>

----

<font color="black">

<font size=8><b> 打表實例 </b></font>

* 本機爆搜
* 推導出DP式
* 發現題目性質(遞增or遞減?)
* 通靈出賽局的答案
* 發現ISSC的測資是錯的

</font>

----

<font color="black">

<font size=8><b> 枚舉 </b></font>

雖然枚舉大家都會，但能真正掌握枚舉的人不多

</font>

----

<font color="black">

<font size=8><b> 枚舉可以做什麼 </b></font>

* 拿來打表
* 獲得複雜度比較弱的解 or 玄學解
* 降低思維複雜度 ***(Important)***
* 唬爛

</font>

----

<font color="black">

<font size=8><b> 如何枚舉 </b></font>

FOR：

* 固定枚舉某一個變量，外層迴圈視為定值

DFS：

```cpp=
void dfs(int left, int right, int height, int sum) {
    // 很多剪枝
}
void dfs2(int x, int sum) { if(x >= n) return; }
void dfs3() {
    // 自由發揮
}
```

</font>

----

<font color="black">

<font size=8><b> 降低思維複雜度 </b></font>

* 數字小的時候暴力枚舉他也無妨 [[例題 abc184C]](https://atcoder.jp/contests/abc184/tasks/abc184_c)

* 當你發現 $O(1)$ 數學不好推可以考慮二分搜

* 當你覺得你的二分搜會爛的時候可以檢查+-5之類的

![](https://i.imgur.com/IGRpZpw.png)

</font>

----

<font color="black">

<font size=8><b> 其他小技巧 </b></font>

* Pigeon Hole Principle
* 按字典序枚舉有時候可以壓掉permutation的複雜度
* 玄學剪枝
* LittlePants枚舉超強 [[例題 abc187 F]](https://atcoder.jp/contests/abc187/tasks/abc187_f)
* LittlePants 真的超強 [[YTP 2020某一題]](https://judge.tcirc.tw/ShowProblem?problemid=c056)

</font>

---

<font color="black">

<font size=8><b> 數論 </b></font>

請不要放棄數學，數學真的很重要

</font>

----

<font color="black">

<font size=8><b> 目錄 </b></font>

1. 質數與因數
2. GCD
3. 分數
4. 平方
5. 絕對值
6. 矩陣
7. 組合數
8. LittlePants 分塊 (感謝LittlePants指導)
9. 奇怪的東西

</font>

----

<font color="black">

<font size=8><b> 質數與因數 </b></font>

* $O(\sqrt{n})$ 找因數/質數
* 篩法 $O(n\sim nlogn)$
* 質數/因數個數估計
* HAHA Series ***IMPORTANT*** 請見LittlePants講義

</font>

----

<font color="black">

<font size=8><b> 質數/因數個數估計 </b></font>

質數個數：$O(\frac{x}{\ln{x}})$

因數個數：$O(n^{\frac{1}{3}})$

上面兩個東西都是常用的，常常搭配DP或其他東西

</font>

----

<font color="black">

<font size=8><b> GCD </b></font>

* HAHA Series ***Important***

* $gcd(a,b)$ 的複雜度：$O(log(max(a,b))$ =>

* 每做一次 $gcd$ 至少減半 =>

* 左端點固定，右端點越往右 $gcd$ 越小 => 單調性

* 可以搭配 Sparse Table 服用

* Optional：Mobius

</font>

----

<font color="black">

<font size=8><b> GCD 例題 </b></font>

隨手亂出：

給定一個陣列 $a$ 跟一個數字 $K$，請求出最長的一段區間 $[L,R]$ 使得其最大公因數不小於 $K$。$N\leq 2\cdot 10^5$

</font>

----

<font color="black">

<font size=8><b> 分數 </b></font>

經典操作：
* 數論分塊
* 對值域二分搜
* 轉換成斜率

</font>

----

<font color="black">

<font size=8><b> 平方 </b></font>

經典操作：
* 暴力展開處理
* 把他特別分開來處理

</font>

----

<font color="black">

<font size=8><b> 絕對值 </b></font>

經典操作：
* 轉成距離 => 中位數
* 分項討論 ex：有序數列 $<O(N),O(1)>$ 區間中位數
* 維護單調性讓絕對值失效
* 當最大值跟絕對值有關 => $|x-y|=max(x-y,y-x)$

</font>

----

<font color="black">

<font size=8><b> 矩陣 </b></font>

目錄：
* 矩陣快速冪
* Floyd 跟 [[類floyd 操作]](https://cses.fi/problemset/task/1724)
* 高斯消元 + 生成集(線性獨立的向量)
* 高斯消元求解詭異DP

</font>

----

<font color="black">

<font size=8><b> 組合數 </b></font>

目錄：
* 記得 C 可以線性蓋(mod 質數)也可以 $O(NM)$ (沒限制)
* 組合數就是DP，但是可以用 C 的就用 C (複雜度好)
* 史特林數 [[例題]](https://zerojudge.tw/ShowProblem?problemid=b685)
* Lucas 定理 *Optional*

</font>

----

<font color="black">

<font size=8><b> LittlePants 分塊 </b></font>

![](https://i.imgur.com/uCdMPme.png)

*Optional*

名字未知，但是聽起來很電

</font>

----

<font color="black">

<font size=8><b> LittlePants 分塊 </b></font>

* 當你遇到每次加會至少加兩倍的東西就可以使用
* ex：$\sum\limits_{j=1}^{i-1}A_j\leq A_i$

</font>

----

<font color="black">

<font size=8><b> 值域倍增分塊 </b></font>

* 用法：$[2^i+1,2^{i+1}]$ 分成一塊

* 想辦法維護塊內資訊，跟你做分塊的做法一樣

* 總共會分成 $log_2n$ 塊

</font>

----

<font color="black">

<font size=8><b> 奇怪的東西 </b></font>

* CRT 雖然毒瘤但是他可以用在很多地方
* 莫比烏斯函數就是排容原理的係數

</font>

---

<font color="black">

<font size=8><b> 資料結構 </b></font>

補習是為了不補
學資料結構是為了不砸

-- 汪大久

</font>

----

<font color="black">

<font size=8><b> 目錄 </b></font>

* 前言
* $O(N)$ 資料結構
* 動態資料結構：PQ/set/map
* 並查集
* BIT
* Sparse Table
* 線段樹
* 分塊

</font>

----

<font color="black">

<font size=8><b> 前言 </b></font>

記得看題目是靜態問題還是動態問題

純靜態問題通常不會需要用到資料結構，可以用BS, 前綴和，DP 等等的東西解決掉

有些靜態問題可以轉成動態問題，例如：一個元素一個元素加到資料結構

</font>

----

<font color="black">

<font size=8><b> 前言 </b></font>

補習是為了不補，學資料結構是為了不**亂**砸

資料結構不是讓你看到題目就說你想要砸線段樹

正確的做法是先分析題目**需要什麼**

以及這題可能可以怎麼**維護這些資料**

</font>

----

<font color="black">

<font size=8><b> $O(N)$ 資料結構 </b></font>

萬物皆陣列：vector, stack, queue, deque, linked-list 都是陣列

盡量不要用 stack 跟 queue 跟 deque 的內建資料結構

他們的常數極大，除非題目不卡常不然請用陣列 or vector

</font>

----

<font color="black">

<font size=8><b> Stack </b></font>

別名：右界會一直前後嚕的單指針

經典操作：
* 均攤，均攤，更多的均攤
* 均攤再加一點數學 ex: 最大矩形
* 維護單調性 => 單調 stack
* 回滾stack => 樹上偽 stack [[例題]](https://drive.google.com/drive/u/3/folders/1H74CYz1jYPRDt0d1L349YDjSEUUXVEta) 登入MDCPP Gmail帳號來看

</font>

----

<font color="black">

<font size=8><b> Queue and Deque </b></font>

* 別名：雙指針

經典操作：
* 均攤，均攤，更多的均攤
* 維護單調性 => 單調隊列
* BFS 的時候可以把 queue 換成 priority queue

</font>

----

<font color="black">

<font size=8><b> Linked List </b></font>

經典操作：
* $O(1)$ 支援插入/刪除
* 快速維護一個數的前後資訊
* 直接想像成是閹割版的set可能會好一點

</font>

----

<font color="black">

<font size=8><b> 動態資料結構 </b></font>

* Priority Queue / Heap
* Set / Multiset
* Map / Unordered map

</font>

----

<font color="black">

<font size=8><b> Priority Queue </b></font>

* 別名：常數很小的set

經典操作：
* 如果可以用 PQ 就不要用 set
* Lazy Insertion/Deletion：打個tag紀錄東西要不要被刪除 例題：[[TIOJ 1911 雲端列印]](https://tioj.ck.tp.edu.tw/problems/1911)

</font>

----

<font color="black">

<font size=8><b> Set </b></font>

* 別名：萬用資料結構

經典操作：
* 掃描線 ***Important***
* set<pii> 維護二元組訊息 => 加入時間的維度進行排序
* set 維護區間 => 均攤 set, ODT
* set當作單調隊列 [[例題 DP Contest Q Flowers]](https://atcoder.jp/contests/dp/tasks/dp_q)

</font>

----

<font color="black">

<font size=8><b> Set </b></font>

常用技巧：
* 如果發現變數之間影響太全域，可以考慮觀察/規約成相鄰的關係
* 全域難做的時候，改小部分去討論他的前後兩個值
* 動一個東西觀察其他東西的變化
* 小於等於某數的最大值：prev(st.upper_bound(x))
* 小於某數的最大值：prev(st.lower_bound(x))

</font>

----

<font color="black">

<font size=8><b> Set </b></font>

常見的雷：
* 如果怕會戳到不該戳的東西可以加正負無限大到set裡面
* set 會去重，multiset 不會

</font>

----

<font color="black">

<font size=8><b> Map </b></font>

經典操作：
* set 可以做的 map 都可以
* 當大陣列用 => 不用離散化
* unordered_map 可以拿來唬爛 (要記得reserve)

</font>

----

<font color="black">

<font size=8><b> Map </b></font>

常見的雷：
* 查一個元素有沒有在map裡面：
```cpp=
if(mp.find(x) != mp.end()) { do something } // good
if(mp[x]) { do something } // bad
```
第二行的做法會幫你新建立一個節點(如果原本沒有)
[[例題]](https://zerojudge.tw/ShowProblem?problemid=e288)

</font>

----

<font color="black">

<font size=8><b> 各種例題 </b></font>

* CSES sorting and searching
* AP325 2-4章

</font>

----

<font color="black">

<font size=8><b> 並查集 </b></font>

* 序列操作
* 做並查集同時維護塊內資訊
* 反著做並查集
* 帶權並查集
* 回滾並查集

</font>

----

<font color="black">

<font size=8><b> 序列操作 </b></font>

[OI WIKI 並查集 的 D,E](https://oi-wiki.org/topic/dsu-app/)

[[例題 建中2021校內複賽pA]](https://tioj.ck.tp.edu.tw/contests/81/problems/2161)

</font>

----

<font color="black">

<font size=8><b> 同時維護塊內資訊 </b></font>

可以維護的東西：
* 連通塊大小/權值/最大值/資料結構
* 帶權並查集

</font>

----

<font color="black">

<font size=8><b> 回滾並查集 </b></font>

意思就是可以回到上一步的並查集

開一個vector紀錄在一次union操作的時候改動了那些東西的值

這樣就可以 $O(1)$ 回到上一步

可以搭配時間線段樹一啟用

</font>

----

<font color="black">

<font size=8><b> BIT </b></font>

多練題就會了：

[Csacdemy 非常多經典題 (#Fenwick Tree)](https://csacademy.com/contest/archive)

[經典題：多組詢問一個區間內有多少不同的數](https://atcoder.jp/contests/abc174/tasks/abc174_f)

[經典題：LIS](https://csacademy.com/contest/archive/task/dominant-free-sets/)

[配合貪心概念](https://codeforces.com/contest/1430/problem/E)

[上一題的類似題](https://csacademy.com/contest/archive/task/swap_pairing/)

[二維BIT](http://poj.org/problem?id=2155)

[BIT 當平衡樹](https://tioj.ck.tp.edu.tw/problems/1382)

</font>

----

<font color="black">

<font size=8><b> Sparse Table </b></font>

* 當你不帶修改而且需要快速取值的時候可以考慮使用

* 經常跟著 GCD 一起出現

```cpp=
int lg[mxN];
lg[1] = lg[2] = 1;
for(int i = 3; i <= n; i ++) {
    lg[i] = lg[i >> 1] + 1;
}
int get(int l, int r) {
    int t = lg[r - l + 1];
    return max(dp[l][t], dp[r - (1 << t) + 1][t]);
}
```

</font>

----

<font color="black">

<font size=8><b> 線段樹 </b></font>

* 拜託不要亂砸

* 多練題就好，請見 LittlePants 資料結構題單

</font>

----

<font color="black">

<font size=8><b> 分塊 </b></font>

* 線段樹可以做的分塊都可以做

* 適合拿來喇分

* 值域分塊

</font>

---

<font color="black">

<font size=8><b> 圖論 </b></font>

圖論好難

</font>

----

<font color="black">

<font size=8><b> 圖論 </b></font>

* [[圖論小技巧]](https://www.luogu.com.cn/blog/chengni5673/tu-lun-di-xiao-ji-qiao-yi-ji-kuo-zhan)

* 因為我圖論很爛，這部分就交給LittlePants了

</font>

---

<font color="black">

<font size=8><b> dp </b></font>

如果把dp反過來看還是dp喔

</font>

----

<font color="black">

<font size=8><b> DP </b></font>

請熟悉以下DP的基本作法：

* 區間 DP
* 環狀 DP
* 背包 DP
* 期望值 DP：機率DP記得從後面開始做(期望值為1)。可以以每一種狀態發生的機率作為狀態
* 狀態壓縮 DP
* 樹 DP

</font>

----

<font color="black">

<font size=8><b> DP </b></font>

你應該要會的 DP 優化：

* 前綴和優化
* 單調隊列優化
* 資料結構優化：BIT, 線段樹
* 倍增 DP：主要有兩種做法：1. 直接多設一維當作$2^i$ 2. 設位置

</font>

----

<font color="black">

<font size=8><b> When to use DP </b></font>

萬物皆DP，DP會出現在各種神奇的地方

也可能會出現在 cost 的計算或者是輔助工具

[[例題 CF1582E]](https://codeforces.com/contest/1582/problem/E)

</font>

----

<font color="black">

<font size=8><b> DP 狀態設計 </b></font>

* 多解題目就會發現很多題目的狀態是類似的
* 先看題目有什麼把它當成狀態試試看
* 發現有缺東西就補給他
* 很多東西都可以拿來DP：答案、位置、題目限制

</font>

----

<font color="black">

<font size=8><b> 怎麼練DP </b></font>

* 多刷題 ***Important***
* Atcoder DP Contest
* AP325
* ABC, ARC 的各種 DP 題

</font>

----


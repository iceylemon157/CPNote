---
title: 那些可愛的根號算法>w<
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
<font size=15><b> 那些可愛的根號算法>w< </b></font>

<font size=14><b> 作者: iceylemon </b></font>


----

<font color="black">

<font size=8><b> 根號算法 </b></font>

1. 找質數/因數
2. 數論分塊
3. 大小分塊
4. 序列分塊
5. 詢問分塊(定期重構)
6. 莫隊算法
7. 其他怪怪的東西

</font>

---

<font color="black">

<font size=8><b> 大小分塊 </b></font>

小於 $\sqrt{N}$ 一個做法，大於 $\sqrt{N}$ 另一個做法

</font>

----

<font color="black">

<font size=8><b> 分析 </b></font>

* 小於 $\sqrt{N}$：通常是暴力
* 大於 $\sqrt{N}$：因為大於的數會有$O(N)$個，所以轉移或操作的複雜度平均要是$O(\sqrt{N})$以下。通常圍繞著$\sqrt{N}$跑。

</font>

----

<font color="black">

<font size=8><b> 例題 </b></font>

題目：非常多，到處都是

1. ABC 219G
2. LOJ 6089

</font>

---

<font color="black">

<font size=8><b> 序列分塊 </b></font>

俗稱優雅的暴力，把一個序列分成若干塊處理

</font>

----

<font color="black">

<font size=8><b> 例題 </b></font>

給定一個陣列$A$，支援以下操作：

1. 區間加值
2. 區間查詢

</font>

----

<font color="black">

<font size=8><b> 分塊先備條件 </b></font>

1. **大段維護，局部暴力**
2. 局部暴力通常不成問題難在如何維護整塊的資訊
3. 除了維護單一塊內資訊，如何合併答案也很重要

</font>

----

<font color="black">

<font size=8><b> 慣用手法 </b></font>

1. 首先先把陣列分成若干塊，每塊大小為 $B$，不足的就讓它不足
2. (可選) 標記每一個位置是屬於哪一塊，通常 0-base 我們會使用 $\frac{i}{B}$ 來作為塊編號(向下取整)
3. 對於一個區間 $[L,R]$，最多會包含到兩個不完整的塊(左右)，局部處理這兩塊，剩下的用打tag的方式維護
4. 處理答案的合併

</font>

----

<font color="black">

<font size=8><b> 例題講解 </b></font>

1. 區間修改：不完整的塊一個一個修改，完整的塊打一個tag: 塊內元素*val
2. 區間查詢：同上，修改改成相加即可

</font>

----

<font color="black">

<font size=8><b> 複雜度 </b></font>

1. 不完整的塊一個一個修改：$O(2B)=O(B)$
2. 完整的塊打一個tag: $O(N/B)$

總複雜度：$O(Q(B+N/B))$，由算幾不等式可知取 $B=\sqrt{N}$最優，整體複雜度$O(Q\sqrt N)$

</font>

----

<font color="black">

<font size=8><b> 分塊可以做什麼 </b></font>

* 很多的區間問題，只要可以打tag維護通常都可
* 可以在塊內做二分搜，甚至可以塞資料結構
* 複雜度通常不好分析，但理論上他是好的
* 分塊本人就是一個**資料結構**，資料結構可以做的他都可以做 ex: DP 優化

</font>

----

<font color="black">

<font size=8><b> 值域分塊 </b></font>

值域分塊是一種資料結構

</font>

----

<font color="black">

<font size=8><b> 值域分塊 </b></font>

值域分塊是一種資料結構

跟值域線段樹很像，就是對值域進行分塊

每塊分別統整該塊的答案

</font>

----

<font color="black">

<font size=8><b> 題目? </b></font>

他不太常出現，因為值域線段樹可以蓋掉大部分的CASE

但值域分塊還是有一些好用的地方：單點修很快

有些題目用是要用值域分塊才可以過的

</font>

----

<font color="black">

<font size=8><b> 回家作業 </b></font>

1. hzwer 的分塊 9 講
LOJ 6277~6285

</font>

---

<font color="black">

<font size=8><b> 詢問分塊 </b></font>

又叫定期重構。適用於有修改也有查詢的題目。顧名思義將詢問進行分塊，當處理完整個塊所有的詢問時，將你的陣列一次加上那些修改操作。在塊內時暴力查詢不修改。

</font>

----

<font color="black">
<font size=8><b> 詢問分塊 </b></font>

又叫定期重構。適用於有修改也有查詢的題目。顧名思義將詢問進行分塊，當處理完整個塊所有的詢問時，將你的陣列一次加上那些修改操作。在塊內時暴力查詢不修改。

**所以什麼是詢問分塊?**

</font>

----

<font color="black">

<font size=8><b> 例題 </b></font>

給定一個陣列$A$，支援以下操作：

1. 區間加值
2. 區間查詢

</font>

----

<font color="black">

<font size=8><b> 例題講解 </b></font>

1. 每出現 $\sqrt{Q}$ 次修改操作就把 $A$ 加上那些修改重新算一遍。
2. 每次詢問最多只會有 $\sqrt{Q}$ 的未處理修改，直接暴力計算那些修改對該詢問的影響。

複雜度：$O(N\sqrt{Q})$
</font>

----

<font color="black">

<font size=8><b> 回家作業 </b></font>

[[MDCPP B053]](http://mdcpp.mingdao.edu.tw/problem/B053) 大電神說都沒人解他很難過QQ

</font>

---

<font color="black">

<font size=8><b> 莫隊算法 </b></font>

莫隊算法是一個離線算法，可以處理一個range的區間問題。

</font>

----

<font color="black">

<font size=8><b> 品種 </b></font>

* 普通莫隊算法
* 帶修改莫隊
* 回滾莫隊
* 樹上莫隊
* 莫隊搭配bitset(?)

</font>

----

<font color="black">

<font size=8><b> 使用時機 </b></font>

可以離線做
當你有區間 $[L,R]$ 的答案時，可以快速算出區間 $[L,R-1],[L,R+1],[L-1,R],[L+1,R]$ 的答案

</font>

----

<font color="black">

<font size=8><b> 莫隊算法使用 </b></font>

1. 把序列分塊，塊大小 $B$
2. 把詢問區間按照以下規則排序：左界按**所在的塊編號**排序，右界按**自己的編號**排序。
3. 用兩個指針l,r每次一格一格移動指針到下一個詢問(先移右指針再移左指針)，過程中同時維護答案

</font>

----

## 偽Py代碼

```python=
sort(Q) # 左界塊編號排序，右界自身編號排序
ans = 0
def add(x): # 把位置x加進去答案
def sub(x): # 把位置x從答案扣掉
l, r = 1, 0
for [L,R] in Q:
    while r < R: add(++ r)
    while r > R: sub(r --)
    while l > L: add(-- l)
    while l < L: sub(l ++)
    print(ans)
```

----

<font color="black">

<font size=8><b> 複雜度分析 </b></font>

1. 排序 $O(NlogN)$
2. 當左界都在同一塊右界只會一直往右邊嚕。所以右界移動的格子數不超過 $O(N)$，而這種Case最多只會有 $O(N/B)$ 種=>$O(\frac{N^2}{B})$
3. 左界都在同一塊內移動，所以一次最多移$O(B)$個位置，總共最多移$O(Q)$次整體複雜度$O(QB)$
4. $O(NlogN+\frac{N^2}{B}+QB)$ 取$B=\frac{N}{\sqrt{Q}}$

</font>

----

<font color="black">
<font size=8><b> 題目 </b></font>

1. [區間眾數](https://zerojudge.tw/ShowProblem?problemid=b417)
2. [區間MEX](https://www.luogu.com.cn/problem/P4137) $O(N\sqrt{N})$ Hint: 6I6r6ZqKKyAi5YC85Z+f5YiG5aGKIiDntq3orbfmlbTloYros4foqIo= 請用base64解碼 [解碼器](http://www.mxcz.net/tools/zh-TW/base64.aspx)
3. [非常多題目](https://www.luogu.com.cn/training/2914)

----

<font color="black">

<font size=8><b> 帶修改莫隊 </b></font>

可以帶修改的莫隊，我不會。大概是把**時間**這維加進去一起排序，然後做一些壞壞的事情。

時間複雜度：$O(N^{5/3})$，coding 複雜度：O(玄學)

</font>

----

<font color="black">

<font size=8><b> 回滾莫隊 </b></font>

可以回滾的莫隊。

</font>

----

<font color="black">

<font size=8><b> 回滾莫隊 </b></font>

可以回滾的莫隊。

當你發現你只會作加法(減法)的時候就可以考慮

</font>

----

<font color="black">

<font size=8><b> 回滾莫隊 </b></font>

可以回滾的莫隊。

當你發現你只會作加法(減法)的時候就可以考慮

所以回滾是什麼？

</font>

----

<font color="black">

<font size=8><b> 名詞解釋 </b></font>

* 加法：把某些東西加進答案
* 減法：把某些東西從答案扣掉
* 回滾：英文叫做 rollback，就是回到之前的某一個狀態

</font>

----

<font color="black">

<font size=8><b> 作法 </b></font>

1. 一樣先做莫隊，用下面的方法改一下
2. 右界：如果左界在同一塊的話右界會遞增，所以右界只會有加法
3. 左界：因為左界永遠都在同一塊，所以不妨每一次都暴力算那一塊的答案，算完之後直接退回就好

</font>

----

<font color="black">

<font size=8><b> 題目 </b></font>

1. [區間MAX](https://zerojudge.tw/ShowProblem?problemid=d539)
2. CF EDU DSU PART3 P2
3. [區間MEX](https://www.luogu.com.cn/problem/P4137)
4. [JOISC 2014 D1 某一題](https://loj.ac/p/2874)

</font>

----

<font color="black">

<font size=8><b> 樹上莫隊 </b></font>

在樹上做莫隊。但你要先會樹上分塊，請左轉選訓大電神。

</font>

----

<font color="black">

<font size=8><b> 假樹上莫隊 </b></font>

把樹壓平之後就變成序列問題了，直接莫隊

</font>

----

<font color="black">

<font size=8><b> 莫隊+bitset(?) </b></font>

在做莫隊的時候轉移有時候可以套資料結構，就用bitset當資料結構就好了

</font>

----

<font color="black">

<font size=8><b> 莫隊+bitset(?) </b></font>

在做莫隊的時候轉移有時候可以套資料結構，就用bitset當資料結構就好了

我也沒打過，請右轉OI WIKI

</font>

---

<font color="black">

<font size=8><b> 其他怪怪的東西 </b></font>

根號可以出現在很多地方，偶爾就會在神奇的地方出現
1. YTP2021 pre 第8題可以暴力做(做過的詢問要記起來)，複雜度會是根號級別
2. NPSC 2019 國中組初賽 pB 是一個跟上一題一樣的題目。可以用大小分塊證明，詳見[2019資芽講義](https://www.csie.ntu.edu.tw/~sprout/algo2019/ppt_pdf/week10/root_method.pdf)
3. $K=\frac{N*(N + 1)}{2}$，$O(N)=O(\sqrt{k})$
4. 若干個數相加為 $N$ => 最多只有 $\sqrt{N}$ 個相異數(轉有限背包問題)


</font>

----


















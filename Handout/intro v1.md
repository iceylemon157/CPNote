---
title: MDCPP競程介紹和基本技巧
tags: MDCPP
slideOptions:
    theme: sky
    transition: 'slide'

---
#### MDCPP進階組講義01
## 競程介紹和基本技巧
作者：ICLEMON

----

## 講師介紹

---

## 競程比賽介紹

1. APCS：升大學很有用 (但其實他不是競賽)(必考)

2. NPSC：台大辦的比賽，決賽有氣球(??

3. YTP：精誠資訊辦的比賽，有超多食物，入選可以參加專題

4. HPC：HP Codewar，有變裝秀，感覺很有趣

----

5. 學科能力競賽：就學科能力競賽

6. ISSC：一個全英文的比賽，前幾名可以出國比賽的樣子

7. TOI ：前進資奧!!

---

## Why C++?

----

為什麼要學C++?
C, Java, Python...不好嗎?

----

### 沒有不好
### 但是所有語言都有他擅長的領域!

----

### C++ vs C

如果你是使用C的使用者呢?
C與C++語法相容，又幫你寫好了很多很棒的東西!
很多東西都可以直接用!
這麼香還不學嗎?
但是C的穩定性卻是最棒的

----

### C++ vs Java

Java跟C++比，Java的執行效率比較慢
而且實際上Java的碼長也會比較長
但是Java在網頁方面有比較好的表現

----

### C++ vs Python

競程打Python?
~~毒瘤(X~~
Python的執行效率不是普通的慢
雖然他的程式碼也不是普通的短
Python適合用於機器學習和Deep Learning

---

## judge系統

----

什麼是judge系統呢?
大家或多或少應該會用過吧
像是zerojudge就是一個judge系統
上面會有題目，你需要寫一個程式碼來解決他的問題

----

他可能會給你一些反饋


| 簡稱      | 全名     | 介紹      |解決方法|
| -------- | -------- | -------- | --------|
| <a style="color:#00FF00;">AC</a> | Accepted | 答案正確 | |
| <a style="color:#FF0000;">WA</a> | Wrong Answer  | 答案錯誤     | 找bug或是驗證正確性 |
|CE| Compilation Error| 編譯時發生問題| 編譯過了再丟judge啦QQ|
| <a style="color:#0000FF;">TLE</a> | Time Limit Error | 執行時間超過題目限制| 換效率更好的演算法|

----

| 簡稱      | 全名     | 介紹      |解決方法|
| -------- | -------- | -------- | --------|
|MLE| Memory Limit Error|使用的記憶體超過限制|換更好的演算法|
| RE| Runtime Error| 執行時發生錯誤| 檢查是否有未定義行為|
| OLE| Output Limit Error | 輸出檔過大| 檢查你是不是多輸出了什麼|
| | Judge Error| Judge發生錯誤|跟管理員反應| 

----

常見的judge

- Zerojudge, 簡稱ZJ
- 建中judge, 簡稱TIOJ
- Codeforces, 簡稱CF
- UVA

我們也建了自己的judge[[MDCPP judge]](http://mdcpp.mingdao.edu.tw/)

---


## 進入正課!

---

## 標準輸入輸出

----

哭阿我是不是跑錯棚了，標準輸入輸出是什麼東東

----

你確定你知道你在用的是C的輸入輸出
還是C++的輸入輸出嗎?

----

有時候我們常常以為自己在打C++
但其實我們壓根就是在打C!

----

C語言使用的輸入輸出：

```cpp
int n;
scanf("%d", &n);
printf("%d\n", n);
```

----

C++使用的輸入輸出

```cpp
int n;
cin >> n;
cout << n << endl;
```

----

好喔那我知道這個了有什麼用嗎?
阿反正C++跟C相容，用哪個我開心就好了吧?

----

### 當然(X

----

但是要注意一下
有時候你們可能用cin/cout寫好了一份程式碼
丟上去之後
<a style="color:#FF0000;font-size:50px">哭阿TLE</a>

----

但是你看到你旁邊的同學用scanf/printf
拿了一個可愛的
<a style="color:#00FF00;font-size:50px;">AC</a>
結果你在那邊de了很久的bug
最後才發現自己的程式碼跟他的一模一樣

----

### QQ 系統霸凌我

----

其實並沒有！
cin/cout本身速度就會比C的輸入方法還慢
但是其實有一個方法可以匹敵C的輸入方法!

----

### I/O優化

```cpp
ios_base::sync_with_stdio(0);
cin.tie(0);
```
* 不要用endl
* 用了這個之後就不可以跟scanf/printf混用

----

### 常用的輸入輸出表格

| C / C++  |   C語言   |  C++     |
| -------- | -------- | -------- |
| 一般輸入  | scanf     | cin     |
| 一般輸出  | printf    | cout    |
| 讀取整行  | fgets     |getline / cin.getline|
| 讀取字元  | getchar   | cin.get |
| 輸出整行  | puts      |         |
| 輸出字元  | putchar   | cin.put |
| 字串串流  | sscanf/sprintf|stringstream|

----

其實有更快的輸入輸出方法
好像是利用getchar跟putchar/puts
~~但是我不會~~
那要自己刻很多麻煩的東西
而且大部分時間I/O優化就夠快了
所以其實不常用到

----

### getline

有時候我們會遇到一些很討人厭的測資輸入
~~像是最常有的uva~~
會要我們輸入整行
或者是有時候要我們連空白字元都吃進去
這時候就可以使用getline

----

要注意一件事情
getline會吃空白字元，也會吃**換行符號**
所以要注意一下
如果你先用cin吃一個整數
接著要用getline吃字串
要記得先多用一次getline把cin沒吃到的\n吃掉

----

用法：

```cpp
string s;
getline(cin, s);
```

----

還有另外一個在競程可能會用到的東西是stringstream
這個東西很酷，可以搭配getline一起使用
但是因為碰到的機率比較小
這個部份你們就自己研究吧

---

## 時間複雜度
### <DIV style="text-align:right;">----分析程式效率</DIV>

----

上面的課程中有提到說不同的輸入方式
或是不同的程式語言會有不同的執行速度

----

但事實上更重要的是
### <p style="color:RED;">#程式的執行效率！</p>

----

於是人們就發明了
### <p style="color:RED">時間複雜度</p>
來表示程式的執行效率

----

### 時間複雜度の介紹

----

用C++每秒大概可以執行
$10^8$ 次的基本運算(<a>+ - * /</a>)
所以其實我們只要把全部的運算次數算出來就好了！

----

### 哭阿那麼麻煩？

### 其實可以用估算的！

----

## 時間複雜度の表示
### <DIV style="text-align:right;">----大O記號</DIV>

----

時間複雜度有很多種表示方法
最常使用到的是大O記號

:warning: **下方數學警告** :warning:

----

### <p style="color:Blue;">#定義</p>
![](https://i.imgur.com/bbzd0PE.png)

----

### 修但幾類
### 那是蝦米碗糕

----

換句話說，就是
$f(x)$ 與 $g(x)$ 的增長速度相近！

----

還是太數學了啦我不會。
那就直接用規則來看吧！

----

### <p style="color:red;">#規則</p>

1. 對於一個多項式，只取數量級最大的
2. 省略所有常數

----

#### <p style="color:blue">#舉個栗子</p>

$g(x) = 3x^3 + 2x^2 + 7x + 48763$

rule1：
取數量級最大 => $O(3x^3)$

rule2：
省略常數 => $O(x^3)$

----

所以$g(x)$的大O符號表示就是
#### $O(x^3)$

----

#### 數量級表格(增長速度排序)

![](https://i.imgur.com/29JnWRS.png)


----

介紹完大O記號的表示方式
我們就可以來進行估算了！

----

### <p style="color:red;">#How to 估算</p>

看迴圈跑幾次就對了！
```cpp
for(int i = 0; i < n; i ++);
```
#### n次！

----

### 練習題

計算二維前綴和
```cpp
for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+x[i][j];
    }
}
```

----

### ANS: $O(n^2)$

----

### 練習題

枚舉區間

```cpp
// 定義sum[i] 為 x[1] ~ x[i] 的和
for(int i = 1; i <= n; i ++){
    for(int j = i + 1; j <= n; j ++){
        cout << sum[j] - sum[i - 1] << "\n";
    }
}

```

----

### ANS: $O(n^2)$

----

### 練習題

LCA倍增法

```cpp
int power[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

for(int i = 1; i <= n; i ++){
    int cnt = 0;
    for(int k = 1; power[k] <= n; k ++){
        up[i][k] = up[up[i][k - 1]][k - 1];
    }
}
```

----

### ANS: $O(nlogn)$

----

### 練習題

快速冪(計算2的k次)

```cpp
int ans = 1, sum = 2;
while(k){
    if(k % 2 == 1) ans *= sum;
    sum *= sum;
    k /= 2;
}
cout << ans << "\n";
```

----

### ANS: $O(logn)$

----

題目通常會給你測資範圍
下頁是每個數量級 $n$ 的最大值

----

![](https://i.imgur.com/YY2q8e3.png)


----

複雜度對應到的常見演算法

| 複雜度 | 對應演算法 |
| --------  | -------- |
| $O(1)$    | 各種基礎運算，數學 |
| $O(logn)$ | 二分搜，map, set, pq 一次操作
| $O(\sqrt n)$| 判斷質數，找因數 |
| $O(n)$    | 遍歷陣列 |
| $O(nlogn)$ | 排序(merge, heap, quick sort等等)
| $O(2^n)$  | 2-subset問題，暴力枚舉|
| $O(n!)$   | 遍歷所有排列 |

----

### 題外話：主定理

主定理主要是在處理遞迴關係式
並且算出這個遞迴關係式的解

----

### 規則

假設某個遞迴算法的時間複雜度遞迴公式為：
$T(n) = a * T (n / b) + n^d$
其中 $a > 1, b > 1, d > 0$。

當 $\log_b a < d$ 時，$T(n) = O(n^d)$
當 $\log_b a = d$ 時，$T(n) = O(n^{\log_b a} * logn)$
當 $\log_b a > d$ 時，$T(n) = O(n^{\log_b a})$

----

### 給個栗子
### Merge Sort

----

大家應該都知道排序這種東西
而最初階的Bubble Sort就是其中一種
<p style="color:red;">#Question : 求 Bubble Sort 時間複雜度?</p>

----

我們知道的C++ sort()是nlogn的複雜度
merge sort其實也是一個nlogn的複雜度
其中作法如下

----

Merge Sort是一種分治法(Divide and Conquer)
是把大問題分成子問題(Divide)
子問題處理完後再合併(Conquer)回大問題

----

### Merge Sort

Divide: 先將陣列分成兩半

Conquer: 按由小到大的順序合併

----

### Merge Sort

![](https://i.imgur.com/MbDegsI.png)

圖片取自[[參考資料]](https://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html)

----

我們可以列出這樣的遞迴關係式

$T(n) = 2T(n/2) + O(n)$

套用主定理我們可以解得

$T(n) = O(nlogn)$

----

詳見講義[[時間複雜度]](https://drive.google.com/file/d/124wLy-bHDpfyPe6irTtq2w9_m7Aw-NhA/view?usp=sharing)

---

## C++好用的函式

----

## ``` #include<algorithm> ```


----

algorithm是C++STL裡面的一個模板庫

至於什麼是STL呢?

中文叫標準模板庫，也就是可以直接引用的模板。

algorithm裡面有許多C++ STL標準中的基礎性的算法（均為函式模板）

---

## 幾種常用的函式模板

----

### 比大小系列

min (const T& a, const T& b, Compare comp)
取兩個值中的最小值

max (const T& a, const T& b, Compare comp)
取兩個值中的最大值


----

### 比大小系列

##### min_element (ForwardIterator first, ForwardIterator last)
返回序列中最小值的疊代器

##### max_element (ForwardIterator first, ForwardIterator last)
返回序列中最大值的疊代器

----

### 排序

#### sort (RandomAccessIterator first, RandomAccessIterator last)
把你要的東西排序好！可重載

----

### 排序

因為sort太重要了，所以來介紹一下到底要怎麼用
陣列的sort方式：
```cpp
    int x[5] = {4, 8, 7, 6, 3};
    sort(x, x + 3); // x = {4, 7, 8, 6, 3}
    sort(x, x + 5); // x = {3, 4, 6, 7, 8}
```

----

### 排序

sort的重載
```cpp
    bool cmp(const int a, const int b){
        return a > b;
    }
    int x[5] = {4, 8, 7, 6, 3};
    sort(x, x + 5, cmp); // x = {8, 7, 6, 4, 3}
```

----

### 排序

所有資料結構都可以被丟進去排序

ex: Vector
``` cpp
    vector<int> vc;
    sort(vc.begin(), vc.end());
```

但是有某些一定要另外重載(struct之類的)

----

### 有序序列的查找

lower_bound(forIterBegin, forIterEnd, targetVal)
<p>在升序序列中查找第一個
<a style="color:#FF0000";>大於等於</a>
targetVal的元素</p>


upper_bound(forIterBegin, forIterEnd, targetVal)
<p>在升序序列中查找第一個
<a style="color:#FF0000";>大於</a>
targetVal的元素</p>

----

binary_search(ForwardIterator f,ForwardIterator l,const T& val)
對一個升序序列做二分搜，判定序列中是否有val。


----

### 有序序列的查找

!!注意!!
標題有寫說是**有序序列**
如果是無序的話他會返回怪怪的東西喔

要注意一點，這裡lower_bound返回的是迭代器
至於迭代器是什麼?這有點複雜，以後會教的QQ

----

### 有序序列的查找

使用範例：找到大於等於7的第一個值

```cpp
    int x[5] = {1, 3, 6, 8, 10};
    int a = *lower_bound(x, x + 5, 7); // a = 8
```

因為lower_bound返回的是迭代器
所以加*號才可以取到值喔

----

### 有序序列的查找

使用範例：找到大於等於7的第一個值的位置
```cpp
    int x[5] = {1, 3, 6, 8, 10};
    int a = lower_bound(x, x + 5, 7) - x; // a = 4
```
至於為什麼要這樣打又是一門學問了
我們就先把這個作法記起來吧

----

### 排列

注意這個是排列不是排序喔
排列是指一個數組的排列方式

----

### 排列
next_permutation(BidirectionalIterator first, BidirectionalIterator last)
##### n個元素有n!種排列。這些排列中，規定升序序列為最小排列，降序序列為最大的排列，任意兩個排列按照字典序分出大小。該函數返回當前序列作為一個排列按字典序的下一個排列。

----

### 排列

這個東東可以讓你要寫全排列問題時不用寫回溯法

使用範例：
從某一個狀態輸出比他字典序更大的所有排列
```cpp
    int x[5] = {2, 3, 4, 5, 1};
    do{
        for(int i = 0; i < 5; i ++)
            cout << x[i] << " ";
        cout << "\n";
    }while(next_permutation(x, x + 5));
```

----

### 排列

當然也有prev_permutation可以用
用法一模一樣所以這裡就跳過啦

----

### 其他

swap (T& a, T& b)
交換兩個對象

fill(ForwardIterator f,ForwardIterator l,const T& val)
用給定值填充序列中每個元素

reverse(BidirectionalIterator f, BidirectionalIterator l)
把序列中的元素逆序

----

### 哭阿終於講完了

你可能會想說
那麼多東西誰記的起來啦?
沒關係，多打一些題目就可以慢慢記起來了喔OuO(X
如果不會的話就隨時來這邊看一下就好

----

### 參考資料

- [C++/STL/Algorithm](https://zh.m.wikibooks.org/zh-tw/C%2B%2B/STL/Algorithm)

- [C++ reference](http://www.cplusplus.com/reference/)

---

## 其他標頭檔

----

事實上還有很多是很好用的標頭檔
像是：
```cpp
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
```

----

這些標頭檔裡面也有一些很棒的東西
像是string裡面有to_string() (C++11)
可以把東西int或float等等的東西轉成string

但是礙於篇幅關係還有講師很懶
所以其他的部份就請大家自行上網搜尋啦

----

本人常用的一些標頭檔如下：

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<string>
#include<queue>
```
----

你們可能會想說
哭阿標頭檔那麼多我哪記的起來
難道我每次打程式都要先打這一長串東東嗎OAO

----

萬用標頭檔
直接include所有std標準庫裡面的所有東東
```cpp
#include<bits/stdc++.h>
```

---

## for迴圈

----

因為之前編過了，然後我很懶
所以就直接給你們吧
[[for-while迴圈講義]](https://drive.google.com/file/d/1iyJR6jbezkjZyfIDxMgFhyufwMaF-HQT/view?usp=sharing)要用明道帳號才能看喔

----

我們常用的for迴圈有兩種
一種就是我們常見的
```cpp
    for(int i = 1; i <= n; i ++);
```
另外一種比較特別，他叫做ranged-based-for迴圈

----

### ranged-based-for

在提ranged-based-for迴圈之前
我想先介紹一種只有C++11才有的變數類型
**<a style="color:#FF0000;"> auto </a>**

----

auto 是一種自動變數類型
他會自動辨識你是什麼資料型態

真香

----

直接上用法
```cpp
int x[5] = {1, 3, 6, 8, 10}
auto a = 4;
auto b = "loli";
auto c = lower_bound(x, x + n, 7);
auto d;    //這是錯的，你要先給他一個東西讓他判斷他的型態
```

----

好了那我們可以進ranged-based-for迴圈了
他長成下面這樣
```cpp
int x[5] = {4, 8, 7, 6, 3};
for(int i : x){
    cout << i << " ";
}
//輸出 4 8 7 6 3
```
應該大概能懂吧(?

----

其實ranged-based-for迴圈比較常拿來遍歷STL
雖然我們還沒學STL但是沒關係
先跟你們講用法之後就會用了
也可以去看我們之前編的for-while迴圈講義

----

雖然ranged-based-for迴圈可以遍歷陣列
但是要注意一件事，他會遍歷整個陣列
也就是說不管你那個位置有沒有初始化
你的陣列開多大他就會跑到哪裡
要特別注意一下！

---

## 競賽常用的輸入方式

----

競賽中常常會有要你輸入多組測資的情形
我們通常會有一套模板來處理這種多組輸入
我們已經編在上面的for-while講義了
要好好看喔~

----

這邊教大家一個最常用的
要求：給你一個數T代表接下來會有T組測資
```cpp
int T;
cin >> T;
while(T--){
    //初始化
    //你的程式碼
}
```

---

## 其他技巧

----

### 陣列宣告

有時候我們在宣告陣列的時候，題目數字比較大一點
然後宣告陣列準備要編譯的時候卻收到了CE
這代表你的陣列開太大
但其實有一種方法可以讓你的陣列開的大一點

----

### 把陣列開在全域變數

養成這個好習慣，除非你要開的陣列夠小
就算開在全域變數，陣列也只能開到1e7
要特別注意一下

----

有時候我們在宣告陣列的時候
雖然編譯過了但是輸出莫名其妙跑出一些奇怪的亂數
那可能是因為**動態宣告陣列**
```cpp
int n;
cin >> n;
int x[n];
```

----

我覺得這不是一個太好的習慣，因為之前被這個坑過很多次OAO
所以建議大家可以先看測資範圍多大就開多大的陣列
建議可以再比測資範圍大一點避免RE
```cpp
const int maxn = 1e5 + 50;
int x[maxn];
```

----

這個部份待補


----

來點有趣的
```cpp
while(x --> 0){
    printf("%d ", x);
}
```
請問 C++ 的這個 "- - >" 運算子要怎麼念？

取自靠北工程師

----

有人說是lambda運算子
但其實lambda運算子長這樣 "=>"
而且他也是 C# 才有的東西

----

也有人說他是指標會用到的運算子"->"
但是這很顯然少了一橫阿OAO

----

```cpp
while(x --> 0){}

while(x-- > 0){}

while(x--){}
```


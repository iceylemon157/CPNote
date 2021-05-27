---
title: 基礎資料結構2
tags: MDCPP
slideOptions:
    theme: solarized
    transition: 'slide'
---

#### MDCPP進階組培訓講義
## 基礎資料結構 v2
#### 作者：iceylemon157

---

## 前言

### 什麼是資料結構?

資料結構，簡稱叫做資結。英文叫做 Data Structure，簡寫為DS。什麼是資料結構呢？顧名思義，資料結構就是一個**儲存資料**的一種結構。例如我們學過的 int, char, bool 等等，這些東西都可以被稱作為資料結構。

你以為接下來我們會只教這些東西嗎？當然不可能。 

我個人不太會把 int, char, bool 這些東西稱作資料結構(雖然他確實是)，畢竟他們就只是最常用的東西。接下來我要說的 **資料結構** 會是比這些東西還要複雜許多的東西。

資料結構通常不會只像是 int, char 這種那麼簡單的東西，大部分的資料結構通常會有一些特性或是功用。舉一些例子來說，有些資料結構可以讓你獲得第一次/最後一次放進去的元素，有些資料結構可以讓你每次都拿出你存在裡面的資料中最大/最小的元素等等。

再強調一次，資料結構是一個**儲存資料**的一種結構。所以我們會想要在這個結構裡面**存放一些資料**。而資料結構在做的事情是，根據不同的資料結構，他會透過一些操作來**維護這些資料的一些資訊**。

----

### 為什麼要學資料結構？

看到這裡你可能會想說資料結構到底有什麼用？我用上面提到的 **從一個集合中獲得最大元素** 做為一個例子：

獲得最大的元素這件事情大家都知道可以直接用 for 迴圈掃過一遍就知道了，為什麼還要特別用資料結構呢？如果我現在想要在集合裡面插入一個數，然後詢問目前所有元素的最大值要怎麼辦呢？聰明的你一定想的到可以直接讓原本的最大值跟後來插入的那個數取max，這樣就可以了！

但是如果我現在想要**移除**資料結構裡面的一個數呢？我們會發現如果我移掉了最大值的話，如果還要維護最大值，那麼就勢必需要重新掃過所有的元素來找出操作過後的最大值是誰。這樣的複雜度會是 $O(N^2)$ 的 ($N$ 是集合元素個數)。但是如果用了資料結構，我們就可以在 $O(NlogN)$ 的時間內做到這件事。

這裡我先不介紹他是怎麼做到的，這份講義接下來會提到。在這裡我想說的是，資料結構可以幫我們**更有效率**的**動態的維護或處理**一些跟資料有關的事情。你放了什麼樣的東西到資料結構裡面，他就會跟你說這些資料有著什麼樣的性質。而在時間複雜度上，資料結構有時候可以**加速程式執行效率**，並且同時**維護好你想要的資訊**。

那麼接下來我們就來介紹一些簡單但是很常用到的資料結構吧。

----

## Table of Content

1. Stack (堆疊)
2. Queue (佇列)
3. Vector (動態陣列)
4. Heap(Priority Queue) (堆)

---

## 前言：什麼是STL

----

雖然資料結構這種東西雖然聽起來很方便，但是我們還是需要用程式碼把這個資料結構打出來之後才可以使用。這是一件相當煩躁的事情。而C++其實有一個叫做 **STL** 的東西。STL是什麼呢？STL讓你可以只引用一些標頭檔，就可以使用資料結構的力量。接下來就來介紹STL是什麼吧。

----

- STL，全名為Standard Template Library，中文叫標準模板庫。簡單來說就是C++特有的一個模板庫，可以直接呼叫使用。

----

- STL有4大部分的模板，分別是演算法，容器，函式跟迭代器。

- 我們今天要介紹的資料結構主要是容器的部份

- 上面的東西都看不懂？沒關係那其實不太重要。

----

- STL提供了一些預設已經寫好的模板讓你直接用，讓你不用自己把資料結構用程式碼打出來。

- 那麼棒還不趕快學起來?

---

## 基礎資料結構(DS)

---

## STACK 堆疊/棧

stack是一種先進後出(FILO, first in last out)的資料結構。就像堆盤子一樣，先放進去的會在最下面，最後才被拿出來。而最後放進去的則會在最上面，會先被拿出來。

[Stack可視化](https://visualgo.net/en/list)

----

### Stack的宣告

使用C++內建的Stack時要引用標頭檔
``` cpp=
#include <stack>
stack<int> st;
```

### 常用操作

* `empty()` - 判斷是否為空。
* `size()` - 取得stack大小。
* `top()` - 取得stack頂的元素(也就是最後一個放進去的元素)。
* `push(T value)` - 放入一個元素至堆頂。
* `emplace(T value)` - 常數比較小的 push。
* `pop()` - 把堆頂元素移除。

### 使用範例

```cpp=
if(st.empty()) cout << "empty\n";
st.push(87); // 此時 stack 裡面長這樣 {87}
st.emplace(33); //此時 stack 裡面長這樣 {87, 33}
cout << st.top(); // 輸出 33
cout << st.size(); // 輸出 2
st.pop(); 
```


### 實作細節

1. 如果stack裡面沒有元素的話是不能使用 ```st.top(), st.pop()``` 這兩個操作的。因為你stack裡面沒有東西，所以他取不到任何東西，他就會回傳給你一個RE(runtime error)。所以在使用這兩個操作前，記得先用```st.empty()``` 判斷stack裡面有沒有元素。

2. st.size() 這個東西他回傳的不是int，而是unsigned int。雖然你可能會覺得沒有差，但是實作上的經驗會告訴我們有時候他會在判斷上出問題。所以如果可以的話，盡量先把 ```st.size()``` 先轉成 int 的型態再進行操作。做法如下：
```cpp=
(int)st.size()
```
3. pop 的時候他只是把最後一個放進去的元素移除，所以括號裡面不需要放東西。

### 陣列實作Stack

Stack除了C++提供的STL之外，也有陣列用實作的方法。
程式碼也相當簡單，大家可以學起來。


``` cpp=
int top = 0;
int st[1000];
st[++ top] = a; // push(a) / emplace(a)操作
 
top --;         // pop()操作
    
cout << st[top] << "\n";  // top()操作
    
if(top == 0);   // empty()
    
int size = top; // size()
    
```

----

### 實戰演練 

#### 經典題 Parenthese Balance

給一個由括號組成的字串，請問字串是否合法？
規則如下：
1. 空字串是合法的
2. A是合法的的話，(A)和[A]也是合法的
3. A、B是合法的話，AB也是合法的

----

給個栗子

```((([])))``` 是合法的
```(([]))[]``` 是合法的
```((])()```   是不合法的

----

那我們要怎麼做呢？先觀察一下題目。我們可以先發現一件事，如果合法的話，從左往右掃過去一定會先出現 '(', '\[' 才會出現')',']'。

那我們就從左邊往右邊掃過去，每當遇到 ( 或 \[ 就代表他們在等待匹配到他們對應的括號。


把他們放到stack等待配對。然後我們就可以比對每一次出現的 ) 或 ] 
是不是可以分別對應到 (, \[
如果可以就把它從stack pop出來
繼續我們的操作。直到最後stack是空的的時候我們就知道這個字串是合法的了。可能看起來會有點難懂，可以搭配下面的Demo服用來了解他到底是怎麼運作的。

----

#### Demo

現在要判斷 ```(([]))[]``` 
從左往右掃過去(用 $i$ 代表處理從左數來第 $i$ 個符號)

$i=1\ Stack:\ ($
$i=2\ Stack:\ (($
$i=3\ Stack:\ (([$
$i=4\ Stack:\ (($
$i=5\ Stack:\ ($
$i=6\ Stack:\ empty$
$i=7\ Stack:\ [$
$i=8\ Stack:\ empty$


----

但要注意一點，如果stack是空的的話不能取stack.top()
否則你會拿到一個RE(runtime error)
原因就是你沒有東西取不到top
所以要先判斷st.empty()
在最後的時候也要記得判斷stack是否為空

----

完整code如下，提供參考

``` cpp=
#include<bits/stdc++.h>
using namespace std;
string s;

int main() {
    int t;
    cin >> t;
    getline(cin, s);  //把換行符號吃掉
    while(t --){
        getline(cin, s);
        stack<char> st;
        bool err = 0;
        if(s.empty()) {  //special case : 空字串
            cout << "Yes\n";
            continue;
        }
        for(int i = 0; i < (int)s.size(); i ++) {
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    err = 1;
                    break;
                }
                else{
                    char top = st.top();
                    st.pop();
                    if(s[i] == ')' && top != '('){
                        err = 1;
                        break;
                    }
                    else if(s[i] == ']' && top != '['){
                        err = 1;
                        break;
                    }
                }
            }
        }
        if(err || !st.empty()) cout << "No\n";
        else cout << "Yes\n";
    }
}
```

---

## 動態陣列 -- Vector

Vector 是 C++ STL 中的一個 class
簡單來講，Vector 就是一個很高端的進階版陣列
Vector 跟陣列一樣可以用[ ]來存取
可以存各種的資料型態(在宣告時註明)
也可以開到二維，三維... ...

### Vector與陣列的不同

還記得我們的標題是什麼嗎?

<p style="color:red;">動態陣列!</p>

正常的陣列試開一段連續的記憶體來存
而且在一開始宣告的時候就要先決定

<b>而動態陣列就是可以改變長度的陣列</b>

----

### 常用操作

* `empty()` - 判斷是否為空
* `size()` - 取得vector大小
* `front()` - 取得第一個元素(等價vc[0])
* `back()` - 取得最後面的元素(等價vc[vc.size()-1])
* `reserve()` - 改變容量大小
* `push_back(T value)` - 放一個元素到vector後面。
* `emplace_back(T value)` - 常數比較小的push_back。
* `pop_back()` - 把vector最後一個元素移除。
* `clear()` - 清除所有元素。

### 宣告方式

```c++
vector<int> vc;            //宣告一個vector vc
vector<int> vc(100);       //宣告一個大小為100的vector，所有元素都初始化為0
vector<int> vc(100, 9);    //宣告一個大小為100，每個值都是9的vector
vector<int> vc = {4, 8, 7, 6, 3}; //跟陣列一樣
vector< vector<int> > vc;  // 二維陣列
vector< vector<int> > vc(100, vector<int>(100)); // 宣告一個大小為100 * 100 的二維陣列
```

### 使用範例

```cpp=
vector<int> vc;
vc.push_back(54);    // vc = {54}
vc.emplace_back(87); // vc = {54, 87}
if(vc.empty() == false) cout << "not empty\n";
cout << "size = " << vc.size() << endl;
cout << vc[1] << " " << vc[0] << endl;
cout << vc.front() << " " << vc.back() << endl;
vc.clear();    // 清空vector
```



要特別注意的一件事情，有些人可能會發現宣告了大小之後就不能用push_back了。
其實是可以的，但是你如果push_back元素的話他會元素新增在你已經開的大小的後面。
也就是說假設你開了一個大小為100的vector，那麼你push_back之後新的元素就會在101的位置。

----

### vector有什麼用呢

1. 當陣列
2. 當鄰接表(存圖)(important)
3. 當stack來用
4. 模擬
5. 存struct

----


除此之外vector還有一個很好用的特性，那就是他可以使用range-base-for迴圈遍歷。
```cpp=
for(auto i : vc) cout << i << "\n";
```
也可以這樣輸入陣列
```cpp=
for(auto& p : vc) cin >> p;
```
所以也有很多人直接把vector當陣列來用

** 這邊的 '&' 有特別的意義，它叫做參考(英文叫做 Reference)詳細請見[[C++ Reference]](https://openhome.cc/Gossip/CppGossip/Reference.html)。


### 補充：Vector運作方式簡介

Vector 運作的方式比較特別
Vector 有 size 跟 capacity 兩種東東
size：元素個數(以下簡稱陣列長度)
capacity：容量大小

一開始vector會先開一段記憶體(容量)
之後如果你塞元素進去之後(push_back)
如果你的陣列長度大於容量大小的時候
他會開一段更長的記憶體
然後把所有東西都移到新的那邊

至於時間複雜度呢？事實上透過"均攤"
如果擴展很多次的話常數就會變很大！
但其實如果沒有很在意執行效率的話可以不要理他

----

### 解決方法#1

如果你已經知道你要開多大的記憶體
只是想要把他當陣列用
可以直接就把陣列開大
就不用一直進行擴展的動作了

----

### 解決方法#2

如果你不清楚你要開多大的記憶體，
你可以大概估計一下大概會開到多大
再用reserve這個函式先把空間開大
這樣擴展的次數就會變少很多

### 補充：Vector存圖

在程式競賽中有一類題目叫做圖論
圖論是在探討點與點之間的連接關係
![](https://i.imgur.com/ZwuVd9D.png)
(圖源：https://zhuanlan.zhihu.com/p/25498681?from_voters_page=true)
上面的網站介紹了所有的基本圖論算法

----

而有時候我們會需要把整張圖存起來
比較主流的作法有兩個：
1. 鄰接矩陣
2. 鄰接表

----

### 鄰接矩陣

鄰接矩陣簡單來講就是開一個二維陣列
如果點跟點之間有連邊就設為1(或邊權)
舉個粒子：
![](https://i.imgur.com/bXcT6wX.png)

這張圖的鄰接矩陣如下頁所示

----



|      |  1   |  2   |  3   |  4   |  5   |
| ---  | ---  | ---  | ---  | ---  | ---  |
|  1   |  0   |  0   |  1   |  0   |  1   |
|  2   |  0   |  0   |  1   |  0   |  1   |
|  3   |  1   |  1   |  0   |  1   |  0   |
|  4   |  0   |  0   |  1   |  0   |  1   |
|  5   |  1   |  1   |  0   |  1   |  0   |

----

### 鄰接表

鄰接表有許多種的實現方式
其中最方便也最常用的是用vector實作
```cpp
const int maxn = 1e5 + 50;
vector<int> vc[maxn];
```

----

鄰接表的原理就是對於每個點
都儲存他連到所有點
同樣以這張圖來看，他的鄰接表如下方所示
![](https://i.imgur.com/bXcT6wX.png)

----

上圖的鄰接表
```cpp
vc[1] : 3, 5
vc[2] : 3, 5
vc[3] : 1, 2, 4
vc[4] : 3, 5
vc[5] : 1, 2, 4
```

----

如果他們給你這樣表示點跟點的關係
```cpp
5 6    // 第一行 n代表點數 m代表邊數
1 5    // 第 2 ~ m + 1 行分別為連接關係
1 3
2 3
3 5
4 3
5 4
```

----

建圖的方式如下
```cpp
for(int i = 1; i <= m; i ++){
    int a, b;
    cin >> a >> b;
    vc[a].push_back(b);
    vc[b].push_back(a);
}
```


---

## QUEUE 佇列/隊列

----

queue是一種先進先出(FIFO, first in first out)的結構
就像排隊一樣，先放進去的會在最前面先出來。

可以用上面 stack 的可視化網站看他是怎麼實現的

----

常用操作：

* `empty()` - 判斷是否為空。
* `size()` - 取得queue大小。
* `front()` - 取得最前面的元素。
* `back()` - 取得最後面的元素。
* `push(T value)` - 放入一個元素至最後面。
* `emplace(T value)` - 常數比較小的 push。
* `pop()` - 把最前面的元素移除。

----

### 宣告方式

使用C++內建的queue時要引用標頭檔
``` c++
    #include <queue>
    queue<int> q;
    queue<string> sq;
```

----

### 實作範例

```cpp=
queue<int> q;
q.push(87);  // q = {87}
q.push(32);  // q = {87, 32}
cout << q.front(); // 輸出 87
q.pop();     // q = {32}
if(q.empty()) cout << "empty\n";   // 無輸出
cout << q.size(); // 輸出 1
```

----

### 陣列實作

1. 陣列

``` c++
    int head = 0, tail = -1;
    int q[1000];
    q[++ tail] = a; // push(a) / emplace(a)操作
    
    head ++;         // pop()操作
    
    cout << q[head] << "\n";  // front()操作
    
    cout << q[tail] << "\n";  // back()操作
    
    if(tail < head);   // empty()
    
    int size = tail - head + 1; // size()
```

----

由上面陣列的實作方式我們可以發現，head 跟 tail都是一直在往前加的，也就是說head前面的元素都不會再被用到，這樣不是很浪費記憶體嗎?

如果前面的元素確定不會被戳到，其實我們可以讓tail到某一個值之後繼續從0開始跑
形成一個 ""環狀的queue""。
其實STL的queue就是利用這個想法實作的

----

實作方式：

直接取模即可
``` c++
    int head = 0, tail = -1;
    int q[1005];
    int mod = 1000;
    
    q[++ tail] = a; 
    tail %= mod;     // push(a) / emplace(a)操作
    
    head ++;         
    head %= mod;     // pop()操作
    
    cout << q[head] << "\n";  // front()操作
    
    cout << q[tail] << "\n";  // back()操作
    
    if(tail < head);   // empty()
    
    int size = tail - head + 1; // size()
```

----

### 實戰演練 小組隊列

----

有 $n$ 個小組要排成一個隊列，每個小組中有若干人。

當一個人來到隊列時，如果隊列中已經有了自己小組的成員，他就直接插隊排在自己小組成員的後面，否則就站在隊伍的最後面。

入隊和出隊都需要使用常數時間。

----

這題看起來很queue，但是他多了一個神奇的條件
如果隊列中已經有了自己小組的成員，他就直接插隊排在自己小組成員的後面。

欸?插在後面?這不也是queue嗎!
所以這是一個queue中queue!
帥氣吧?

但是實作方面要怎麼做呢?
```c++
queue< queue<int> > q; (?
```
這樣實在有點炫泡


其實我們可以直接開一個queue的陣列
跟一個真正的queue
```c++
queue<int> Q[1000], mainQ;
```
mainQ 是存組別的。
Q[i] 是存目前第i組每個人的排隊順序


對於每次 ENQUEUE a 的操作
先找到a在第幾組(假設為i)，可以直接開個陣列紀錄
然後每次Enqueue先檢查Q[i]有沒有人
如果沒有就把i加在mainQ。
然後在Q[i]後面加入a



對於每次 DEQUEUE 操作
先取a = mainQ.front()
輸出Q[a].front()，再Q[a].pop()
再判斷一下，如果Q[a]已經沒東西了，我們就把mainQ.front() pop掉

----

完整code，提供參考

```c++
#include<bits/stdc++.h>
using namespace std;
const int maxx = 1e6 + 50;
const int maxn = 1e3 + 50;
int m, mp[maxx];
queue<int> q[maxn], mainq;

signed main(){
	int cpt = 0;
	while(cin >> m && m){
		cout << "Scenario #" << ++ cpt << "\n";
		while(!mainq.empty()) mainq.pop();
		for(int i = 1; i <= m; i ++){
			int a;
			cin >> a;
			for(int j = 1; j <= a; j ++){
				int b;
				cin >> b;
				mp[b] = i;
			}
			while(!q[i].empty()) q[i].pop();
		}
		string s;
		while(cin >> s && s[0] != 'S'){
			if(s[0] == 'E'){
				int a;
				cin >> a;
				int k = mp[a];
				if(q[k].empty()) mainq.push(k);
				q[k].push(a);
			}
			else{
				int t = mainq.front();
				cout << q[t].front() << "\n";
				q[t].pop();
				if(q[t].empty()) mainq.pop();
			}
		}
		cout << "\n";
	}
}
```

----

### 實戰演練2 slide window

----

MDOJ T006(加強)

題意：

請在 $O(N)$ 的時間內求出最小的連續區間長度使得其和 $>=k$


----

#### $O(N^2)$ 的解法

先求出前綴和再枚舉每一個區間看看是否可以滿足條件
順便記下最小值即可
或者也可以不需要前綴和，想辦法枚舉出答案就可以了

----

### $O(NlogN)$的解法

logN會讓你想到什麼呢?
沒錯就是二分搜!
一樣我們先做出前綴和
然後我們可以枚舉每一個位置當開頭
在對長度做二分搜找到它最短可以多短

這樣複雜度就是 $O(N)$ * $O(logN)$ = $O(NlogN)$

雖然 $NlogN$ 已經不錯了，但是我們還沒進入正題呢
別忘了我們的主題是什麼
<span style="font-size:30px;color:red"> Queue </span>

----

### $O(N)$ 的解法

可以利用 **滑窗(Slide Window)** 的概念

我們從最左邊開始掃過這個陣列，每一次操作都往右吃一個元素push 到 queue 裡
當我們找到一段滿足題意的子陣列，我們就看看可以從左邊刪掉多少元素
因為當然是丟掉越多越好(題目要求最短)，所以就丟到不能丟為止
然後我們就重複一直重複這樣的操作直到把整個陣列都吃完為止


你可能會想說
不對阿這樣子你又遍歷又要打掉
時間不應該是 $O(N)$ * $O(N)$ = $O(N^2)$嗎???

我們來仔細分析一下，可以發現到，每一個元素都只會進到 queue 一次，也就是說最多只會出去一次

所以說其實我們的時間複雜度是
$O(N)$ + $O(N)$ = $O(N)$

----

完整code，提供參考

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 50;
int x[maxn];
queue<int> q;

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i ++) cin >> x[i];
	int sum = 0, ans = 1e9;
	for(int i = 0; i < n; i ++){
		sum += x[i];
		q.push(x[i]);
		if(sum >= k) ans = min(ans, (int)q.size());
		while(sum - q.front() >= k){
			sum -= q.front();
			q.pop();
			ans = min(ans, (int)q.size());
		}
	}
	cout << ans;
}

```


題外話：
如果用陣列實作的做法理論上可以再快一點

---

## Deque 雙向佇列/隊列


Deque顧名思義就是兩邊都可以進出的queue
但跟vector一樣他也是動態陣列的一種，
而且支援O(1)隨機存取
所以我覺得叫他兩邊都可以進出的vector
會比較好一點(?

----

常用操作：

* `empty()` - 判斷是否為空。
* `size()` - 取得queue大小。
* `front()` - 取得最前面的元素。
* `back()` - 取得最後面的元素。
* `operator[]` - 就是[ ]運算子，存取該位置的元素。
* `push_back(T value)` - 放入一個元素至最後面。
* `push_front(T value)` - 放入一個元素至最前面。
* `pop_back()` - 把最後面的元素移除。
* `pop_front()` - 把最前面的元素移除。
* `clear()` - 清除所有元素



----

使用C++內建的deque時要引用標頭檔
``` c++
    #include <deque>
    deque<int> q;
    deque< pair<int, int> > sq;
```

----

Deque 主要

## Priority Queue 優先隊列

### 維修中

----


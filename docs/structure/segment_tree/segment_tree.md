## 概要
  
各ノードが区間に対応した、完全二分木。
- 子は親の半分の区間を持つ  
- モノイドについて、区間に対する演算が$O(log(n))$で処理できる。
  - 単位元の存在・結合律

セグメント木とは → https://www.slideshare.net/iwiwi/ss-3578491
実装について → https://tsutaj.hatenablog.com/entry/2017/03/29/204841

## 使い方

**区間に対して更新を高速に行いたい場合は、遅延セグメント木を使う。**

`SegmentTree(n, f, id)` : サイズが`n`のセグメント木を作成する。
  - `f` : 区間に対する演算
  - `id` : 単位元

ex.  
  - 区間和 : `SegmentTree<ll> seg(n, [](ll a, ll b) { return a + b; }, 0);`
  - 区間max : `SegmentTree<ll> seg(n, [](ll a, ll b) { return max(a, b); }, 0);`
  - 区間min : `SegmentTree<ll> seg(n, [](ll a, ll b) { return min(a, b); }, LLONG_MAX);`
  - 区間xor : `SegmentTree<ll> seg(n, [](ll a, ll b) { return a ^ b; }, 0);`
  - 区間GCD : `SegmentTree<ll> seg(n, [](ll a, ll b) { gcd(a, b); }, 0);`
  - 区間LCM : `SegmentTree<ll> seg(n, [](ll a, ll b) { lcm(a, b); }, 1);`

`seg.build(A)` : 配列Aをセグメント木に設定する。

`seg.update(x, val)` : x番目の値をvalに更新する。

`seg.get(l, r)` : 区間[l, r)についての演算結果を取得する


## 計算量

-  `build` : $O(n)$
-  `update` : $O(log(n))$
-  `get` : $O(log(n))$
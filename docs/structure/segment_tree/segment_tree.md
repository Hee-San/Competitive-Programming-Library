## 概要

Segment Tree / セグメント木 (monoids, 完全二分木, 一点更新, 区間取得)

- Monoidは、結合則を満たす二項演算と単位元を持つ集合。非可換でもOK
- 更新時に区間の演算結果を更新する

### References

- セグメント木とは: [プログラミングコンテストでのデータ構造](https://www.slideshare.net/iwiwi/ss-3578491)
- 基本的な実装: [セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/29/204841)
- 非再帰・1-indexed・非2冪: [非再帰セグ木サイコー！ 一番すきなセグ木です](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)
- 蟻本 p.153
- かつっぱさんの動画: [木マスター養成講座](https://www.youtube.com/watch?v=LjhVy1ZJTMc&list=PL3Hpv03CoZ24p5a6qT0LsFKEhiDWxf_B_&index=3)

## 使い方

### 初期化

- `n` 要素の配列を持つセグメント木を初期化する

``` cpp
segment_tree<plus_monoid<ll>> seg(n);
rep(i, n) seg.point_set(i, v[i]);

// または
rep(i, n) seg.unsafe_set(i, v[i]);
seg.build();
```

- 配列 `v` で初期化する

``` cpp
segment_tree<plus_monoid<ll>> seg(v);
```

- monoid を定義する

``` cpp
struct ll_plus_monoid : public Monoid<ll> {
public:
    ll unit() override { return 0; }
    ll mult(const ll& a, const ll& b) override { return a + b; }
};

void main(){
  // ...
  segment_tree<ll_plus_monoid> seg(v);
  // ...
}
```

### 更新

- `i` 番目の要素を `x` に更新する
- $O(\log n)$

``` cpp
seg.point_set(i, x);
```

### 区間取得

- `[l, r)` の区間の演算結果を取得する
- $O(\log n)$

``` cpp
seg.fold(l, r);
```

### 可視化（デバッグ用）

``` cpp
seg.visualize_for_debug();
```

``` bash
 0: |                    343|
 1: |        189|        154|
 2: |  140|   49|   91|   63|
 3: |60|80|24|25|19|72|25|38|
```

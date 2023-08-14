---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Square-Matrix(\u6B63\u65B9\u884C\u5217)"
    links: []
  bundledCode: "#line 1 \"math/square-matrix..cpp\"\n/**\n * @brief Square-Matrix(\u6B63\
    \u65B9\u884C\u5217)\n */\n\ntemplate <class T, int N>\nstruct SquareMatrix {\n\
    \  array<array<T, N>, N> A;\n\n  SquareMatrix() : A{ {} } {}\n\n  size_t size()\
    \ const { return N; }\n\n  inline const array<T, N>& operator[](int k) const {\
    \ return (A.at(k)); }\n\n  inline array<T, N>& operator[](int k) { return (A.at(k));\
    \ }\n\n  static SquareMatrix add_identity() { return SquareMatrix(); }\n\n  static\
    \ SquareMatrix mul_identity() {\n    SquareMatrix mat;\n    for (size_t i = 0;\
    \ i < N; i++) mat[i][i] = 1;\n    return mat;\n  }\n\n  SquareMatrix operator+(const\
    \ SquareMatrix& B) const {\n    return SquareMatrix(*this) += B;\n  }\n\n  SquareMatrix&\
    \ operator+=(const SquareMatrix& B) {\n    for (size_t i = 0; i < N; i++) {\n\
    \      for (size_t j = 0; j < N; j++) {\n        (*this)[i][j] += B[i][j];\n \
    \     }\n    }\n    return *this;\n  }\n\n  SquareMatrix operator-(const SquareMatrix&\
    \ B) const {\n    return SquareMatrix(*this) -= B;\n  }\n\n  SquareMatrix& operator-=(const\
    \ SquareMatrix& B) {\n    for (size_t i = 0; i < N; i++) {\n      for (size_t\
    \ j = 0; j < N; j++) {\n        (*this)[i][j] -= B[i][j];\n      }\n    }\n  \
    \  return *this;\n  }\n\n  SquareMatrix operator*(const SquareMatrix& B) const\
    \ {\n    return SquareMatrix(*this) *= B;\n  }\n\n  SquareMatrix& operator*=(const\
    \ SquareMatrix& B) {\n    array<array<T, N>, N> C;\n    for (size_t i = 0; i <\
    \ N; i++) {\n      for (size_t j = 0; j < N; j++) {\n        for (size_t k = 0;\
    \ k < N; k++) {\n          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);\n  \
    \      }\n      }\n    }\n    A.swap(C);\n    return (*this);\n  }\n\n  SquareMatrix\
    \ operator^(uint64_t k) const { return SquareMatrix(*this) ^= k; }\n\n  SquareMatrix&\
    \ operator^=(uint64_t k) {\n    SquareMatrix B = SquareMatrix::mul_identity();\n\
    \    while (k > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n  \
    \    k >>= 1LL;\n    }\n    A.swap(B.A);\n    return *this;\n  }\n};\n"
  code: "/**\n * @brief Square-Matrix(\u6B63\u65B9\u884C\u5217)\n */\n\ntemplate <class\
    \ T, int N>\nstruct SquareMatrix {\n  array<array<T, N>, N> A;\n\n  SquareMatrix()\
    \ : A{ {} } {}\n\n  size_t size() const { return N; }\n\n  inline const array<T,\
    \ N>& operator[](int k) const { return (A.at(k)); }\n\n  inline array<T, N>& operator[](int\
    \ k) { return (A.at(k)); }\n\n  static SquareMatrix add_identity() { return SquareMatrix();\
    \ }\n\n  static SquareMatrix mul_identity() {\n    SquareMatrix mat;\n    for\
    \ (size_t i = 0; i < N; i++) mat[i][i] = 1;\n    return mat;\n  }\n\n  SquareMatrix\
    \ operator+(const SquareMatrix& B) const {\n    return SquareMatrix(*this) +=\
    \ B;\n  }\n\n  SquareMatrix& operator+=(const SquareMatrix& B) {\n    for (size_t\
    \ i = 0; i < N; i++) {\n      for (size_t j = 0; j < N; j++) {\n        (*this)[i][j]\
    \ += B[i][j];\n      }\n    }\n    return *this;\n  }\n\n  SquareMatrix operator-(const\
    \ SquareMatrix& B) const {\n    return SquareMatrix(*this) -= B;\n  }\n\n  SquareMatrix&\
    \ operator-=(const SquareMatrix& B) {\n    for (size_t i = 0; i < N; i++) {\n\
    \      for (size_t j = 0; j < N; j++) {\n        (*this)[i][j] -= B[i][j];\n \
    \     }\n    }\n    return *this;\n  }\n\n  SquareMatrix operator*(const SquareMatrix&\
    \ B) const {\n    return SquareMatrix(*this) *= B;\n  }\n\n  SquareMatrix& operator*=(const\
    \ SquareMatrix& B) {\n    array<array<T, N>, N> C;\n    for (size_t i = 0; i <\
    \ N; i++) {\n      for (size_t j = 0; j < N; j++) {\n        for (size_t k = 0;\
    \ k < N; k++) {\n          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);\n  \
    \      }\n      }\n    }\n    A.swap(C);\n    return (*this);\n  }\n\n  SquareMatrix\
    \ operator^(uint64_t k) const { return SquareMatrix(*this) ^= k; }\n\n  SquareMatrix&\
    \ operator^=(uint64_t k) {\n    SquareMatrix B = SquareMatrix::mul_identity();\n\
    \    while (k > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n  \
    \    k >>= 1LL;\n    }\n    A.swap(B.A);\n    return *this;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/square-matrix..cpp
  requiredBy: []
  timestamp: '2023-08-14 18:19:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/square-matrix..cpp
layout: document
redirect_from:
- /library/math/square-matrix..cpp
- /library/math/square-matrix..cpp.html
title: "Square-Matrix(\u6B63\u65B9\u884C\u5217)"
---

/**
 * @brief モノイドを定義するための基底クラスです。
 * モノイドは、結合法則を満たす二項演算と単位元を持つ集合です。
 * 可換である必要はありません。
 * @tparam T モノイドの要素の型
 */
template <typename T>
class Monoid {
public:
    typedef T value_type;
    /**
     * @brief モノイドの単位元を返します。
     * 単位元 e は、任意の要素 a に対して a * e = e * a = a を満たす必要があります。
     * @return T モノイドの単位元
     */
    virtual T unit();

    /**
     * @brief モノイドの要素 a と b の積を返します。
     * 結合法則 a * (b * c) = (a * b) * c を満たす必要があります。
     * 可換則 a * b = b * a を満たす必要はありません。
     * @param a モノイドの要素
     * @param b モノイドの要素
     * @return T モノイドの要素
     */
    virtual T mult(const T& a, const T& b);
};

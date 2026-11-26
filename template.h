#ifndef PR10_VIRTUAL_SHAPES_NO_TEMPLATE_H
#define PR10_VIRTUAL_SHAPES_NO_TEMPLATE_H

template <class T>
class Element {
private:
    T data;
public:
    Element(T _t);
    T& value();
    void plus(T value);
};

template<class T>
Element<T>::Element(T _t) : data(_t) {
    ;
}

template<class T>
T& Element<T>::value() {
    return data;
}

template<typename K> K max(K a, K b);

template<typename K> K max(K a, K b) {
    return a > b ? a : b;
}

#endif

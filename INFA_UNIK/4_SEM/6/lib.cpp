#include <iostream>

template<typename A, int n>
class Vector_t
{
    private:
        A x[n];
    public:
        Vector_t();
        Vector_t(A x_);
        Vector_t(A x_[]);
        
        void Set(A x_[]);
        A* Get();
        
        template<typename B, int m> friend Vector_t<B, m> operator +(Vector_t<B, m> &vector_1, Vector_t<B, m> &vector_2);
};

template<typename A, int n>
Vector_t<A, n>::Vector_t() {
    for(int i = 0; i < n; i++) {
        x[i] = 0;
    }
}

template<typename A, int n>
Vector_t<A, n>::Vector_t(A x_) {
    for(int i = 0; i < n; i++) {
        x[i] = x_;
    }
}

template<typename A, int n>
Vector_t<A, n>::Vector_t(A x_[]) {
    for(int i = 0; i < n; i++) {
        x[i] = x_[i];
    }
}

template<typename A, int n>
A* Vector_t<A, n>::Get() {
    return x;
}

template<typename B, int m>
Vector_t<B, m> operator + (Vector_t<B, m> &vector_1, Vector_t<B, m> &vector_2) {
    B array[m] = {};
    for(int i = 0; i < m; i++) {
        array[i] = vector_1.x[i] + vector_2.x[i];
    }
    return Vector_t<B, m>{array};
}

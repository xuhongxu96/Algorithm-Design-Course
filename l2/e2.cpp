//
// Created by xuhongxu on 16/4/8.
//

#include <iostream>
#include <cstring>
using namespace std;

class Matrix {
private:
    int n;
    int N;
    int *m;

    static Matrix multiply(Matrix a, Matrix b) {
        if (a.n != b.n)
            throw "the size of a and b must be the same;";
        if (a.n == 0) {
            Matrix res(0);
            res.get(0, 0) = a.get(0, 0) * b.get(0, 0);
            return res;
        }
        Matrix c11 = multiply(a.getBlock(0, 0), b.getBlock(0, 0))
                     + multiply(a.getBlock(0, 1), b.getBlock(1, 0));
        Matrix c12 = multiply(a.getBlock(0, 0), b.getBlock(0, 1))
                     + multiply(a.getBlock(0, 1), b.getBlock(1, 1));
        Matrix c21 = multiply(a.getBlock(1, 0), b.getBlock(0, 0))
                     + multiply(a.getBlock(1, 1), b.getBlock(1, 0));
        Matrix c22 = multiply(a.getBlock(1, 0), b.getBlock(0, 1))
                     + multiply(a.getBlock(1, 1), b.getBlock(1, 1));
        return Matrix(c11, c12, c21, c22);
    }

public:
    Matrix() : n(0), N(0), m(nullptr) {}
    Matrix(int sz) : n(sz), N(1 << sz) {
        m = new int[N * N];
    }
    Matrix(const Matrix &t) : m(nullptr) {
        *this = t;
    }
    Matrix &operator =(const Matrix &t) {
        n = t.n;
        N = t.N;
        if (m) delete [] m;
        m = new int[N * N];
        memcpy(m, t.m, N * N * sizeof(int));
        return *this;
    }
    Matrix(Matrix &a11, Matrix &a12, Matrix &a21, Matrix &a22) : n(a11.n + 1), N(a11.N << 1) {
        m = new int[N * N];
        for (int i = 0; i < a11.N; ++i) {
            for (int j = 0; j < a11.N; ++j) {
                get(i, j) = a11.get(i, j);
            }
        }
        for (int i = a11.N; i < N; ++i) {
            for (int j = 0; j < a11.N; ++j) {
                get(i, j) = a21.get(i - a11.N, j);
            }
        }
        for (int i = 0; i < a11.N; ++i) {
            for (int j = a11.N; j < N; ++j) {
                get(i, j) = a12.get(i, j - a11.N);
            }
        }
        for (int i = a11.N; i < N; ++i) {
            for (int j = a11.N; j < N; ++j) {
                get(i, j) = a22.get(i - a11.N, j - a11.N);
            }
        }
    }
    void setSize(int sz) {
        n = sz;
        N = 1 << n;
        m = nullptr;
        m = new int[N * N];
    }
    int &get(int x, int y) {
        return m[x * N + y];
    }
    Matrix operator +(Matrix t) {
        if (n != t.n)
            throw "the size of a and b must be the same;";
        Matrix res(n);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res.get(i, j) = get(i, j) + t.get(i, j);
            }
        }
        return res;
    }
    Matrix operator *(Matrix t) {
        if (n != t.n)
            throw "the size of a and b must be the same;";
        return multiply(*this, t);
    }
    Matrix getBlock(int x, int y) { // 0, 0; 0, 1; 1, 0; 1, 1
        int tN = N >> 1;
        Matrix res(n - 1);
        int sx = x * tN, dx = (x + 1) * tN;
        int sy = y * tN, dy = (y + 1) * tN;
        for (int i = sx; i < dx; ++i) {
            for (int j = sy; j < dy; ++j) {
                res.get(i - sx, j - sy) = get(i, j);
            }
        }
        return res;
    }
    void print() {
        cout << "---" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
        cout << "---" << endl;

    }
    ~Matrix() {
        if (m != nullptr) {
            delete [] m;
            m = nullptr;
        }
    }
};

int n, N;
Matrix m1, m2, res;


int main() {

    cin >> n;
    N = 1 << n;
    m1.setSize(n);
    m2.setSize(n);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> m1.get(i, j);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> m2.get(i, j);

    res = m1 * m2;
    res.print();
    return 0;
}

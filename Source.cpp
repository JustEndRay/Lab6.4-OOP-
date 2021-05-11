#include <iostream>
using namespace std;


template <typename T>
class MATRIX
{
public:
    T** M; 
    int m; 
    int n; 

public:
    // конструкторы
    MATRIX()
    {
        n = m = 0;
        M = nullptr; 
    }


    MATRIX(int _m, int _n)
    {
        m = _m;
        n = _n;


        M = (T**) new T * [m];


        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];


        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
    }


    MATRIX(const MATRIX& _M)
    {

        m = _M.m;
        n = _M.n;


        M = (T**) new T * [m]; 

        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];


        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
    }


    T GetMij(int i, int j)
    {
        if ((m > 0) && (n > 0))
            return M[i][j];
        else
            return 0;
    }

    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
    }


    void Print(const char* ObjName)
    {
        cout << "Object: " << ObjName << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "--------------------------" << endl << endl;
    }


    MATRIX operator=(const MATRIX& _M)
    {
        if (n > 0)
        {

            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
        {
            delete[] M;
        }


        m = _M.m;
        n = _M.n;


        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];


        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
        return *this;
    }


    ~MATRIX()
    {
        if (n > 0)
        {
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
    }
};
template <class T> MATRIX<T> operator + (MATRIX<T>& x, MATRIX<T>& y) 
{
    MATRIX<T> z(x.m,x.n);
    for (int i = 0; i < x.m; i++)
    {
        for (int j = 0; j < x.m; j++)
        {
            z.M[i][j] = x.M[i][j] + y.M[i][j];
        }
    }
    return z;
}
template <class T> MATRIX<T> operator * (MATRIX<T>& x,int y) 
{
    MATRIX<T> z(x.m, x.n);
    for (int i = 0; i < x.m; i++)
    {
        for (int j = 0; j < x.m; j++)
        {
            z.M[i][j] = x.M[i][j] * y;
        }
    }
    return z;
}
int main()
{

    MATRIX<int> A(4, 4);
    MATRIX<int> B(4, 4);
    MATRIX<int> C(4, 4);
    MATRIX<int> D(4, 4);
    A.Print("A");
    A.Print("B");
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            A.SetMij(i, j, rand() % 10);
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            B.SetMij(i, j, rand() % 10);
    A.Print("A");
    B.Print("B");
    C = A + B;
    C.Print("C");
    D = C * 4;
    D.Print("D");
    return 0;
}

#include <iostream>
#include<vector>
//#include<stdlib>

using namespace std;

typedef vector <int> vetor;
typedef vector <vetor> matriz;


matriz multiplicaMatriz(const matriz &a, const matriz &b)
{
    int i, j;
    matriz c;
    c.resize(a.size());

    for(int i = 0; i < c.size(); i++)
    {
        c[i].resize(j);

        for (int j = 0; j < c.size(); j++)
        {
            for (int k = 0; k < c[i].size(); k++)
            {
                c[i][j] += a[i][k]*b[k][j];

            }
        }
    }

    return c;
}

matriz digitaMatriz()
{

    int linha, coluna;
    matriz m;

    cout << "Informe o numero de linhas: ";
    cin >> linha;
    cout << "Informe o numero de colunas: ";
    cin >> coluna;
    m.resize(linha);
    for(int i=0; i<m.size(); i++)
    {
        m[i].resize(coluna);
        return m;
    }

}

int main()
{

    matriz a;
    a = digitaMatriz();
    matriz b;
    b = digitaMatriz();

     multiplicaMatriz(a, b);

    return 0;
}

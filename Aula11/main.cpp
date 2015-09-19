#include <iostream>
#include <vector>

using namespace std;
typedef vector <int> vetor;
typedef vector <vetor> matriz;




matriz alimentaMatriz(){
    matriz m;
    int num, lin, col;
    cout << "Linhas: ";
    cin >> lin;
    cout << "Colunas: ";
    cin >> col;
    m.resize(lin);
    for (int i=0; i<m.size(); i++){
        m[i].resize(col);
        for(int j=0; j<m[i].size(); j++){
            cout << "Valor ["<< i <<"] [" << j << "]: ";
            cin >> num;
            m[i][j]=num;
        }
    }
    return m;
}

void mostraMatriz(const matriz &m){
    int i, j;
    for (i=0; i<m.size(); i++){
        for (j=0; j<m[i].size(); j++){
            cout << m[i][j] << "  ";
        }
        cout << endl;
    }
}
matriz multiplicaMatriz(const matriz &a, const matriz &b){
    matriz c;
    c.resize(a.size());
    int i = 0,
        j = 0,
        k = 0;

    for(i = 0; i< c.size(); i++)
            c[i].resize(b[0].size());
        for(i = 0; i < a.size(); i++)
            {
                for(j = 0; j < b[0].size(); j++)
                    {
                        c[i][j] = 0;
                        for (k = 0; k < a.size(); k++)
                            c[i][j] += a[i][k] * b[k][j];
                    }
            }
            return c;
}
matriz somaMatriz(const matriz &a, const matriz &b){

matriz c;
    c.resize(a.size());
    int i = 0,
        j = 0,
        k = 0;

    for(i = 0; i< c.size(); i++)
            c[i].resize(b[0].size());
        for(i = 0; i < a.size(); i++)
            {
                for(j = 0; j < b[0].size(); j++)
                    {
                        c[i][j] = 0;
                        for (k = 0; k < a.size(); k++)
                            c[i][j] = a[i][j] + b[k][j];
                    }
            }
            return c;

}
matriz multiplicaMatrizporNum(const matriz &a, int &nro){
    matriz c;
    c.resize(a.size());
    int i = 0,
        j = 0,
        k = 0;

    for(i = 0; i< c.size(); i++)
            c[i].resize(a[0].size());
        for(i = 0; i < a.size(); i++)
            {
                for(j = 0; j < a[0].size(); j++)
                    {
                        c[i][j] = 0;
                        for (k = 0; k < a.size(); k++)
                            c[i][j] = a[i][j] * nro;
                    }
            }
            return c;
}




int main()
{
    char menu;
     int status, nro;
        matriz a;
        matriz b;
        matriz c;
        matriz d;
        matriz e;

    do
    {
        cout<<"\tMenu\n";
         cout<<"________________________\n";
        cout<<"1)Cria Matriz A\n";
        cout<<"2)Cria a Matriz B\n";
        cout<<"3)Entra numero inteiro\n";
        cout<<"4)Somar as matrizes A e B e apresentar o resultado\n";
        cout<<"5)Multiplicar as matrizes A e B e apresentar o resultado\n";
        cout<<"6)Multiplicar a matriz A pelo numero inteiro e apresentar o resultado\n";
        cout<<"7)Encerrar o programa:    ";
        cin>>menu;
        cout<<endl;

        switch(menu)
        {
        case '1':
            a = alimentaMatriz();
            mostraMatriz(a);
            break;

        case '2':
            b = alimentaMatriz();
            mostraMatriz(b);
            break;

        case '3':
            cout <<"Digite um numero inteiro";
            cin>> nro;
            break;

        case '4':
            c = somaMatriz(a, b);
                mostraMatriz(c);
            break;

        case '5':
            d = multiplicaMatriz(a, b);
                mostraMatriz(d);
            break;

          case '6':
            e = multiplicaMatrizporNum(a, nro);
            mostraMatriz(e);
            break;
    }

         }while(menu != 7);

    }

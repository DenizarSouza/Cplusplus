#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
typedef vector <int> vetor;
typedef vector <vetor> matriz;

matriz multiplicaMatriz(const matriz &a, const matriz &b, int status){

    matriz c;
    if (a[0].size() != b.size()){
        status = -1;
        return c;
    }else{
        status = 0;
        c.resize(a.size());
        for(int i = 0; i < c.size(); i++){
            c[i].resize(b[0].size());
        }
        for(int i = 0; i < c.size(); i++){
            for (int j = 0; j < b[0].size(); j++){
                c[i][j]=0;
                for (int k = 0; k < b.size(); k++){
                    c[i][j] += a[i][k]*b[k][j];
                }
            }
        }
    }
    return c;
}
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

int main(){
    int status;
    matriz a;
    matriz b;
    matriz c;
    a = alimentaMatriz();
    mostraMatriz(a);
    b = alimentaMatriz();
    mostraMatriz(b);
    c = multiplicaMatriz(a, b, status);
    if (status = -1){
        cout << "Matriz incopativel!!!" << endl;
    }else{
        cout << "Resultado:" << endl;
        mostraMatriz(c);
    }
    system("pause");
    return 0;
}

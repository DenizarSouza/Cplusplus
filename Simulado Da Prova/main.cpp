#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef vector < int > vetor;

vetor EntradaDados()
{
    vetor v;
    int nro, n;

    cout << "Entre com um valor: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Entre com um numero: ";
        cin >> nro;
        v.push_back(nro);
    }
    return v;
}

void Grava(const vetor &v)
{
    int soma = 0;
    ofstream arq_saida;
    arq_saida.open("numeros.txt", ios::out);

    for(int i = 0; i < v.size(); i++)
    {
         cout << v[i] << endl;
         arq_saida  << v[i] << endl;
         soma += v[i];
    }
    cout << "A soma eh: " << soma << endl;
    arq_saida << "A soma eh: " << soma << endl;
    arq_saida.close();
}

int main()
{
    vetor v = EntradaDados();
    Grava(v);
    return 0;
}

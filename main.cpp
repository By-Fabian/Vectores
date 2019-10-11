#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

void imprimir(vector<vector<int>> matriz,int precision){

    for (auto & filas:matriz) {
        for (auto & item:filas)
            cout<<setw(precision)<<item;
        cout<<endl;
    }
}

void matriz_a_transpuesta(vector<vector<int>> matriz,vector<vector<int>> &matrizt){

    int filas=matriz.size();
    int columnas=matriz[0].size();

    matrizt.resize(columnas);

    for (int j = 0; j <columnas ; ++j) {
        matrizt[j].resize(columnas);
    }


    for(int k=0;k<filas;k++)
        for (int i=0;i<columnas;i++){
            matrizt[i][k]=matriz[k][i];
        }
}

void matrizporescalar(vector<vector<int>> matriz, double escalar,vector<vector<int>> &matrizxescalar){

    int filas=matriz.size();
    int columnas=matriz[0].size();

    for(int k=0;k<filas;k++)
        for (int i=0;i<columnas;i++){
            matrizxescalar[filas][columnas]=(matriz[filas][columnas]*escalar);
        }
}

int main() {

    unsigned int filas=0;
    unsigned int columnas=0;
    auto valor=0;
    int first=0;
    int last=0;
    double escalar=0;

    random_device device;
    uniform_int_distribution<int> distribution(20,40);

    //////////////////////////////////////////////////////////////////////////

    cout<<"Ingrese filas: ";cin>>filas;cout<<endl;
    cout<<"Ingrese columnas: ";cin>>columnas;cout<<endl;
    cout<<"Ingrese valor: ";cin>>valor;cout<<endl;
    cout<<"Ingrese first: ";cin>>first;cout<<endl;
    cout<<"Ingrese second: ";cin>>last;cout<<endl;
    cout<<"Ingrese escalar: ";cin>>escalar;cout<<endl;

    ////////////////////////////////////////////////////////////////////////

    vector<vector<int>>matriz1(filas,vector<int>(columnas,valor));

    vector<vector<int>>matriz2(filas, vector<int>(columnas));

    for (auto & filas:matriz2) {
        for (auto & item:filas)
            item=distribution(device);
    }

    vector<vector<int >>matriz3;

    matriz3={{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{21,22,23}};

    /////////////////////////////////////////////////////////////////////////////////////////

    vector<vector<int>>matriztranspuesta;

    vector<vector<int>>matrizxescalar;

    matriz_a_transpuesta(matriz2,matriztranspuesta);

    matrizporescalar(matriz2,escalar,matrizxescalar);

    /*
    cout<<"Matriz con valores predefinidos: "<<endl;
    imprimir(matriz1,3);
    cout<<endl;

    cout<<"Matriz con valores random: "<<endl;
    imprimir(matriz2,3);
    cout<<endl;

    cout<<"Matriz con valores escritos a mano"<<endl;
    imprimir(matriz3,3);
    cout<<endl;

    cout<<"Matriz Transpuesta: "<<endl;
    imprimir(matriztranspuesta,3);
    cout<<endl;

    cout<<"Matriz por Escalar: "<<endl;
    imprimir(matrizxescalar,3);
    cout<<endl;
    */
    return 0;
}


#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void imprimir(vector<vector<float> >vectores){
    for(int i = 0; i < vectores.size(); i++){
        for(int j = 0; j < vectores[i].size(); j++){
            cout << vectores[i][j] << " ";
        }
        cout << endl;
    }
}

float norma(vector<float> name){
    float rpta = 0;
    for(int i = 0; i < name.size(); i++){
        rpta += pow(name[i],2);
    }
    return sqrt(rpta);
}

float punto(vector<float> name, vector<float> last){
    float rpta = 0;
    for(int i = 0; i < name.size(); i++){
        rpta += name[i]*last[i];
    }
    return rpta;
}

vector<float> suma(vector<float> name, vector<float> last){
    vector<float> rpta;
    for(int i = 0; i < name.size(); i++){
        rpta.push_back(name[i]+last[i]);
    }
    return rpta;
}

vector<float> resta(vector<float> name, vector<float> last){
    vector<float> rpta;
    for(int i = 0; i < name.size(); i++){
        rpta.push_back(name[i]-last[i]);
    }
    return rpta;
}

vector<float> pro_esca(float name, vector<float> last){
    vector<float> rpta;
    for(int i = 0; i < last.size(); i++){
        rpta.push_back(name*last[i]);
    }
    return rpta;
}

vector<vector<float> > generar_vector(int cant, int val){
    vector<vector<float> > rpta;
    float x;
    for(int i = 0; i < cant; i++){
        vector<float> temp;
        for(int j = 0; j < val; j++){
            cout << "Ingrese un valor: ";
            cin >> x;
            temp.push_back(x);
        }
        rpta.push_back(temp);
        cout << endl;
    }
    return rpta;
}

vector<vector<float> > ortonormal(int cant, int val){
    vector<vector<float> > general = generar_vector(cant, val);
    vector<vector<float> > rpta;
    rpta.push_back(general[0]);
    for(int i = 1; i < general.size(); i++){
        vector<float> temp;
        for(int k = 0; k < val; k++){
            temp.push_back(0);
        }
        float u;
        for(int j = 0; j < i; j++){
            u = punto(general[i],rpta[j])/pow(norma(rpta[j]),2);
            temp = suma(pro_esca(u,rpta[j]),temp);
        }
        rpta.push_back(resta(general[i],temp));
    }
    imprimir(rpta);
    return rpta;
}

int main(){
    int total, variables;
    cout << "Ingrese la cantidad de vectores: ";
    cin >> total;
    cout << "Ingrese la cantidad de variables: ";
    cin >> variables;

    ortonormal(total,variables);
    return 0;
}

#include <fstream>
using namespace std;

fstream guardapolt;
const int T_colunas;
const int T_linhas;

void tamanho_coluna(){
   int Tam_Col = 0;
   string linha;
    
    guardapolt.open("poltselecionada.txt", ios::in);
    while(getline(guardapolt, linha)){
    for (int i = 0; i < linha.size(); i++){
      if (linha[i] == ';'){
        Tam_Col++;
      }
      else{
        if(linha[i] == '/'){
          guardapolt.close();
          T_colunas = Tam_Col;
        }
      }
    }
  }
}

int tamanho_linha(){
  int Tam_linha = 0;
   string linha;
    
    guardapolt.open("poltselecionada.txt", ios::in);
    while(getline(guardapolt, linha)){
    for (int i = 0; i < linha.size(); i++){
      if (linha[i] == '/'){
        Tam_linha++;
      }
    }
  }
  guardapolt.close();
  T_linhas = Tam_linha;
}

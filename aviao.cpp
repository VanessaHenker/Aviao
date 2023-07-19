#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
void desenhar_boneco(int chances);

int main(){
  using namespace std;

  char palavra[20], secreta[20], letra[1];
  int i, tam, acertos, chances, opcao, erros;
  bool acerto;

  do{
    i = 0;
    tam = 0;
    chances = 7;
    erros = 0;
    acertos = 0;
    acerto = false;

    cout << "\nQual sera a palavra secreta? ";
    cout << endl;
    cin >> palavra;
    system("cls");
    while (palavra[i] != '\0'){
      i++;
      tam++;
    }
    for (i = 0; i < 20; i++){
      secreta[i] = '-';
    }
    while ((chances > 0) && (acertos < tam)){
      cout << "\nPalavra secreta ";
      for (i = 0; i < tam; i++){
        cout << secreta[i];
      }
      cout << "\n                                          Chances restantes " << chances;
      desenhar_boneco(chances);
      cout << "\nDigite uma letra: ";
      cin >> letra[0];
      for (i = 0; i < tam; i++){
        if (palavra[i] == letra[0]){
          acerto = true;
          secreta[i] = palavra[i];
          acertos++;
        }
      }
      if (acerto == false){
        chances--;
      }
      acerto = false;
      system("cls");
    }
    if (acertos == tam){
      cout << "\nVoce venceu!";
      cout << "\nDigite 1 se quiser jogar novamente: ";
      cin >> opcao;
      system("cls");
    }
    else{
    cout << "\nQue pena, voce perdeu!\n";
    cout << "\nDigite 1 se quiser jogar novamente: ";
    cin >> opcao;
    system("cls");
    }
  }while (opcao == 1);
  return 0;
}

void desenhar_boneco(int chances){
  using namespace std;
  switch (chances){
  case 6:
    cout << "\n                                         --------------";
    cout << "\n                                         |            O";
    cout << "\n                                         |";
    cout << "\n                                         |";
    cout << "\n                                         |";
    break;

  case 5:
    cout << "\n                                         --------------";
    cout << "\n                                         |            O";
    cout << "\n                                         |            |";
    cout << "\n                                         |";
    cout << "\n                                         |";
    break;

  case 4:
    cout << "\n                                         --------------";
    cout << "\n                                         |            O";
    cout << "\n                                         |           /|";
    cout << "\n                                         |";
    cout << "\n                                         |";
    break;

  case 3:
    cout << "\n                                         --------------";
    cout << "\n                                         |            O";
    cout << "\n                                         |           /|>";
    cout << "\n                                         |";
    cout << "\n                                         |";
    break;

  case 2:
    cout << "\n                                         --------------";
    cout << "\n                                         |           O";
    cout << "\n                                         |          /|>";
    cout << "\n                                         |          /  ";
    cout << "\n                                         |";
    break;

  case 1:
    cout << "\n                                         ---------------";
    cout << "\n                                         |           O";
    cout << "\n                                         |          /|>";
    cout << "\n                                         |          / | ";
    cout << "\n                                         |";
    break;
  }
}




#include <iostream>
#include <string>
using namespace std;

void mostrar_nome();
void lugar();
void escolher_lugar();
string nomes[31], lugares[31];
char destino_dnv;
int origem, destino;

int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");

 cout << "\n    PRA ONDE VAMOS? ";
 cout << "\n    Mais de 30 lugares para você escolher!" << endl;
 cout << endl;
 mostrar_nome();
 escolher_lugar();
 return 0;
}

void mostrar_nome(){
setlocale(LC_ALL, "Portuguese_Brazil");
int i = 0;
lugares[0] = "Rio de Janeiro";
lugares[1] = "São Paulo";
lugares[2] = "Belém";
lugares[3] = "Brasília";
lugares[4] = "Cuiabá";
lugares[5] = "Curitiba";
lugares[6] = "Miami";
lugares[7] = "Fort Lauderdale";
lugares[8] = "Florianópolis";
lugares[9] = "Foartaleza";
lugares[10] = "Goiânia";
lugares[11] = "Lisboa";
lugares[12] = "Manaus";
lugares[13] = "Orlando";
lugares[14] = "Carrasco";
lugares[15] = "Paris";
lugares[16] = "Porto Alegre";
lugares[17] = "Porto Velho";
lugares[18] = "Recife";
lugares[19] = "Santos Dumont";
lugares[20] = "São Luíz";
lugares[21] = "Vitória";
lugares[22] = "Málaga";
lugares[23] = "Aracaju";
lugares[24] = "Barcelona";
lugares[25] = "João Pessoa";
lugares[26] = "Los Angeles";
lugares[27] = "New York";
lugares[28] = "Alemanha";
lugares[29] = "Argentina";
lugares[30] = "França";
lugares[31] = "Dubai";
for(i < 0; i < 31; i++){
  cout << "[" << i << "]-> " << lugares[i]; 
  cout << "\n";
}
}
void escolher_lugar(){
setlocale(LC_ALL, "Portuguese_Brazil");

int i;
i = 0;
origem = 32;

while(origem < 1 || origem > 31){
 cout << "\nORIGEM? ";
 cin >> origem;
 switch (origem){
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
  case 15:
  case 16:
  case 17:
  case 18:
  case 19:
  case 20:
  case 21:
  case 22:
  case 23:
  case 24:
  case 25:
  case 26:
  case 27:
  case 28:
  case 29:
  case 30:
  case 31:
  case 32:
  cout << "\nDESTINO? ";
  cin >> destino;
  if(destino == origem){
    cout << "\nErro, você já selecionou " << lugares[origem] << " como origem!" << endl;
    cout << "\nSe deseja escolher outro destino ";
    cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
    cin >> destino_dnv;
  }
  else{
  cout << "\nORIGEM: " << lugares[origem];
  cout << "\nDESTINO: " << lugares[destino];
  }
  break;
  default:
    cout << "\nErro, tente novamente!" << endl;
    break;
    }
  }
}
void lugar(){
setlocale(LC_ALL, "Portuguese_Brazil");

}


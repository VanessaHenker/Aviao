#include <iostream>
#include <string>
using namespace std;

void mostrar_nome();
void escolher_lugar();
string nomes[30], lugares[30];
int origem, destino;

int main() {
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
nomes[0] = " [1]->  Rio de Janeiro";
nomes[1] = " [2]->  São Paulo";
nomes[2] = " [3]->  Belém";
nomes[3] = " [4]->  Brasília";
nomes[4] = " [5]->  Cuiabá";
nomes[5] = " [6]->  Curitiba";
nomes[6] = " [7]->  Miami";
nomes[7] = " [8]->  Fort Lauderdale";
nomes[8] = " [9]->  Florianópolis";
nomes[9] = " [10]-> Foartaleza";
nomes[10] = "[11]-> Goiânia";
nomes[11] = "[12]-> Lisboa";
nomes[12] = "[13]-> Manaus";
nomes[13] = "[14]-> Orlando";
nomes[14] = "[15]-> Carrasco";
nomes[15] = "[16]-> Paris";
nomes[16] = "[17]-> Porto Alegre";
nomes[17] = "[18]-> Porto Velho";
nomes[18] = "[19]-> Recife";
nomes[19] = "[20]-> Santos Dumont";
nomes[20] = "[21]-> São Luíz";
nomes[21] = "[22]-> Vitória";
nomes[22] = "[23]-> Málaga";
nomes[23] = "[24]-> Aracaju";
nomes[24] = "[25]-> Barcelona";
nomes[25] = "[26]-> João Pessoa";
nomes[26] = "[27]-> Los Angeles";
nomes[27] = "[28]-> New York";
nomes[28] = "[29]-> Alemanha";
nomes[29] = "[30]-> Argentina";
nomes[30] = "[31]-> França";
nomes[31] = "[32]-> Dubai";

for(i = 0; i < 31; i++){
  cout << nomes[i] << endl;
}
}

void escolher_lugar(){
setlocale(LC_ALL, "Portuguese_Brazil");

int i;
i = 0;
cout << endl;
cout << endl;
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
break;
default:
  cout << "\nErro, tente novamente!" << endl;
  break;
}

}
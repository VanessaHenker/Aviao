#include <iostream>
#include <string>
using namespace std;

void mostrar_nome();
void lugar();
void escolha_lugar();
string nomes[31], lugares[31];
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
nomes[0] =  "[1]->  Rio de Janeiro";
nomes[1] =  "[2]->  São Paulo";
nomes[2] =  "[3]->  Belém";
nomes[3] =  "[4]->  Brasília";
nomes[4] =  "[5]->  Cuiabá";
nomes[5] =  "[6]->  Curitiba";
nomes[6] =  "[7]->  Miami";
nomes[7] =  "[8]->  Fort Lauderdale";
nomes[8] =  "[9]->  Florianópolis";
nomes[9] =  "[10]-> Foartaleza";
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
}

void lugar(){
setlocale(LC_ALL, "Portuguese_Brazil");
if(origem == 1){
cout << lugares[0] << endl;
}
if(origem == 2){
cout << lugares[1] << endl;
}
if(origem == 3){
cout << lugares[2] << endl;
}
if(origem == 4){
cout << lugares[3] << endl;
}
if(origem == 5){
cout << lugares[4] << endl;
}
if(origem == 6){
cout << lugares[5] << endl;
}
if(origem == 7){
cout << lugares[6] << endl;
}
if(origem == 8){
cout << lugares[7] << endl;
}
if(origem == 9){
cout << lugares[8] << endl;
}
if(origem == 10){
cout << lugares[9] << endl;
}
if(origem == 11){
cout << lugares[10] << endl;
}
if(origem == 12){
cout << lugares[11] << endl;
}
if(origem == 13){
cout << lugares[12] << endl;
}
if(origem == 14){
cout << lugares[13] << endl;
}
if(origem == 15){
cout << lugares[14] << endl;
}
if(origem == 16){
cout << lugares[15] << endl;
}
if(origem == 17){
cout << lugares[16] << endl;
}
if(origem == 18){
cout << lugares[17] << endl;
}
if(origem == 19){
cout << lugares[18] << endl;
}
if(origem == 20){
cout << lugares[19] << endl;
}
if(origem == 21){
cout << lugares[20] << endl;
}
if(origem == 22){
cout << lugares[21] << endl;
}
if(origem == 23){
cout << lugares[22] << endl;
}
if(origem == 24){
cout << lugares[23] << endl;
}
if(origem == 25){
cout << lugares[24] << endl;
}
if(origem == 26){
cout << lugares[25] << endl;
}
if(origem == 27){
cout << lugares[26] << endl;
}
if(origem == 28){
cout << lugares[27] << endl;
}
if(origem == 29){
cout << lugares[28] << endl;
}
if(origem == 30){
cout << lugares[29] << endl;
}
if(origem == 31){
cout << lugares[30] << endl;
}
if(origem == 32){
cout << lugares[31] << endl;
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
cout << lugares[31] << endl;
cout << "\nDESTINO? ";
cin >> destino;
break;
default:
  cout << "\nErro, tente novamente!" << endl;
  break;
}

}
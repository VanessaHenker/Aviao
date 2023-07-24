#include <iostream>
#include <string>
using namespace std;

void mostrar_nome();
void escolher_lugar();
string nomes[30], lugares[30], origem, destino;

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
nomes[0] = "[1]Rio de Janeiro";
nomes[1] = "[2]São Paulo";
nomes[2] = "[3]Belém";
nomes[3] = "[4]Brasília";
nomes[4] = "[5]Cuiabá";
nomes[5] = "Curitiba";
nomes[6] = "Miami";
nomes[7] = "Fort Lauderdale";
nomes[8] = "Florianópolis";
nomes[9] = "Foartaleza";
nomes[10] = "Goiânia";
nomes[11] = "Lisboa";
nomes[12] = "Manaus";
nomes[13] = "Orlando";
nomes[14] = "Carrasco";
nomes[15] = "Paris";
nomes[16] = "Porto Alegre";
nomes[17] = "Porto Velho";
nomes[18] = "Recife";
nomes[19] = "Santos Dumont";
nomes[20] = "São Luíz";
nomes[21] = "Vitória";
nomes[22] = "Málaga";
nomes[23] = "Aracaju";
nomes[24] = "Barcelona";
nomes[25] = "João Pessoa";
nomes[26] = "Los Angeles";
nomes[27] = "New York";
nomes[28] = "Alemanha";
nomes[29] = "Argentina";
nomes[30] = "França";
nomes[31] = "Dubai";

cout << nomes[0] << endl;
cout << nomes[1] << endl;
cout << nomes[2] << endl;
cout << nomes[3] << endl;
cout << nomes[4] << endl;
cout << nomes[5] << endl;
cout << nomes[6] << endl;
cout << nomes[7] << endl;
cout << nomes[8] << endl;
cout << nomes[9] << endl;
cout << nomes[10] << endl;
cout << nomes[11] << endl;
cout << nomes[12] << endl;
cout << nomes[13] << endl;
cout << nomes[14] << endl;
cout << nomes[15] << endl;
cout << nomes[16] << endl;
cout << nomes[17] << endl;
cout << nomes[18] << endl;
cout << nomes[19] << endl;
cout << nomes[20] << endl;
cout << nomes[21] << endl;
cout << nomes[22] << endl;
cout << nomes[23] << endl;
cout << nomes[24] << endl;
cout << nomes[25] << endl;
cout << nomes[26] << endl;
cout << nomes[27] << endl;
cout << nomes[28] << endl;
cout << nomes[29] << endl;
cout << nomes[30] << endl;
cout << nomes[31] << endl;
}

void escolher_lugar(){
setlocale(LC_ALL, "Portuguese_Brazil");

int i;
i = 0;
cout << endl;
cout << endl;
cout << "ORIGEM? ";
getline(cin,origem);
cout << origem;
for (i = 0; i < 31; i++){
 if(origem == lugares[i]){
  cout << "\nDestino? ";
  cin >> destino;
 }
 else{
  cout << "\nErro, tente novamente!" << endl;
 }
}


}
#include <iostream>
#include <string>
using namespace std;

void destinos();
void mostrar_nome();
void escolher_lugar();
string nomes[30], lugares[30], origem, destino;

int main() {
  setlocale(LC_ALL, "Portuguese_Brazil");
 
 cout << "\n    PRA ONDE VAMOS? ";
 cout << "\n    Mais de 30 lugares para voc� escolher!" << endl;
 cout << endl;
 mostrar_nome();

 return 0;
}

void destinos(){
setlocale(LC_ALL, "Portuguese_Brazil");
lugares[0] = "Rio de Janeiro", "rio de janeiro";
lugares[1] = "S�O Paulo", "s�o paulo", "Sao Paulo", "sao paulo";
lugares[2] = "Bel�m", "Belem", "belem", "bel�m";
lugares[3] = "Bras�lia", "Brasilia", "brasilia", "bras�lia";
lugares[4] = "Cuiab�", "Cuiaba", "cuiab�", "cuiaba",
lugares[5] = "Curitiba", "curitida";
lugares[6] =  "Miami", "miami";
lugares[7] = "Fort Lauderdale", "fort lauderdale";
lugares[8] = "Florian�polis", "Florianopolis","floarianopolis";
lugares[9] = "Foartaleza", "fortaleza";
lugares[10] = "Goi�nia", "Goiania", "goiania";
lugares[11] = "Lisboa", "lisboa";
lugares[12] = "Manaus", "manaus";
lugares[13] = "Orlando", "orlando";
lugares[14] = "Carrasco" "carrasco";
lugares[15] = "Paris", "paris";
lugares[16] = "Porto Alegre", "Porto alegre", "porto alegre";
lugares[17] = "Porto Velho", "Porto velho", "porto velho";
lugares[18] = "Recife", "recife";
lugares[19] = "Santos Dumont"; "Santos dumont", "santos dumont";
lugares[20] = "S�o Lu�z"; "s�o lu�z", "sao luiz";
lugares[21] = "Vit�ria", "vit�ria", "vitoria";
lugares[22] = "M�laga", "malaga", "m�laga";
lugares[23] = "Aracaju", "aracaju";
lugares[24] = "Barcelona", "barcelona";
lugares[25] = "Jo�o Pessoa", "Joao Pessoa", "joao pessoa", "jo�o pessoa";
lugares[26] = "Los Angeles", "los angeles", "Los angeles";
lugares[27] = "New York", "new york";
lugares[28] = "Alemanha", "alemanha"; 
lugares[29] = "Argentina","argentina";
lugares[30] = "Fran�a", "fran�a", "franca";
lugares[31] = "Dubai", "dubai";
}

void mostrar_nome(){
nomes[0] = "Rio de Janeiro";
nomes[1] = "S�o Paulo";
nomes[2] = "Bel�m";
nomes[3] = "Bras�lia";
nomes[4] = "Cuiab�";
nomes[5] = "Curitiba";
nomes[6] = "Miami";
nomes[7] = "Fort Lauderdale";
nomes[8] = "Florian�polis";
nomes[9] = "Foartaleza";
nomes[10] = "Goi�nia";
nomes[11] = "Lisboa";
nomes[12] = "Manaus";
nomes[13] = "Orlando";
nomes[14] = "Carrasco";
nomes[15] = "Paris";
nomes[16] = "Porto Alegre";
nomes[17] = "Porto Velho";
nomes[18] = "Recife";
nomes[19] = "Santos Dumont";
nomes[20] = "S�o Lu�z";
nomes[21] = "Vit�ria";
nomes[22] = "M�laga";
nomes[23] = "Aracaju";
nomes[24] = "Barcelona";
nomes[25] = "Jo�o Pessoa";
nomes[26] = "Los Angeles";
nomes[27] = "New York";
nomes[28] = "Alemanha";
nomes[29] = "Argentina";
nomes[30] = "Fran�a";
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
int i;
cout << endl;
cout << endl;
cout << "Origem? ";
cin >> origem;
for (i = 0; i < 31; i++){
 if(origem == lugares[i]){
  cout << "Destino? ";
  cin >> destino;
 }
}


}
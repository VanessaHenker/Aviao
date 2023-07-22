#include <iostream>
#include <string>
using namespace std;

string lugares[30], origem;

int main() {
  setlocale(LC_ALL, "Portuguese_Brazil");
 
 cout << "Origem? ";
 cin >> origem;
    
    return 0;
}

void destinos(){
setlocale(LC_ALL, "Portuguese_Brazil");
lugares[0] = "Rio de Janeiro", "rio de janeiro";
lugares[1] = "SÃO Paulo", "são paulo", "Sao Paulo", "sao paulo";
lugares[2] = "Belém", "Belem", "belem", "belém";
lugares[3] = "Brasília", "Brasilia", "brasilia", "brasília";
lugares[4] = "Cuiabá", "Cuiaba", "cuiabá", "cuiaba",
lugares[5] = "Curitiba", "curitida";
lugares[6] =  "Miami", "miami";
lugares[7] = "Fort Lauderdale", "fort lauderdale";
lugares[8] = "Florianópolis", "Florianopolis","floarianopolis";
}
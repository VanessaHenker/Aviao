#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <locale.h>
#include <chrono>
using namespace std;

void mostrar_nome();
void calendario();
void escolher_lugar();
void escolher_passagem();
void escolha_dia();
void horario();
void opcao_selec();
// variáveis pra escolher o lugar
int origem, destino, escolha_mes, escolha_lugar, opcao_lugar;
string lugares[31], name_month[13];
char destino_dnv;
// variáveis da função calandario
int day, month, year, option;
// variáveis pra escolher passagem
int qtd_pass[3], escolherPass, compra_pass, opcao_dia;

void printCalendar(int year, int month){
  // Criar uma estrutura tm com a data do primeiro dia do mês
  std::tm timeinfo = {};
  timeinfo.tm_year = year - 1900; // tm_year é o número de anos desde 1900
  timeinfo.tm_mon = month - 1;    // tm_mon é base 0 (janeiro é representado por 0)
  timeinfo.tm_mday = 1;
  std::mktime(&timeinfo);

  // Obter o número de dias no mês atual
  int daysInMonth;
  if (month == 2){
    // Verificar se é um ano bissexto (fevereiro tem 29 dias em anos bissextos)
    daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11){
    daysInMonth = 30;
  }
  else{
    daysInMonth = 31;
  }

  // Imprimir o cabeçalho do calendário
  std::cout << "  " << std::setw(11) << std::left << "DOM SEG TER QUA QUI SEX SAB" << std::endl;

  // Imprimir os espaços iniciais para alinhar o primeiro dia do mês
  for (int i = 0; i < timeinfo.tm_wday; ++i){
    std::cout << "    ";
  }

  // Imprimir os dias do mês
  for (int day = 1; day <= daysInMonth; ++day){
    std::cout << std::setw(4) << std::right << day;

    if ((timeinfo.tm_wday + day) % 7 == 0){
      std::cout << std::endl;
    }
  }

  std::cout << std::endl;
}
int main(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  horario();
  cout << "\nPRA ONDE VAMOS? ";
  cout << "\nMais de 30 lugares para você escolher!" << endl;
  cout << endl;
  mostrar_nome();
  escolher_lugar();
  escolher_passagem();
  return 0;
}

void mostrar_nome(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i = 0;
  lugares[0] = "RIO- Rio de Janeiro";
  lugares[1] = "CGH- São Paulo";
  lugares[2] = "BEL- Belém";
  lugares[3] = "BSB- Brasília";
  lugares[4] = "CGB- Cuiabá";
  lugares[5] = "CWB- Curitiba";
  lugares[6] = "FLL- Miami";
  lugares[7] = "FLL- Fort Lauderdale";
  lugares[8] = "FLN- Florianópolis";
  lugares[9] = "FOR- Foartaleza";
  lugares[10] = "GYN- Goiânia";
  lugares[11] = "LIS- Lisboa";
  lugares[12] = "MAO- Manaus";
  lugares[13] = "MCO- Orlando,FL";
  lugares[14] = "MVD- Carrasco";
  lugares[15] = "PAR- Paris";
  lugares[16] = "POA- Porto Alegre";
  lugares[17] = "PVH- Porto Velho";
  lugares[18] = "REC- Recife";
  lugares[19] = "SDU- Santos Dumont";
  lugares[20] = "SLZ- São Luíz";
  lugares[21] = "VIX- Vitória";
  lugares[22] = "AGP- Málaga";
  lugares[23] = "AJU- Aracaju";
  lugares[24] = "BCN- Barcelona";
  lugares[25] = "JPA- João Pessoa";
  lugares[26] = "LAX- Los Angeles, CA";
  lugares[27] = "JFK- New York";
  lugares[28] = "AJU- Sergipe";
  lugares[29] = "SSA- Salvador";
  lugares[30] = "BVB- Boa Vista";
  lugares[31] = "CFB- Cabo Frio";
  opcao_lugar = 3;

  while (opcao_lugar != 2){
    opcao_lugar = 0;
    while (opcao_lugar == 0){
      i = 0;
      for (i < 0; i <= 10; i++){
        cout << "[" << i << "] " << lugares[i] << endl;
      }
      cout << endl;
      cout << " 0- Anterior, 1- Próximo, 2- Sair" << endl;
      cin >> opcao_lugar;

      if (opcao_lugar == 1){
        for (i < 10; i <= 20; i++){
          cout << "[" << i << "] " << lugares[i] << endl;
        }
        cout << endl;
        cout << " 0- Anterior, 1- Próximo, 2- Sair" << endl;
        cin >> opcao_lugar;
      }
      if (opcao_lugar == 1){
        for (i < 20; i <= 30; i++){
          cout << "[" << i << "] " << lugares[i] << endl;
        }
        cout << endl;
        cout << " 0- Anterior, 1- Próximo, 2- Sair" << endl;
        cin >> opcao_lugar;
      }
    }
  }
}
void escolher_lugar(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i;
  i = 0;
  origem = 32;
  destino = 0;
  destino_dnv = 's';
  while (origem < 0 || origem > 31){
    cout << "\nORIGEM? ";
    cin >> origem;
    switch (origem){
    case 0:
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
      cout << "\nDESTINO? ";
      cin >> destino;
      if (destino == origem){
        while (destino == origem && destino_dnv == 's' || destino_dnv == 'S'){
          cout << "\nErro, você já selecionou " << lugares[origem] << " como origem!" << endl;
          cout << "\nSe deseja escolher outro destino ";
          cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
          cin >> destino_dnv;
          if (destino_dnv == 's' || destino_dnv == 'S'){
            cout << "\nDESTINO? ";
            cin >> destino;
          }
          if (destino_dnv == 'n' || destino_dnv == 'N'){
            main();
          }
        }
      }
      break;
    default:
      cout << "\nErro, tente novamente!" << endl;
      break;
    }
  }
  if (destino != origem){
    opcao_selec();
    cout << endl;
    cout << "\n0- Anterior, 1- Próximo" << endl;
    cin >> opcao_lugar;
    if (opcao_lugar == 0){
      mostrar_nome();
      escolher_lugar();
      calendario();
    }
    else{
      calendario();
    }
  }
}
void calendario(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  name_month[0] = "Janeiro";
  name_month[1] = "Janeiro";
  name_month[2] = "Fevereiro";
  name_month[3] = "Março";
  name_month[4] = "Abril";
  name_month[5] = "Maio";
  name_month[6] = "Junho";
  name_month[7] = "Julho";
  name_month[8] = "Agosto";
  name_month[9] = "Setembro";
  name_month[10] = "Outubro";
  name_month[11] = "Novembro";
  name_month[12] = "Dezembro";
  // Obter o horário atual do sistema
  std::time_t currentTime = std::time(nullptr);

  // Converter para uma estrutura tm (hora local)
  std::tm *localTime = std::localtime(&currentTime);

  // Extrair o mês e o ano atual
  day = 27;
  month = localTime->tm_mon + 1;    // tm_mon é base 0 (janeiro é representado por 0)
  year = localTime->tm_year + 1900; // tm_year é o número de anos desde 1900

  option = 3;
  cout << endl;
  while (option != 2){
    if (year < 2025 && month >= 7 || year == 2024 && month >= 1){
      // Exibir o calendário do mês atual
      cout << "\n------------------------------";
      cout << "\n       DATA DAS VIAGENS";
      cout << "\n------------------------------";
      std::cout << "\n        " << name_month[month] << "       " << month << "/" << year << std::endl;
      printCalendar(year, month);

      // Pedir ao usuário para navegar para o mês seguinte ou anterior
      std::cout << " 0- Anterior, 1- Próximo, 2- Sair" << std::endl;
      std::cin >> option;

      if (option == 1){
        if (month == 12 && option == 1 && year == 2024){
          month = 12;
        }
        else{
          month++;
        }
        if (month > 12){
          month = 1;
          year++;
        }
      }
      else if (option == 0){
        if (month <= 7 && option == 0 && year == 2023){
          month = 7;
        }
        else{
          month--;
        }
        if (month < 1){
          month = 12;
          year--;
        }
      }
    }
  }
  escolha_dia();
}
void escolha_dia(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  opcao_dia = 32;
  while (opcao_dia > 31 || opcao_dia < 1){
    if (option == 2){
      cout << "\nDigite o dia: ";
      cin >> opcao_dia;
      switch (opcao_dia){
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
        cout << "DATA SELECIONADA: " << opcao_dia << "/" << month << "/" << year;
        break;
      case 29:
        if (month == 2 && opcao_dia == 28 || opcao_dia == 29){
          cout << "DATA SELECIONADA: " << opcao_dia << "/" << month << "/" << year;
        }
        break;
      case 30:
        if (opcao_dia == 30 && month == 4 || month == 6 || month == 9 || month == 11){
          cout << "DATA SELECIONADA: " << opcao_dia << "/" << month << "/" << year;
       }
        break;
      case 31:
        if (opcao_dia == 31 && month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
          cout << "DATA SELECIONADA: " << opcao_dia << "/" << month << "/" << year;
        }
        break;
        if (opcao_dia > 31 || opcao_dia < 1){
          cout << "DATA SELECIONADA: " << opcao_dia << "/" << month << "/" << year;
        }
      }
    }
    if (month == 2 && opcao_dia == 31 || opcao_dia == 31 && month == 4 || opcao_dia == 31 && month == 6 || opcao_dia == 31 && month == 9 || opcao_dia == 31 && month == 11){
      escolha_dia();
    }
    if (month == 2 && opcao_dia > 29){
      escolha_dia();
    }
  }
}
void escolher_passagem(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i = 0;
  for (i = 0; i < 3; i++){
    qtd_pass[i] = 0;
  }
  opcao_selec();
  cout << "\nViajante" << endl;
  cout << "[0]Adulto: A partir de 12 anos" << endl;
  cout << "[1]Criança: 2 a 11 anos" << endl;
  cout << "[2]Bebê: de 0 a 23 meses" << endl;

  cout << "\nDigite o numero: ";
  cin >> escolherPass;
  switch (escolherPass){
  case 0:
    cout << "[" << qtd_pass[0] << "]";
    cout << "\nQuantidade: ";
    cin >> compra_pass;
    break;
  case 1:
    cout << "[" << qtd_pass[1] << "]";
    cout << "\nQuantidade: ";
    cin >> compra_pass;
    break;
  case 2:
    cout << "[" << qtd_pass[2] << "]";
    cout << "\nQuantidade: ";
    cin >> compra_pass;
    break;
  default:
    cout << "\nErro, tente novamente!";
    break;
  }
}

void horario(){
  // Obter o tempo atual
  auto tempoAtu = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // Converter o tempo em uma struct tm
  std::tm* dataHoraAtual = std::localtime(&tempoAtu);
  // Obter o dia do mês atual
  int diaAtual = dataHoraAtual->tm_mday;
  // Obter o horário atual do sistema
  std::time_t currentTime = std::time(nullptr);
  // Converter para uma estrutura tm (hora local)
  std::tm *localTime = std::localtime(&currentTime);
  int month = localTime->tm_mon + 1;   
  int year = localTime->tm_year + 1900;
  // Imprimir o dia atual
  std::cout << "DATA: " << diaAtual  << "/" << month << "/" << year << std::endl;
    
  // Obtendo o tempo atual em segundos desde a epoch
  std::time_t tempoAtual = std::time(nullptr);
  // Convertendo o valor do tempo para uma estrutura tm
  std::tm *horaAtual = std::localtime(&tempoAtual);
  // Mostrando o horário atual
 std::cout << "Horario: " << horaAtual->tm_hour << ":" << horaAtual->tm_min << std::endl;

}
void opcao_selec(){
 setlocale(LC_ALL, "Portuguese_Brazil");
  cout << endl;
  if (origem && destino >= 0){
    cout << "\nORIGEM: " << lugares[origem];
    cout << "\nDESTINO: " << lugares[destino];
  }
  if (opcao_dia > 0 && month > 0 && year >= 2023){
    cout << "\nDATA: " << opcao_dia << "/" << month << "/" << year << endl;
  } 
}                             
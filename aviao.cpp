#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <locale.h>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;

void mostrar_nome();
void calendario_ida();
void calendario_volta();
void escolher_lugar();
void escolher_passagem();
void escolha_dia_ida();
void escolha_dia_volta();
void horario();
void opcao_selec();
void pass_ida_volta();
void horario_voo();
void escolha_horario();
void dados_viajante();
void tchau_cases(string local_atual);
// variáveis pra escolher o lugar
int opc_orig, opc_dest, origem_ida, dest_ida, orig_volta, dest_volta, escolha_mes, escolha_lugar, opcao_lugar;
string lugares[31], name_month[13];
char destino_dnv;
// variáveis da função calandario
int daysInMonth, month, year, option, current_month, diaAtual, current_year, month_next, month_back, year_next, year_back, selec_pass, pass_dnv;
char pass_volta;
// variáveis pra escolher passagem
int qtd_pass[3], escolherPass, guarda_pass, opc_ida, opc_volta, horario_pass;

// Rio de Janeiro
struct RJ{
  std::string time;
  float priceTime;

  RJ(const std::string &t, const float &price)
    : time(t), priceTime(price) {}
};
// São Paulo
struct SP{
  std::string time;
  float priceTime;
  
  SP(const std::string &t, const float &price)
    : time(t), priceTime(price) {}
};
// Belém
struct PA{
  std::string time;
  float priceTime;

  PA(const std::string &t, const float &price)
  : time(t), priceTime(price){}
};
// Brasília
struct BSB{
  std::string time;
  float priceTime;
  
  BSB(const std::string &t, const float &price)
  : time(t), priceTime(price){}
};
// Cuiabá
struct MT{
  std::string time;
  float priceTime;
  
  MT(const std::string &t, const float &price)
  : time(t), priceTime(price){}
};
// Curitiba
struct PR{
  std::string time;
  float priceTime;
  
  PR(const std::string &t, const float &price)
  : time(t), priceTime(price){}
};
// Miami
struct MIA{
  std::string time;
  float priceTime;
  
  MIA(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Fort Lauderdale
struct FLL{
  std::string time;
  float priceTime;
  
  FLL(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Florianópolis 
struct SC{
  std::string time;
  float priceTime;
  
  SC(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Fortaleza
struct CE{
  std::string time;
  float priceTime;
  
  CE(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Goiânia
struct GYN{
  std::string time;
  float priceTime;
  
  GYN(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Lisboa
struct LX{
  std::string time;
  float priceTime;
  
  LX(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Manaus
struct AM{
  std::string time;
  float priceTime;
  
  AM(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Orlando
struct MCO{
  std::string time;
  float priceTime;
  
  MCO(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Carrasco
struct MVD{
  std::string time;
  float priceTime;
  
  MVD(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// París
struct PAR{
  std::string time;
  float priceTime;
  
  PAR(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Porto Alegre
struct POA{
  std::string time;
  float priceTime;
  
  POA(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Porto Velho
struct RO{
  std::string time;
  float priceTime;
  
  RO(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Recife
struct PE{
  std::string time;
  float priceTime;
  
  PE(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Santos Dumont
struct SDU{
  std::string time;
  float priceTime;
  
  SDU(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// São Luíz
struct MA{
  std::string time;
  float priceTime;
  
  MA(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Vitória
struct VIX{
  std::string time;
  float priceTime;
  
  VIX(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Málaga
struct AGP{
  std::string time;
  float priceTime;
  
  AGP(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Aracaju
struct AJU{
  std::string time;
  float priceTime;
  
  AJU(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Barcelona
struct BCN{
  std::string time;
  float priceTime;
  
  BCN(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// João Pessoa
struct PB{
  std::string time;
  float priceTime;
  
  PB(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Los Angeles
struct LA{
  std::string time;
  float priceTime;
  
  LA(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// New York
struct NY{
  std::string time;
  float priceTime;
  
  NY(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Sergipe
struct SE{
  std::string time;
  float priceTime;
  
  SE(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Salvador
struct SSA{
  std::string time;
  float priceTime;
  
  SSA(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Boa Vista
struct BVB{
  std::string time;
  float priceTime;
  
  BVB(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Cabo Frio
struct CFB{
  std::string time;
  float priceTime;
  
  CFB(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
//CPF viajantes
/*struct CPF{
  std::string cpf_vj, name, surname, birth, gender;
  CPF(const std::string &c, const std::string &n, const std::string &s, const std::string &b, const std::string &g)
    : cpf_vj(c), name(n), surname(s), birth(b), gender(g){}
}; */

struct CPF{
  string cpf_vj, name, surname, birth, gender;
};
void printCalendar(int year, int month){
  // Criar uma estrutura tm com a data do primeiro dia do mês
  std::tm timeinfo = {};
  timeinfo.tm_year = year - 1900; // tm_year é o número de anos desde 1900
  timeinfo.tm_mon = month - 1;    // tm_mon é base 0 (janeiro é representado por 0)
  timeinfo.tm_mday = 1;
  std::mktime(&timeinfo);

  // Obter o número de dias no mês atual
  daysInMonth;
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
  int x = 0;
  //while(x == 0){
  //dados_viajante();
  //}
  horario();
  cout << "\nPRA ONDE VAMOS? ";
  cout << "\nMais de 30 lugares para você escolher!" << endl;
  cout << endl;
  mostrar_nome();
  escolher_lugar();
  escolher_passagem();
  escolha_horario();
  
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
      opcao_lugar = 3;
      while (opcao_lugar != 0 && opcao_lugar != 1 && opcao_lugar != 2){
        cout << endl;
        cout << " 0- Anterior, 1- Próximo, 2- Sair" << endl;
        cin >> opcao_lugar;
      }
      if (opcao_lugar == 1){
        for (i < 10; i <= 20; i++){
          cout << "[" << i << "] " << lugares[i] << endl;
        }
        opcao_lugar = 3;
        while (opcao_lugar != 0 && opcao_lugar != 1 && opcao_lugar != 2){
          cout << endl;
          cout << " 0- Anterior, 1- Próximo, 2- Sair" << endl;
          cin >> opcao_lugar;
        }
      }
      if (opcao_lugar == 1){
        for (i < 20; i <= 31; i++){
          cout << "[" << i << "] " << lugares[i] << endl;
        }
        opcao_lugar = 3;
        while (opcao_lugar != 0 && opcao_lugar != 1 && opcao_lugar != 2){
          cout << endl;
          cout << " 0- Anterior, 1- Próximo, 2- Sair" << endl;
          cin >> opcao_lugar;
        }
      }
    }
  }
}

  void tchau_cases(string local_atual){
    for (size_t i = 0; i < local_atual.size(); ++i){
      std::cout << "[" << i << "] " << local_atual[i].time << " - " << "R$" << local_atual[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= local_atual.size()){
        cout << endl;
        cout << local_atual[horario_pass].time << " - " << local_atual[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > local_atual.size());
    return 
  }

void escolher_lugar(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i;
  i = 0;
  opc_orig = 32;
  opc_dest = 0;
  destino_dnv = 's';
    while (opc_orig < 0 || opc_orig > 31){
    cout << "\nORIGEM? ";
    cin >> opc_orig;
    if(pass_volta == 's' || pass_volta == 'S'){
    orig_volta = opc_orig;
    }
    else{
    origem_ida = opc_orig;
    }
   switch (opc_orig){
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
      cin >> opc_dest;
      if (opc_dest == opc_orig){
        destino_dnv = 't';
        while (opc_dest == opc_orig || destino_dnv == 's' && destino_dnv != 's' && destino_dnv != 'S' && destino_dnv != 'N' && destino_dnv != 'n'){
          cout << "\nErro, você já selecionou " << lugares[opc_orig] << " como origem!" << endl;
          cout << "\nSe deseja escolher outro destino";
          cout << "\nDigite 'S' para SIM ou 'N' para NÂO: ";
          cin >> destino_dnv;
          if (destino_dnv == 's' || destino_dnv == 'S'){
            cout << "\nDESTINO? ";
            cin >> opc_dest;
          }
          if (destino_dnv == 'n' || destino_dnv == 'N'){
            main();
          }
        }
      }
    if(pass_volta == 's' || pass_volta == 'S'){
    dest_volta = opc_dest;
    }
    else{
    dest_ida = opc_dest;
    }
      break;
    default:
      cout << "\nErro, tente novamente!" << endl;
      break;
    }
  }
  if (opc_dest != opc_orig && pass_volta != 's' && pass_volta != 'S'){
    opcao_selec();
    cout << endl;
    cout << "\n0- Alterar origem/destino" << endl;
    cout << "1- Selecionar dia de ida" << endl;
    cout << "\n0- Anterior, 1- Próximo" << endl;
    cin >> opcao_lugar;
    if (opcao_lugar == 0){
      mostrar_nome();
      escolher_lugar();
      calendario_ida();
      escolha_dia_ida();
      pass_ida_volta();
      escolha_dia_volta();
    }
    else{
      calendario_ida();
      escolha_dia_ida();
      pass_ida_volta();
    }
  }
}
void calendario_ida(){
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
  month = localTime->tm_mon + 1;    // tm_mon é base 0 (janeiro é representado por 0)
  year = localTime->tm_year + 1900; // tm_year é o número de anos desde 1900
  // Mês e ano atual
  current_month = localTime->tm_mon + 1; 
  current_year =  localTime->tm_year + 1900; 
  
  option = 3;
  cout << endl;
  while (option != 2){
    if (year < 2025 && month >= current_month || year == 2024 && month <= 12){
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
        if (month <= current_month && option == 0 && year == 2023){
          month = current_month;
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
}
void pass_ida_volta(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  selec_pass = 1;
  while (selec_pass == 1){
    if (option == 2){
    cout << endl;
    cout << "0- Alterar data de ida" << endl;
    cout << "1- Passagem de volta" << endl;
    cout << "2- Dados viajante" << endl;
    cout << "\n 0- Anterior, 1- Próximo, 2- Sair" << endl;
    cin >> selec_pass;
    if (selec_pass == 0){
      calendario_ida();
      escolha_dia_ida();
     }
     if (selec_pass == 1){
        orig_volta = dest_ida;
        dest_volta = origem_ida;
        month_back = month_next;
        year_back = year_next; 
        cout << "\nORIGEM: " << lugares[orig_volta];
        cout << "\nDESTINO: " << lugares[dest_volta];
        cout << endl;
        pass_volta = 't';
        while(pass_volta != 's' && pass_volta != 'S' && pass_volta != 'n' && pass_volta != 'N'){
        cout << "\nSe deseja trocar origem e destino";
        cout << "\nDigite 's' para 'SIM' ou 'N' para 'NÂO': ";
        cin >> pass_volta;
        }
        if (pass_volta == 's' || pass_volta == 'S'){
          mostrar_nome();
          escolher_lugar();
          opcao_selec();
          calendario_volta();
          escolha_dia_volta();
        }
        if (pass_volta == 'n' || pass_volta == 'N'){
          opcao_selec();
          calendario_volta();
          escolha_dia_volta();
        }
        selec_pass = 3;
        while(selec_pass != 2){ 
          cout << endl;
          cout << "0- Alterar data de volta" << endl;
          cout << "1- Alterar data de ida" << endl;
          cout << "2- Dados viajante" << endl;
          cout << "\n 0- Anterior, 1- Próximo, 2- Sair" << endl;
          cin >> selec_pass;
        if (selec_pass == 0){
            month_back = month_next;
            year_back = year_next; 
            calendario_volta();
            escolha_dia_volta();
          }
        }
        if (selec_pass == 2){
          dados_viajante();
        }
      }
    }
  }
}
void calendario_volta(){
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
  month = localTime->tm_mon + 1;    // tm_mon é base 0 (janeiro é representado por 0)
  year = localTime->tm_year + 1900; // tm_year é o número de anos desde 1900
  // Mês e ano atual
  current_month = localTime->tm_mon + 1; 
  current_year =  localTime->tm_year + 1900; 
  
  option = 3;
  cout << endl;
  while (option != 2){
    if (year_back >= year_next){
      // Exibir o calendário do mês atual
      cout << "\n------------------------------";
      cout << "\n       DATA DAS VIAGENS";
      cout << "\n------------------------------";
      std::cout << "\n        " << name_month[month_back] << "       " << month_back << "/" << year_back << std::endl;
      printCalendar(year, month);

      // Pedir ao usuário para navegar para o mês seguinte ou anterior
      cout << "\n  Data de ida: " << opc_ida << "/" << month_next << "/" << year_next << endl;
      std::cout << "\n 0- Anterior, 1- Próximo, 2- Sair" << std::endl;
      std::cin >> option;
      if (option == 1){
        if (month_back == 12 && option == 1 && year_back == 2024){
          month_back = 12;
        }
        else{
          month_back++;
        }
        if (month_back > 12){
          month_back = 1;
          year_back++;
        }
      }
      else if (option == 0){
        if (month_back <= month_next && option == 0 && year_back == year_next){
          month_back = month_next;
          
        }
        else{
          month_back--;
        }
        if (month_back < 1){
          month_back = 12;
          year_back--;
        }
      }
    }
  }
}
void escolha_dia_ida(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  opc_ida = 32;
  opc_ida = 32;
  month_next = month;
  year_next = year; 
 while (opc_ida > daysInMonth || opc_ida < 1 || opc_ida < diaAtual && month == current_month){
    if (option == 2){
      do{
      cout << "\nDigite o dia: ";
      cin >> opc_ida;
      if (opc_ida < diaAtual && month == current_month){
        cout << "\nErro, estamos no dia: " << diaAtual << "/" << current_month << "/" << current_year << endl;
      }
    }while(opc_ida < diaAtual && month == current_month);
      switch (opc_ida){
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
      if (opc_ida >= diaAtual && month >= current_month && opc_ida <= daysInMonth && year <= current_year || opc_ida <= diaAtual && month >= current_month && opc_ida <= daysInMonth && year <= current_year){
          cout << "\nDATA SELECIONADA: " << opc_ida << "/" << month_next << "/" << year_next << "(IDA)" << endl;
        }
      if(opc_ida <= daysInMonth && year > current_year){
          cout << "\nDATA SELECIONADA: " << opc_ida << "/" << month_next << "/" << year_next << "(IDA)" << endl;
        }
        break;
      default:
        cout << "\nErro, tente novamente!" << endl;
        break; 
      }
    }
  }
}
void escolha_dia_volta(){
setlocale(LC_ALL, "Portuguese_Brazil");
  if (option == 2){
     do{ 
      cout << "\nDigite o dia: ";
      cin >> opc_volta;
    if (opc_volta < opc_ida && month_back <= month_next && year_back <= year_next){
        cout << "\nErro! Data de ida: " << opc_ida << "/" << month_next << "/" << year_next << endl;
        calendario_volta();
      }
    }while (opc_volta < opc_ida && month_back <= month_next && year_back <= year_next);
    switch (opc_volta){
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
      if (opc_volta >= opc_ida || opc_volta <= opc_ida && month_back >= month_next && opc_volta <= daysInMonth && year_back >= year_next){
          cout << "\nDATA SELECIONADA: " << opc_volta << "/" << month_back << "/" << year_back << "(VOLTA)" << endl;
        }
        break;
      default:
        cout << "\nErro, tente novamente!" << endl;
        break; 
      }
    }
  }
void escolher_passagem(){
setlocale(LC_ALL, "Portuguese_Brazil");
int i = 0;
pass_dnv = 0;
for (i = 0; i < 3; i++){
  qtd_pass[i] = 0;
}
opcao_selec();
while (pass_dnv == 0 || qtd_pass[0] == 0 && pass_dnv == 1){
  guarda_pass = 0;
  cout << "\nViajante" << endl;
  cout << "[0]Adulto: A partir de 12 anos" << endl;
  cout << "[1]Criança: 2 a 11 anos" << endl;
  cout << "[2]Bebê: de 0 a 23 meses" << endl;

  cout << "\nDigite o numero: ";
  cin >> escolherPass;
  switch (escolherPass){
  case 0:
    cout << "[" << qtd_pass[0] << "]QTD";
    cout << "\nQuantidade: ";
    cin >> guarda_pass;
    qtd_pass[0] = qtd_pass[0] + guarda_pass;
    break;
  case 1:
    cout << "[" << qtd_pass[1] << "]QTD";
    cout << "\nQuantidade: ";
    cin >> guarda_pass;
    qtd_pass[1] = qtd_pass[1] + guarda_pass;
    break;
  case 2:
    cout << "[" << qtd_pass[2] << "]QTD";
    cout << "\nQuantidade: ";
    cin >> guarda_pass;
    qtd_pass[2] = qtd_pass[2] + guarda_pass;
    break;
  default:
    cout << "\nErro, tente novamente!";
    break;
  }
  cout << "\n0- Anterior, 1- Próximo" << endl;
  cin >> pass_dnv;
  if (qtd_pass[0] == 0 && pass_dnv == 1){
    cout << "\nÉ necessário no minímo 1 passagem de adulto!";
    }
  }
}
void horario(){
  // Obter o tempo atual
  auto tempoAtu = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // Converter o tempo em uma struct tm
  std::tm* dataHoraAtual = std::localtime(&tempoAtu);
  // Obter o dia do mês atual
  diaAtual = dataHoraAtual->tm_mday;
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
  std::cout << "Horário: " << horaAtual->tm_hour << ":" << horaAtual->tm_min << std::endl;
}
void opcao_selec(){
 setlocale(LC_ALL, "Portuguese_Brazil");
  int i = 0;
  string nomes[3];
  nomes[0] = "ORIGEM: ";
  nomes[1] = "DESTINO: ";
  nomes[2] = "DATA SELECIONADA: ";
  
  cout << endl;
  cout << "------------------------------------------------" << endl;
  cout << "PASSAGEM IDA!" << endl;
  cout << nomes[0] << lugares[origem_ida] << endl;
  cout << nomes[1] << lugares[dest_ida] << endl;
  if (opc_ida <= 0){
    cout << "------------------------------------------------";
  }
  else{
    cout << nomes[2] << opc_ida << "/" << month_next << "/" << year_next << endl;
    cout << "------------------------------------------------";
  }
  if (pass_volta == 's' || pass_volta == 'S' || pass_volta == 'n' || pass_volta == 'N'){
    cout << "\nPASSAGEM VOLTA!" << endl;
    cout << nomes[0] << lugares[orig_volta] << endl;
    cout << nomes[1] << lugares[dest_volta] << endl;
  if (opc_volta <= 0){
    cout << "\n------------------------------------------------";
  }
  else{
    cout << nomes[2] << opc_volta << "/" << month_back << "/" << year_back << endl;
    cout << "------------------------------------------------";
    }
  }
}                             
void escolha_horario(){
setlocale(LC_ALL, "Portuguese_Brazil");
cout << "\nData de ida: " << opc_ida << "/" << month_next << "/" << year_next << endl;
cout << lugares[origem_ida] << " -> " << lugares[dest_ida] << endl;
cout << endl;
horario_voo();

}

void horario_voo(){
setlocale(LC_ALL, "Portuguese_Brazil");
  std::vector<RJ> rj;
  rj.push_back(RJ("06:45", 200.75));
  rj.push_back(RJ("10:00", 200.75));
  rj.push_back(RJ("12:00", 200.75));
  rj.push_back(RJ("14:30", 200.75));
  rj.push_back(RJ("20:00", 200.75));
  rj.push_back(RJ("21:30", 200.75));

  std::vector<SP> sp;
  sp.push_back(SP("07:45", 230.50));
  sp.push_back(SP("08:00", 230.50));
  sp.push_back(SP("13:30", 230.50));
  sp.push_back(SP("14:30", 230.50));
  sp.push_back(SP("20:00", 230.50));
  sp.push_back(SP("21:50", 230.50));

  std::vector<PA> pa;
  pa.push_back(PA("04:45", 230.80));
  pa.push_back(PA("05:50", 230.80));
  pa.push_back(PA("13:30", 230.80));
  pa.push_back(PA("14:30", 230.80));
  pa.push_back(PA("17:00", 230.80));
  pa.push_back(PA("20:20", 230.80));

  std::vector<BSB> bsb;
  bsb.push_back(BSB("05:45", 215.80));
  bsb.push_back(BSB("07:50", 215.80));
  bsb.push_back(BSB("13:45", 215.80));
  bsb.push_back(BSB("14:20", 215.80));
  bsb.push_back(BSB("16:40", 215.80));
  bsb.push_back(BSB("21:20", 215.80));

  std::vector<MT> mt;
  mt.push_back(MT("05:45", 215.80));
  mt.push_back(MT("06:50", 215.80));
  mt.push_back(MT("09:45", 215.80));
  mt.push_back(MT("14:20", 215.80));
  mt.push_back(MT("17:40", 215.80));
  mt.push_back(MT("19:20", 215.80));

  std::vector<PR> pr;
  pr.push_back(PR("06:45", 215.80));
  pr.push_back(PR("08:30", 215.80));
  pr.push_back(PR("10:45", 215.80));
  pr.push_back(PR("12:30", 215.80));
  pr.push_back(PR("17:45", 215.80));
  pr.push_back(PR("20:30", 215.80));

  std::vector<MIA> mia;
  mia.push_back(MIA("06:45", 200.75));
  mia.push_back(MIA("10:00", 200.75));
  mia.push_back(MIA("12:00", 200.75));
  mia.push_back(MIA("14:30", 200.75));
  mia.push_back(MIA("20:00", 200.75));
  mia.push_back(MIA("21:30", 200.75));

  std::vector<FLL> fll;
  fll.push_back(FLL("05:25", 220.80));
  fll.push_back(FLL("08:00", 220.80));
  fll.push_back(FLL("14:00", 220.80));
  fll.push_back(FLL("17:30", 220.80));
  fll.push_back(FLL("19:00", 220.80));
  fll.push_back(FLL("22:30", 220.80));

  std::vector<SC> sc;
  sc.push_back(SC("05:25", 225.80));
  sc.push_back(SC("08:00", 225.80));
  sc.push_back(SC("14:00", 225.80));
  sc.push_back(SC("17:30", 225.80));
  sc.push_back(SC("19:00", 225.80));
  sc.push_back(SC("22:30", 225.80));

  std::vector<CE> ce;
  ce.push_back(CE("07:25", 205.80));
  ce.push_back(CE("10:20", 205.80));
  ce.push_back(CE("14:55", 205.80));
  ce.push_back(CE("17:30", 205.80));
  ce.push_back(CE("19:00", 205.80));
  ce.push_back(CE("22:30", 205.80));

  std::vector<GYN> gyn;
  gyn.push_back(GYN("05:45", 215.80));
  gyn.push_back(GYN("06:50", 215.80));
  gyn.push_back(GYN("09:45", 215.80));
  gyn.push_back(GYN("14:20", 215.80));
  gyn.push_back(GYN("17:40", 215.80));
  gyn.push_back(GYN("19:20", 215.80));

  std::vector<LX> lx;
  lx.push_back(LX("04:45", 215.80));
  lx.push_back(LX("06:25", 215.80));
  lx.push_back(LX("10:45", 215.80));
  lx.push_back(LX("14:20", 215.80));
  lx.push_back(LX("18:40", 215.80));
  lx.push_back(LX("22:20", 215.80));

  std::vector<AM> am;
  am.push_back(AM("07:45", 230.50));
  am.push_back(AM("08:00", 230.50));
  am.push_back(AM("13:30", 230.50));
  am.push_back(AM("14:30", 230.50));
  am.push_back(AM("20:00", 230.50));
  am.push_back(AM("21:50", 230.50));

  std::vector<MCO> mco;
  mco.push_back(MCO("05:45", 215.80));
  mco.push_back(MCO("06:50", 215.80));
  mco.push_back(MCO("09:45", 215.80));
  mco.push_back(MCO("14:20", 215.80));
  mco.push_back(MCO("17:40", 215.80));
  mco.push_back(MCO("19:20", 215.80));

  std::vector<MVD> mvd;
  mvd.push_back(MVD("06:00", 250.80));
  mvd.push_back(MVD("08:50", 250.80));
  mvd.push_back(MVD("09:45", 250.80));
  mvd.push_back(MVD("14:20", 250.80));
  mvd.push_back(MVD("18:40", 250.80));
  mvd.push_back(MVD("21:34", 250.80));

  std::vector<PAR> par;
  par.push_back(PAR("07:25", 205.80));
  par.push_back(PAR("10:20", 205.80));
  par.push_back(PAR("14:55", 205.80));
  par.push_back(PAR("17:30", 205.80));
  par.push_back(PAR("19:00", 205.80));
  par.push_back(PAR("22:30", 205.80));

  std::vector<POA> poa;
  poa.push_back(POA("06:00", 210.65));
  poa.push_back(POA("08:50", 210.65));
  poa.push_back(POA("09:45", 210.65));
  poa.push_back(POA("14:20", 210.65));
  poa.push_back(POA("18:40", 210.65));
  poa.push_back(POA("21:34", 210.65));

  std::vector<RO> ro;
  ro.push_back(RO("07:25", 205.80));
  ro.push_back(RO("10:20", 205.80));
  ro.push_back(RO("14:55", 205.80));
  ro.push_back(RO("17:30", 205.80));
  ro.push_back(RO("19:00", 205.80));
  ro.push_back(RO("22:30", 205.80));

  std::vector<PE> pe;
  pe.push_back(PE("07:45", 230.50));
  pe.push_back(PE("08:00", 230.50));
  pe.push_back(PE("13:30", 230.50));
  pe.push_back(PE("14:30", 230.50));
  pe.push_back(PE("20:00", 230.50));
  pe.push_back(PE("21:50", 230.50));

  std::vector<SDU> sdu;
  sdu.push_back(SDU("06:45", 200.75));
  sdu.push_back(SDU("10:00", 200.75));
  sdu.push_back(SDU("12:00", 200.75));
  sdu.push_back(SDU("14:30", 200.75));
  sdu.push_back(SDU("20:00", 200.75));
  sdu.push_back(SDU("21:30", 200.75));

  std::vector<MA> ma;
  ma.push_back(MA("05:25", 225.60));
  ma.push_back(MA("08:00", 225.60));
  ma.push_back(MA("14:00", 225.60));
  ma.push_back(MA("17:30", 225.60));
  ma.push_back(MA("19:00", 225.60));
  ma.push_back(MA("22:30", 225.60));

  std::vector<VIX> vix;
  vix.push_back(VIX("06:45", 200.75));
  vix.push_back(VIX("10:00", 200.75));
  vix.push_back(VIX("12:25", 200.75));
  vix.push_back(VIX("14:35", 200.75));
  vix.push_back(VIX("20:00", 200.75));
  vix.push_back(VIX("21:00", 200.75));

  std::vector<AGP> agp;
  agp.push_back(AGP("07:45", 230.50));
  agp.push_back(AGP("08:00", 230.50));
  agp.push_back(AGP("13:30", 230.50));
  agp.push_back(AGP("14:30", 230.50));
  agp.push_back(AGP("20:00", 230.50));
  agp.push_back(AGP("21:50", 230.50));

  std::vector<AJU> aju;
  aju.push_back(AJU("07:45", 215.80));
  aju.push_back(AJU("09:00", 215.80));
  aju.push_back(AJU("12:15", 215.80));
  aju.push_back(AJU("15:45", 215.80));
  aju.push_back(AJU("18:40", 215.80));
  aju.push_back(AJU("23:30", 215.80));

  std::vector<BCN> bcn;
  bcn.push_back(BCN("04:45", 215.80));
  bcn.push_back(BCN("06:25", 215.80));
  bcn.push_back(BCN("10:45", 215.80));
  bcn.push_back(BCN("14:20", 215.80));
  bcn.push_back(BCN("18:40", 215.80));
  bcn.push_back(BCN("22:20", 215.80));

  std::vector<PB> pb;
  pb.push_back(PB("05:25", 220.45));
  pb.push_back(PB("08:00", 220.45));
  pb.push_back(PB("14:00", 220.45));
  pb.push_back(PB("17:30", 220.45));
  pb.push_back(PB("19:00", 220.45));
  pb.push_back(PB("22:30", 220.45));

  std::vector<LA> la;
  la.push_back(LA("05:45", 215.80));
  la.push_back(LA("06:50", 215.80));
  la.push_back(LA("09:45", 215.80));
  la.push_back(LA("14:20", 215.80));
  la.push_back(LA("17:40", 215.80));
  la.push_back(LA("19:20", 215.80));

  std::vector<NY> ny;
  ny.push_back(NY("06:45", 200.75));
  ny.push_back(NY("10:00", 200.75));
  ny.push_back(NY("12:00", 200.75));
  ny.push_back(NY("14:30", 200.75));
  ny.push_back(NY("20:00", 200.75));
  ny.push_back(NY("21:30", 200.75));

  std::vector<SE> se;
  se.push_back(SE("05:45", 215.80));
  se.push_back(SE("07:50", 215.80));
  se.push_back(SE("13:45", 215.80));
  se.push_back(SE("14:20", 215.80));
  se.push_back(SE("16:40", 215.80));
  se.push_back(SE("21:20", 215.80));

  std::vector<SSA> ssa;
  ssa.push_back(SSA("05:25", 225.80));
  ssa.push_back(SSA("08:00", 225.80));
  ssa.push_back(SSA("14:00", 225.80));
  ssa.push_back(SSA("17:30", 225.80));
  ssa.push_back(SSA("19:00", 225.80));
  ssa.push_back(SSA("22:30", 225.80));

  std::vector<BVB> bvb;
  bvb.push_back(BVB("06:45", 215.80));
  bvb.push_back(BVB("08:30", 215.80));
  bvb.push_back(BVB("10:45", 215.80));
  bvb.push_back(BVB("12:30", 215.80));
  bvb.push_back(BVB("17:45", 215.80));
  bvb.push_back(BVB("20:30", 215.80));

  std::vector<CFB> cfb;
  cfb.push_back(CFB("04:45", 215.80));
  cfb.push_back(CFB("06:25", 215.80));
  cfb.push_back(CFB("10:45", 215.80));
  cfb.push_back(CFB("14:20", 215.80));
  cfb.push_back(CFB("18:40", 215.80));
  cfb.push_back(CFB("22:20", 215.80));

  switch (opc_orig){
  case 0:
    for (size_t i = 0; i < rj.size(); ++i){
      std::cout << "[" << i << "] " << rj[i].time << " - " << "R$" << rj[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= rj.size()){
        cout << endl;
        cout << rj[horario_pass].time << " - " << rj[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > rj.size());
    break;
  case 1:
    for (size_t i = 0; i < sp.size(); ++i){
      std::cout << "[" << i << "] " << sp[i].time << " - " << "R$" << sp[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= sp.size()){
        cout << endl;
        cout << sp[horario_pass].time << " - " << sp[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > sp.size());
    break;
  case 2:
    for (size_t i = 0; i < pa.size(); ++i){
      std::cout << "[" << i << "] " << pa[i].time << " - " << "R$" << pa[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= sp.size()){
        cout << endl;
        cout << sp[horario_pass].time << " - " << sp[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
        cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > sp.size());
    break;
  case 3:
    for (size_t i = 0; i < bsb.size(); ++i){
      std::cout << "[" << i << "] " << bsb[i].time << " - " << "R$" << bsb[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= bsb.size()){
        cout << endl;
        cout << bsb[horario_pass].time << " - " << bsb[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > bsb.size());
    break;
  case 4:
    for (size_t i = 0; i < mt.size(); ++i){
      std::cout << "[" << i << "] " << mt[i].time << " - " << "R$" << mt[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= mt.size()){
        cout << endl;
        cout << mt[horario_pass].time << " - " << mt[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > mt.size());
    break;
  case 5:
  string local_atual = pr;
  tchau_cases(local_atual);
  break;
  case 6:
    for (size_t i = 0; i < mia.size(); ++i){
      std::cout << "[" << i << "] " << mia[i].time << " - " << "R$" << mia[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= mia.size()){
        cout << endl;
        cout << mia[horario_pass].time << " - " << mia[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > mia.size());
    break;
  case 7:
    for (size_t i = 0; i < fll.size(); ++i){
      std::cout << "[" << i << "] " << fll[i].time << " - " << "R$" << fll[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= fll.size()){
        cout << endl;
        cout << fll[horario_pass].time << " - " << fll[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > fll.size());
    break;
  case 8:
    for (size_t i = 0; i < sc.size(); ++i){
      std::cout << "[" << i << "] " << sc[i].time << " - " << "R$" << sc[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= sc.size()){
        cout << endl;
        cout << sc[horario_pass].time << " - " << sc[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > sc.size());
    break;
  case 9:
    for (size_t i = 0; i < ce.size(); ++i){
      std::cout << "[" << i << "] " << ce[i].time << " - " << "R$" << ce[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= ce.size()){
        cout << endl;
        cout << ce[horario_pass].time << " - " << ce[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > ce.size());
    break;
  case 10:
    for (size_t i = 0; i < gyn.size(); ++i){
      std::cout << "[" << i << "] " << gyn[i].time << " - " << "R$" << gyn[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= gyn.size()){
        cout << endl;
        cout << gyn[horario_pass].time << " - " << gyn[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > gyn.size());
    break;
  case 11:
    for (size_t i = 0; i < lx.size(); ++i){
      std::cout << "[" << i << "] " << lx[i].time << " - " << "R$" << lx[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= lx.size()){
        cout << endl;
        cout << lx[horario_pass].time << " - " << lx[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > lx.size());
    break;
  case 12:
    for (size_t i = 0; i < am.size(); ++i){
      std::cout << "[" << i << "] " << am[i].time << " - " << "R$" << am[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= am.size()){
        cout << endl;
        cout << am[horario_pass].time << " - " << am[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > am.size());
    break;
  case 13:
    for (size_t i = 0; i < mco.size(); ++i){
      std::cout << "[" << i << "] " << mco[i].time << " - " << "R$" << mco[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= mco.size()){
        cout << endl;
        cout << mco[horario_pass].time << " - " << mco[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > mco.size());
    break;
  case 14:
    for (size_t i = 0; i < mvd.size(); ++i){
      std::cout << "[" << i << "] " << mvd[i].time << " - " << "R$" << mvd[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= mvd.size()){
        cout << endl;
        cout << mvd[horario_pass].time << " - " << mvd[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > mvd.size());
    break;
  case 15:
    for (size_t i = 0; i < par.size(); ++i){
      std::cout << "[" << i << "] " << par[i].time << " - " << "R$" << par[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= par.size()){
        cout << endl;
        cout << par[horario_pass].time << " - " << par[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > par.size());
    break;
  case 16:
    for (size_t i = 0; i < poa.size(); ++i){
      std::cout << "[" << i << "] " << poa[i].time << " - " << "R$" << poa[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= poa.size()){
        cout << endl;
        cout << poa[horario_pass].time << " - " << poa[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > poa.size());
    break;
  case 17:
    for (size_t i = 0; i < ro.size(); ++i){
      std::cout << "[" << i << "] " << ro[i].time << " - " << "R$" << ro[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= ro.size()){
        cout << endl;
        cout << ro[horario_pass].time << " - " << ro[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > ro.size());
    break;
  case 18:
    for (size_t i = 0; i < pe.size(); ++i){
      std::cout << "[" << i << "] " << pe[i].time << " - " << "R$" << pe[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= pe.size()){
        cout << endl;
        cout << pe[horario_pass].time << " - " << pe[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > pe.size());
    break;
  case 19:
    for (size_t i = 0; i < sdu.size(); ++i){
      std::cout << "[" << i << "] " << sdu[i].time << " - " << "R$" << sdu[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= sdu.size()){
        cout << endl;
        cout << sdu[horario_pass].time << " - " << sdu[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > sdu.size());
    break;
  case 20:
    for (size_t i = 0; i < ma.size(); ++i){
      std::cout << "[" << i << "] " << ma[i].time << " - " << "R$" << ma[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= ma.size()){
        cout << endl;
        cout << ma[horario_pass].time << " - " << ma[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > ma.size());
    break;
  case 21:
    for (size_t i = 0; i < vix.size(); ++i){
      std::cout << "[" << i << "] " << vix[i].time << " - " << "R$" << vix[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= vix.size()){
        cout << endl;
        cout << vix[horario_pass].time << " - " << vix[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > vix.size());
    break;
  case 22:
    for (size_t i = 0; i < agp.size(); ++i){
      std::cout << "[" << i << "] " << agp[i].time << " - " << "R$" << agp[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= agp.size()){
        cout << endl;
        cout << agp[horario_pass].time << " - " << agp[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > agp.size());
    break;
  case 23:
    for (size_t i = 0; i < aju.size(); ++i){
      std::cout << "[" << i << "] " << aju[i].time << " - " << "R$" << aju[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= aju.size()){
        cout << endl;
        cout << aju[horario_pass].time << " - " << aju[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > aju.size());
    break;
  case 24:
    for (size_t i = 0; i < bcn.size(); ++i){
      std::cout << "[" << i << "] " << bcn[i].time << " - "<< "R$" << bcn[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= bcn.size()){
        cout << endl;
        cout << bcn[horario_pass].time << " - " << bcn[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > bcn.size());
    break;
  case 25:
    for (size_t i = 0; i < pb.size(); ++i){
      std::cout << "[" << i << "] " << pb[i].time << " - " << "R$" << pb[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= pb.size()){
        cout << endl;
        cout << pb[horario_pass].time << " - " << pb[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > pb.size());
    break;
  case 26:
    for (size_t i = 0; i < la.size(); ++i){
      std::cout << "[" << i << "] " << la[i].time << " - " << "R$" << la[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= la.size()){
        cout << endl;
        cout << la[horario_pass].time << " - " << la[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > la.size());
    break;
  case 27:
    for (size_t i = 0; i < ny.size(); ++i){
      std::cout << "[" << i << "] " << ny[i].time << " - " << "R$" << ny[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= ny.size()){
        cout << endl;
        cout << ny[horario_pass].time << " - " << ny[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > ny.size());
    break;
  case 28:
    for (size_t i = 0; i < se.size(); ++i){
      std::cout << "[" << i << "] " << se[i].time << " - " << "R$" << se[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= se.size()){
        cout << endl;
        cout << se[horario_pass].time << " - " << se[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > se.size());
    break;
  case 29:
    for (size_t i = 0; i < ssa.size(); ++i){
      std::cout << "[" << i << "] " << ssa[i].time << " - " << "R$" << ssa[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= ssa.size()){
        cout << endl;
        cout << ssa[horario_pass].time << " - " << ssa[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > ssa.size());
    break;
  case 30:
    for (size_t i = 0; i < bvb.size(); ++i){
      std::cout << "[" << i << "] " << bvb[i].time << " - " << "R$" << bvb[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= bvb.size()){
        cout << endl;
        cout << bvb[horario_pass].time << " - " << bvb[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > bvb.size());
    break;
  case 31:
    for (size_t i = 0; i < cfb.size(); ++i){
      std::cout << "[" << i << "] " << cfb[i].time << " - "<< "R$" << cfb[i].priceTime << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass <= cfb.size()){
        cout << endl;
        cout << cfb[horario_pass].time << " - " << cfb[horario_pass].priceTime << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          horario_voo();
        }
        if (pass_dnv == 1){
          dados_viajante();
        }
      }
    } while (horario_pass > cfb.size());
    break;
  }
}

void dados_viajante(){
  int digite_cpf, i, numdados;
  digite_cpf = 0;
  string dadoscompletos, guarda;
  CPF pessoa[2];
  fstream dadosvj;
  numdados = 0;
  int aux = 0;

  dadosvj.open("dadosviajante.txt", ios::in);
  if (dadosvj.is_open()){
    for (int j = 0; j < 7;){
      while (getline(dadosvj, dadoscompletos)){
        for (i = 0; i < dadoscompletos.size(); i++){
          if (dadoscompletos[i] != ',' && dadoscompletos[i] != ';'){
            guarda = guarda + dadoscompletos[i];
          }
          else{
            switch (aux){
            case 0:
              pessoa[j].cpf_vj = guarda;
              guarda = "";
              aux++;
              break;
            case 1:
              pessoa[j].name = guarda;
              guarda = "";
              aux++;
              break;
            case 2:
              pessoa[j].surname = guarda;
              guarda = "";
              aux++;
              break;
            case 3:
              pessoa[j].birth = guarda;
              guarda = "";
              aux++;
              break;
            case 4:
              pessoa[j].gender = guarda;
              guarda = "";
              aux = 0;
              j++;
              break;
            }
          }
        }
      }
    }
    for (i = i + 1; i < dadoscompletos.size(); i++){
      guarda = guarda + dadoscompletos[i];
    }
  }
  else{
    cout << "Arquivo invalido";
  }
  dadosvj.close();
  for (i = 0; i < 2; i++){
    cout << "CPF: " << pessoa[i].cpf_vj << endl;
    cout << "Nome viajante: " << pessoa[i].name << endl;
    cout << "Ultimo sobrenome: " << pessoa[i].surname << endl;
    cout << "Data de nascimento: " << pessoa[i].birth << endl;
    cout << "Sexo: " << pessoa[i].gender << endl;
  }
}

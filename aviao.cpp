#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <locale.h>
#include <chrono>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <map>
//#include "mede_arquivo.h"

using namespace std;
//#define tamanho_linhas_jhonatan T_linhas
//#define tamanho_colunas_jhonatan T_colunas
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
void guarda_lugares();
void lugar_preco_hora();
void diaSele_rj();
void aviao1();
int tamanho_coluna();
int tamanho_linha();
int tamanho_espaco();

// variáveis pra escolher o lugar
int opc_orig, opc_dest, origem_ida, dest_ida, orig_volta, dest_volta, escolha_mes, escolha_lugar, opcao_lugar;
string lugares[31], name_month[13];
char destino_dnv;

// variáveis da função calandario
int daysInMonth, month, year, option, current_month, diaAtual, current_year, month_next, month_back, year_next, year_back, selec_pass, pass_dnv;
char pass_volta;

// variáveis pra escolher passagem
int qtd_pass[3], escolherPass, guarda_pass, opc_ida, opc_volta, horario_pass;

// variáveis da função guarda_lugar
string localSele[100];
float precoLocal[100];
int tamLugar;

// Rio de Janeiro
struct RJ{
  std::string time;
  float priceTime;

  RJ(const std::string &t,const float &price)
    : time(t), priceTime(price) {}
};
// São Paulo
struct SP{
  std::string time;
  float priceTime;
  
  SP(const std::string &t, const float &price)
    : time(t), priceTime(price) {}
};
// Brasília
struct BSB{
  std::string time;
  float priceTime;
  
  BSB(const std::string &t, const float &price)
  : time(t), priceTime(price){}
};
// Goiânia
struct GYN{
  std::string time;
  float priceTime;
  
  GYN(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Manaus
struct MAO{
  std::string time;
  float priceTime;
  
  MAO(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Porto Alegre
struct POA{
  std::string time;
  float priceTime;
  
  POA(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Vitória
struct VIX{
  std::string time;
  float priceTime;
  
  VIX(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Belém
struct BEL{
  std::string time;
  float priceTime;
  
  BEL(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Cuiaba
struct CGB{
  std::string time;
  float priceTime;
  
  CGB(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Fortaleza
struct FOR{
  std::string time;
  float priceTime;
  
  FOR(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
struct CWB{
  std::string time;
  float priceTime;
  
  CWB(const std::string &t, const float &price)
  : time(t), priceTime(price){}

};
// Guardar lugar selecionado
struct GudardaVoos{
  string day, month, year, time, priceTime;
  
  //GArquivo(const std::string &t, const std::string &price, const std::string &y, const std::string &m, const std:: string &d)
  //: time(t), priceTime(price), year(y), month(m), day(d){}
};
// Dados viajante
struct CPF{
  string cpf_vj, name, surname, birth, gender;
};
// Declarando as variáveis para global
std::vector<RJ> rj;
std::vector<SP> sp;
std::vector<BEL> bel;
std::vector<BSB> bsb;
std::vector<GYN> gyn;
std::vector<POA> poa;
std::vector<VIX> vix;
std::vector<CGB> cgb;
std::vector<FOR> fort;
std::vector<MAO> mao;
std::vector<CWB> cwb;

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
  //  aviao1();
  //  x = 0;
  //}
    horario();
    cout << "\nPRA ONDE VAMOS? ";
    cout << "\nMais de 10 lugares para você escolher!" << endl;
    cout << endl;
    mostrar_nome();
    escolher_lugar();
    escolher_passagem();
    escolha_horario();
    diaSele_rj();
    return 0; 
}
void mostrar_nome(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  int i = 0;
  lugares[0] = "RIO- Rio de Janeiro";
  lugares[1] = "CGH- São Paulo";
  lugares[2] = "BEL- Belém";
  lugares[3] = "VIX- Vitória";
  lugares[4] = "CGB- Cuiabá";
  lugares[5] = "CWB- Curitiba";
  lugares[6] = "FOR- Fortaleza";
  lugares[7] = "GYN- Goiânia";
  lugares[8] = "MAO- Manaus";
  lugares[9] = "POA- Porto Alegre";
  lugares[10] = "BSB- Brasília";
  opcao_lugar = 3;
  while (opcao_lugar != 2){
    opcao_lugar = 0;
    while (opcao_lugar == 0){
      i = 0;
      for (i < 0; i <= 5; i++){
        cout << "[" << i << "] " << lugares[i] << endl;
      }
      opcao_lugar = 3;
      while (opcao_lugar != 0 && opcao_lugar != 1 && opcao_lugar != 2){
        cout << endl;
        cout << " 0- Anterior, 1- Próximo, 2- Sair" << endl;
        cin >> opcao_lugar;
      }
      if (opcao_lugar == 1){
        for (i < 5; i <= 10; i++){
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
  selec_pass = 3;
  while (selec_pass == 1 || selec_pass != 2){
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

void dados_viajante(){
  int  i, numdados, cont;
  string dadoscompletos, guarda, digite_cpf;
  int tamDados;
  fstream dadosvj;
  int aux = 0;
  cont = 0;
  numdados = 0;
  tamDados = 0;
  dadosvj.open("dadosviajante.txt", ios::in);
  while (getline(dadosvj, dadoscompletos)){
    for (i = 0; i < dadoscompletos.size(); i++){
      if (dadoscompletos[i] == ';'){
        tamDados++;
      }
    }
  }
  
  CPF pessoa[tamDados];
  dadosvj.close();
  dadosvj.open("dadosviajante.txt", ios::in);
  if (dadosvj.is_open()){
    for (int j = 0; j < tamDados;j++){
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
  }
  else{
    cout << "Arquivo inválido";
  }
    dadosvj.close();
    cout << "\nDigite seu CPF: ";
    cin >> digite_cpf; 
  
  for (i = 0; i <= tamDados; i++){
    if (digite_cpf == pessoa[i].cpf_vj){
      cout << "CPF: " << pessoa[i].cpf_vj << endl;
      cout << "Nome viajante: " << pessoa[i].name << endl;
      cout << "Ultimo sobrenome: " << pessoa[i].surname << endl;
      cout << "Data de nascimento: " << pessoa[i].birth << endl;
      cout << "Sexo: " << pessoa[i].gender << endl;
      cout << endl;
      cont--;
    }
    if(digite_cpf != pessoa[i].cpf_vj && cont >= tamDados){
      cout << "\nCPF inválido!" << endl;
      dados_viajante();
    }
    else{
      cont++;
    }
  }
}
void lugar_preco_hora(){
  fstream horarioVoo;
  string lerArq, linha, guarda, dia, mes, ano, horario, preco;
  int aux = 0, tamDados = 0;;

 horarioVoo.open("Rj_dia1.txt", ios::in);
  while (getline(horarioVoo, linha)){
    for (int i = 0; i < linha.size(); i++){
      if (linha[i] == '!'){
        tamDados++;
      }
    }
  }
  GudardaVoos voos[tamDados];
  horarioVoo.close();  
  horarioVoo.open("Rj_dia1.txt", ios::in);
  if(horarioVoo.is_open()){
    for(int j = 0; j <= rj.size(); j++){
      while(getline(horarioVoo, linha)){
        for(int i = 0; i < linha.size(); i++){
          if(linha[i] != ',' && linha[i] != '!'){
          guarda = guarda + linha[i];
          }
          else{
            switch(aux){
            case 0:
              voos[j].day = guarda;
              guarda = "";
              aux++;
              break;
            case 1:
              voos[j].month = guarda;
              guarda = "";
              aux++;
              break;
            case 2:
              voos[j].year = guarda;
              guarda = "";
              aux++;
              break;
            case 3:
              voos[j].time = guarda;
              guarda = "";
              aux++;
              break;
            case 4:
              voos[j].priceTime = guarda;
              guarda = "";
              aux = 0;
              j++;
              break;
            }
          }
        }
      }
    }
  }
  else{
    cout << "\nArquivo inválido, tente novamente!" << endl;
  }
  horarioVoo.close();  
  
  rj.push_back(RJ("06:45", 200.75));
  rj.push_back(RJ("10:00", 200.75));
  rj.push_back(RJ("12:00", 200.75));
  rj.push_back(RJ("14:30", 200.75));
  rj.push_back(RJ("20:00", 200.75));
  rj.push_back(RJ("21:30", 200.75));
  
  sp.push_back(SP("07:45", 230.50));
  sp.push_back(SP("08:00", 230.50));
  sp.push_back(SP("13:30", 230.50));
  sp.push_back(SP("14:30", 230.50));
  sp.push_back(SP("20:00", 230.50));
  sp.push_back(SP("21:50", 230.50));

  bel.push_back(BEL("04:45", 230.80));
  bel.push_back(BEL("05:50", 230.80));
  bel.push_back(BEL("13:30", 230.80));
  bel.push_back(BEL("14:30", 230.80));
  bel.push_back(BEL("17:00", 230.80));
  bel.push_back(BEL("20:20", 230.80));

  bsb.push_back(BSB("05:45", 215.80));
  bsb.push_back(BSB("07:50", 215.80));
  bsb.push_back(BSB("13:45", 215.80));
  bsb.push_back(BSB("14:20", 215.80));
  bsb.push_back(BSB("16:40", 215.80));
  bsb.push_back(BSB("21:20", 215.80));

  gyn.push_back(GYN("05:45", 215.80));
  gyn.push_back(GYN("06:50", 215.80));
  gyn.push_back(GYN("09:45", 215.80));
  gyn.push_back(GYN("14:20", 215.80));
  gyn.push_back(GYN("17:40", 215.80));
  gyn.push_back(GYN("19:20", 215.80));

  poa.push_back(POA("06:00", 210.65));
  poa.push_back(POA("08:50", 210.65));
  poa.push_back(POA("09:45", 210.65));
  poa.push_back(POA("14:20", 210.65));
  poa.push_back(POA("18:40", 210.65));
  poa.push_back(POA("21:34", 210.65));

  vix.push_back(VIX("06:45", 200.75));
  vix.push_back(VIX("10:00", 200.75));
  vix.push_back(VIX("12:25", 200.75));
  vix.push_back(VIX("14:35", 200.75));
  vix.push_back(VIX("20:00", 200.75));
  vix.push_back(VIX("21:00", 200.75));

  cgb.push_back(CGB("07:45", 230.50));
  cgb.push_back(CGB("08:00", 230.50));
  cgb.push_back(CGB("13:30", 230.50));
  cgb.push_back(CGB("14:30", 230.50));
  cgb.push_back(CGB("20:00", 230.50));
  cgb.push_back(CGB("21:50", 230.50));

  cwb.push_back(CWB("07:45", 215.80));
  cwb.push_back(CWB("09:00", 215.80));
  cwb.push_back(CWB("12:15", 215.80));
  cwb.push_back(CWB("15:45", 215.80));
  cwb.push_back(CWB("18:40", 215.80));
  cwb.push_back(CWB("23:30", 215.80));

  fort.push_back(FOR("04:45", 215.80));
  fort.push_back(FOR("06:25", 215.80));
  fort.push_back(FOR("10:45", 215.80));
  fort.push_back(FOR("14:20", 215.80));
  fort.push_back(FOR("18:40", 215.80));
  fort.push_back(FOR("22:20", 215.80));

  gyn.push_back(GYN("05:25", 220.45));
  gyn.push_back(GYN("08:00", 220.45));
  gyn.push_back(GYN("14:00", 220.45));
  gyn.push_back(GYN("17:30", 220.45));
  gyn.push_back(GYN("19:00", 220.45));
  gyn.push_back(GYN("22:30", 220.45));

  mao.push_back(MAO("05:45", 215.80));
  mao.push_back(MAO("06:50", 215.80));
  mao.push_back(MAO("09:45", 215.80));
  mao.push_back(MAO("14:20", 215.80));
  mao.push_back(MAO("17:40", 215.80));
  mao.push_back(MAO("19:20", 215.80));
}
void horario_voo(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  lugar_preco_hora();
  tamLugar = 0;
  for (int i = 0; i < 100; i++){
    precoLocal[i] = 0;
    localSele[i] = "";
  }
  switch (opc_orig){
  case 0:
    for (int i = 0; i < rj.size(); i++){
      localSele[i] = rj[i].time;
      precoLocal[i] = rj[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 1:
    for (int i = 0; i < sp.size(); i++){
      localSele[i] = sp[i].time;
      precoLocal[i] = sp[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 2:
    for (int i = 0; i < bsb.size(); i++){
      localSele[i] = bsb[i].time;
      precoLocal[i] = bsb[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 3:
     for (int i = 0; i < poa.size(); i++){
      localSele[i] = poa[i].time;
      precoLocal[i] = poa[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 4:
    for (int i = 0; i < vix.size(); i++){
      localSele[i] = vix[i].time;
      precoLocal[i] = vix[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 5:
    for (int i = 0; i < vix.size(); i++){
      localSele[i] = vix[i].time;
      precoLocal[i] = vix[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 6:
    for (int i = 0; i < cwb.size(); i++){
      localSele[i] = cwb[i].time;
      precoLocal[i] = cwb[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 7:
    for (int i = 0; i < mao.size(); i++){
      localSele[i] = mao[i].time;
      precoLocal[i] = mao[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 8:
    for (int i = 0; i < bel.size(); i++){
      localSele[i] = bel[i].time;
      precoLocal[i] = bel[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 9:
    for (int i = 0; i < poa.size(); i++){
      localSele[i] = poa[i].time;
      precoLocal[i] = poa[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 10:
    for (int i = 0; i < gyn.size(); i++){
      localSele[i] = gyn[i].time;
      precoLocal[i] = gyn[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  }
}

void guarda_lugares(){
 for (size_t i = 0; i < tamLugar; i++){
      std::cout << "[" << i << "] " << localSele[i] << " - "<< "R$" << precoLocal[i] << std::endl;
    }
    do{
      cout << "\nDigite um numero: ";
      cin >> horario_pass;
      if (horario_pass < tamLugar && horario_pass >= 0){
        cout << endl;
        cout << localSele[horario_pass] << " - " << "R$" << precoLocal[horario_pass] << " foi selecionado!" << endl;
        pass_dnv = 2;
        while (pass_dnv != 0 && pass_dnv != 1){
          cout << "\n0- Anterior, 1- Próximo" << endl;
          cin >> pass_dnv;
        }
        if (pass_dnv == 0){
          guarda_lugares();
        }
        if (pass_dnv == 1){
        dados_viajante();
      }
    }
  } while (horario_pass >= tamLugar || horario_pass < 0);
}

void diaSele_rj(){
  if(opc_ida >= 0 || opc_volta <= 31){
    aviao1();
  }
}

fstream guardapolt;
int tamanho_coluna(){
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
          return Tam_Col;
        }
      }
    }
  }
  return 1;
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
  return Tam_linha;
}
int tamanho_espaco(){
  int Tam_espaco = 0;
   string linha;
    guardapolt.open("poltselecionada.txt", ios::in);
    while(getline(guardapolt, linha)){
    for (int i = 0; i < linha.size(); i++){
      if (linha[i] == ';'){
        Tam_espaco++;
        if(linha[i+1] == 'X'){
          guardapolt.close();
          return Tam_espaco;
        }
      }
    }
  }
return 0;
}
//int Tam_Col = tamanho_coluna();
//int Tam_linha = tamanho_linha();
//string polt[tamanho_linhas_jhonatan][tamanho_colunas_jhonatan];
//std::vector polt[][]; 

void aviao1(){
setlocale(LC_ALL, "Portuguese_Brazil");
  int contpolt;
  char reserva_polt;
  int i, j;
  int escolha1,escolha2;
  string linha, guardaLinha, guardaEspaco, polt[10][5], guarda;
  int Tam_Col, Tam_linha, Tam_espaco, tamLinha2, tamCol2, tamArq;
  reserva_polt = 's', 'S';
  tamArq = 0;
  contpolt = 0;
  tamLinha2 = 0;
  tamCol2 = 0;
  i = 0;
  j = 0;
  //opc_ida--;
  Tam_espaco = tamanho_espaco();
  Tam_Col = tamanho_coluna();
  Tam_linha = tamanho_linha();
  tamLinha2 = Tam_linha -1;
  tamCol2 = Tam_Col -1;
  fstream lerArq;
  string guardaDados[Tam_linha][Tam_Col];
  lerArq.open("ArqDias_RJ.txt", ios::in);
  if(lerArq.is_open()){
    while(getline(lerArq, linha)){
      for(int i = 0; i < linha.size(); i++){
        if(linha[i] == ';'){
          tamArq++;
        }
      }
    }
  }
  else{
    cout << "\nArquivo inválido, tente novamente!" << endl;
  }
 
  string guardaArquiv[tamArq];
  lerArq.close();

  lerArq.open("ArqDias_RJ.txt", ios::in);
  if(lerArq.is_open()){
    for (int j = 0; j <= tamArq; j++){
      while(getline(lerArq, linha)){
        for(int i = 0; i < linha.size(); i++){
          if(linha[i] != ';'){
            guarda = guarda + linha[i];
          }
          else{
            guardaArquiv[j] = guarda;
            guarda = "";
            j++;
          }
        }
      }
    }
  }
  else{
    cout << "\nArquivo inválido, tente novamente!" << endl;
  }
  lerArq.close();  
  

  if(opc_ida == tamArq){
    opc_ida--;
    guardapolt.open(guardaArquiv[opc_ida], ios::out);
    if(guardapolt.is_open()){
    for (i = 0; i < Tam_linha; i++){
      for (j = 0; j < Tam_Col; j++){
       if(j > Tam_espaco){
          guardapolt << "[";
          guardapolt << i << j-1;
          guardapolt << "]";
          guardapolt << ";";
          }
          else if(j > 1){
          guardapolt << "XXX";
           guardapolt << ";";
          }
          else{
          guardapolt << "[";
          guardapolt << i << j;
          guardapolt << "]";
          guardapolt << ";";
          }
        }
        guardapolt << "/";
        guardapolt << endl;
      } 
    }
    else{
    cout << "\nArquivo inválido!" << endl;
  } 
  guardapolt.close();
  }
  opc_ida--;
  guardapolt.open(guardaArquiv[opc_ida], ios::in);
    if(guardapolt.is_open()){
    int i = 0;
    int j = 0;
    while(getline(guardapolt, linha)){
      for(int k = 0; k < linha.size(); k++){
        if(linha[k] != ';' && linha[k] != '/' && linha[k] != 'X'){
          guardaLinha = guardaLinha + linha[k];
        }
        else{
          if(linha[k] == '/'){
            i++;
            j = 0;
          }
          else{
            if(linha[k] != 'X'){
            guardaDados[i][j] = guardaLinha;
            guardaLinha = "";
            j++;
            }
          }
        }
      }
    }
  }
  else{
    cout << "\nArquivo inválido" << endl;
  }
  cout << endl;
  for(int i = 0; i < Tam_linha;i++){
    for(int j = 0; j < Tam_Col; j++){
      if(guardaDados[i][j] != ""){
      polt[i][j] = guardaDados[i][j];
      }
    }
  }
  guardapolt.close();
  /*guardapolt.open(guardaArquiv[opc_ida], ios::out);
  if(guardapolt.is_open()){
    for (i = 0; i < Tam_linha; i++){
      for (j = 0; j < Tam_Col; j++){
        if(polt[i][j] == "[--]"){
        guardapolt << polt[i][j];
        }
        else if(polt[i][j] == ""){
        guardapolt << "XXX";
        }
        else{
         if(j > Tam_espaco){
          guardapolt << "[";
          guardapolt << i << j-1;
          guardapolt << "]";
          }
          else{
          guardapolt << "[";
          guardapolt << i << j;
          guardapolt << "]";
          }
        }
        guardapolt << ";";
      } 
      guardapolt << "/";
      guardapolt << endl;
    }
  }
  else{
    cout << "\nArquivo inválido!" << endl;
  } 
  guardapolt.close(); */ 

  for (i = 0; i < Tam_linha; i++){
    for (j = 0; j < Tam_Col; j++){
      if (polt[i][j] == "[--]"){
        cout << "[--] ";
      }
      else if(polt[i][j] == ""){
      cout << "   ";
      }
      else{
        if(j > Tam_espaco){
        cout << "[" << i << j-1 << "] ";
        }else{
        cout << "[" << i << j << "] ";
        }
      }
    }
    cout << endl;
  }
  
  while (reserva_polt == 's' || reserva_polt == 'S'){
    do{
      do{
        cout << "\nSelecionar assentos: ";
        cin >> escolha1 >> escolha2;
        //system("cls");
        cout << endl;
        for (i = 0; i < Tam_linha; i++){
          for (j = 0; j < Tam_Col; j++){
            if (polt[i][j] == "[//]" || polt[i][j] == "[--]"){
              if (polt[i][j] == "[//]"){
                cout << "[//] ";
              }
              if (polt[i][j] == "[--]"){
                cout << "[--] ";
              }
            }
            else if(polt[i][j] == ""){
              cout << "   ";
            }
            else{
              if(j > Tam_espaco){
              cout << "[" << i << j-1 << "] ";
            }
            else{
              cout << "[" << i << j << "] ";
              }
            }
          }
          cout << endl;
        }
        cout << endl;
        if (escolha1 > tamLinha2 || escolha2 >= tamCol2){
          escolha2++;
          cout << "\nNão existe, Tente novamente!" << endl;
        }
      } while(escolha1 > tamLinha2 || escolha2 > tamCol2);
      if (polt[escolha1][escolha2] == "[--]"){
        cout << "\nEstá ocupado!";
        cout << endl; 
      }
    } while (polt[escolha1][escolha2] == "[--]");
    if(polt[escolha1][escolha2] == "" && escolha2 > 1 && polt[escolha1][escolha2] != "[//]"){
      escolha2++;
      if(polt[escolha1][escolha2] == "[//]"){
      polt[escolha1][escolha2] = "[ ]";
      }
      else{polt[escolha1][escolha2] = "[//]";
      }
    }
    else if(polt[escolha1][escolha2] != "" && escolha2 > 1){
      escolha2++;
      if(polt[escolha1][escolha2] == "[//]"){
      polt[escolha1][escolha2] = "[ ]";
      }
      else{polt[escolha1][escolha2] = "[//]";
      }
    } 
    else if (polt[escolha1][escolha2] == "[//]"){
      polt[escolha1][escolha2] = "[ ]";
    }
    else{
      polt[escolha1][escolha2] = "[//]";
    }
    if (polt[escolha1][escolha2] != "[--]" && polt[escolha1][escolha2] != "[ ]" && polt[escolha1][escolha2] != ""){
      polt[escolha1][escolha2] = "[//]";
    }
    //system("cls");
  cout << endl;
  for (i = 0; i < Tam_linha; i++){
    for (j = 0; j < Tam_Col; j++){
      if (polt[i][j] == "[//]" || polt[i][j] == "[--]"){
        if (polt[i][j] == "[//]"){
          cout << "[//] ";
        }
        if (polt[i][j] == "[--]"){
          cout << "[--] ";
        }
      }
      else if(polt[i][j] == ""){
          cout << "   ";
        }
      else{
        if(j > Tam_espaco){
            cout << "[" << i << j-1 << "] ";
          }
        else{
          cout << "[" << i << j << "] ";
        }
      }
    }
    cout << endl;
  }
    cout << "\nAssentos selecionados: ";
  for (i = 0; i < Tam_linha; i++){
    for (j = 0; j < Tam_Col; j++){
      if (polt[i][j] == "[//]"){
        if(j > Tam_espaco){
          cout << i << j-1 <<", ";
        }
        else{
          cout <<  i << j << ", ";
        }
      }
    }
  }
    cout << endl;
    reserva_polt = 't';
    while (reserva_polt != 'S' && reserva_polt != 's' && reserva_polt != 'n' && reserva_polt != 'N'){
      cout << endl;
      cout << "\nSe deseja selecionar mais";
      cout << "\nDigite 'S' para SIM ou 'N' para N?: ";
      cin >> reserva_polt;
    }
  }
  if (reserva_polt == 'n' || reserva_polt == 'N'){
    for (i = 0; i < Tam_linha; i++){
      for (j = 0; j < Tam_Col; j++){
        if (polt[i][j] == "[//]"){
          contpolt++;
        }
      }
    }
    for (i = 0; i < Tam_linha; i++){
      for (j = 0; j < Tam_Col; j++){
        if (polt[i][j] == "[//]"){
          if(j > Tam_espaco){
            cout << i << j-1 <<", ";
          }
          else{
            cout <<  i << j << ", ";
          }
        }
      }
    }
    cout << endl;
  } 
  
  for (int i = 0; i < Tam_linha; i++){
    for (int j = 0; j < Tam_Col; j++){
      if (polt[i][j] == "[//]"){
        polt[i][j] = "[--]";
      }
    }
  }
   for (i = 0; i < Tam_linha; i++){
    for (j = 0; j < Tam_Col; j++){
      if (polt[i][j] == "[//]" || polt[i][j] == "[--]"){
        if (polt[i][j] == "[//]"){
          cout << "[//] ";
        }
        if (polt[i][j] == "[--]"){
            cout << "[--] ";
          }
        }
        else if(polt[i][j] == ""){
          cout << "   ";
        }
        else{
          if(j > Tam_espaco){
            cout << "[" << i << j-1 << "] ";
          }
          else{
            cout << "[" << i << j << "] ";
            }
          }
        }
        cout << endl;
      }
  guardapolt.open(guardaArquiv[opc_ida], ios::out);
  if(guardapolt.is_open()){
    for (i = 0; i < Tam_linha; i++){
      for (j = 0; j < Tam_Col; j++){
        if(polt[i][j] == "[--]"){
        guardapolt << polt[i][j];
        }
        else if(polt[i][j] == ""){
        guardapolt << "XXX";
        }
        else{
         if(j > Tam_espaco){
          guardapolt << "[";
          guardapolt << i << j-1;
          guardapolt << "]";
          }
          else{
          guardapolt << "[";
          guardapolt << i << j;
          guardapolt << "]";
          }
        }
        guardapolt << ";";
      } 
      guardapolt << "/";
      guardapolt << endl;
    }
  }
  else{
    cout << "\nArquivo inválido!" << endl;
  } 
  guardapolt.close(); 
}

  



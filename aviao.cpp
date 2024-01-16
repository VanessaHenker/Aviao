#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <locale.h>
#include <chrono>
#include <vector>
#include <fstream>
#include <stdlib.h>

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

// variï¿½veis pra escolher o lugar
int opc_orig, opc_dest, origem_ida, dest_ida, orig_volta, dest_volta, escolha_mes, escolha_lugar, opcao_lugar;
string lugares[31], name_month[13];
char destino_dnv;

// variï¿½veis da funï¿½ï¿½o calandario
int daysInMonth, month, year, option, current_month, diaAtual, current_year, month_next, month_back, year_next, year_back, selec_pass, pass_dnv;
char pass_volta;

// variï¿½veis pra escolher passagem
int qtd_pass[3], escolherPass, guarda_pass, opc_ida, opc_volta, horario_pass;

// variï¿½veis da funï¿½ï¿½o guarda_lugar
string localSele[100], precoLocal[100];
int tamLugar;

// horarios e precos
struct Voos{
  string time, priceTime;
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
Voos rj[20];
Voos sp[20];
Voos bel[20];
Voos bsb[20];
Voos gyn[20];
Voos poa[20];
Voos vix[20];
Voos cgb[20];
Voos fort[20];
Voos mao[20];
Voos cwb[20];

void printCalendar(int year, int month){
  // Criar uma estrutura tm com a data do primeiro dia do mï¿½s
  std::tm timeinfo = {};
  timeinfo.tm_year = year - 1900; // tm_year ï¿½ o nï¿½mero de anos desde 1900
  timeinfo.tm_mon = month - 1;    // tm_mon ï¿½ base 0 (janeiro ï¿½ representado por 0)
  timeinfo.tm_mday = 1;
  std::mktime(&timeinfo);

  // Obter o nï¿½mero de dias no mï¿½s atual
  daysInMonth;
  if (month == 2){
    // Verificar se ï¿½ um ano bissexto (fevereiro tem 29 dias em anos bissextos)
    daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11){
    daysInMonth = 30;
  }
  else{
    daysInMonth = 31;
  }

  // Imprimir o cabeï¿½alho do calendï¿½rio
  std::cout << "  " << std::setw(11) << std::left << "DOM SEG TER QUA QUI SEX SAB" << std::endl;

  // Imprimir os espaï¿½os iniciais para alinhar o primeiro dia do mï¿½s
  for (int i = 0; i < timeinfo.tm_wday; ++i){
    std::cout << "    ";
  }

  // Imprimir os dias do mï¿½s
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
    cout << "\nMais de 10 lugares para vocï¿½ escolher!" << endl;
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
  lugares[1] = "CGH- Sâo Paulo";
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
          cout << "\nDigite 'S' para SIM ou 'N' para Nï¿½O: ";
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
  name_month[3] = "Marï¿½o";
  name_month[4] = "Abril";
  name_month[5] = "Maio";
  name_month[6] = "Junho";
  name_month[7] = "Julho";
  name_month[8] = "Agosto";
  name_month[9] = "Setembro";
  name_month[10] = "Outubro";
  name_month[11] = "Novembro";
  name_month[12] = "Dezembro";
  // Obter o horï¿½rio atual do sistema
  std::time_t currentTime = std::time(nullptr);

  // Converter para uma estrutura tm (hora local)
  std::tm *localTime = std::localtime(&currentTime);

  // Extrair o mï¿½s e o ano atual
  month = localTime->tm_mon + 1;    // tm_mon ï¿½ base 0 (janeiro ï¿½ representado por 0)
  year = localTime->tm_year + 1900; // tm_year ï¿½ o nï¿½mero de anos desde 1900
  // Mï¿½s e ano atual
  current_month = localTime->tm_mon + 1; 
  current_year =  localTime->tm_year + 1900; 
  
  option = 3;
  cout << endl;
  while (option != 2){
    if (year < 2025 && month >= current_month || year == 2024 && month <= 12){
      // Exibir o calendï¿½rio do mï¿½s atual
      cout << "\n------------------------------";
      cout << "\n       DATA DAS VIAGENS";
      cout << "\n------------------------------";
      std::cout << "\n        " << name_month[month] << "       " << month << "/" << year << std::endl;
      printCalendar(year, month);

      // Pedir ao usuï¿½rio para navegar para o mï¿½s seguinte ou anterior
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
        cout << "\nDigite 's' para 'SIM' ou 'N' para 'NÃO': ";
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
  // Obter o horï¿½rio atual do sistema
  std::time_t currentTime = std::time(nullptr);

  // Converter para uma estrutura tm (hora local)
  std::tm *localTime = std::localtime(&currentTime);

  // Extrair o mï¿½s e o ano atual
  month = localTime->tm_mon + 1;    // tm_mon ï¿½ base 0 (janeiro ï¿½ representado por 0)
  year = localTime->tm_year + 1900; // tm_year ï¿½ o nï¿½mero de anos desde 1900
  // Mï¿½s e ano atual
  current_month = localTime->tm_mon + 1; 
  current_year =  localTime->tm_year + 1900; 
  
  option = 3;
  cout << endl;
  while (option != 2){
    if (year_back >= year_next){
      // Exibir o calendï¿½rio do mï¿½s atual
      cout << "\n------------------------------";
      cout << "\n       DATA DAS VIAGENS";
      cout << "\n------------------------------";
      std::cout << "\n        " << name_month[month_back] << "       " << month_back << "/" << year_back << std::endl;
      printCalendar(year, month);

      // Pedir ao usuï¿½rio para navegar para o mï¿½s seguinte ou anterior
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
    cout << "\nNecessário no minímo 1 passagem de adulto!";
    }
  }
}
void horario(){
  // Obter o tempo atual
  auto tempoAtu = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  // Converter o tempo em uma struct tm
  std::tm* dataHoraAtual = std::localtime(&tempoAtu);
  // Obter o dia do mï¿½s atual
  diaAtual = dataHoraAtual->tm_mday;
  // Obter o horï¿½rio atual do sistema
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
  // Mostrando o horï¿½rio atual
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
    cout << "Arquivo invï¿½lido";
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
      cout << "\nCPF invï¿½lido!" << endl;
      dados_viajante();
    }
    else{
      cont++;
    }
  }
}

int tamDados;
void lugar_preco_hora(){
  fstream horarioVoo;
  string lerArq, linha, guarda, dia, mes, ano, horario, preco, guardaLocais;
  int aux = 0, tamArq = 0, tamLocais = 0;
  tamDados = 0;
  fstream lerLugares;
  lerLugares.open("lugaresVoo.txt", ios::in);
  while (getline(lerLugares, linha)){
    for (int i = 0; i < linha.size(); i++){
      if (linha[i] == ';'){
        tamLocais++;
      }
    }
  }
  string locais[tamLocais];
  lerLugares.close();
  lerLugares.open("lugaresVoo.txt", ios::in);
  for(int j = 0; j < tamLocais;){
    while (getline(lerLugares, linha)){
      for (int i = 0; i < linha.size(); i++){
        if (linha[i] != ';'){
          guardaLocais = guardaLocais + linha[i];
        }
        else{
        locais[j] = guardaLocais;
        guardaLocais = "";
        j++;
        }
      }
    }
  } 
  lerLugares.close();
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
    for(int j = 0; j < tamDados;){
      while(getline(horarioVoo, linha)){
        for(int i = 0; i < linha.size(); i++){
          if(linha[i] != ',' && linha[i] != '!'){
            guarda = guarda + linha[i];
          if(linha[i] == '/'){
            guarda = "";
            }
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
    cout << "\nArquivo inváido, tente novamente!" << endl;
  }
  horarioVoo.close();  
  
  switch (opc_orig){
  case 0:
    rj[tamDados].time;
    rj[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      rj[i].time = voos[i].time;
      rj[i].priceTime = voos[i].priceTime;
    }
    break;
  case 1:
    sp[tamDados].time;
    sp[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      sp[i].time = voos[i].time;
      sp[i].priceTime = voos[i].priceTime;
    }
    break;
  case 2:
    bel[tamDados].time;
    bel[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      bel[i].time = voos[i].time;
      bel[i].priceTime = voos[i].priceTime;
    }
    break;
  case 3:
    vix[tamDados].time;
    vix[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      vix[i].time = voos[i].time;
      vix[i].priceTime = voos[i].priceTime;
    }
    break;
  case 4:
    cgb[tamDados].time;
    cgb[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      cgb[i].time = voos[i].time;
      cgb[i].priceTime = voos[i].priceTime;
    }
    break;
  case 5:
    cwb[tamDados].time;
    cwb[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      cwb[i].time = voos[i].time;
      cwb[i].priceTime = voos[i].priceTime;
    }
    break;
  case 6:
    fort[tamDados].time;
    fort[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      fort[i].time = voos[i].time;
      fort[i].priceTime = voos[i].priceTime;
    }
    break;
  case 7:
    gyn[tamDados].time;
    gyn[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      gyn[i].time = voos[i].time;
      gyn[i].priceTime = voos[i].priceTime;
    }
    break;
  case 8:
    mao[tamDados].time;
    mao[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      mao[i].time = voos[i].time;
      mao[i].priceTime = voos[i].priceTime;
    }
    break;
  case 9:
    poa[tamDados].time;
    poa[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      poa[i].time = voos[i].time;
      poa[i].priceTime = voos[i].priceTime;
    }
    break;
  case 10:
    bsb[tamDados].time;
    bsb[tamDados].priceTime;
    for(int i = 0; i < tamDados; i++){
      bsb[i].time = voos[i].time;
      bsb[i].priceTime = voos[i].priceTime;
    }
    break; 
  }
}
void horario_voo(){
  setlocale(LC_ALL, "Portuguese_Brazil");
  lugar_preco_hora();
  tamLugar = 0;
  for (int i = 0; i < 100; i++){
    precoLocal[i] = "";
    localSele[i] = "";
  }
  switch (opc_orig){
  case 0:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = rj[i].time;
      precoLocal[i] = rj[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 1:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = sp[i].time;
      precoLocal[i] = sp[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 2:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = bsb[i].time;
      precoLocal[i] = bsb[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 3:
     for (int i = 0; i < tamDados; i++){
      localSele[i] = poa[i].time;
      precoLocal[i] = poa[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 4:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = vix[i].time;
      precoLocal[i] = vix[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 5:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = vix[i].time;
      precoLocal[i] = vix[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 6:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = cwb[i].time;
      precoLocal[i] = cwb[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 7:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = mao[i].time;
      precoLocal[i] = mao[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 8:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = bel[i].time;
      precoLocal[i] = bel[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 9:
    for (int i = 0; i < tamDados; i++){
      localSele[i] = poa[i].time;
      precoLocal[i] = poa[i].priceTime;
      tamLugar++;
    }
    guarda_lugares();
    break;
  case 10:
    for (int i = 0; i < tamDados; i++){
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
  string guardaDados[Tam_linha][Tam_Col], guarda_origens[2];
  int opc_orig2 = 0;
  opc_orig2 = opc_orig;
  
  switch (opc_orig){
    case 0:
    guarda_origens[0] = "ArqDias_RJ.txt";
      break;
    case 1:
    guarda_origens[1] = "ArqDias_SP.txt";
      break;
  }
  lerArq.open(guarda_origens[opc_orig2], ios::in);
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

  lerArq.open(guarda_origens[opc_orig2], ios::in);
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
    cout << "\nArquivo invï¿½lido!" << endl;
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
      cout << "\nDigite 'S' para SIM ou 'N' para NÃO: ";
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

  



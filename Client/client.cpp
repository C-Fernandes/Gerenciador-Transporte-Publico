#include "headerClient.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void separadorC()
{
  cout << "----------------------------------------------" << endl;
}
void listarOnibus()
{
  fstream arq;
  string leitura, palavra;

  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, leitura))
  {
    vector<string> palavras;
    istringstream tokenizer{leitura};
    while (getline(tokenizer, palavra, '-'))
    {
      palavras.push_back(palavra);
    }
 
    cout << "Nome do ônibus:" << palavras[0] << " - Terminal: " << palavras[1] << endl;
    separadorC();
  };
  arq.close();
}
void registrarReclamacao(){
  fstream arq;
  string reclamacao, data;
  arq.open("./Arquivos/reclamacoes.txt", ios::out | ios::app);
  cout << "Informe a data de hoje: (DD/MM/AAAA)" << endl;
  getline(cin, data);
  cout << "Digite sua reclamação, não se preocupe, ela será feita de forma anônima." << endl;
  getline(cin, reclamacao);
  data += '-' + reclamacao;
  arq << data;
}
void consultarIntinerario(std::string nomeOnibus)
{
  fstream arq;
  string linha, palavra;

  bool encontrou = false;
  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, linha))
  {
    vector<string> palavras;
    istringstream separacao(linha);
    while (getline(separacao, palavra, '-'))
    {
      palavras.push_back(palavra);
    }
    if (palavras[0] == nomeOnibus)
    {
      encontrou = true;
 
      cout << "Nome do ônibus: " << palavras[0] << "\nItinerario: \n";
      for (int i = 2; i < palavras.size(); i++)
      {
        cout << palavras[i] << endl;
      }
      separadorC();
      break;
    }
  }
  if (!encontrou)
    cout << "Ônibus não encontrado." << endl;
}
void buscarPorTerminal(std::string terminal){
   fstream arq;
  string linha, palavra;

  bool encontrou = false;
  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, linha))
  {
    vector<string> palavras;
    istringstream separacao(linha);
    while (getline(separacao, palavra, '-'))
    {
      palavras.push_back(palavra);
    }
    if (palavras[1] == terminal)
    {
      encontrou = true;
 
      cout << "Nome do ônibus: " << palavras[0] << endl;
      separadorC();
      break;
    }
  }
  if (!encontrou)
    cout << "Ônibus não encontrado." << endl;

}
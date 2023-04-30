#include "headerClient.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void linhaC()
{
  cout << "----------------------------------------------" << endl;
}
void printarOnibus(vector<string> onibus)
{
  cout << "Nome do ônibus:" << onibus[0] << "\nTerminal: " << onibus[1] << "\nIntinerario: "
       << endl;

  for (int i = 2; i < onibus.size(); i++)
  {
    cout << onibus[i] << endl;
  }
  linhaC();
}
vector<string> separadorLinha(std::string frase)
{
  vector<string> palavras;
  string palavra;
  istringstream separacao(frase);
  while (getline(separacao, palavra, '-'))
  {
    palavras.push_back(palavra);
  }
  return palavras;
}
void listarOnibus()
{
  fstream arq;
  string leitura, palavra;

  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinha(leitura);
    printarOnibus(palavras);
  };
  arq.close();
}
void registrarReclamacao()
{
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
    vector<string> palavras= separadorLinha(linha);
    if (palavras[0] == nomeOnibus)
    {
      encontrou = true;
      printarOnibus(palavras);
      linhaC();
      break;
    }
  }
  if (!encontrou)
    cout << "Ônibus não encontrado." << endl;
}
void buscarPorTerminal(std::string terminal)
{
  fstream arq;
  string linha, palavra;

  bool encontrou = false;
  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, linha))
  {
    vector<string> palavras = separadorLinha(linha);
   
    if (palavras[1] == terminal)
    {
      encontrou = true;
      printarOnibus(palavras);
      linhaC();
      break;
    }
  }
  if (!encontrou)
    cout << "Ônibus não encontrado." << endl;
}
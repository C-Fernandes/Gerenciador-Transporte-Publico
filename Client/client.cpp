#include "headerClient.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void linha() // Função para printar linha
{
  cout << "----------------------------------------------" << endl;
}
void printarOnibus(vector<string> onibus) // Função para printar qualquer ônibus
{
  linha();
  cout << "Nome do ônibus: " << onibus[0] << "\nTerminal: " << onibus[1] << "\nIntinerario: "
       << endl;

  for (int i = 2; i < onibus.size(); i++)
  {
    cout << onibus[i] << endl;
  }
  
}
vector<string> separadorLinha(std::string frase) // Função para separar em vector uma string(linha) retirada do arquivo
{
  vector<string> palavras;
  string palavra;
  istringstream separacao(frase);
  while (getline(separacao, palavra, ';')) // Separando as palavras por ;
  {
    palavras.push_back(palavra);
  }
  return palavras;
}
void listarOnibus() // Função listar onibus 
{
  fstream arq;
  string leitura, palavra;

  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinha(leitura); // utilizando a função para printar os ônibus sem ;
    printarOnibus(palavras);
  };
  linha();
  arq.close();
}
void registrarReclamacao() // Função para registrar reclamação
{
  fstream arq;
  string reclamacao, data;
  arq.open("./Arquivos/reclamacoes.txt", ios::out | ios::app);
  cout << "Informe a data de hoje: (DD/MM/AAAA)" << endl;
  getline(cin, data);
  cout << "Digite sua reclamação, não se preocupe, ela será feita de forma anônima." << endl;
  getline(cin, reclamacao);
  data += ';' + reclamacao + "\n"; // Adicionar - para cadastrar linha completa com ambos os dados no arquivo
  arq << data;
}
void consultarIntinerario(std::string nomeOnibus) // Função para consultar ônibus por itinerario
{
  fstream arq;
  string linha, palavra;

  bool encontrou = false;                     // Variavel para caso nn encontre poder informar ao usuario
  arq.open("./Arquivos/onibus.txt", ios::in); // Abrir arquivos para leitura e ler dados
  while (getline(arq, linha))
  {
    vector<string> palavras = separadorLinha(linha); // Separar linhas
    if (palavras[0] == nomeOnibus)                   // O nome sempre vai estar na primeira posição, verificamos portanto se a 1º posição é igual ao nome
    {
      encontrou = true;
      printarOnibus(palavras); // Printa o ônibus
      break;                   // Como encontrou o ônibus não precisa mais verificar outras linhas
    }
  }
  if (!encontrou) // Caso não encontre o ônibus com esse nome, informar ao usuário
    cout << "Ônibus não encontrado." << endl;
}
void buscarPorTerminal(std::string terminal) // Função para buscar por Terminal
{
  fstream arq;
  string leitura, palavra;

  bool encontrou = false;
  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinha(leitura);

    if (palavras[1] == terminal) // Muda apenas que em vez de verificar a posição 0, verificaremos a posição 1, já que o terminal estará sempre salvo depois do nome, sua posição será sempre a 1

    {
      encontrou = true;
      printarOnibus(palavras);
      linha();
      break;
    }
  }
  if (!encontrou)
    cout << "Ônibus não encontrado." << endl;
}
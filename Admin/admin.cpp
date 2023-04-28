#include "headerAdmin.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void separador()
{
  cout << "----------------------------------------------"<<endl;
}
bool verificarAutorizacao(std::string senha)
{
  if (senha == "123")
  {
    return true;
  }
  else
  {
    return false;
  }
}
void listarOnibusAdmin()
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
    cout << "Nome do ônibus:" << palavras[0] << "\nTerminal: " << palavras[1] << "\nIntinerario: "
         << endl;

    for (int i = 2; i < palavras.size(); i++)
    {
      cout << palavras[i] << endl;
    }
    separador();
  };
  arq.close();
}
void listarReclamacoes()
{
  fstream arq;
  string leitura;

  arq.open("./Arquivos/reclamacoes.txt", ios::in);
  while (getline(arq, leitura))
  {
    cout << leitura << endl;
  };
  arq.close();
}
void cadastrarOnibus(std::string nomeBus)
{
  cout << "Entrou aqui\n";
  string terminal, parada, paradas, onibus;
  int retorno;
  cout << "Informe o terminal do ônibus:\n";
  getline(cin, terminal);
  cout << "Adicione a primeira parada do ônibus:\n";
  getline(cin, parada);

  while (true)
  {
    cout << "Entrou no while\n";
    paradas += "-" + parada;
    cout << "Deseja adicionar mais uma parada?\n1-Sim\n2-Não\n";
    cin >> retorno;
    cin.ignore();
    if (retorno == 1)
    {
      cout << "Informe a próxima parada: \n";
      getline(cin, parada);
    }
    else
    {
      onibus = nomeBus + "-" + terminal + paradas + "\n";
      fstream arq;
      arq.open("./Arquivos/onibus.txt", ios::out | ios::app);
      cout << "Passou do abrir arquivo\n";
      cout << onibus;
      arq << onibus;
      arq.close();
      cout << "Fechou arquivo\n";
      break;
    }
  };
}
void buscarOnibusPorNome(std::string nomeBus)
{

  fstream arq;
  string leitura, palavra;
  bool encontrou = false;

  arq.open("./Arquivos/onibus.txt", ios::in);

  while (getline(arq, leitura))
  {
    vector<string> palavras;
    istringstream separacao(leitura);
    while (getline(separacao, palavra, '-'))
    {
      palavras.push_back(palavra);
    }
    if (palavras[0] == nomeBus)
    {
      encontrou = true;
      separador();
      cout << "Nome do ônibus: " << palavras[0] << "\nBairro: " << palavras[1] << "\nItinerario: \n";
      for (int i = 2; i < palavras.size(); i++)
      {
        cout << palavras[i] << endl;
      }
      separador();
      break;
    }
  }
  if (!encontrou)
    cout << "Não foi possivel encontrar o ônibus." << endl;
}
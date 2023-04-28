#include "headerAdmin.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool verificarAutorizacao(std::string senha)
{
  if (senha == "1a2b3c4d")
  {
    return true;
  }
  else
  {
    return false;
  }
}



void listarOnibus()
{
  fstream arq;
  string leitura, palavra;
  vector<string> palavras;

  arq.open(nomeDoArquivo, ios::in);
  while (getline(arq, leitura))
  {

    cout << leitura << endl;
    istringstream tokenizer{leitura};
    while (getline(tokenizer, palavra, '-'))
    {
      palavras.push_back(palavra);
    }
    cout << "Nome do ônibus:" <<palavras[0]<<"\n - Terminal: "<<palavras[1]<< endl;
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
      arq.open("./Arquivos/onibus.txt", ios::out);
      cout << "Passou do abrir arquivo\n";
      cout << onibus;
      arq << onibus;
      arq.close();
      cout << "Fechou arquivo\n";
      break;
    }
  };
}
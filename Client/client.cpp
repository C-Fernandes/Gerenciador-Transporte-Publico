#include "headerClient.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int menuClient()
{
  int entrada;
  cout << "Informe o que deseja fazer: \n1 - Consultar ônibus cadastrados\n2 - "
          "Buscar ônibus por bairro\n3 - Consultar itinerário\n4 - Fazer uma "
          "reclamação\n5 - Voltar\n6 - Fechar"
       << endl;
  cin >> entrada;
  // 1 - Não precisa encerrar
  // 2 - Voltar para o menu anterior
  // 3 - Encerrar programa
  if (entrada == 1)
  {
  }
  if (entrada == 2)
  {
  }
  if (entrada == 3)
  {
  }
  if (entrada == 4)
  {
  }
  if (entrada == 5)
  {
  }
  if (entrada == 6)
  {
  }

  return 1;
}

void listar(std::string nomeDoArquivo)
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
    cout << "Nome do ônibus:" <<palavras[0]<<"\nTerminal: "<<palavras[1]<< endl;
    for (int i = 2; i < palavras.size(); i++)
    {
      cout << palavras[i];
    };
  };
  arq.close();
}

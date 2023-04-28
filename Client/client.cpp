#include "headerClient.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


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
    cout << "Nome do ônibus:" <<palavras[0]<<"\n - Terminal: "<<palavras[1]<< endl;
  };
  arq.close();
}

void registrarReclamacao(){
  fstream arq;
  string reclamacao;
  arq.open("./Arquivos/reclamacoes.txt", ios::in);
  cout << "Digite sua reclamação, não se preocupe, ela será feita de forma anônima." << endl;

  getline(cin, reclamacao);
  arq << reclamacao << "\n" <<endl;
}

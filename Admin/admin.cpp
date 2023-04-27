#include "headerAdmin.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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

int menuAdmin()
{
  int entrada;
  cout << "Informe o que deseja fazer: \n1 - Listar ônibus cadastrados\n2 - "
          "Buscar ônibus por nome\n3 - Buscar ônibus por terminal\n4 - "
          "Atualizar terminal\n5 - Atualizar itinerário\n6 - Excluir um "
          "ônibus\n7 - Listar reclamações\n8 - Cadastrar ônibus\n9 - Voltar\n10 - Encerrar"
       << endl;

  cin >> entrada;

  switch (entrada)
  {
  case 1:
    listar("onibus.txt");
    return 1;
    break;
  case 2:
    return 1;
    break;
  case 3:
    return 1;
    break;
  case 4:
    return 1;
    break;
  case 5:
    return 1;
    break;
  case 6:
    return 1;
    break;
  case 7:
    listar("reclamacoes.txt");
    return 1;
    break;
  case 8:
    return 1;
    break;
  case 9:
    return 2;
    break;
  case 10:
    return 3;
    break;
  }
}

void listar(std::string nomeDoArquivo)
{
  FILE *arq;
  string leitura;
  arq = fopen(nomeDoArquivo.c_str(), "r");
  while (fscanf(arq, "\n", leitura) != NULL)
  {
    cout << leitura << "\n"
         << endl;
  };
  fclose(arq);
}

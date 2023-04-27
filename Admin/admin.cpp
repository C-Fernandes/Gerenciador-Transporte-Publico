#include "headerAdmin.hpp"
#include <iostream>
#include <fstream>
#include <map>

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
  cin.ignore();

  if (entrada == 1)
  {
    listar("./Arquivos/onibus.txt");
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
  if (entrada == 7)
  {
    listar("./Arquivos/reclamacoes.txt");
  }
  if (entrada == 8)
  {
    string nomeBus;
    cout << "Informe o nome do ônibus que deseja cadastrar a rota:\n";
    getline(cin, nomeBus);
    cadastrarOnibus(nomeBus);
  }
  if (entrada == 9)
  {
    return 2;
  }
  if (entrada == 10)
  {
    return 3;
  }

  /*
    switch (entrada)
    {
    case 1:

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
      listar("../Arquivos/reclamacoes.txt");
      return 1;
      break;
    case 8:
      string nomeBus;
      cout << "Informe o nome do ônibus que deseja cadastrar a rota:\n";
      cin >> nomeBus;
      cadastrarOnibus(nomeBus);
      return 1;
      break;
    case 9:
      return 2;
      break;
    case 10:
      return 3;
      break;
    }
    */
  return 1;
}

void listar(std::string nomeDoArquivo)
{
  fstream arq;
  string leitura;
  arq.open(nomeDoArquivo, ios::in);
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
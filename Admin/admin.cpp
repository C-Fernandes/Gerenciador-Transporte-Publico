#include "headerAdmin.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void linhaA()
{
  cout << "----------------------------------------------" << endl;
}
void printarOnibusA(vector<string> onibus)
{
  cout << "Nome do ônibus:" << onibus[0] << "\nTerminal: " << onibus[1] << "\nIntinerario: "
       << endl;

  for (int i = 2; i < onibus.size(); i++)
  {
    cout << onibus[i] << endl;
  }
  linhaA();
}
vector<string> separadorLinhaA(std::string frase)
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
    palavras = separadorLinhaA(leitura);
    printarOnibusA(palavras);
    linhaA();
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
    palavras = separadorLinhaA(leitura);
    if (palavras[0] == nomeBus)
    {
      encontrou = true;
      printarOnibusA(palavras);
      linhaA();
      break;
    }
  }
  if (!encontrou)
    cout << "Não foi possivel encontrar o ônibus." << endl;
}
void atualizarTerminal(std::string nomeBus)
{
  fstream arq;
  bool encontrou = false;
  string leitura, palavra;
  arq.open("./Arquivos/onibus.txt", ios::in | ios::out);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinhaA(leitura);
    if (nomeBus == palavras[0])
    {
      encontrou = true;
      string novoTerminal, atualizacao;
      cout << "ônibus encontrado! Informe qual o novo nome do terminal:\n"
           << endl;
      getline(cin, novoTerminal);
      atualizacao = palavras[0] + '-' + novoTerminal + '-';
      for (int i = 2; i < palavras.size(); i++)
      {
        if (i < palavras.size() - 1)
        {
          atualizacao += palavras[i] + '-';
        }
        else
        {
          atualizacao += palavras[i];
        }
      }
      int resposta;
      while (true)
      {
        cout << "Deseja confirmar a atualização?\n1-Sim\n2-Não" << endl;
        cin >> resposta;
        cin.ignore();
        if (resposta == 1)
        {
          arq << atualizacao;
          cout << "Ônibus atualizado:" << endl;
          palavras[1] = novoTerminal;
          printarOnibusA(palavras);
          break;
        }
        if (resposta == 2)
        {
          cout << "Atualização cancelada:" << endl;
          printarOnibusA(palavras);
          break;
        }
        else
        {
          cout << "Não entedi a resposta, tente novamente." << endl;
        }
      }
      break;
    }
  }
  if (!encontrou)
    cout << "Ônibus não encontrado" << endl;
}
void atualizarItinerario(std::string nomeBus)
{
  fstream arq;
  bool encontrou = false;
  string leitura, palavra;
  arq.open("./Arquivos/onibus.txt", ios::in | ios::out);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinhaA(leitura);
    if (nomeBus == palavras[0])
    {
      encontrou = true;
      vector<string> novoItinerario;
      string atualizacao;
      int resposta, contador = 1;
      cout << "ônibus encontrado! Informe o novo do itinerario:\n"
           << endl;
      getline(cin, novoItinerario[0]);
      while (true)
      {
        cout << "Deseja adicionar mais uma parada?\n1 - Sim\n2 - Não" << endl;
        cin >> resposta;
        cin.ignore();
        if (resposta == 1)
        {
          cout << "Digite a próxima parada:" << endl;
          getline(cin, novoItinerario[contador]);
          contador++;
        }
        if (resposta == 2)
        {
          atualizacao = palavras[0] + '-' + palavras[1] + '-';
          for (int i = 0; i < novoItinerario.size(); i++)
          {
            if (i != novoItinerario.size() - 1)
            {
              atualizacao += novoItinerario[i] + '-';
            }
            if (i == novoItinerario.size() - 1)
            {
              atualizacao += novoItinerario[i];
            }
          }
          vector<string> novoOnibus = separadorLinhaA(atualizacao);

          int resposta;
          printarOnibusA(novoOnibus);
          cout << "Deseja confirmar a atualização?\n1 - Sim\n2 - Não" << endl;
          cin >> resposta;
          cin.ignore();
          while (true)
          {
            if (resposta == 1)
            {
              arq << atualizacao;
              cout << "Ônibus atualizado!" << endl;
              break;
            }
            if (resposta == 2)
            {
              cout << "Atualização cancelada!" << endl;
              break;
            }
            else
            {
              cout << "Não entedi a resposta, tente novamente." << endl;
            }
          }
        }
      }
    }
    if (!encontrou)
      cout << "Ônibus não encontrado" << endl;
  }
}
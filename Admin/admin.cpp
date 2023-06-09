#include "headerAdmin.hpp"
#include "../Client/headerClient.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

bool verificarAutorizacao(std::string senha) // Verifica se a senha está correta ou não
{
  if (senha == "admin")
  {
    return true;
  }
  else
  {
    return false;
  }
}
void listarReclamacoes() // Lista as reclamações para o adm
{
  fstream arq;
  string leitura;
vector<string> linhaR;
  arq.open("./Arquivos/reclamacoes.txt", ios::in);
  linha();
  while (getline(arq, leitura))
  {
    linhaR = separadorLinha(leitura);
    cout << linhaR[0] << " - " << linhaR[1] << endl;
  };
  linha();
  arq.close();
}
void cadastrarOnibus(std::string nomeBus) // Função para adm cadastrar ônibus
{
  string terminal, parada, paradas, onibus;
  int retorno;
  cout << "Informe o terminal do ônibus:\n";
  getline(cin, terminal);
  cout << "Adicione a primeira parada do ônibus:\n";
  getline(cin, parada);

  while (true) // Repetição para usuário cadastrar as paradas de forma ilimitada
  {
    paradas += ";" + parada;
    cout << "Deseja adicionar mais uma parada?\n1-Sim\n2-Não\n";
    cin >> retorno;
    cin.ignore();
    if (retorno == 1) // Caso deseje continuar
    {
      cout << "Informe a próxima parada: \n";
      getline(cin, parada);
    }
    else // Caso o usuário tenha terminado de cadastrar todas as paradas
    {
      onibus = nomeBus + ";" + terminal + paradas + "\n"; // Adiciona todas as informações na variavel ônibus divididas por -
      fstream arq;
      arq.open("./Arquivos/onibus.txt", ios::out | ios::app); // Abre o arquivo no fim para gravar o novo ônibus
      arq << onibus;
      arq.close();
      break;
    }
  };
}
void buscarOnibusPorNome(std::string nomeBus) // Função para buscar por nome, copia da função do cliente
{
  fstream arq;
  string leitura, palavra;
  bool encontrou = false;

  arq.open("./Arquivos/onibus.txt", ios::in);

  while (getline(arq, leitura))
  {
    vector<string> palavras;
    palavras = separadorLinha(leitura); // Utilizando a função separador
    if (palavras[0] == nomeBus)
    {
      encontrou = true;
      printarOnibus(palavras);
      break;
    }
  }
  linha();
  if (!encontrou)
    cout << "Não foi possivel encontrar o ônibus." << endl;
}
void atualizarTerminal(std::string nomeBus) // Função para atualizar terminal
{
  fstream arq;
  bool encontrou = false;
  string leitura, palavra;
  vector<string> novaLista;
  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinha(leitura);
    if (nomeBus == palavras[0]) // Verifica se encontrou o ônibus
    {
      encontrou = true;
      string novoTerminal, atualizacao;
      cout << "ônibus encontrado! Informe qual o novo nome do terminal:\n"
           << endl;
      getline(cin, novoTerminal);                           // Pega o nome do novo terminal
      atualizacao = palavras[0] + ';' + novoTerminal + ';'; // Adiciona o novo terminal e o nome, separados por - na string atualização
      for (int i = 2; i < palavras.size(); i++)             // Adiciona o itinerario na string
      {
        if (i < palavras.size() - 1)
        {
          atualizacao += palavras[i] + ';';
        }
        else
        {
          atualizacao += palavras[i];
        }
      }
      int resposta;
      while (true) // Confirma atualização com o usuário
      {

        palavras[1] = novoTerminal;
        printarOnibus(palavras); // Printa o onibus com o terminal atualizado
        linha();
        cout << "Deseja confirmar a atualização?\n1-Sim\n2-Não" << endl;
        cin >> resposta;
        cin.ignore();
        if (resposta == 1) // Se confirmar a atualização, atualiza a variavel leitura com todas as informações atualizadas
        {
          leitura = atualizacao;
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
    novaLista.push_back(leitura); //Adiciona a variavel leitura numa nova lista, para sobreescrever e atualizar o arquivo
  }
  arq.close(); //Fecha o arquivo
  arq.open("./Arquivos/onibus.txt", ios::out);  //Abre pra escrita 
  for (int i = 0; i < novaLista.size(); i++) //Sobreescreve o arquivo 
  {
    novaLista[i] += "\n";
    arq << novaLista[i];
  }
  if (!encontrou)
    cout << "Ônibus não encontrado" << endl;
}
void atualizarItinerario(std::string nomeBus) // Função para atualizar itinerario, mesmo modelo da função para atualizar terminal
{
  fstream arq;
  bool encontrou = false;
  string leitura, palavra;
  vector<string> novaLista;
  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinha(leitura);
    if (nomeBus == palavras[0])
    {
      encontrou = true;
      vector<string> novoItinerario;
      string atualizacao, novaParada;
      int resposta;
      cout << "Ônibus encontrado! Informe o novo do itinerario:\n"
           << endl;
      getline(cin, novaParada);
      novoItinerario.push_back(novaParada);
      while (true) //A única mudança da função anterior, vai a grosso modo, perguntar quantas vezes o usário deseja adicionar outra parada
      {
        cout << "Deseja adicionar mais uma parada?\n1 - Sim\n2 - Não" << endl;
        cin >> resposta;
        cin.ignore();
        if (resposta == 1)
        {
          cout << "Digite a próxima parada:" << endl;
          getline(cin, novaParada);
          novoItinerario.push_back(novaParada);
        }
        if (resposta == 2)
        {
          atualizacao = palavras[0] + ';' + palavras[1] + ';';
          for (int i = 0; i < novoItinerario.size(); i++)
          {
            if (i != novoItinerario.size() - 1)
            {
              atualizacao += novoItinerario[i] + ';';
            }
            if (i == novoItinerario.size() - 1)
            {
              atualizacao += novoItinerario[i];
            }
          }
          break;
        }
      }

      vector<string> novoOnibus = separadorLinha(atualizacao);

      printarOnibus(novoOnibus);
      while (true)
      {
        linha();
        cout << "Deseja confirmar a atualização?\n1 - Sim\n2 - Não" << endl;
        cin >> resposta;
        cin.ignore();

        if (resposta == 1)
        {
          leitura = atualizacao;
          cout << "Ônibus atualizado!" << endl;
          linha();
          break;
        }
        if (resposta == 2)
        {
          cout << "Atualização cancelada!" << endl;
          linha();
          break;
        }
        else
        {
          cout << "Não entedi a resposta, tente novamente." << endl;
        }
      }
    }
    novaLista.push_back(leitura);
  }
  if (!encontrou)
    cout << "Ônibus não encontrado" << endl;
  arq.close();
  arq.open("./Arquivos/onibus.txt", ios::out);
  for (int i = 0; i < novaLista.size(); i++)
  {
    novaLista[i] += "\n";
    arq << novaLista[i];
  }
}
void excluirOnibus(std::string nomeOnibus) // Função para excluir ônibus
{

  fstream arq;
  string leitura;
  bool encontrou = false;
  vector<string> novaLista;
  arq.open("./Arquivos/onibus.txt", ios::in);
  while (getline(arq, leitura))
  {
    vector<string> palavras = separadorLinha(leitura);
    if (palavras[0] != nomeOnibus)  // Enquanto for diferente do ônibus procurado, adiciona 
    {                               // a linha numa nova lista, para sobreescrever e atualizar arquivo  
      novaLista.push_back(leitura); 
    }
    else // Quando encontra, só marca que encontrou
    {
      encontrou = true;
    }
  }
  arq.close();
  arq.open("./Arquivos/onibus.txt", ios::out);
  for (int i = 0; i < novaLista.size(); i++) // Sobrescreeve o arquivo com a nova lista, sem o ônibus excluido
  {
    novaLista[i] += "\n";
    arq << novaLista[i];
  }
  arq.close();
  if (!encontrou)
    cout << "Ônibus não encontrado" << endl;
  if (encontrou)
    linha();
  cout << "Ônibus excluido com sucesso!" << endl;
  linha();
}
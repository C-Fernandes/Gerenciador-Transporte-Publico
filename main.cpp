#include "Admin/headerAdmin.hpp"
#include "Client/headerClient.hpp"
#include <iostream>

using namespace std;

int main()
{

    cout << "##### BEM VINDO AO SISTEMA GERENCIADOR DE TRANSPORTE PÚBLICO #####\n" << endl;
    bool continuar = true;
    int entrada;
    while (continuar)
    {
        cout << "Informe o tipo de usuário que deseja acessar:\n1 - Cliente\n2 - Administrador\n3 - "
                "Encerrar" << endl;
        cin >> entrada;
        cin.ignore();

        if (entrada == 1)
        {
            while (true)
            {
                int entrada;
                cout << "Informe o que deseja fazer: \n1 - Consultar ônibus cadastrados\n2 - "
                        "Buscar ônibus por bairro\n3 - Consultar itinerário\n4 - Fazer uma "
                        "reclamação\n5 - Voltar\n0 - Fechar"
                     << endl;
                cin >> entrada;
                cin.ignore();
                if (entrada == 1)
                {
                    listarOnibus();
                }
                if (entrada == 2)
                {
                    string terminal;
                    cout << "Informe o bairro para realizar a busca:" << endl;
                    getline(cin, terminal);
                    buscarPorTerminal(terminal);
                }
                if (entrada == 3)
                {
                    string nomeOnibus;
                    cout << "Informe o nome do ônibus para consultar o itinerario:" << endl;
                    getline(cin, nomeOnibus);
                    consultarIntinerario(nomeOnibus);
                }
                if (entrada == 4)
                {
                    registrarReclamacao();
                }
                if (entrada == 5)
                {
                    break;
                }
                if (entrada == 0)
                {
                     cout << "Encerrando o programa..." << endl;
                    continuar = false;
                    break;
                }
            }
        }
        if (entrada == 2)
        {

            string senha;
            bool verificacao;
            cout << "Para acessar, informe a senha:\n"
                 << endl;
            getline(cin, senha);
            verificacao = verificarAutorizacao(senha);
            if (verificacao)
            {
                cout << "--------------------------------------\n        Bem vindo Administrador!\n--------------------------------------\n"
                     << endl;
                while (true)
                {

                    int entrada;
                    cout << "Informe o que deseja fazer: \n1 - Listar ônibus cadastrados\n2 - "
                            "Buscar ônibus por nome\n3 - Buscar ônibus por terminal\n4 - "
                            "Atualizar terminal\n5 - Atualizar itinerário\n6 - Excluir um "
                            "ônibus\n7 - Listar reclamações\n8 - Cadastrar ônibus\n9 - Voltar\n0 - Encerrar"
                         << endl;

                    cin >> entrada;
                    cin.ignore();

                    if (entrada == 1)
                    {
                        listarOnibus();
                    }
                    if (entrada == 2)
                    {
                        string onibus;
                        cout << "Por favor, informe o nome do ônibus que deseja consultar:\n";
                        getline(cin, onibus);
                        buscarOnibusPorNome(onibus);
                    }
                    if (entrada == 3)
                    {
                        string terminal;
                        cout << "Informe o bairro para realizar a busca:" << endl;
                        getline(cin, terminal);
                        buscarPorTerminal(terminal);
                    }
                    if (entrada == 4)
                    {
                        string onibus;
                        cout << "Por favor, informe o nome do ônibus que deseja atualizar:\n";
                        getline(cin, onibus);
                        atualizarTerminal(onibus);
                    }
                    if (entrada == 5)
                    {
                        string onibus;
                        cout << "Por favor, informe o nome do ônibus que deseja atualizar o itinerario:\n";
                        getline(cin, onibus);
                        atualizarItinerario(onibus);
                    }
                    if (entrada == 6)
                    {
                        string nomeBus;
                        cout << "Informe o nome do ônibus que deseja excluir:\n";
                        getline(cin, nomeBus);
                        excluirOnibus(nomeBus);
                    }
                    if (entrada == 7)
                    {
                        listarReclamacoes();
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
                        break;
                    }
                    if (entrada == 0)
                    {
                        continuar = false;
                        cout << "Encerrando o programa..." << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "Senha incorreta!\n"
                     << endl;
            }
        }
        if (entrada == 3)
        {
             cout << "Encerrando o programa..." << endl;
            continuar = false;
        }
    }
    return 0;
}

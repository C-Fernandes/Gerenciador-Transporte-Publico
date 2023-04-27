#include "Admin/headerAdmin.hpp"
#include "Client/headerClient.hpp"
#include <iostream>

using namespace std;

int main()
{
    int retorno = 1;
    int entrada;
    while (retorno != 3)
    {
        cout << "Informe o tipo de usuário:\n1 - Cliente\n2 - Administrador\n3 - "
                "Encerrar\n";
        cin >> entrada;
        cin.ignore();

        if (entrada == 1)
        {
            while (retorno == 1)
            {
                retorno = menuClient();
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
                cout << "--------------------------------------\nBem vindo "
                        "Administrador!\n--------------------------------------\n"
                     << endl;
                retorno = menuAdmin();
            }
            else
            {
                cout << "Senha incorreta!\n"
                     << endl;
            }
        }
        if (entrada == 3)
        {
        }
    }
    return 0;
}

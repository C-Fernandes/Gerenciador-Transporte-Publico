#include "headerAdmin.hpp"
#include <iostream>

using namespace std;

bool verificarAutorizacao(string senha) {
  if (senha == "1a2b3c4d") {
    return true;
  } else {
    return false;
  }
}

int menuAdmin() {
  int entrada;
  cout << "Informe o que deseja fazer: \n1 - Listar ônibus cadastrados\n2 - "
          "Buscar ônibus por nome\n3 - Buscar ônibus por terminal\n4 - "
          "Atualizar terminal\n5 - Atualizar itinerário\n6 - Excluir um "
          "ônibus\n7 - Listar reclamações\n8 - Voltar\n9 - Encerrar"
       << endl;

  cin >> entrada;

  switch (entrada) {
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
    return 1;
    break;
  case 8:
    return 2;
    break;
  case 9:
    return 3;
    break;
  }
}
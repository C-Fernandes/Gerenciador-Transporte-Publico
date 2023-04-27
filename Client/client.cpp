#include "headerClient.hpp"
#include <iostream>

using namespace std;

int menuClient() {
  int entrada;
  cout << "Informe o que deseja fazer: \n1 - Consultar ônibus cadastrados\n2 - "
          "Buscar ônibus por bairro\n3 - Consultar itinerário\n4 - Fazer uma "
          "reclamação\n5 - Voltar\n6 - Fechar"
       << endl;
  cin >> entrada;
  // 1 - Não precisa encerrar
  // 2 - Voltar para o menu anterior
  // 3 - Encerrar programa
  if (entrada == 1) {
    return 1;
  }
  if (entrada == 2) {
    return 1;
  }
  if (entrada == 3) {
    return 1;
  }
  if (entrada == 4) {
    return 1;
  }
  if (entrada == 5) {
    return 2;
  }
  if (entrada == 6) {
    return 3;
  }
  return 1;
}

#ifndef HEADERADMIN_HPP
#define HEADERADMIN_HPP

#include <iostream>

bool verificarAutorizacao(std::string senha);
int menuAdmin();
void listar(std::string nomeDoArquivo);
void cadastrarOnibus(std::string nomeBus);



#endif
#ifndef HEADERADMIN_HPP
#define HEADERADMIN_HPP

#include <iostream>

bool verificarAutorizacao(std::string senha);
void listarOnibusAdmin();
void cadastrarOnibus(std::string nomeBus);
void listarReclamacoes();
void buscarOnibusPorNome(std::string nomeBus);

#endif
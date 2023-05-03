#ifndef HEADERCLIENT_HPP
#define HEADERCLIENT_HPP
#include <iostream>
#include <vector>

using namespace std;

void linha();
void printarOnibus(vector<string> onibus);
vector<string> separadorLinha(std::string frase);
void listarOnibus();
void registrarReclamacao();
void consultarIntinerario(std::string nomeOnibus);
void buscarPorTerminal(std::string terminal);

#endif
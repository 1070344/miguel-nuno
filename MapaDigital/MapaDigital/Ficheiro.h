#ifndef Ficheiro_
#define Ficheiro_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "Ficheiro.h"
#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"
#include "ViasLigacao.h"
#include "AutoEstradas.h"
#include "EstradasNacionais.h"

using namespace std;

class Ficheiro
{

private:
	int actual, tamM;
	Locais **vecLocais;
	//Estrada* *Estradas;
public:
	
	Ficheiro();
	Ficheiro(int d);
	Ficheiro(const Ficheiro &f);
	~Ficheiro();

	void inserirLocais(Locais *loc);
	void lerFicheiroLocais();
	void escrever(ostream& ostr) const;
	void contarTiposLocal();
	void ordenar();

};

#endif
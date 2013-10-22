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
		int actual1,actual2;
		int tamanho1,tamanho2;
		Locais **vecLocais;
		ViasLigacao **vecVias;
	public:
		Ficheiro();
		Ficheiro(int t);
		Ficheiro(const Ficheiro &f);
		~Ficheiro();

		void lerFicheiroLocais();
		void inserirLocais(Locais *loc);
		void contarTiposLocal();
		void ordenar();

		void lerFicheiroVias();
		void inserirVias(ViasLigacao *vias);

		void escreverLocais(ostream& ostr) const;
		void escreverVias(ostream& ostr) const;
};

#endif
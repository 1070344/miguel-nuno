#ifndef Pvias_
#define Pvias_

#include "ViasLigacao.h"
#include "graphStlPath.h"
#include "Ficheiro.h"

#include <iostream>


using namespace std;

template<class TV,class TE>
class Pvias
{
	private:
		list<ViasLigacao *>listaVias;
	public:
		Pvias();
		Pvias(const Pvias &pvias);
		~Pvias();

		int percorreListaVias();
		

};





#endif 
#ifndef MapaDigital_
#define MapaDigital_

#include <iostream>
#include <list>

using namespace std;

#include "graphStlPath.h"
#include "Pvias.h"

template<class TV,class TE>
class MapaDigital
{
	private:
		

	public:
		MapaDigital();
		MapaDigital(const MapaDigital &map);
		void criarGrafo();
		void percorreListaVias();
		void caminhoMaisCurto(string Local_1,string Local_2);
};



template<class TV,class TE>
void MapaDigital<TV,TE>::criarGrafo()
{
	graphStlPath<Locais,Pvias> mapa;
	bool graphStl<TV,TE>::addGraphEdge(const TE& eContent, const TV& vOrigin, const TV& vDestination);
	//recebe os valores do metedo percoreListaVias
	//e manda para  o addGraphEdge();
}


template<class TV,class TE>
void MapaDigital<TV,TE>::percorreListaVias()
{
	list<Pvias *> pvias;
	Pvias p;
	//ir buscar os valores à lista das vias com a classe Pvias.h
	//recebe os valores e manda para  o metodo criarGrafo();
}


template<class TV,class TE>
void MapaDigital<TV,TE>::caminhoMaisCurto(string Local_1,string Local_2)
{
	//invocar o metodo queue <TV> getDijkstrasPath(int vKeyOrigin, vector <int> pathKeys)
	//invocar o motodo

}



#endif
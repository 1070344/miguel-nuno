#ifndef MapaDigital_
#define MapaDigital_

#include <iostream>
#include <list>

using namespace std;

#include "graphStlPath.h"
#include "Pvias.h"
#include "ViasLigacao.h"
#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"

class MapaDigital : public graphStlPath <Locais*,Pvias>
{

private: 
	void mostrarCaminho(int vi, const vector <int> &cam);
	void menorCaminho(const string &ci, const string &menorCam);

public:
	MapaDigital();
	MapaDigital(const MapaDigital &map);

	void mostrarGrafo();
	queue < stack <Locais*> > caminhos(const string &local1, const string &local2); //Apresentar todos os percursos possíveis entre dois locais de interesse turístico
	void menorCaminhoDistancia(const string &ci, const string &cf);
	void maiorCaminho(const string &ci, const string &cf);
	void menorCaminhoCusto(const string &ci, const string &cf);
	void tempoMedioVisita(const string &ci, const string &cf);
	Locais * localDef(const string &s1);

	void menorDistancia();
};


MapaDigital::MapaDigital() : graphStlPath <Locais* , Pvias>()
{
}

MapaDigital::MapaDigital(const MapaDigital &map) : graphStlPath <Locais* ,Pvias>(map)
{
}

void MapaDigital::mostrarGrafo()
{
	cout << *this << endl;
}

Locais * MapaDigital::localDef(const string &s1)
{
	Locais * aux;

	list < graphVertex <Locais* ,Pvias> >::iterator itv;
	for (itv=vlist.begin() ; itv != vlist.end() ; itv++ )
	{ 
		if (getVertexContentByKey(aux,itv->getVKey()))
		{ 
			if(aux->getDescricao()==s1)
			{
				return aux; 
			}
		} 
	}
}


queue < stack <Locais*> > MapaDigital::caminhos(const string &local1, const string &local2)
{
	queue < stack <Locais*> > caminhos = distinctPaths(localDef(local1),localDef(local2));

	cout << "Caminhos entre " + local1 +  " e " + local2 + ": " << caminhos.size() << endl;
	while (!caminhos.empty()) 
	{ 
		stack <Locais*> sp = caminhos.front(); 
		while (!sp.empty()) 
		{ 
			cout << sp.top()->getDescricao() << " <- "; 
			sp.pop(); 
		} 
		caminhos.pop(); 
		cout << endl; 
	}
	return caminhos;
}

//Apresentar o maior percurso
void MapaDigital::maiorCaminho(const string &local1, const string &local2)
{
	queue < stack <Locais*> > caminhos = distinctPaths(localDef(local1),localDef(local2));

	stack <Locais *> max;
	stack <Locais *> aux;
	int tmax = 0;

	cout << "Numero Caminhos entre: " + local1 +  " e " + local2 + " : " << caminhos.size() << endl;
	cout << "Maior Caminho entre: " + local1 +  " e " + local2 + " : " << endl;
	stack <Locais*> sp = caminhos.front();

	while(!caminhos.empty())
	{
		max = caminhos.front();

		int t = max.size();

		if ( t > tmax)
		{
			aux = max;
			tmax = t;
		}
		caminhos.pop();
	}
	while (!aux.empty()) 
	{ 
		cout << aux.top()->getDescricao() << " <- "; 
		aux.pop();
	} 
}

void MapaDigital::menorCaminhoDistancia(const string &ci, const string &cf) 
{
	Pvias::setComparacaoKMS();
	cout << "Menor caminho entre " << ci << " e " << cf << " : " ;
	menorCaminho(ci, cf);
}

void MapaDigital::menorCaminhoCusto(const string &ci, const string &cf) 
{
	Pvias::setComparacaoCUSTO();
	cout << "Menor caminho entre " << ci << " e " << cf << " : " ;
	menorCaminho(ci, cf);
}

void MapaDigital::tempoMedioVisita(const string &ci, const string &cf) 
{
	Pvias::setComparacaoTEMPO();
	cout << "Tempo Medio de visita entre " << ci << " e " << cf << " : " ;
	menorCaminho(ci, cf);
}


void MapaDigital::menorCaminho(const string &ci, const string &cf) 
{
	vector <int> path; 
	vector <Pvias> dist; 
	int key;

	getVertexKeyByContent(key, localDef(cf));

	dijkstrasAlgorithm(localDef(ci), path, dist);

	cout << dist[key].getKM() << " kms " << dist[key].getPreco() << " euros " <<dist[key].getTempo() << " minutos" << endl;

	cout << ci << endl;		
	mostrarCaminho(key,path);	


}

void MapaDigital::mostrarCaminho(int vi, const vector <int> &path)
{
	if (path[vi] == -1) return;

	mostrarCaminho(path[vi],  path);

	Pvias pvia;	
	this->getEdgeByVertexKeys(pvia, path[vi], vi);
	string c; 
	Locais* aux;

	this->getVertexContentByKey(aux, vi);
	cout << " -> " << pvia  << " -> " << aux;
}




#endif
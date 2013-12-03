#ifndef MapaDigital_
#define MapaDigital_

#include <iostream>
#include <list>

using namespace std;

#include "graphStlPath.h"
#include "Pvias.h"
#include "ViasLigacao.h"

class MapaDigital : public graphStlPath <Locais*,Pvias>
{

private: 
	void mostraCaminho(int vi, const vector <int> &path);
	void menorCaminho(const string &ci, const string &cf);

public:
	MapaDigital();
	MapaDigital(const MapaDigital &g);

	void mostrarGrafo();
	queue < stack <Locais*> > caminhos(const string &l1, const string &l2); //Apresentar todos os percursos possíveis entre dois locais de interesse turístico
	void menorCaminhoDistancia(const string &ci, const string &cf);
	void maiorcaminho(const string &ci, const string &cf);
	void menorCaminhoCusto(const string &ci, const string &cf);
	void TerminarVisita(const string &ci, const string &cf);
	Locais * localdef(const string &s1);

	void menorDistancia();
};


MapaDigital::MapaDigital() : graphStlPath <Locais* , Pvias>()
{
}

MapaDigital::MapaDigital(const MapaDigital &g) : graphStlPath <Locais* ,Pvias>(g)
{
}

void MapaDigital::mostrarGrafo()
{
	cout << *this << endl;
}

Locais * MapaDigital::localdef(const string &s1){
	Locais * aux;

	list < graphVertex <Locais* ,Pvias> >::iterator itv;
	for (itv=vlist.begin() ; itv != vlist.end() ; itv++ ){ 
		if (getVertexContentByKey(aux,itv->getVKey())){ 
			if(aux->getDescricao1()==s1){
				return aux; 
			}
		} 
	}
}

//Apresentar todos os percursos possíveis entre dois locais de interesse turístico
queue < stack <Locais*> > MapaDigital::caminhos(const string &l1, const string &l2){
	queue < stack <Locais*> > caminhos = distinctPaths(localdef(l1),localdef(l2));

	cout << "\nCaminhos entre " + l1 +  " e " + l2 + ": " << caminhos.size() << endl;
	while (!caminhos.empty()) { 
		stack <Locais*> sp = caminhos.front(); 
		while (!sp.empty()) 
		{ 
			cout << sp.top()->getDescricao1() << " <- "; 
			sp.pop(); 
		} 
		caminhos.pop(); 
		cout << endl; 
	}
	return caminhos;
}

//Apresentar o maior percurso
void MapaDigital::maiorcaminho(const string &l1, const string &l2){
	queue < stack <Locais*> > caminhos = distinctPaths(localdef(l1),localdef(l2));

	stack <Locais *> max;
	stack <Locais *> aux;
	int tmax = 0;

	cout << "\nNumero Caminhos entre: " + l1 +  " e " + l2 + " : " << caminhos.size() << endl;
	cout << "\nMaior Caminho entre: " + l1 +  " e " + l2 + " : " << endl;
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

void MapaDigital::menorCaminhoDistancia(const string &ci, const string &cf) {
	Pvias::setComparacaoKMS();
	cout << "Menor distancia entre " << ci << " e " << cf << " : " ;
	menorCaminho(ci, cf);
}

void MapaDigital::menorCaminhoCusto(const string &ci, const string &cf) {
	Pvias::setComparacaoCUSTO();
	cout << "Menor distancia entre " << ci << " e " << cf << " : " ;
	menorCaminho(ci, cf);
}

void MapaDigital::TerminarVisita(const string &ci, const string &cf) {
	Pvias::setComparacaoTEMPO();
	cout << "Tempo Medio de visita entre " << ci << " e " << cf << " : " ;
	menorCaminho(ci, cf);
}


void MapaDigital::menorCaminho(const string &ci, const string &cf) {
	vector <int> path; 
	vector <Pvias> dist; 
	int key;

	getVertexKeyByContent(key, localdef(cf));

	//if(typeid(LocaisHistoricosCulturais) == typeid(localdef(ci)))
	//{
	//	int soma = dynamic_cast <LocaisHistoricosCulturais *> 
	//}

	dijkstrasAlgorithm(localdef(ci), path, dist);

	cout << dist[key].getKM() << " kms " << dist[key].getPreco() << " euros " <<dist[key].getTempo() << " minutos" << endl;

	cout << ci << endl;		
	mostraCaminho(key,path);	


}

void MapaDigital::mostraCaminho(int vi, const vector <int> &path) {
	if (path[vi]==-1) return;

	mostraCaminho(path[vi],  path);

	Pvias pvia;	
	this->getEdgeByVertexKeys(pvia, path[vi], vi);
	string c; 
	Locais* aux;

	this->getVertexContentByKey(aux, vi);
	cout << " -> " << pvia  << " -> " << aux;
}




#endif
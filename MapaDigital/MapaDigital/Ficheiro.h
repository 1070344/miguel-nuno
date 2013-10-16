#ifndef Ficheiro_
#define Ficheiro_

#include <iostream>
#include <fstream>
#include "Queue.h"
#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"


class Ficheiro
{
	private:
		Queue<Locais*> locais;
		int tamM;
	public:
		Ficheiro();
		Ficheiro(const Ficheiro &f);
		~Ficheiro();

		void inserirLocais(Locais *loc);
		int fillDataLocais(string nameFx);
		int fillDataLocaisTuristicos(string nameFx);
		int fillData(string nameFx1,string nameFx2);
		void escreve(ostream &out) const;
};


Ficheiro::Ficheiro()
{
	tamM=10;
}
Ficheiro::Ficheiro(const Ficheiro &f)
{
	locais=f.locais;
	tamM=f.tamM;
}

Ficheiro::~Ficheiro(){}



//inserir posto no vector de locais
void Ficheiro::inserirLocais(Locais *loc)
{
	locais.insere(loc);
}



void Ficheiro::escreve(ostream& out) const
{	
	cout << "Locais:" << endl;
	locais.escreve(cout);
}



//Carregamento de todos os ficheiros
int Ficheiro::fillData(string nameFx1,string nameFx2){
	int nLocais=fillDataLocais(nameFx1);
	if(nLocais<0){
		cerr << "Erro a carregar os locais." << endl;
		return -1;
	}
	
	
	return 0;
}


//Carregamento de locais historicos e culturais
int Ficheiro::fillDataLocaisTuristicos(string nameFx)
{
	//Parte Leitura de Ficheiros
	int cont=0;
	ifstream origem;
	string linha;
	
	
	origem.open("Ficheiro1.txt");
	if(!origem){
		cerr<<"Erro a abrir ficheiro\n";
		return -1;
	}

	getline(origem, linha,'\n');
	while(!origem.eof())
	{
		getline(origem,linha,'\n');
		if(linha.size() > 0)
		{
			int inic=0;
			int pos=linha.find(',',inic);
			string desc(linha.substr(inic,pos-inic));
			pos++;

			inic=pos;
			pos=linha.find(',',inic);
			string tempoVisita(linha.substr(inic,pos-inic));
			pos++;

			inic=pos;
			pos=linha.find(',',inic);
			string horAbertura(linha.substr(inic,pos-inic));
			pos++;

			inic=pos;
			pos=linha.find(',',inic);
			string horEncerramento(linha.substr(inic,pos-inic));
			pos++;

			//Parte Adição de informação
			char *aux=&tempoVisita[0];
			int tVisita=atoi(aux);

			char *aux=&horAbertura[0];
			int hAbertura=atoi(aux);

			char *aux=&horEncerramento[0];
			int hEncerramento=atoi(aux);

			
			


			LocaisHistoricosCulturais *locAux = new LocaisHistoricosCulturais(desc,tVisita,hAbertura,hEncerramento);
			inserirLocais(locAux);
			cont++;
		}
	}
	origem.close();
	return cont;
}




ostream & operator << (ostream& out, const Ficheiro *f)
{
	f->escreve(out);
	return out;
}



#endif
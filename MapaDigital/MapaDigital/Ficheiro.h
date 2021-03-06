#ifndef Ficheiro_
#define Ficheiro_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <list>

using namespace std;

#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"
#include "ViasLigacao.h"
#include "AutoEstradas.h"
#include "EstradasNacionais.h"
#include "MapaDigital.h"


class Ficheiro
{
	private:
		list<Locais *>listaLocais;
		list<ViasLigacao *>listaVias;
	public:
		Ficheiro();
		Ficheiro(const Ficheiro &f);
		~Ficheiro();

		void lerFicheiroLocais(string fx);
		//void inserirLocais(Locais *loc);
		void contarTiposLocal();
		//void ordenar();
	
		void lerFicheiroVias(string fx);
		//void inserirVias(ViasLigacao *vias);
		bool validarOrigem(string origem);
		bool validarDestino(string destino);
		
		void listarLocais();
		void listarVias();

		void criarGrafo(MapaDigital &graf);
};


Ficheiro::Ficheiro()
{

}

Ficheiro::~Ficheiro()
{
	
}


void Ficheiro::criarGrafo(MapaDigital &map){
	list < ViasLigacao* > :: iterator it;
	for(it = listaVias.begin(); it != listaVias.end(); it++)
	{
		if(typeid(AutoEstradas) == typeid(**it))
		{
			Pvias p(AutoEstradas((*it)->getOrigem(),(*it)->getDestino(),(*it)->getCodigoVia(),(*it)->getTotalKilometrosVia(),(*it)->getTempoMedioPercurso(),((AutoEstradas*)*it)->getPrecoPortagem()));
			map.addGraphEdge(p,(*it)->getOrigem(),(*it)->getDestino());
		}
		if(typeid(EstradasNacionais) == typeid(**it))
		{
			Pvias p(EstradasNacionais((*it)->getOrigem(),(*it)->getDestino(),(*it)->getCodigoVia(),(*it)->getTotalKilometrosVia(),(*it)->getTempoMedioPercurso(),((EstradasNacionais*)*it)->getTipoPavimento()));
			map.addGraphEdge(p,(*it)->getOrigem(),(*it)->getDestino());
		}
	}
}



void Ficheiro::lerFicheiroLocais(string fx)
{
	ifstream file;
	file.open(fx);
	if (!file)
	{
		cerr << "Erro a abrir ficheiro dos locais!" << endl;
	}

	string linha;
	char *aux;
	string aux1;
	string desc;
	int v2,abertura,encerramento;

		while (!file.eof())
		{
				getline(file, linha, '\n');
	
				if(linha.size() > 0)
				{

					//Descricao
					int inic=0;
					int pos=linha.find(',',inic);	
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					desc=aux1;
					pos++;
	
			
					//area OU tempo medio
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					v2=atoi(aux);
					pos++;



					//hora de abertura
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					abertura=atoi(aux);
					pos++;

					//hora de encerramento
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					encerramento=atoi(aux);

					if (abertura == 0 ) 
					{
						listaLocais.push_back(new LocaisNaturais(desc,v2));
					}
					else
					{
						listaLocais.push_back(new LocaisHistoricosCulturais(desc,v2,abertura,encerramento));
					}

				}
		}
		file.close();
}


bool ordenarLocais(Locais* loc1, Locais* loc2)
{
	return loc1->getDescricao() < loc2->getDescricao();
}

void Ficheiro::listarLocais()
{				
	listaLocais.sort(ordenarLocais);
	for(list<Locais *>::iterator it = listaLocais.begin(); it != listaLocais.end(); it++)
	{
		(*it)->escrever(cout);
	}
	cout << endl;		
}

void Ficheiro::contarTiposLocal()
{			

	int totalNaturais = 0;
	int totalCulturais= 0;

	for(list<Locais *>::iterator it = listaLocais.begin(); it != listaLocais.end(); it++)
	{
		if (typeid(**it) == (typeid(LocaisNaturais)))
		{
			totalNaturais++;
		}
		else 
			if (typeid(**it) == (typeid(LocaisHistoricosCulturais)))
			{
				totalCulturais++;
			}
	}
	cout << "TOTAL de LOCAIS NATURAIS: " << totalNaturais << endl;	
	cout << "TOTAL ce LOCAIS HISTORICO CULTURAIS: " << totalCulturais << endl;	

}

/*void Ficheiro::inserirLocais(Locais *loc)
{
	if (actual1 == tamanho1)
	{
		tamanho1 = 2 * tamanho1;
		Locais **vecTemp = new Locais * [tamanho1];
		for (int i=0; i<actual1; i++)
			vecTemp[i] = vecLocais[i];
		delete [] vecLocais;
		vecLocais = vecTemp;
	}

	vecLocais[actual1] = loc->clone();
	actual1++;
}*/


void Ficheiro::lerFicheiroVias(string fx)
{
	ifstream file;
	
	file.open(fx);
	if (!file)
	{
		cerr << "Erro a abrir ficheiro das vias de ligacao!" << endl;
	}

	string linha;
	char *aux;
	string aux1;
	string origem,destino,codigo,pavimento;
	int totalKilom,tempMedio;
	double portagem;

	/*		ORIGEM	DESTINO		CODIGO DA VIA		TOTALQUILOMETROS		TEMPOMEDIO		PAVIMENTO / PRECO PORTAGEM     */
	/*		string	string		string				int						int				string	  / double					*/
	while (!file.eof())
	{
				getline(file, linha, '\n');
	
				if(linha.size() > 0)
				{

					//local de origem
					int inic=0;
					int pos=linha.find(',',inic);	
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					origem = aux1;
					pos++;
					
			
					//local de destino
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					destino = aux;
					pos++;
					

					//c�digo da via
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					codigo = aux;
					pos++;

					//total de quilometros da via
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					totalKilom = atoi(aux);
					pos++;

					//tempo medio do percurso
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					tempMedio = atoi(aux);
					pos++;

					//tipo de pavimento OU pre�o da portagem
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					bool a = validarOrigem(origem);
					bool b = validarDestino(destino);

					Locais * local1;
					Locais * local2;

					if(validarOrigem(origem)==true && validarDestino(destino)==true)
					{
						if(codigo[0] == 'E')
						{
							list < Locais* > :: iterator it;
							for(it=listaLocais.begin() ; it!=listaLocais.end(); it++)
							{
								if((*it)->getDescricao() == origem)
								{
									local1 = *it;
								}
								if((*it)->getDescricao() == destino)
								{
									local2 = *it;
								}
							}

							pavimento = aux;
							listaVias.push_back(new EstradasNacionais(local1,local2,codigo,totalKilom,tempMedio,pavimento));
						}
						else
						{
							list < Locais* > :: iterator it;
							for(it=listaLocais.begin() ; it!=listaLocais.end(); it++){
								if((*it)->getDescricao() == origem){

									local1 = *it;

								}
								if((*it)->getDescricao() == destino){

									local2 = *it;

								}
							}

							portagem = atof(aux);
							listaVias.push_back(new AutoEstradas(local1,local2,codigo,totalKilom,tempMedio,portagem));
						}
					}
				}
		}
		file.close();
}



bool Ficheiro::validarOrigem(string origem)
{
	for(list<Locais *>::iterator it = listaLocais.begin(); it != listaLocais.end(); it++)
		if(origem == (*it)->getDescricao())
			return true;
}

bool Ficheiro::validarDestino(string destino)
{
	for(list<Locais *>::iterator it = listaLocais.begin(); it != listaLocais.end(); it++)
		if(destino == (*it)->getDescricao())
			return true;
}



/*void Ficheiro::inserirVias(ViasLigacao *vias)
{
	if (actual2 == tamanho2)
	{
		tamanho2 = 2 * tamanho2;
		ViasLigacao **vecTemp = new ViasLigacao * [tamanho2];
		for (int i=0; i<actual2; i++)
			vecTemp[i] = vecVias[i];
		delete [] vecVias;
		vecVias = vecTemp;
	}

	vecVias[actual2] = vias->clone();
	actual2++;
}
*/


/*void Ficheiro::ordenar()
{
	list<Locais *>temp;

	for (int i=0; i<actual1; i++)
	{
		for(int j=i+1; j<actual1; j++)
		{
			if(listaLocais[i]->getDescricao1() > listaLocais[j]->getDescricao1())
			{
				temp = listaLocais[i];     
				listaLocais[i] = listaLocais[j];
				listaLocais[j] = temp;
			}
		}
	}
}*/
 




void Ficheiro::listarVias()
{				
	for(list<ViasLigacao *>::iterator it = listaVias.begin(); it != listaVias.end(); it++)
	{
			(*it)->escrever(cout);
	}
	cout << endl;
}



#endif





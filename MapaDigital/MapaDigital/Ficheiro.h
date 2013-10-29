#ifndef Ficheiro_
#define Ficheiro_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

#include "Ficheiro.h"
#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"
#include "ViasLigacao.h"
#include "AutoEstradas.h"
#include "EstradasNacionais.h"


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
		void inserirNovoLocal();

		void lerFicheiroVias();
		void inserirVias(ViasLigacao *vias);
		bool validarOrigem(string origem);
		bool validarDestino(string destino);

		void escreverLocais(ostream& ostr) const;
		void escreverVias(ostream& ostr) const;
};


Ficheiro::Ficheiro(int t)
{
	actual1 = 0;
	actual2 = 0;
	tamanho1 = t;
	tamanho2 = t;
	vecLocais = new Locais * [tamanho1];
	vecVias = new ViasLigacao * [tamanho2]; 
}

Ficheiro::Ficheiro(const Ficheiro &f)
{
	vecLocais = f.vecLocais;
	vecVias = f.vecVias; 
	tamanho1 = f.tamanho1;
	tamanho2 = f.tamanho2;
}

Ficheiro::~Ficheiro()
{
	for (int i=0; i<actual1; i++)
		delete vecLocais[i];
	delete [] vecLocais;
	
	for (int j=0; j<actual2; j++)
		delete vecVias[j];
	delete [] vecVias;
}

void Ficheiro::lerFicheiroLocais()
{
	ifstream file;
	file.open("Ficheiro1.txt");
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
						LocaisNaturais locNat(desc,v2);
						inserirLocais(&locNat);
					}
					else
					{
						LocaisHistoricosCulturais locHist(desc,v2,abertura,encerramento);
						inserirLocais(&locHist);
					}

				}
		}
		file.close();
}

void Ficheiro::inserirLocais(Locais *loc)
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
}


void Ficheiro::lerFicheiroVias()
{
	ifstream file;
	
	file.open("Ficheiro2.txt");
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
					

					//código da via
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

					//tipo de pavimento OU preço da portagem
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					bool a = validarOrigem(origem);
					bool b = validarDestino(destino);

					if(validarOrigem(origem)==true && validarDestino(destino)==true)
					{
						if(codigo[0] == 'E')
						{
							pavimento = aux;
							EstradasNacionais en(origem,destino,codigo,totalKilom,tempMedio,pavimento);
							inserirVias(&en);
						}
						else
						{
							portagem = atof(aux);
							AutoEstradas ae(origem,destino,codigo,totalKilom,tempMedio,portagem);
							inserirVias(&ae);
						}
					}
				}
		}
		file.close();
}



bool Ficheiro::validarOrigem(string origem)
{
	for(int i=0 ; i<actual1 ; i++)
		if(origem == vecLocais[i]->getDescricao1())
			return true;
}

bool Ficheiro::validarDestino(string destino)
{
	for(int i=0 ; i<actual1 ; i++)
		if(destino == vecLocais[i]->getDescricao1())
			return true;
}



void Ficheiro::inserirVias(ViasLigacao *vias)
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



void Ficheiro::ordenar()
{
	Locais *temp;

	for (int i=0; i<actual1; i++)
	{
		for(int j=i+1; j<actual1; j++)
		{
			if(vecLocais[i]->getDescricao1() > vecLocais[j]->getDescricao1())
			{
				temp = vecLocais[i];     
				vecLocais[i] = vecLocais[j];
				vecLocais[j] = temp;
			}
		}
	}
}
 

void Ficheiro::contarTiposLocal()
{			
	int totalNaturais = 0;
	int totalCulturais= 0;
	for (int i=0; i<actual1; i++)
	{
		if (typeid(*vecLocais[i]) == typeid(LocaisHistoricosCulturais))
		{
			totalCulturais++;		
		}
		
		if (typeid(*vecLocais[i]) == typeid(LocaisNaturais)) 
		{
			totalNaturais++;
		}
		
	}
	cout << "TOTAL DE LOCAIS HISTORICO CULTURAIS: " << totalCulturais << endl;
	for (int j=0; j<actual1; j++)
	{
		if (typeid(*vecLocais[j]) == typeid(LocaisHistoricosCulturais))
		{
			cout << "->" << dynamic_cast <LocaisHistoricosCulturais *>(vecLocais[j])->getDescricao1() << endl;
		}
	}

	cout << endl;

	cout << "TOTAL DE LOCAIS NATURAIS: " << totalNaturais << endl;
	for (int k=0; k<actual1; k++)
	{
		if (typeid(*vecLocais[k]) == typeid(LocaisNaturais))
		{
			cout << "->" << dynamic_cast <LocaisNaturais *>(vecLocais[k])->getDescricao1() << endl;
		}
	}
	cout << endl;
}



void Ficheiro::escreverLocais(ostream & out) const
{				
	for (int i=0; i<actual1; i++)
	{
		if (typeid(*vecLocais[i]) == typeid(LocaisHistoricosCulturais)) dynamic_cast <LocaisHistoricosCulturais *>(vecLocais[i])->escrever(cout);
		if (typeid(*vecLocais[i]) == typeid(LocaisNaturais)) dynamic_cast <LocaisNaturais *>(vecLocais[i])->escrever(cout);
	
	}
}


void Ficheiro::escreverVias(ostream & out) const
{				
	for (int i=0; i<actual2; i++)
	{
		if (typeid(*vecVias[i]) == typeid(AutoEstradas)) dynamic_cast <AutoEstradas *>(vecVias[i])->escrever(cout);
		if (typeid(*vecVias[i]) == typeid(EstradasNacionais)) dynamic_cast <EstradasNacionais *>(vecVias[i])->escrever(cout);
	}
}



#endif





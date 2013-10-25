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
		bool verificarOrigem(string origem);
		bool verificarDestino(string destino);

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
	string v1;
	int v2,v3,v4;

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
					v1=aux1;
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
					v3=atoi(aux);
					pos++;

					//hora de encerramento
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					v4=atoi(aux);
					if (v3 == 0 ) 
					{
						LocaisNaturais locNat(v1,v2);
						inserirLocais(&locNat);
					}
					else
					{
						LocaisHistoricosCulturais locHist(v1,v2,v3,v4);
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
	/*		string	string		string				int						int				string	  / int					*/
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
					
					if(verificarOrigem(origem)==true && verificarDestino(destino)==true)
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





bool Ficheiro::verificarOrigem(string origem)
{
	for(int i=0 ; i<actual1 ; i++)
		if(origem == vecLocais[i]->getDescricao1())
			return true;
	
}

bool Ficheiro::verificarDestino(string destino)
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
	int chc = 0;
	int clog = 0;
	for (int i=0; i<actual1; i++)
	{
		if (typeid(*vecLocais[i]) == typeid(LocaisHistoricosCulturais))
		{
			chc++;		
		}
		
		if (typeid(*vecLocais[i]) == typeid(LocaisNaturais)) 
		{
			clog++;
		}
		
	}
	cout << "TOTAL DE LOCAIS HISTORICO CULTURAIS: " << chc << endl;
	for (int j=0; j<actual1; j++)
	{
		if (typeid(*vecLocais[j]) == typeid(LocaisHistoricosCulturais))
		{
			cout << "->" << dynamic_cast <LocaisHistoricosCulturais *>(vecLocais[j])->getDescricao1() << endl;
		}
	}

	cout << "\nTOTAL DE LOCAIS NATURAIS: " << clog << endl;
	for (int k=0; k<actual1; k++)
	{
		if (typeid(*vecLocais[k]) == typeid(LocaisNaturais))
		{
			cout << "->" << dynamic_cast <LocaisNaturais *>(vecLocais[k])->getDescricao1() << endl;
		}
	}
	cout << "\n";
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





#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>

#include "Ficheiro.h"
#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"
#include "ViasLigacao.h"
#include "AutoEstradas.h"
#include "EstradasNacionais.h"

Ficheiro::Ficheiro(int t)
{
	tamanho = t;
	actual = 0;
	vecLocais = new Locais * [tamanho];
	vecVias = new ViasLigacao * [tamanho]; 
}

Ficheiro::Ficheiro(const Ficheiro &f)
{
	vecLocais = f.vecLocais;
	vecVias = f.vecVias; 
	tamanho = f.tamanho;
}

Ficheiro::~Ficheiro()
{
	for (int i=0; i<actual; i++)
		delete vecLocais[i];
	delete [] vecLocais;
	
	for (int j=0; j<actual; j++)
		delete vecVias[j];
	delete [] vecVias;
}

void Ficheiro::lerFicheiroLocais()
{
	ifstream file;
	
	file.open("Ficheiro1.txt");
	if (!file)
	{
		cerr << "Erro a abrir ficheiro dos locais" << endl;
	}

	int minutos1;
	int minutos2;
	int horas1;
	int horas2;
	string time1;
	string time2;
	int timex1;
	int timex2;
	string linha;
	string info;
	char *aux;
	string aux1;
	string v1;
	int v2,v3,v4;
	int nLinhas= 0;

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
					horas1 = v3/60;
					minutos1 = v3%60;
					timex1 = horas1;
					pos++;

					//hora de encerramento
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					v4=atoi(aux);
					horas2 = v4 / 60;
					minutos2 = v4 % 60;
					timex2 = horas2;
					if (v3 == 0 ) 
					{
							LocaisNaturais locNat(v1,v2);
							inserirLocais(&locNat);
					}
					else
					{
						LocaisHistoricosCulturais locHist(v1,v2,timex1,timex2);
						inserirLocais(&locHist);
					}

				}
		}
		file.close();
}

void Ficheiro::inserirLocais(Locais *loc)
{
	if (actual == tamanho)
	{
		tamanho = 2 * tamanho;
		Locais **vecTemp = new Locais * [tamanho];
		for (int i=0; i<actual; i++)
			vecTemp[i] = vecLocais[i];
		delete [] vecLocais;
		vecLocais = vecTemp;
	}

	vecLocais[actual] = loc->clone();
	actual++;
}


void Ficheiro::lerFicheiroVias()
{
	ifstream file;
	
	file.open("Ficheiro2.txt");
	if (!file)
	{
		cerr << "Erro a abrir ficheiro das vias de ligação" << endl;
	}

	string linha;
	string info;
	char *aux;
	string aux1;
	string origem,destino,codigo,pavimento;
	int totalKilom,tempMedio,portagem;
	int nLinhas= 0;
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
		file.close();
}


void Ficheiro::inserirVias(ViasLigacao *vias)
{
	if (actual == tamanho)
	{
		tamanho = 2 * tamanho;
		ViasLigacao **vecTemp = new ViasLigacao * [tamanho];
		for (int i=0; i<actual; i++)
			vecTemp[i] = vecVias[i];
		delete [] vecVias;
		vecVias = vecTemp;
	}

	vecVias[actual] = vias->clone();
	actual++;
}



void Ficheiro::ordenar()
{
	Locais *temp;

	for (int i=0; i<actual; i++)
	{
		for(int j=i+1; j<actual; j++)
		{
			if(vecLocais[i]->getDescricao() > vecLocais[j]->getDescricao())
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
	for (int i=0; i<actual; i++)
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
	for (int j=0; j<actual; j++)
	{
		if (typeid(*vecLocais[j]) == typeid(LocaisHistoricosCulturais))
		{
			cout << "->" << dynamic_cast <LocaisHistoricosCulturais *>(vecLocais[j])->getDescricao() << endl;
		}
	}

	cout << "\nTOTAL DE LOCAIS NATURAIS: " << clog << endl;
	for (int k=0; k<actual; k++)
	{
		if (typeid(*vecLocais[k]) == typeid(LocaisNaturais))
		{
			cout << "->" << dynamic_cast <LocaisNaturais *>(vecLocais[k])->getDescricao() << endl;
		}
	}
	cout << "\n";
}


void Ficheiro::escreverLocais(ostream & out) const
{				
	for (int i=0; i<actual; i++)
	{
		if (typeid(*vecLocais[i]) == typeid(LocaisHistoricosCulturais)) dynamic_cast <LocaisHistoricosCulturais *>(vecLocais[i])->escrever(cout);
		if (typeid(*vecLocais[i]) == typeid(LocaisNaturais)) dynamic_cast <LocaisNaturais *>(vecLocais[i])->escrever(cout);
	
	}
}


void Ficheiro::escreverVias(ostream & out) const
{				
	for (int i=0; i<actual; i++)
	{
		if (typeid(*vecVias[i]) == typeid(AutoEstradas)) dynamic_cast <AutoEstradas *>(vecVias[i])->escrever(cout);
		if (typeid(*vecVias[i]) == typeid(EstradasNacionais)) dynamic_cast <EstradasNacionais *>(vecVias[i])->escrever(cout);
	
	}
}


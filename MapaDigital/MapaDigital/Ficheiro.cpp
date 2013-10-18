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

Ficheiro::Ficheiro(int d)
{
	tamM=d;
	actual = 0;
	vecLocais = new Locais * [tamM]; 
}

Ficheiro::Ficheiro(const Ficheiro &f)
{
	vecLocais=f.vecLocais;
	tamM=f.tamM;
}

Ficheiro::~Ficheiro()
{
	for (int i=0; i<actual; i++)
		delete vecLocais[i];

	delete [] vecLocais;
}

//inserir locais no vector de local
void Ficheiro::inserirLocais(Locais *loc)
{
	if (actual == tamM)
	{
		tamM = 2* tamM;
		Locais * * vecTemp = new Locais * [tamM];
		for (int i=0; i<actual; i++)
			vecTemp[i] = vecLocais[i];
		delete [] vecLocais;
		vecLocais = vecTemp;
	}

	vecLocais[actual] = loc->clone();
	actual++;
}

void Ficheiro::lerFicheiroLocais()
{
		
    ifstream origem;
	

	origem.open("Ficheiro1.txt");
	if (!origem){
		cerr << "Erro a abrir ficheiro dos locais\n";
	}

	string linha;
	string info;
	char *aux;
	string aux1;
	string v1;
	int v2,v3,v4;
	int nLinhas= 0;

	while (!origem.eof())
	{
				getline(origem, linha, '\n');
	
				if(linha.size() > 0)
				{

					//Descricao
					int v = 0;
					int inic=0;
					int pos=linha.find(',',inic);	
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					//cout << aux << ",";
					v1=aux1;
					pos++;
	
			
					//area OU tempo medio
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					//cout << aux << ",";
					v2=atoi(aux);
					pos++;



					//hora de abertura
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					//cout << aux << ",";
					v3=atoi(aux);
					pos++;

					//hora de encerramento
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					//cout << aux << endl;
					v4=atoi(aux);

					if (v3 == 0 ) {
							LocaisNaturais na(v1,v2);
							inserirLocais(&na);
					}
					else
					{
							LocaisHistoricosCulturais LH(v1,v2,v3,v4);
							inserirLocais(&LH);
					}

				}
				
		}
		origem.close();
}

void Ficheiro::ordenar(){
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
 
void Ficheiro::escrever(ostream & out) const{				//sobrecarga do operador outstream
	for (int i=0; i<actual; i++)
	{
		if (typeid(*vecLocais[i]) == typeid(LocaisHistoricosCulturais)) dynamic_cast <LocaisHistoricosCulturais *>(vecLocais[i])->escrever(cout);
		if (typeid(*vecLocais[i]) == typeid(LocaisNaturais)) dynamic_cast <LocaisNaturais *>(vecLocais[i])->escrever(cout);
	
	}
	system("pause");
}

void Ficheiro::contarTiposLocal(){				//sobrecarga do operador outstream
	int chc = 0;
	int clog = 0;
	for (int i=0; i<actual; i++)
	{
		if (typeid(*vecLocais[i]) == typeid(LocaisHistoricosCulturais)) {
			chc++;		
		}
		
		if (typeid(*vecLocais[i]) == typeid(LocaisNaturais)) {
			clog++;
		}
		
	}
	cout << "Numero de locais Historicos: " << chc;
	cout << "\n" << endl;
	for (int j=0; j<actual; j++)
	{
		if (typeid(*vecLocais[j]) == typeid(LocaisHistoricosCulturais))
		{
			cout << dynamic_cast <LocaisHistoricosCulturais *>(vecLocais[j])->getDescricao() << endl;
		}
	}

	cout << "\nNumero de locais Naturais: " << clog;
	cout << "\n" << endl;
	for (int k=0; k<actual; k++)
	{
		if (typeid(*vecLocais[k]) == typeid(LocaisNaturais))
		{
			cout << dynamic_cast <LocaisNaturais *>(vecLocais[k])->getDescricao() << endl;
		}
	}
	cout << "\n";
}

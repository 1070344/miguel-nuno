#ifndef Ficheiro_
#define Ficheiro_

#include<iostream>
#include <string>
#include <fstream>

using namespace std;


#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"
#include "ViasLigacao.h"
#include "AutoEstradas.h"
#include "EstradasNacionais.h"


class Ficheiro
{

	private:
		int n;
		int tam;
		int cont; // Contador para Locais
		char linha[1024]; // Linha com um maximo de 1024 chars
		char *token; // Recebe o valor do split da linha
		Locais **local; // Vector de Locais
		string nomeFicheiro;


	public:
		Ficheiro();
		Ficheiro(const Ficheiro &fx);
		Ficheiro(string nome);
		virtual ~Ficheiro();


		void setNomeFicheiro(string nome);
		string getNomeFicheiro()const;
		
		void FicheiroLocais();


};


Ficheiro::Ficheiro()
{
	nomeFicheiro = "";
}

Ficheiro::~Ficheiro(){}


Ficheiro::Ficheiro(string nome)
{
	nomeFicheiro = nome;
}

Ficheiro::Ficheiro(const Ficheiro &fx)
{

	setNomeFicheiro(fx.nomeFicheiro);
}


void Ficheiro::setNomeFicheiro(string nome)
{
	nomeFicheiro = nome;
}



void Ficheiro::FicheiroLocais()
{
		/*
			FICHEIRO LOCAIS 

			[[[Locais Turisticos Historico Culturais]]]

			DESCRIÇÃO		TEMP.MEDIO.VISITA			HORARIO_ABERTURA						HORARIO_ENCERRAMENTO
			Serralves		130 minutos					15h25m = 15*60+25 = 925 minutos			18h40m = 18*60+40 = 1120 minutos
		--->PORTANTO FICA: Serralves,130,925,1120

			
			[[[Locais Turisticos Naturais]]]

			DESCRIÇÃO		ÁREA(km2)
			Sé do Porto		200
		--->PORTANTO FICA: Sé do Porto,200


		*/
	string desc;
	double area;
	int tVisita;
	int abertura;
	int encerramento;
	int totalLocais = 0;
	string nomefich1="Ficheiro1.txt";	//ficheiro dos locais
	ifstream ler(nomefich1.c_str()); // Verifica se o Ficheiro existe
	
	if (!ler)
	{
		cout << "Erro na leitura do Ficheiro dos Locais!" << endl << endl;			
	
	}
	else 
	{
		while (ler.getline(linha,1024)!=NULL)// Fazer o Split de cada linha pela ',' para criação do objecto
		{	 	
			token=strtok(linha,",");
			string chave2= token;

			token=strtok(NULL,",");
			string designa2= token;

			token=strtok(NULL,",");

			


			while(token!=NULL) // Verifica se o ficheiro tem locais
			{	
				int descj=atoi(token);
				token = strtok (NULL, ",");
				int capa= atoi(token);	
				
				Locais *loc = new Locais(desc); // Cria um local turistico natural
				totalLocais++; // Incrementa o numero de locais			
				if(n==tam)//verifica se o tamanho do vector é igual ao tamanho maximo
				{	
					Locais **aux=new Locais*[2*tam]; // Cria um Vector auxiliar para fazer copia do vector original
					for(int j=0;j<n;j++)
					{
						aux[j]=local[j];
					}
					tam=2*tam; // Duplicação do tamanho máximo 
					delete[]local;
					local=aux;
				}
				local[n]=loc->clone(); // Chamar clone do Objecto
				n++; // Incrementar as posicoes vector
				token= strtok(NULL,","); // Lê o próximo para verificar se contêm mais locais
			}
			Locais *ln= new LocaisNaturais(desc,area); // Cria um local turistico natural
			Locais *lhc = new LocaisHistoricosCulturais(desc,tVisita,abertura,encerramento); // Cria um local historico
			totalLocais=0; 
			n=0;	
		}	
	}
	ler.close();
}


#endif

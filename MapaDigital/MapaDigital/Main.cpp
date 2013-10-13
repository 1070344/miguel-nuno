#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>


#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"
#include "ViasLigacao.h"
#include "AutoEstradas.h"
#include "EstradasNacionais.h"
#include "Ficheiro.h"


 



int lerFicheiroLocais(Locais vecLocais)
{
		
    ifstream origem;
	string linha;
	string info;
	char *aux;
	string aux1;
	LocaisHistoricosCulturais locHist;
	int numLocais;
	int nlinhas= 0;

	origem.open("Ficheiro1.txt");
	if (!origem){
		cerr << "Erro a abrir ficheiro dos locais\n";
		return -1;
	}




	while (!origem.eof()){
		getline(origem, linha, '\n');
	
		if(linha.size() > 0)
		{
	
			if(nlinhas == 0)
			{
				int inic=0;
				int pos=linha.find(',', inic);	
				aux1 = linha.substr(inic,pos-inic);
				aux = &aux1[0];
				numLocais = atoi(aux);
				pos++;
				nlinhas++;
			}
			else
			{
				//descrição
				int inic=0;
				int pos=linha.find(',', inic);
				locHist.setDescricao((linha.substr(inic, pos-inic)));
				pos++;

				//area OU tempo medio
				inic = pos;
				pos=linha.find(',', inic);
				aux1 = linha.substr(inic,pos-inic);
				aux = &aux1[0];
				locHist.setTempoVisita(atof(aux));
				pos++;

				//hora de abertura
				inic = pos;
				pos=linha.find(',', inic);
				aux1 = linha.substr(inic,pos-inic);
				aux = &aux1[0];
				locHist.setHorarioAbertura(atoi(aux));
				pos++;

				//hora de encerramento
				inic = pos;
				pos=linha.find(',', inic);
				aux1 = linha.substr(inic,pos-inic);
				aux = &aux1[0];
				locHist.setHorarioEncerramento(atoi(aux));

				//invocar metodo para inserir os locais no vector
			}
		}
	}
	origem.close();
	return 0;
}
 






int main()
{
	

	Ficheiro fx;
	char sel;
	Locais vecLocais;



	//carregar dados para a memoria
	lerFicheiroLocais(vecLocais);//carregar locais para a memória

	cout << "------------------------------------" << endl;
	cout << "------------------------------------" << endl;
    cout << "       M A P A   D I G I T A L       " << endl;
	cout << "------------------------------------" << endl;
	cout << "------------------------------------" << endl;
	cout << "Selecione uma opcao" << endl;
    cout << "1. Inserir locais a partir de um ficheiro de texto" << endl;
    cout << "2. Inserir vias de ligacao a partir do ficheiro" << endl;
	cout << "3. Contabilizar os locais historicos e naturais por ordem alfabetica da sua descricao" << endl;
	cout << "0. Fechar programa\n" << endl;
	cout << "Opcao: ";
	
    cin >> sel;
	

    switch(sel){
        case '1':
			cout << "Opcao 1 " << endl;
			
			break;
 
        case '2':
            cout << "Opcao 2 " << endl;
			break;
                
		case '3':
			cout << "Opcao 3" << endl;
			break;

			case '0':
			cout << "Opcao 0" << endl;
			system("exit");
			break;
 	}



	system("pause");
}
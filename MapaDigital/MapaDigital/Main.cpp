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
	LocaisNaturais locNat;
	int nLinhas= 0;

	origem.open("Ficheiro1.txt");
	if (!origem){
		cerr << "Erro ao abrir ficheiro dos locais\n";
		return -1;
	}




	while (!origem.eof())
	{
				getline(origem, linha, '\n');
	


					//descrição
					int inic=0;
					int pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					cout << aux << ",";
					pos++;
					nLinhas++;
				
					
					inic=0;
					pos=linha.find(',', inic);
					locHist.setDescricao((linha.substr(inic, pos-inic)));
					pos++;
			
					//area OU tempo medio
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					cout << aux << ",";
					locHist.setTempoVisita(atoi(aux));
					pos++;
					
					//hora de abertura
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					cout << aux << ",";
					locHist.setHorarioAbertura(atoi(aux));
					pos++;
				

					//hora de encerramento
					inic = pos;
					pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					cout << aux << endl;
					locHist.setHorarioEncerramento(atoi(aux));

					vecLocais.inserirLocal((Locais *) locHist.clone());
					
		}
		origem.close();
		return 0;
}
 






int main()
{
	char sel;
	Ficheiro fx;

	//carregar dados para a memoria
	lerFicheiroLocais(*vecLocais);//carregar locais para a memória

	cout << "----------------------------------------------------" << endl;
	cout << "----------------------------------------------------" << endl;
    cout << "---------------M A P A   D I G I T A L--------------" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Selecione uma opcao" << endl;
    cout << "1. Inserir um local" << endl;
    cout << "2. Inserir uma via de ligacao" << endl;
	cout << "3. Mostar todos os locais" << endl;
	cout << "0. Fechar programa\n" << endl;
	cout << "Opcao: ";
	
    cin >> sel;
	

    switch(sel)
	{
        case '1':
			
			break;
 
        case '2':
            break;
                
		case '3':
			system("pause");
			break;

		case '0':
			system("exit");
			break;
 	}


}
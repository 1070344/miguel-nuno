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


int lerFicheiroLocais(Locais &vecLocais)
{
		
    ifstream origem;
	

	origem.open("Ficheiro1.txt");
	if (!origem){
		cerr << "Erro a abrir ficheiro dos locais\n";
		return -1;
	}

	string linha;
	string info;
	char *aux;
	string aux1;
	LocaisHistoricosCulturais locHist;
	LocaisNaturais locNat;
	int nLinhas= 0;


	while (!origem.eof())
	{
				getline(origem, linha, '\n');
	
				if(linha.size() > 0)
				{
					//Descricao
					int inic=0;
					int pos=linha.find(',', inic);
					aux1 = linha.substr(inic,pos-inic);
					aux = &aux1[0];
					locHist.setDescricao(aux);
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
					locNat.setArea(atoi(aux));
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


					vecLocais.inserirLocal((Locais *)locHist.clone());//inserir no vector os locais
					

				}
					
		}
		origem.close();
		return 0;
}
 






int main()
{
	char sel;
	Locais vecLocais;

	//carregar dados para a memoria
	lerFicheiroLocais(vecLocais);//carregar locais para a memória

	cout << "----------------------------------------------------" << endl;
	cout << "----------------------------------------------------" << endl;
    cout << "---------------M A P A   D I G I T A L--------------" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Selecione uma opcao" << endl;
    cout << "1. Listagem de Locais (sem filtragem)" << endl;
    cout << "2. Inserir uma via de ligacao" << endl;
	cout << "3. Mostar todos os locais" << endl;
	cout << "0. Fechar programa\n" << endl;
	cout << "Opcao: ";
	
    cin >> sel;
	

    switch(sel)
	{
        case '1':
			vecLocais.escrever(cout);
			system("pause");
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
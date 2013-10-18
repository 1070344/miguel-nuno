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

int main()
{
	char sel;
	Ficheiro f(100);

	//carregar dados para a memoria
	
	f.lerFicheiroLocais();
	f.ordenar();

	cout << "----------------------------------------------------" << endl;
	cout << "----------------------------------------------------" << endl;
    cout << "---------------M A P A   D I G I T A L--------------" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Selecione uma opcao" << endl;
    cout << "1. Listagem de Locais (sem filtragem)" << endl;
    cout << "2. Inserir uma via de ligacao" << endl;
	cout << "3. Numero total de tipos de local" << endl;
	cout << "0. Fechar programa\n" << endl;
	cout << "Opcao: ";
	
    cin >> sel;
	

    switch(sel)
	{
        case '1':
			f.escrever(cout);
			break;
 
        case '2':
            break;
                
		case '3':
			f.contarTiposLocal();
			system("pause");
			break;

		case '0':
			system("exit");
			break;
 	}


}
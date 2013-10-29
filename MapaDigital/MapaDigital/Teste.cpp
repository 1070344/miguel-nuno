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
	system("COLOR 0A");
	cout << "|========================================================================|" << endl;
	cout << "|                         M A P A   D I G I T A L                        |" << endl;
	cout << "|========================================================================|" << endl;


	char sel;
	Ficheiro f(50);
	
	f.lerFicheiroLocais();
	f.ordenar();
	f.lerFicheiroVias();


	cout << "Selecione uma opcao" << endl;
    cout << "1. Listagem dos locais" << endl;
    cout << "2. Listagem da vias de ligacao" << endl;
	cout << "3. Total de locais" << endl;
	cout << "0. Sair do programa\n" << endl;
	cout << "Opcao: ";
	cin >> sel;
	cout << endl; 

    switch(sel)
	{
        case '1':
			f.escreverLocais(cout);
			main();
			break;
 
        case '2':
			f.escreverVias(cout);
			main();
			break;
                
		case '3':
			f.contarTiposLocal();
			main();
			break;

		case '0':
			system("exit");
			break;
 	}


}
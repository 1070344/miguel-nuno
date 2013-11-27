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
#include "graphStlPath.h"





int main()
{
	cout << "|========================================================================|" << endl;
	cout << "|                         M A P A   D I G I T A L                        |" << endl;
	cout << "|========================================================================|" << endl;


	char sel;
	Ficheiro f;
	
	f.lerFicheiroLocais("Ficheiro1.txt");
	f.lerFicheiroVias("Ficheiro2.txt");


	cout << "Selecione uma opcao" << endl;
    cout << "1. Listagem dos locais" << endl;
    cout << "2. Listagem da vias de ligacao" << endl;
	cout << "3. Total de locais" << endl;
	cout << "4. Construir grafo" << endl;
	cout << "5. Determinar complexidade temporaral(Big-Oh)" << endl;
	cout << "6. Apresentar percurso entre dois locais" << endl;
	cout << "7. Percurso mais curto em km" << endl;
	cout << "8. Percurso mais economco em euros" << endl;
	cout << "9. Percurso de maior interesse turistico" << endl;
	cout << "0. Sair do programa\n" << endl;
	cout << "Opcao: ";
	cin >> sel;
	cout << endl; 

    switch(sel)
	{
        case '1':
			f.listarLocais();
			main();
			break;
 
        case '2':
			f.listarVias();
			main();
			break;
                
		case '3':
			f.contarTiposLocal();
			main();
			break;

		case '4':
			//MapaDigital m;
			//m.criarGrafo();
			main();
			break;

		case '5':
			
			
			main();
			break;

		case '6':
			
			
			main();
			break;

		case '7':
			//char or;
			//char dest;
			//cout << "Insira origem: " << endl;
			//cin >> or;
			//cout << insira destino: " << endl;
			//cin >> dest;
			//MapaDigital m;
			//m.caminhoMaisCurto(or,dest);
			//m.escreve(out);
			main();
			break;

		case '0':
			system("exit");
			break;
 	}


}


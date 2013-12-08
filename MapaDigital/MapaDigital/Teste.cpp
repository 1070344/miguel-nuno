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
#include "MapaDigital.h"





int main(void)
{
	cout << "|========================================================================|" << endl;
	cout << "|                         M A P A   D I G I T A L                        |" << endl;
	cout << "|========================================================================|" << endl;


	char sel;
	Ficheiro f;
	MapaDigital map;
	f.lerFicheiroLocais("Ficheiro1.txt");
	f.lerFicheiroVias("Ficheiro2.txt");
	f.criarGrafo(map);
	string origem = "";
	string destino = "";
	string instante = "";

	cout << "Selecione uma opcao" << endl;
    cout << "1. Listagem dos locais" << endl;
    cout << "2. Listagem da vias de ligacao" << endl;
	cout << "3. Total de locais" << endl;
	cout << "4. Construir grafo" << endl;
	cout << "5. Apresentar percurso entre dois locais" << endl;
	cout << "6. Percurso mais curto em km" << endl;
	cout << "7. Percurso mais economico em euros" << endl;//
	cout << "8. Percurso de maior interesse turistico" << endl;
	cout << "9. Tempo Medio de Visita" << endl;
	cout << "10. Calcular o instante em que acaba a visita" << endl;
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
			map.mostrarGrafo();
			main();
			break;
		
		case '5':
			cout << "Origem: ";
			cin >> origem;
			cout << "Destino: ";
			cin >> destino;
			map.caminhos(origem , destino);
			main();
			break;
		
		case '6':
			cout << "Origem: ";
			cin >> origem;
			cout << "Destino: ";
			cin >> destino;
			map.menorCaminhoDistancia(origem,destino);
			main();
			break;
		
		case '7':
			cout << "Origem: ";
			cin >> origem;
			cout << "Destino: ";
			cin >> destino;
			map.menorCaminhoCusto(origem,destino);
			main();
			break;
		
		case '8':
			cout << "Origem: ";
			cin >> origem;
			cout << "Destino: ";
			cin >> destino;
			map.maiorCaminho(origem,destino); 
			main();
			break;
		
		case '9':
			cout << "Origem: ";
			cin >> origem;
			cout << "Destino: ";
			cin >> destino;
			map.tempoMedioVisita(origem,destino); 
			main();
			break;

		case '10':
			cout << "Origem: ";
			cin >> origem; 
			cout << "Instante(em minutos): ";
			cin >> instante;
			cout << "Qunatos pontos turisticos deseja visitar: ";

			main();
			break;

		case '0':
			system("exit");
			break;
 	}

}


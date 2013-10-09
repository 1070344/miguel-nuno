#ifndef Locais_
#define Locais_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;



class Locais
{
	private:
		string desc;
		int actual;
		Locais **vec;
	public:
		Locais();
		Locais(const Locais & loc);
		Locais(string desc);
		~Locais();

		//set's e get´s
		void setDescricao(string d);
		string getDescricao()const;

		//metodos da classe
		virtual void contarLocais()const;
		


		/*Sobrecarga de operadores
		Locais & operator =(const Locais &loc);
		bool operator >(const Locais &loc);
		bool operator <(const Locais &loc);
		bool operator ==(const Locais &loc);*/
};

Locais::Locais()
{
	desc = "nenhuma";
}

Locais::Locais(const Locais &loc)
{
	setDescricao(loc.desc);
}


Locais::Locais(string d)
{
	desc = d;
}

Locais::~Locais(){}





void Locais::contarLocais() const
{
	int historicos = 0;
	int naturais = 0;

	for (int i=0; i<actual; i++)
	{
		if (typeid(*vec[i]) == typeid(LocaisNaturais)) historicos++;
		if (typeid(*vec[i]) == typeid(LocaisHistoricosCulturais)) naturais++;
	}
	cout << "Total de Locais" << endl;
	cout << "::::::::::Locais Naturais: " << historicos << " vias." << endl;
	cout << "::::::::::Locais Historicos Naturais: " << naturais << " vias." << endl;
}







#endif

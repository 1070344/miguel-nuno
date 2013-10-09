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
		Locais(const Locais &loc);
		Locais(string desc);
		virtual Locais * clone() const;	
		virtual ~Locais();

		//set's e get´s
		void setDescricao(string d);
		string getDescricao()const;

		//metodos da classe
		virtual void contarLocais()const;
		virtual void inserirLocal()const;

		


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

Locais * Locais::clone() const{
	Locais * l = new Locais(*this);
	return l;
}



void Locais::contarLocais() const
{
	int cont = 0;
	for (int i=0; i<actual; i++)
	{
		cont++;
	}
	cout << "Total de Locais: " << cont << endl;
}



void Locais::inserirLocal()const
{
	
}




#endif

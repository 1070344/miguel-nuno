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

	public:
		Locais();
		Locais(const Locais &loc);
		Locais(string desc);
		virtual Locais * clone() const;	
		virtual ~Locais();

		//set's e get´s
		void setDescricao(string d);
		string getDescricao()const;


		/*Sobrecarga de operadores
		Locais & operator =(const Locais &loc);
		bool operator >(const Locais &loc);
		bool operator <(const Locais &loc);
		bool operator ==(const Locais &loc);*/
		virtual void escrever (ostream & out) const;
};
#endif

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
		string desc1;
		string desc2;

	public:
		Locais();
		Locais(const Locais &loc);
		Locais(string desc1);
		Locais(string desc1,string desc2);
		virtual Locais * clone() const;	
		virtual ~Locais();

		//set's e get´s
		void setDescricao1(string d1);
		void setDescricao2(string d2);
		string getDescricao1()const;
		string getDescricao2()const;

		/*Sobrecarga de operadores
		Locais & operator =(const Locais &loc);
		bool operator >(const Locais &loc);
		bool operator <(const Locais &loc);
		bool operator ==(const Locais &loc);*/
		virtual void escrever (ostream & out) const;
		virtual void escrever2 (ostream & out) const;
};
#endif

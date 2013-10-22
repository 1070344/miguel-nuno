#ifndef LocaisNaturais_
#define LocaisNaturais_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "Locais.h"


class LocaisNaturais : public Locais
{
	private:
		int area;//em km2
	public:
		LocaisNaturais();
		LocaisNaturais(const LocaisNaturais &locNat);
		LocaisNaturais(string desc,int a);
		~LocaisNaturais();
		LocaisNaturais * clone() const;

		//SET's e GET's
		void setArea(int a);
		double getArea() const;

		//Sobrecarga de operadores
		LocaisNaturais & operator =(const LocaisNaturais &locNat);
		bool operator >(const LocaisNaturais &locNat);
		bool operator <(const LocaisNaturais &locNat);
		bool operator ==(const LocaisNaturais &locNat);
		void escrever(ostream &out) const;


};
#endif

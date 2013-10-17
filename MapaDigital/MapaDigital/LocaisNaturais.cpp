#include "LocaisNaturais.h"
#include "Locais.h"

LocaisNaturais::LocaisNaturais()
{
	area = 0;
}


LocaisNaturais::LocaisNaturais(string desc,double a) : Locais(desc)//desc=descrição - variavel da superclasse Locais
{
	area = a;
}

LocaisNaturais::~LocaisNaturais(){}


LocaisNaturais::LocaisNaturais(const LocaisNaturais &locNat)
{
	setArea(locNat.area);
}


Locais * LocaisNaturais::clone() const{
	return new LocaisNaturais(*this);
}



void LocaisNaturais::setArea(double a)
{
	area = a;
}

double LocaisNaturais::getArea()const
{
	return area;
}

void LocaisNaturais::escreve(ostream & out) const
{  
	Locais::escreve(cout);
	cout << "Area: " << area << endl;
}




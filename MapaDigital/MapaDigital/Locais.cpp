#include "Locais.h"

Locais::Locais()
{
	desc1 = "vazio";
	desc2 = "vazio";
}

Locais::Locais(string d1)
{
	desc1 = d1;
}


Locais::Locais(string d1,string d2)
{
	desc1 = d1;
	desc2 = d2;
}


Locais::Locais(const Locais &loc)
{
	setDescricao1(loc.desc1);
	setDescricao2(loc.desc2);
}


Locais::~Locais()
{
}

Locais * Locais::clone() const
{
	return new Locais (*this);
}

void Locais::setDescricao1(const string d1)
{
	desc1 = d1;
}


void Locais::setDescricao2(const string d2)
{
	desc2 = d2;
}


string Locais::getDescricao1()const
{
	return desc1;
}

string Locais::getDescricao2()const
{
	return desc2;
}

void Locais::escrever(ostream & out) const
{  
	cout << "DESCRICAO: " << desc1 << endl;
}

void Locais::escrever2(ostream & out) const
{  
	cout << "ORIGEM: " << desc1 << endl;
	cout << "DESTINO: " << desc2 << endl;
}
#include "Locais.h"

Locais::Locais()
{
	desc = "vazio";
}


Locais::Locais(string d)
{
	desc = d;
}


Locais::Locais(const Locais &loc)
{
	setDescricao(loc.desc);
}


Locais::~Locais()
{
}

Locais * Locais::clone() const
{
	return new Locais (*this);
}

void Locais::setDescricao(const string d)
{
	desc = d;
}

string Locais::getDescricao()const
{
	return desc;
}


void Locais::escrever(ostream & out) const
{  
	cout << "DESCRICAO: " << desc << endl;
}


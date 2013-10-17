#include "Locais.h"
#include "LocaisHistoricosCulturais.h"
#include "LocaisNaturais.h"


Locais::Locais(int d)
{
	descricao = "vazio";
	actual = 0;
	dimensao = d;
	vec = new Locais * [dimensao];

}

Locais::Locais(const Locais &loc)
{
	setDescricao(loc.descricao);

	vec = new Locais *[dimensao];

	for (int i=0; i<actual; i++)
		vec[i] = loc.vec[i]->clone();
}


Locais::Locais(string desc)
{
	descricao = desc;
}

Locais::~Locais()
{
	for (int i=0; i<actual; i++)
		delete vec[i];

	delete [] vec;
}

Locais * Locais::clone() const
{
	Locais * l = new Locais(*this);
	return l;
}

void Locais::setDescricao(string desc){
	descricao = desc;
}

string Locais::getDescricao()const
{
	return descricao;
}

void Locais::contarLocais(Locais *v)
{
	int cont = 0;
	for (int i=0; i<actual; i++)
	{
		cont++;
	}
	cout << "Total de Locais: " << cont << endl;
}


void Locais::inserirLocal(Locais *v)
{
	if(actual == dimensao)
	{
		Locais **locTemp = new Locais *[dimensao * 2];
		for(int i=0 ; i<actual ; i++)
		{
			locTemp[i] = vec[i];
			dimensao = 2 * dimensao;
			delete [] vec;
			vec = locTemp;
		}
	}
	vec[actual] = v->clone();
	actual++;
}



void Locais::listar()const
{
	cout << ":::::LISTAGEM LOCAIS:::::" << endl;
	for(int i=0 ; i<actual ; ++i)
	{
		vec[i]->listar();
	}
}


void Locais::escreve(ostream & out) const
{  
	cout << "\nDescricao: " << descricao << endl;
}

void Locais::escrever(ostream & out)
{  
	for (int i=0; i<actual; i++)
	{
		if (typeid(*vec[i]) == typeid(LocaisHistoricosCulturais)) dynamic_cast <LocaisHistoricosCulturais *>(vec[i])->escreve(cout);
		if (typeid(*vec[i]) == typeid(LocaisNaturais)) dynamic_cast <LocaisNaturais *>(vec[i])->escreve(cout);
		
	}
	system("pause");
}





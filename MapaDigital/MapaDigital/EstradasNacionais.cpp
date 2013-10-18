#include "EstradasNacionais.h"
#include "ViasLigacao.h"


EstradasNacionais::EstradasNacionais()
{
	tipoPavimento = "vazio";
}

EstradasNacionais::EstradasNacionais(string cod,double totalVia,double tempMedio,string orig,string dest,string tipoPav) : ViasLigacao(cod,totalVia,tempMedio,orig,dest)
{
	tipoPavimento = tipoPav;
}

EstradasNacionais::~EstradasNacionais(){}


ViasLigacao * EstradasNacionais::clone() const{
	return new EstradasNacionais(*this);
}



EstradasNacionais::EstradasNacionais(const EstradasNacionais &en)
{
	setTipoPavimento(en.tipoPavimento);
}

void EstradasNacionais::setTipoPavimento(string tipoPav)
{
	tipoPavimento = tipoPav;
}

string EstradasNacionais::getTipoPavimento() const
{
	return tipoPavimento;
}

void EstradasNacionais::escrever(ostream &out)const
{
	ViasLigacao::escrever(cout);
	cout << "Tipo Pavimento: " << tipoPavimento << endl;
}


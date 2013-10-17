#include "EstradasNacionais.h"
#include "ViasLigacao.h"


EstradasNacionais::EstradasNacionais()
{
	tipoPavimento = "não definido";
}

EstradasNacionais::EstradasNacionais(string cod,double totalVia,double tMedio,string tipoPav) : ViasLigacao(cod,totalVia,tMedio)
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

void EstradasNacionais::escreve(ostream &out){
	ViasLigacao::escrever(cout);
	cout << " Tipo Pavimento " << tipoPavimento;
}


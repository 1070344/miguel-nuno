#include "EstradasNacionais.h"
#include "ViasLigacao.h"


EstradasNacionais::EstradasNacionais()
{
	tipoPavimento = "vazio";
}

EstradasNacionais::EstradasNacionais(string orig,string dest,string cod,int totalVia,int tempMedio,string tipoPav) : ViasLigacao(orig,dest,cod,totalVia,tempMedio)
{
	tipoPavimento = tipoPav;
}

EstradasNacionais::~EstradasNacionais(){}


EstradasNacionais * EstradasNacionais::clone() const{
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
	cout << "TIPO DE VIA: " << "Estrada Nacional" << endl;
	ViasLigacao::escrever(cout);
	cout << "TIPO DE PAVIMENTO: " << tipoPavimento << endl << endl;
}


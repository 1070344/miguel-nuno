#include "AutoEstradas.h"
#include "ViasLigacao.h"


AutoEstradas::AutoEstradas()
{
	precoPortagem = 0;
}

AutoEstradas::AutoEstradas(string orig,string dest,string cod,int totalVia,int tempMedio,double preco) : ViasLigacao(orig,dest,cod,totalVia,tempMedio)
{
	precoPortagem = preco;
}

AutoEstradas::~AutoEstradas(){}


AutoEstradas * AutoEstradas::clone() const{
	return new AutoEstradas(*this);
}


AutoEstradas::AutoEstradas(const AutoEstradas &ae)
{
	setPrecoPortagem(ae.precoPortagem);
}

void AutoEstradas::setPrecoPortagem(double preco)
{
	precoPortagem = preco;
}

double AutoEstradas::getPrecoPortagem() const
{
	return precoPortagem;
}

void AutoEstradas::escrever(ostream &out)const
{
	cout << "TIPO DE VIA: " << "Auto Estrada" << endl;
	ViasLigacao::escrever(cout);
	cout << "PRECO DA PORTAGEM: " << precoPortagem << endl << endl;
}
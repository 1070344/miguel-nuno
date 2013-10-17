#include "AutoEstradas.h"
#include "ViasLigacao.h"


AutoEstradas::AutoEstradas()
{
	precoPortagem = 0;
}

AutoEstradas::AutoEstradas(string cod,double totalVia,double tMedio,double preco) : ViasLigacao(cod,totalVia,tMedio)
{
	precoPortagem = preco;
}

AutoEstradas::~AutoEstradas(){}


ViasLigacao * AutoEstradas::clone() const{
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


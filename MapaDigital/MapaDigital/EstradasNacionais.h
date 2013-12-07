#ifndef EstradasNacionais_
#define EstradasNacionais_

#include <iostream>
#include <string>
#include <string.h>


#include "ViasLigacao.h"


class EstradasNacionais : public ViasLigacao
{
	private:
		string tipoPavimento;//asfalto, paralelo, terra batida, etc.
	public:
		EstradasNacionais();
		EstradasNacionais(const EstradasNacionais &en);
		EstradasNacionais(Locais* origem, Locais* destino,string cod,int totalVia,int tempMedio,string tipoPav);
		~EstradasNacionais();
		virtual ViasLigacao * clone() const;

		//SET's e GET's
		void setTipoPavimento(string tipoPav);
		string getTipoPavimento()const;
	
		void escrever(ostream &out)const;
		
		EstradasNacionais & operator = (const EstradasNacionais &en);
		bool operator ==(const EstradasNacionais &en) const;

		friend ostream & operator << (ostream & out, const EstradasNacionais * en);
		friend ostream & operator << (ostream & out, const EstradasNacionais  & en);

};


EstradasNacionais::EstradasNacionais()
{
	tipoPavimento = "vazio";
}

EstradasNacionais::EstradasNacionais(Locais* origem, Locais* destino,string cod,int totalVia,int tempMedio,string tipoPav) : ViasLigacao(origem,destino,cod,totalVia,tempMedio)
{
	tipoPavimento = tipoPav;
}

EstradasNacionais::~EstradasNacionais()
{

}


ViasLigacao * EstradasNacionais::clone() const{
	return new EstradasNacionais(*this);
}

EstradasNacionais::EstradasNacionais(const EstradasNacionais &en) : ViasLigacao(en)
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


EstradasNacionais& EstradasNacionais::operator=(const EstradasNacionais &en) {
	tipoPavimento = en.tipoPavimento;
	return *this;
}

ostream & operator << (ostream & out, const EstradasNacionais * en){
	en->escrever(out);
	return out;
}

ostream & operator << (ostream & out, const EstradasNacionais & en){
	en.escrever(out);
	return out;
}



#endif
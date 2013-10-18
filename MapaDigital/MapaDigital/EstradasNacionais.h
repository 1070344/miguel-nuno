#ifndef EstradasNacionais_
#define EstradasNacionais_

#include "ViasLigacao.h"

class EstradasNacionais : public ViasLigacao
{
	private:
		string tipoPavimento;//asfalto, paralelo, terra batida, etc.
		//código da via
		//ao total de kms da via
		//tempo médio do percurso em minutos entre um local origem e um local destino.
	public:
		EstradasNacionais();
		EstradasNacionais(const EstradasNacionais &en);
		EstradasNacionais(string cod,double totalVia,double tempMedio,string orig,string dest,string tipoPav);
		~EstradasNacionais();
		virtual ViasLigacao * clone() const;

		//SET's e GET's
		void setTipoPavimento(string tipoPav);
		string getTipoPavimento()const;
	
		//Sobrecarga de operadores
		EstradasNacionais & operator =(const EstradasNacionais &en);
		bool operator >(const EstradasNacionais &en);
		bool operator <(const EstradasNacionais &en);
		bool operator ==(const EstradasNacionais &en);
		void escrever(ostream &out)const;
		

};
#endif
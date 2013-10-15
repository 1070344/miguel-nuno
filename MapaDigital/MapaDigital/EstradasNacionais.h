#ifndef EstradasNacionais_
#define EstradasNacionais_

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
		EstradasNacionais(string cod,double totalVia,double tMedio,string tipoPav);
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
		void escreve(ostream &out);
		

};


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
	ViasLigacao::escreve(cout);
	cout << " Tipo Pagvimento " << tipoPavimento;
}


#endif
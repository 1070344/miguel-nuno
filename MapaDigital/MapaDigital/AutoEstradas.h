#ifndef AutoEstradas_
#define AutoEstradas_


class AutoEstradas : public ViasLigacao
{
	private:
		double precoPortagem;
	public:
		AutoEstradas();
		AutoEstradas(const AutoEstradas &ae);
		AutoEstradas(string cod,double totalVia,double tempMedio,double preco);
		~AutoEstradas();

		//SET's e GET's
		void setPrecoPortagem(double preco);
		double getPrecoPortagem() const;
	
		
		//Sobrecarga de operadores
		AutoEstradas & operator =(const AutoEstradas &ae);
		bool operator >(const AutoEstradas &ae);
		bool operator <(const AutoEstradas &ae);
		bool operator ==(const AutoEstradas &ae);
		void escreve(ostream &out) const;
		

};

AutoEstradas::AutoEstradas()
{
	precoPortagem = 0;
}

AutoEstradas::AutoEstradas(string cod,double totalVia,double tMedio,double preco) : ViasLigacao(cod,totalVia,tMedio)
{
	precoPortagem = preco;
}

AutoEstradas::~AutoEstradas(){}

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


#endif
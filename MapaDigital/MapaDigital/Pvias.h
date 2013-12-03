#ifndef Pvias_
#define Pvias_

#include <ostream>

using namespace std;

#include "Locais.h"
#include "ViasLigacao.h"
#include "EstradasNacionais.h"
#include "AutoEstradas.h"


class Pvias {
	private:
		ViasLigacao *apvia;

		enum TipoComparacao { KMS , CUSTO ,TEMPO}; 
		static TipoComparacao  tipoComparacao;

	public:
		Pvias();
		Pvias(int km, int tempo, double preco);
		Pvias(const Pvias &v);
		Pvias(const ViasLigacao &vl);
		~Pvias();

		int getKM() const;
		double getPreco() const;
		int getTempo() const;

		static void setComparacaoKMS();
		static void setComparacaoCUSTO();
		static void setComparacaoTEMPO();

		bool operator >(const Pvias &v) const;
		bool operator <(const Pvias &v) const;
		bool operator ==(const Pvias &v) const;
		Pvias operator+(const Pvias &v);
		const Pvias & operator+=(const Pvias &v);
		const Pvias & operator=(const Pvias &v);

		friend ostream & operator << (ostream & out, const Pvias * v);
		friend ostream & operator << (ostream & out, const Pvias  & v);

		void escreve(ostream &out) const;
};



Pvias::TipoComparacao Pvias::tipoComparacao=Pvias::TipoComparacao::KMS;

void Pvias::setComparacaoKMS() {
	tipoComparacao=TipoComparacao::KMS;
}
void Pvias::setComparacaoCUSTO() {
	tipoComparacao=TipoComparacao::CUSTO;
}
void Pvias::setComparacaoTEMPO() {
	tipoComparacao=TipoComparacao::TEMPO;
}

Pvias::Pvias(){
	apvia = new AutoEstradas();
}

Pvias::Pvias(int km, int tempo, double preco){
	apvia = new AutoEstradas("",km,tempo,preco,NULL,NULL);
}

Pvias::~Pvias(){
	delete apvia;
}

Pvias::Pvias(const Pvias &v){
	apvia=v.apvia->clone();
}

Pvias::Pvias(const ViasLigacao &vl){
	this->apvia=vl.clone();
}

int Pvias::getKM() const {
	return apvia->getTotalKilometrosVia();
}

double Pvias::getPreco() const {
	return apvia->getPrecoPortagem();
}

int Pvias::getTempo() const{
	return apvia->getTempoMedioPercurso();
}

bool Pvias::operator >(const Pvias &v) const{
	if (tipoComparacao==TipoComparacao::KMS) return this->apvia->getTotalKilometrosVia() > v.apvia->getTotalKilometrosVia();
	if (tipoComparacao==TipoComparacao::CUSTO) return this->apvia->getPrecoPortagem() > v.apvia->getPrecoPortagem();	
	if (tipoComparacao==TipoComparacao::TEMPO) return this->apvia->getTempoMedioPercurso() > v.apvia->getTempoMedioPercurso();
}

bool Pvias::operator <(const Pvias &v) const{
	if (tipoComparacao==TipoComparacao::KMS) return this->apvia->getTotalKilometrosVia() < v.apvia->getTotalKilometrosVia();
	if (tipoComparacao==TipoComparacao::CUSTO) return this->apvia->getPrecoPortagem() < v.apvia->getPrecoPortagem();	
	if (tipoComparacao==TipoComparacao::TEMPO) return this->apvia->getTempoMedioPercurso() < v.apvia->getTempoMedioPercurso();
		
}

bool Pvias::operator ==(const Pvias &v) const{
	if (tipoComparacao==TipoComparacao::KMS) return this->apvia->getTotalKilometrosVia() == v.apvia->getTotalKilometrosVia();
	if (tipoComparacao==TipoComparacao::CUSTO) return this->apvia->getPrecoPortagem() == v.apvia->getPrecoPortagem();
	if (tipoComparacao==TipoComparacao::TEMPO) return this->apvia->getTempoMedioPercurso() == v.apvia->getTempoMedioPercurso();
}

Pvias Pvias::operator+(const Pvias &v){
	return Pvias(apvia->getTotalKilometrosVia()+v.apvia->getTotalKilometrosVia(),
		apvia->getTempoMedioPercurso()+v.apvia->getTempoMedioPercurso(),
		apvia->getPrecoPortagem()+v.apvia->getPrecoPortagem());
}

const Pvias & Pvias :: operator+=(const Pvias &v)
{
	apvia->setTotalKilometrosVia(apvia->getTotalKilometrosVia() + v.apvia->getTotalKilometrosVia());
	apvia->setTempoMedioPercurso(apvia->getTempoMedioPercurso() + v.apvia->getTempoMedioPercurso());
	if (typeid(*apvia)==typeid(AutoEstradas)) {
		AutoEstradas *ae = (AutoEstradas *)this->apvia;
		ae->setPrecoPortagem(ae->getPrecoPortagem() + v.apvia->getPrecoPortagem());
	}	
	return *this;
}

const Pvias & Pvias::operator=(const Pvias &v) {
	this->apvia = v.apvia->clone();
	return *this;
}

void Pvias::escreve(ostream & out) const{
	cout << *apvia;
}

ostream & operator << (ostream & out, const Pvias & v){
	v.escreve(out);
	return out;
}



#endif 
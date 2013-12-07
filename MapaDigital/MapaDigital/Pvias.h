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
		Pvias(const Pvias &pvias);
		Pvias(const ViasLigacao &vias);
		~Pvias();

		int getKM() const;
		double getPreco() const;
		int getTempo() const;

		static void setComparacaoKMS();
		static void setComparacaoCUSTO();
		static void setComparacaoTEMPO();

		bool operator >(const Pvias &pvias) const;
		bool operator <(const Pvias &pvias) const;
		bool operator ==(const Pvias &pvias) const;
		Pvias operator+(const Pvias &pvias);
		const Pvias & operator+=(const Pvias &pvias);
		const Pvias & operator=(const Pvias &pvias);

		friend ostream & operator << (ostream & out, const Pvias * pvias);
		friend ostream & operator << (ostream & out, const Pvias  & pvias);

		void escrever(ostream &out) const;
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
	apvia = new AutoEstradas(NULL,NULL,"",km,tempo,preco);
}

Pvias::~Pvias(){
	delete apvia;
}

Pvias::Pvias(const Pvias &pvias){
	apvia=pvias.apvia->clone();
}

Pvias::Pvias(const ViasLigacao &vias){
	this->apvia=vias.clone();
}

int Pvias::getKM() const {
	return apvia->getTotalKilometrosVia();
}

double Pvias::getPreco() const {
	return apvia->getPrecoPortagem();//ainda n pus
}

int Pvias::getTempo() const{
	return apvia->getTempoMedioPercurso();
}

bool Pvias::operator >(const Pvias &pvias) const{
	if (tipoComparacao==TipoComparacao::KMS) return this->apvia->getTotalKilometrosVia() > pvias.apvia->getTotalKilometrosVia();
	if (tipoComparacao==TipoComparacao::CUSTO) return this->apvia->getPrecoPortagem() > pvias.apvia->getPrecoPortagem();	
	if (tipoComparacao==TipoComparacao::TEMPO) return this->apvia->getTempoMedioPercurso() > pvias.apvia->getTempoMedioPercurso();
}

bool Pvias::operator <(const Pvias &pvias) const{
	if (tipoComparacao==TipoComparacao::KMS) return this->apvia->getTotalKilometrosVia() < pvias.apvia->getTotalKilometrosVia();
	if (tipoComparacao==TipoComparacao::CUSTO) return this->apvia->getPrecoPortagem() < pvias.apvia->getPrecoPortagem();	
	if (tipoComparacao==TipoComparacao::TEMPO) return this->apvia->getTempoMedioPercurso() < pvias.apvia->getTempoMedioPercurso();
		
}

bool Pvias::operator ==(const Pvias &pvias) const{
	if (tipoComparacao==TipoComparacao::KMS) return this->apvia->getTotalKilometrosVia() == pvias.apvia->getTotalKilometrosVia();
	if (tipoComparacao==TipoComparacao::CUSTO) return this->apvia->getPrecoPortagem() == pvias.apvia->getPrecoPortagem();
	if (tipoComparacao==TipoComparacao::TEMPO) return this->apvia->getTempoMedioPercurso() == pvias.apvia->getTempoMedioPercurso();
}

Pvias Pvias::operator+(const Pvias &pvias){
	return Pvias(apvia->getTotalKilometrosVia()+pvias.apvia->getTotalKilometrosVia(),
		apvia->getTempoMedioPercurso()+pvias.apvia->getTempoMedioPercurso(),
		apvia->getPrecoPortagem()+pvias.apvia->getPrecoPortagem());
}

const Pvias & Pvias :: operator+=(const Pvias &pvias)
{
	apvia->setTotalKilometrosVia(apvia->getTotalKilometrosVia() + pvias.apvia->getTotalKilometrosVia());
	apvia->setTempoMedioPercurso(apvia->getTempoMedioPercurso() + pvias.apvia->getTempoMedioPercurso());
	if (typeid(*apvia)==typeid(AutoEstradas)) {
		AutoEstradas *ae = (AutoEstradas *)this->apvia;
		ae->setPrecoPortagem(ae->getPrecoPortagem() + pvias.apvia->getPrecoPortagem());
	}	
	return *this;
}

const Pvias & Pvias::operator=(const Pvias &pvias) {
	this->apvia = pvias.apvia->clone();
	return *this;
}

void Pvias::escrever(ostream & out) const{
	cout << *apvia;
}

ostream & operator << (ostream & out, const Pvias & pvias){
	pvias.escrever(out);
	return out;
}



#endif 
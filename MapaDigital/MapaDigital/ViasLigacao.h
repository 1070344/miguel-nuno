#ifndef ViasLigacao_
#define ViasLigacao_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>


using namespace std;



class ViasLigacao
{
	private:
		ViasLigacao **vec;
		string codigo; //c�digo da via
		double totalKilometrosVia; //total de KM's da Via
		double tempMedioPercurso;//tempo m�dio do percurso em minutos entre um local origem e um local destino
		int actual;
		int tamanho;
	
	public:
		ViasLigacao();
		ViasLigacao(const ViasLigacao &vias);
		ViasLigacao(string cod,double totalVia,double tempMedio);
		virtual ViasLigacao * clone() const;
		virtual ~ViasLigacao();

		//SET's e GET's
		void setCodigoVia(string cod);
		void setTotalKilometrosVia(double totalVia);
		void setTempoMedioPercurso(double tempMedio);
		
		string getCodigoVia()const;
		double getTotalKilometrosVia()const;
		double getTempoMedioPercurso()const;

		//M�todos da classe
		virtual void inserirViaLigacao(ViasLigacao * v);
		virtual void contarVias() const;
		virtual void escrever(ostream & out);

		//Sobrecarga de operadores
		/*ViasLigacao & operator =(const ViasLigacao &vias);
		bool operator >(const ViasLigacao &vias);
		bool operator <(const ViasLigacao &vias);
		bool operator ==(const ViasLigacao &vias);*/
};
#endif
#ifndef LocaisHistoricosCulturais_
#define LocaisHistoricosCulturais_

#include "Locais.h"

class LocaisHistoricosCulturais : public Locais
{
	private:
		int tempoVisita;
		int horarioAbertura;
		int horarioEncerramento;
	public:
		LocaisHistoricosCulturais();
		LocaisHistoricosCulturais(const LocaisHistoricosCulturais &locHist);
		LocaisHistoricosCulturais(string desc,int tempoVisita,int horarioAbertura,int horarioEncerramento);
		~LocaisHistoricosCulturais();
		virtual Locais * clone() const;

		//SET's e GET's
		void setTempoVisita(int tVisita);
		void setHorarioAbertura(int abertura);
		void setHorarioEncerramento(int encerramento);

		int getTempoVisita()const;
		int getHorarioAbertura()const;
		int getHorarioEncerramento()const;

		void  escreve(ostream & out) const;	
};
#endif
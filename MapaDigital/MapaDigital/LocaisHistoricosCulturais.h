#ifndef LocaisHistoricosCulturais_
#define LocaisHistoricosCulturais_



class LocaisHistoricosCulturais : public Locais
{
	private:
		int tempoVisita;//tempo medio de visita em minutos
		int horarioAbertura;//em minutos
		int horarioEncerramento;//em minutos
	
	public:
		LocaisHistoricosCulturais();
		LocaisHistoricosCulturais(const LocaisHistoricosCulturais &locHist);
		LocaisHistoricosCulturais(string desc,int tempoVisita,int horarioAbertura,int horarioEncerramento);
		~LocaisHistoricosCulturais();

		//SET's e GET's
		void setTempoVisita(int tVisita);
		void setHorarioAbertura(int abertura);
		void setHorarioEncerramento(int encerramento);

		int getTempoVisita()const;
		int getHorarioAbertura()const;
		int getHorarioEncerramento()const;

		
};

LocaisHistoricosCulturais::LocaisHistoricosCulturais()
{
	tempoVisita = 0;
	horarioAbertura = 0;
	horarioEncerramento = 0;
}


LocaisHistoricosCulturais::LocaisHistoricosCulturais(string desc,int tVisita,int abertura,int encerramento) : Locais(desc)//desc=descrição - variavel da superclasse Locais
{
	tempoVisita = tVisita;
	horarioAbertura = abertura;
	horarioEncerramento = encerramento;
}



LocaisHistoricosCulturais::LocaisHistoricosCulturais(const LocaisHistoricosCulturais &locHist)
{
	setTempoVisita(locHist.tempoVisita);
	setHorarioAbertura(locHist.horarioAbertura);
	setHorarioEncerramento(locHist.horarioEncerramento);
}


void LocaisHistoricosCulturais::setTempoVisita(int tVisita)
{
	tempoVisita = tVisita;
}
						

void LocaisHistoricosCulturais::setHorarioAbertura(int abertura)
{
	horarioAbertura = abertura;
}

void LocaisHistoricosCulturais::setHorarioEncerramento(int encerramento)
{
	horarioEncerramento = encerramento;
}


#endif
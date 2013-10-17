#include "ViasLigacao.h"
#include "EstradasNacionais.h"
#include "AutoEstradas.h"


ViasLigacao::ViasLigacao(){
		codigo = "";
		totalKilometrosVia = 0;
		tempMedioPercurso = 0;
		actual = 0;
		tamanho = 0;
}

ViasLigacao::ViasLigacao(string cod,double totalVia,double tempMedio)
{
	codigo = cod;
	totalKilometrosVia = totalVia;
	tempMedioPercurso = tempMedio;
}


ViasLigacao::ViasLigacao(const ViasLigacao &vias)
{
	setCodigoVia(vias.codigo);
	setTotalKilometrosVia(vias.totalKilometrosVia);
	setTempoMedioPercurso(vias.tempMedioPercurso);
}


ViasLigacao::~ViasLigacao()
{

}


ViasLigacao * ViasLigacao::clone() const
{
	return new ViasLigacao(*this);
}



void ViasLigacao::setCodigoVia(string cod)
{
	codigo = cod;
}

void ViasLigacao::setTotalKilometrosVia(double totalVia)
{
	totalKilometrosVia = totalVia;
}

void ViasLigacao::setTempoMedioPercurso(double tempMedio)
{
	tempMedioPercurso = tempMedio;
}


string ViasLigacao::getCodigoVia() const
{
	return codigo;
}

double ViasLigacao::getTotalKilometrosVia() const
{
	return totalKilometrosVia;
}

double ViasLigacao::getTempoMedioPercurso() const
{
	return tempMedioPercurso;
}





/*ViasLigacao & ViasLigacao::operator=(const ViasLigacao &vias)
{
	if(this != &vias){
		codigo = vias.getCodigoVia();
		totalKilometrosVia = vias.getTotalKilometrosVia();
		tempMedioPercurso = vias.getTempoMedioPercurso();
	}
	return *this;
}

bool ViasLigacao::operator < (const ViasLigacao & vias)
{
	if (codigo < vias.codigo) return true; else return false;
}

bool ViasLigacao::operator > (const ViasLigacao & vias)
{
	if (codigo > vias.codigo) return true; else return false;
}

bool ViasLigacao::operator == (const ViasLigacao & vias)
{
	if (codigo == vias.codigo) return true; else return false;
}*/

void ViasLigacao::inserirViaLigacao(ViasLigacao *v)
{
	/*Inserir as vias de liga��o a partir de um ficheiro de texto com a informa��o estruturada do seguinte 
	modo:
				LocTurist1,LocTurist2,EN1,100,90,asfalto
				LocTurist3,LocTurist7,EN2,55,35,paralelo
				LocTurist2,LocTurist5,EN1,200,150,asfalto
				�
				LocTurist5,LocTurist2,A3,54,30,3.25
				LocTurist4,LocTurist1,A1,120,60,13.25
				LocTurist9,LocTurist6,A4,80,90,7.05
				�
				LocTurist1,LocTurist7,A2,65,40,4.15*/

	if (actual == tamanho)//axo que nao ta bem pro que se pede.comfirmar......
	{
		tamanho = 2* tamanho;
		ViasLigacao * * vec_tmp = new ViasLigacao * [tamanho];
		for (int i=0; i<actual; i++)
			vec_tmp[i] = vec[i];
		delete [] vec;
		vec = vec_tmp;
	}

	vec[actual] = v->clone();
	actual++;
}
	
void ViasLigacao::contarVias() const
{
	int autoestradas = 0;
	int estradasnacionais = 0;

	/*for (int i=0; i<actual; i++)
	{
		if (typeid(*vec[i]) == typeid(AutoEstradas)) autoestradas++;
		if (typeid(*vec[i]) == typeid(EstradasNacionais)) estradasnacionais++;
	}
	cout << "Total de Vias de Ligacao" << endl;
	cout << "::::::::::Auto-Estradas: " << autoestradas << " vias." << endl;
	cout << "::::::::::Estradas-Nacionais: " << estradasnacionais << " vias." << endl;
	*/
}



void ViasLigacao::escrever(ostream & out)
{  
	/*for (int i=0; i<actual; i++)
	{ 
		if (typeid(*vec[i]) == typeid(AutoEstradas)) dynamic_cast <AutoEstradas *>(vec[i])->escreve(out); 
		if (typeid(*vec[i]) == typeid(EstradasNacionais)) dynamic_cast <EstradasNacionais *>(vec[i])->escreve(out); 
	} */
}



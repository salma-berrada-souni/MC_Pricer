#include "MonteCarloVanille.h"
#include "GenerateurAlea.h"
#include <cmath>
using namespace std;


/* Il est important de passer l'objet payoff par reference et d'ajouter le mot clef const car ...*/

double MonteCarloVanille(const OptionVanille& OptionVanille, double So, double Vol, double r, unsigned long NbSimu)
{
	double Maturite=OptionVanille.GetMaturite();

	double variance=Vol*Vol*Maturite;
	double racineVariance=sqrt(variance);
	double correction=-0.5*variance;

	double constante=So*exp(r*Maturite+correction);
	double thisSo;
	double runningSum=0;

	// Param�tres pour r�duction de variance ( Variable antith�tique)
	double runningSum2=0;
	double thisSo2;
	NbSimu=NbSimu/2;

	for (unsigned long i=0; i< (NbSimu); i++)
	{
		// on genere une variable gaussienne centr�e et var 1
		double varNormale=GetOneGaussianByBoxMuller();
		thisSo=constante*exp(racineVariance*varNormale);
		double thisPayOff=OptionVanille.PayOffOption(thisSo);//On utilise ici la classe payoff et l'operateur d�finit dedans pour calculer le Payoff de l'option
		runningSum+=thisPayOff;

		//cr�ation variable antith�tique n�gativement corr�l�e 
		double varNormale2=-varNormale;
		thisSo2=constante*exp(racineVariance*varNormale2);
		double thisPayOff2=OptionVanille.PayOffOption(thisSo2);	//On utilise ici la classe payoff et l'operateur d�finit dedans
		runningSum2+=thisPayOff2;
	}

	//Moyenne des variables de base
	double mean=runningSum/NbSimu;
	mean *=exp(-r*Maturite);

	//Moyenne des variables antith�tiques
	double mean2=runningSum2/NbSimu;
	mean2 *=exp(-r*Maturite);
	
	return (mean+mean2)/2;
}
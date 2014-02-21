#pragma once
#ifndef PAYOFF_H
#define  PAYOFF_H

class PayOff
{

public:

	//Constructeur
	PayOff(){};

	//Operateur de calcul du payoff 
	virtual double operator()(double So) const=0;
	/*le =0 représente le fait que la fonction est purement virtuelle. 
	Cela représente le fait que la classe est incomplète et que certains aspects doivent être spécifiés 
	dans les classes filles ne requiert pas d'être définit dans la classe mère mais dans la classe fille*/

	//Destructeur 
	virtual ~PayOff(){};
	
private:
};

#endif


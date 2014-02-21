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
	/*le =0 repr�sente le fait que la fonction est purement virtuelle. 
	Cela repr�sente le fait que la classe est incompl�te et que certains aspects doivent �tre sp�cifi�s 
	dans les classes filles ne requiert pas d'�tre d�finit dans la classe m�re mais dans la classe fille*/

	//Destructeur 
	virtual ~PayOff(){};
	
private:
};

#endif


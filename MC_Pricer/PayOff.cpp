#include "PayOff.h"
#include <MinMax.h>

/*PayOff::PayOff(double Strike_,OptionType TheOptionsType_)
:
Strike(Strike_), TheOptionsType(TheOptionsType_)
{
}

// Methode de la class retournant le PayOff selon le type de l'option 
double PayOff::operator () (double spot) const
{
	switch (TheOptionsType)
	{
	case call:
		return max(spot-Strike,0.0);

	case put:
		return max(Strike-spot,0.0);

	default:
		throw("Unknown option type found!");
	}
}*/

/*
// Constructeur PayOffcall et PayOffPut
PayOffCall::PayOffCall(double Strike_):Strike(Strike_)
{
}
PayOffPut::PayOffPut(double Strike_):Strike(Strike_)
{
}
// Méthodes associées 

double PayOffCall::operator()(double Spot) const 
{
	return max(Spot-Strike,0.0);
}
double PayOffPut::operator()(double Spot) const 
{
	return max(Strike-Spot,0.0);
}
*/



#ifndef PUT_H
#define PUT_H

#include "PayOff.h"

// Classe PayOffPut qui hérite de la classe PayOff aussi 
class PayOffPut: public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double So) const;
	virtual ~PayOffPut(){};
	
private:
	double Strike; 
};
#endif
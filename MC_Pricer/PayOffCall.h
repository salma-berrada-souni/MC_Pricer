
#ifndef CALL_H
#define CALL_H

#include "PayOff.h"

// Classe PayOffPut qui hérite de la classe PayOff aussi 
class PayOffCall: public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double So) const;
	virtual ~PayOffCall(){};
	
private:
	double Strike; 
};
#endif
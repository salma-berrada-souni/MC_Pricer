
#ifndef VAN
#define VAN

#include "PayOff.h"

class OptionVanille
{
public:
	OptionVanille(PayOff& LePayOff_, double Maturite_);
	double GetMaturite() const; 
	double PayOffOption(double So) const;

private:
	double Maturite;
	PayOff& LePayOff;
};

#endif

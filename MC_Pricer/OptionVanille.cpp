
#include "OptionVanille.h"

OptionVanille::OptionVanille(PayOff& LePayOff_, double Maturite_):LePayOff(LePayOff_), Maturite(Maturite_)
{
}

double OptionVanille::GetMaturite() const
{
	return Maturite; 
}

double OptionVanille::PayOffOption(double So) const
{
return LePayOff(So);
}
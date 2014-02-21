#include "PayOffPut.h"
#include <MinMax.h>

// Constructeur PayOffcall et PayOffPut

PayOffPut::PayOffPut(double Strike_):Strike(Strike_)
{
}

// Méthode
double PayOffPut::operator()(double So) const 
{
	return max(Strike-So,0.0);
}

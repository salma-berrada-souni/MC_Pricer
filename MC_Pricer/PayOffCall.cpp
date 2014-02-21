#include "PayOffCall.h"
#include <MinMax.h>

// Constructeur PayOffcall 

PayOffCall::PayOffCall(double Strike_):Strike(Strike_)
{
}

// surcharge de la methode operator
double PayOffCall::operator()(double So) const 
{
	return max(So-Strike,0.0);
}

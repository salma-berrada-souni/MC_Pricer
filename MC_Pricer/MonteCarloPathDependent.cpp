
#include "OptionPathDependent.h"
#include "GenVecteurAleatoire.h"
#include "MonteCarloPathDependent.h"
#include <cmath>
#include <vector>
using namespace std; 

double MonteCarloPathDependent(const OptionPathDependent& OptionPathDependent,std::vector<double> valeurs,std::vector<double> valeurs2,  double T, double Vol, double r, unsigned long num_sims, unsigned long num_intervals)
{

  double payoff_sum = 0.0;
  double payoff_sum2 = 0.0;
  num_sims=num_sims/2;

  for (int i=0; i<num_sims; i++) {
    MiseAJour(valeurs,valeurs2, r, Vol, T);
    payoff_sum += OptionPathDependent.pay_off_pathdependant(valeurs);
	payoff_sum2 += OptionPathDependent.pay_off_pathdependant(valeurs2);
  }
 
  return ((payoff_sum / static_cast<double>(num_sims)) * exp(-r*T)+(payoff_sum2 / static_cast<double>(num_sims)) * exp(-r*T))/2;

}



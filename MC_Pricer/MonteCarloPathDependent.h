
#ifndef MCA
#define MCA
#include "OptionPathDependent.h"

double  MonteCarloPathDependent(const OptionPathDependent& OptionPathDependent, std::vector<double> valeurs,std::vector<double> valeurs2, double T, double Vol, double r, unsigned long num_sims, unsigned long num_intervals);

#endif
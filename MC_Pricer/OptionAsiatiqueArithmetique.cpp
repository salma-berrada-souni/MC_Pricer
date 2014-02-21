
#include <numeric>  
#include <cmath>  
#include "OptionAsiatiqueArithmetique.h";


OptionAsiatiqueArithmetique::OptionAsiatiqueArithmetique(PayOff& LePayOff_) : LePayOff(LePayOff_) {}

double OptionAsiatiqueArithmetique::PayOffAsiatique(const std::vector<double>& valeurs) const {
  unsigned num_times = valeurs.size();
  double sum = std::accumulate(valeurs.begin(), valeurs.end(), 0);
  double arith_mean = sum / static_cast<double>(num_times);
  return (LePayOff)(arith_mean);
}

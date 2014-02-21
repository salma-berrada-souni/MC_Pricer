

#ifndef OPTIONARI
#define OPTIONARI

#include <vector>
#include "OptionAsiatique.h"
#include "PayOff.h"


class OptionAsiatiqueArithmetique : public OptionAsiatique {
 
public:
  OptionAsiatiqueArithmetique(PayOff& LePayOff);

  virtual ~OptionAsiatiqueArithmetique() {};
  
  // surcharge de la fonction
  virtual double PayOffAsiatique(const std::vector<double>& valeurs) const;

  
private:
  PayOff& LePayOff; 

};

#endif

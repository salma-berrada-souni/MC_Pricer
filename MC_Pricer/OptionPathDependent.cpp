#include <numeric>  // Necessary for std::accumulate
#include <cmath>  // For log/exp functions
#include "OptionPathDependent.h"
#include <minmax.h>



// =====================  
//Option Asiatique Arithmetique 
// =====================  

OptionAsiatAritmetic::OptionAsiatAritmetic(PayOff& _pay_off) : pay_off(_pay_off) {}

double OptionAsiatAritmetic::pay_off_pathdependant(const std::vector<double>& valeurs) const {
  unsigned num_times = valeurs.size();
  double sum = std::accumulate(valeurs.begin(), valeurs.end(), 0);
  double arith_mean = sum / static_cast<double>(num_times);
  return (pay_off)(arith_mean);
}

// ====================
// Option Asiatique Geometrique
// ====================

OptionAsiatGeom::OptionAsiatGeom(PayOff& _pay_off) : pay_off(_pay_off) {}

// Geometric mean pay-off price
double OptionAsiatGeom::pay_off_pathdependant(const std::vector<double>& valeurs) const {
  unsigned num_times = valeurs.size();
  double log_sum = 0.0;
  for (int i=0; i<valeurs.size(); i++) {
    log_sum += log(valeurs[i]);
  }

  double geom_mean = exp(log_sum / static_cast<double>(num_times) );
  return (pay_off)(geom_mean);
}

// ====================
// Option Barrirère Haute Desactivante
// ====================

OptionBarriereHauteDesactivante::OptionBarriereHauteDesactivante(PayOff& _pay_off, double H_) : pay_off(_pay_off), H(H_) {}

double OptionBarriereHauteDesactivante::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
  
  unsigned num_times = valeurs.size();
  int out=0;
  for (int i=0; i<valeurs.size(); i++) 
  {
     if (valeurs[i]>=H)
	 {out=1;}
  }

  if(out==1) {return 0;} 
  if(out==0) {return (pay_off)(valeurs[num_times-1]);}
	 
}
// ====================
// Option Barrirère Haute Activante
// ====================

OptionBarriereHauteActivante::OptionBarriereHauteActivante(PayOff& _pay_off, double H_) : pay_off(_pay_off), H(H_) {}

double OptionBarriereHauteActivante::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
  
  unsigned num_times = valeurs.size();
  int out=0;
  for (int i=0; i<valeurs.size(); i++) 
  {
     if (valeurs[i]>=H)
	 {out=1;}
  }

  if(out==0) {return 0;} 
  if(out==1) {return (pay_off)(valeurs[num_times-1]);}
	 
}
// ====================
// Option Barrirère Basse Desactivante
// ====================

OptionBarriereBasseDesactivante::OptionBarriereBasseDesactivante(PayOff& _pay_off, double L_) : pay_off(_pay_off), L(L_) {}

double OptionBarriereBasseDesactivante::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
  
  unsigned num_times = valeurs.size();
  int out=0;
  for (int i=0; i<valeurs.size(); i++) 
  {
     if (valeurs[i]<=L)
	 {out=1;}
  }

  if(out==1) {return 0;} 
  if(out==0) {return (pay_off)(valeurs[num_times-1]);}
	 
}
 
// ====================
// Option Barrirère Basse Activante
// ====================

OptionBarriereBasseActivante::OptionBarriereBasseActivante(PayOff& _pay_off, double L_) : pay_off(_pay_off), L(L_) {}

double OptionBarriereBasseActivante::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
  
  unsigned num_times = valeurs.size();
  int out=0;
  for (int i=0; i<valeurs.size(); i++) 
  {
     if (valeurs[i]<=L)
	 {out=1;}
  }

  if(out==0) {return 0;} 
  if(out==1) {return (pay_off)(valeurs[num_times-1]);}
	 
}

// ====================
// Option Double Barrirère  Activante
// ====================

OptionDoubleBarriereActivante::OptionDoubleBarriereActivante(PayOff& _pay_off, double L_, double H_) : pay_off(_pay_off), L(L_), H(H_) {}

double OptionDoubleBarriereActivante::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
  
  unsigned num_times = valeurs.size();
  int out=0;
  int out2=0;
  for (int i=0; i<valeurs.size(); i++) 
  {
     if (valeurs[i]<=L)
	 {out2=1;}
	  if(valeurs[i]>=H) 
	 {out=1;}
  }

  if((out==0) || (out2==0)) {return 0;} 
  if((out==1) && (out2==1)) {return (pay_off)(valeurs[num_times-1]);}
	 
}
 
// ====================
// Option Double Barrirère Desactivante
// ====================

OptionDoubleBarriereDesactivante::OptionDoubleBarriereDesactivante(PayOff& _pay_off, double L_, double H_) : pay_off(_pay_off), L(L_), H(H_) {}

double OptionDoubleBarriereDesactivante::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
  
  unsigned num_times = valeurs.size();
  int out=0;
  int out2=0;
  for (int i=0; i<valeurs.size(); i++) 
  {
     if (valeurs[i]<=L)
	 {out2=1;}
	  if(valeurs[i]>=H) 
	 {out=1;}
  }

  if((out==1) || (out2==1)) {return 0;} 
  if((out==0) && (out2==0)) {return (pay_off)(valeurs[num_times-1]);}
	 
}

// ====================
// Option Call LookBack Fixed Strike
// ====================

OptionCallLookBackFixedStrike::OptionCallLookBackFixedStrike(PayOff& _pay_off) : pay_off(_pay_off){}

double OptionCallLookBackFixedStrike::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
 
	unsigned num_times = valeurs.size();
    double sup=0;
    for(int i=0;i<valeurs.size();i++){
	  if (i==0) {sup=valeurs[i];}
	  if (i>0) {sup=max(valeurs[i],valeurs[i-1]);}
  }
	 return (pay_off)(sup);
}



// ====================
// Option Put LookBack Fixed Strike
// ====================

OptionPutLookBackFixedStrike::OptionPutLookBackFixedStrike(PayOff& _pay_off) : pay_off(_pay_off){}

double OptionPutLookBackFixedStrike::pay_off_pathdependant(const std::vector<double>& valeurs) const 
{
 
	unsigned num_times = valeurs.size();
    double inf=0;
    for(int i=0;i<valeurs.size();i++){
	  if (i==0) {inf=valeurs[i];}
	  if (i>0) {inf=min(valeurs[i],valeurs[i-1]);}
  }
	 return (pay_off)(inf);
}

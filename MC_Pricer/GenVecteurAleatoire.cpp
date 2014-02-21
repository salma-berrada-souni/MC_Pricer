
#include "GenVecteurAleatoire.h"
#include <cmath>
using namespace std;  

void MiseAJour(std::vector<double>& valeurs, std::vector<double>& valeurs2,const double& r,const double& vol,const double& T) 
{ 
 double dt = T/static_cast<double>(valeurs.size());
 double constante = exp(dt*(r-0.5*vol*vol));
 double v = sqrt(vol*vol*dt);

  for (int i=1; i<valeurs.size(); i++)
  {
    double var_normale = GetOneGaussianByBoxMuller();
	double var_normale2=-var_normale; //création variable antithétique négativement corrélée
    valeurs[i] = valeurs[i-1] * constante * exp(v*var_normale);
	valeurs2[i] = valeurs2[i-1] * constante * exp(v*var_normale2);//création d'un second vecteur pour la variable antithétique
  }
}

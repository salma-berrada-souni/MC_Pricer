#ifndef __Path
#define __Path

#include <vector>
#include "PayOff.h"

class OptionPathDependent {
 public:	
	 
	OptionPathDependent(){};
  virtual ~OptionPathDependent() {};

  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const = 0;
};


// =====================  
//Option Asiatique Arithmetique 
// =====================  

class OptionAsiatAritmetic : public OptionPathDependent {
 public:
  OptionAsiatAritmetic(PayOff& _pay_off);
  virtual ~OptionAsiatAritmetic() {};
  
//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion asiat arithmetique
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;

  private:
  PayOff& pay_off;
};


// ====================
// Option Asiatique Geometrique
// ====================

class OptionAsiatGeom : public OptionPathDependent {
 public:
  OptionAsiatGeom(PayOff& _pay_off);
  virtual ~OptionAsiatGeom() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion asiat geom
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;
};


// ====================
// Option Barrirère Haute Desactivante
// ====================

class OptionBarriereHauteDesactivante : public OptionPathDependent {
 public:
  OptionBarriereHauteDesactivante(PayOff& _pay_off,double H);
  virtual ~OptionBarriereHauteDesactivante() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;
  double H; 
};

// ====================
// Option Barrirère Haute Activante
// ====================


class OptionBarriereHauteActivante : public OptionPathDependent {
 public:
  OptionBarriereHauteActivante(PayOff& _pay_off,double H);
  virtual ~OptionBarriereHauteActivante() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;
  double H; 
};


// ====================
// Option Barrirère Basse Desactivante
// ====================

class OptionBarriereBasseDesactivante : public OptionPathDependent {
 public:
  OptionBarriereBasseDesactivante(PayOff& _pay_off,double L);
  virtual ~OptionBarriereBasseDesactivante() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;
  double L; 
};


// ====================
// Option Barrirère Basse Activante
// ====================


class OptionBarriereBasseActivante : public OptionPathDependent {
 public:
  OptionBarriereBasseActivante(PayOff& _pay_off,double L);
  virtual ~OptionBarriereBasseActivante() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;
  double L; 
};

// ====================
// Option Double Barrirère  Activante
// ====================

class OptionDoubleBarriereActivante : public OptionPathDependent {
 public:
  OptionDoubleBarriereActivante(PayOff& _pay_off,double L, double H);
  virtual ~OptionDoubleBarriereActivante() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;
  double L; 
  double H;

};


// ====================
// Option Double Barrirère Desactivante
// ====================

class OptionDoubleBarriereDesactivante : public OptionPathDependent {
 public:
  OptionDoubleBarriereDesactivante(PayOff& _pay_off,double L, double H);
  virtual ~OptionDoubleBarriereDesactivante() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;
  double L; 
  double H;

};


// ====================
// Option call LookBack Fixed Strike
// ====================

class OptionCallLookBackFixedStrike : public OptionPathDependent {
 public:
  OptionCallLookBackFixedStrike(PayOff& _pay_off);
  virtual ~OptionCallLookBackFixedStrike() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;

};



// ====================
// Option Put LookBack Fixed Strike
// ====================

class OptionPutLookBackFixedStrike : public OptionPathDependent {
 public:
  OptionPutLookBackFixedStrike(PayOff& _pay_off);
  virtual ~OptionPutLookBackFixedStrike() {};

//reecritue de la fonction virtuelle pour produire le pauoff d'une otpion barriere haute desactivante
  virtual double pay_off_pathdependant(const std::vector<double>& valeurs) const;
 
private:
  PayOff& pay_off;

};

#endif
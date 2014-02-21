#include <iostream>
#include <vector>
#include "PayOff.h"
#include "PayOffCall.h"
#include "OptionPathDependent.h"
#include "MonteCarloPathDependent.h"
#include "GenVecteurAleatoire.h"
#include "MonteCarloVanille.h"
#include "PayOffPut.h" 
#include "PayOffCall.h"
#include "OptionVanille.h"
#include <string>
using namespace std;

int main() {

int achat_vente;
int categorie;
unsigned long num_intervals; 
int nb_intervals;
unsigned long num_sims;  
int nb_sims;  
string typeOption;
string typeCallPut;
double S  ;  
double K  ; 
double r  ;   
double v  ;   
double T  ;
double H  ;
double L  ; 
double resultat=0;

goto debut;
erreurcategorie:
cout << "Erreur: Veuillez recommencer en vous assurant de taper un nombre entier compris entre 1 et 12" << endl <<endl <<endl;

debut:
cout << "Veuillez saisir le numero correspondant a la categorie d'option que vous souhaitez pricer:" <<endl;
cout<<"1: Vanille"<<endl;
cout<<"2: Asiatique (moyenne arithmetique) "<<endl;
cout<<"3: Asiatique (moyenne geometrique) "<<endl;
cout<<"4: Barriere Haute Desactivante"<<endl;
cout<<"5: Barriere Haute Activante"<<endl;
cout<<"6: Barriere Basse Desactivante"<<endl;
cout<<"7: Barriere Basse Activante"<<endl;
cout<<"8: Double Barriere Desactivante (Haute & Basse)"<<endl;
cout<<"9: Double Barriere Activante (Haute & Basse)"<<endl;
cout<<"10: Lookback Fixed Strike"<<endl;

cin>> categorie;

if (categorie!=1 && categorie!=2 && categorie!=3 && categorie!=4 && categorie!=5 && categorie!=6 && categorie!=7 && categorie!=8 && categorie!=9 && categorie!=10) { goto erreurcategorie ;}

goto debut2;
erreurAchatVente:
cout << "Erreur: Veuillez recommencer en vous assurant de taper 1 ou 2" << endl <<endl <<endl;

debut2:
cout << "Veuillez saisir le numero correspondant a la categorie de l'option que vous souhaitez pricer:" <<endl;
cout<<"1: Achat"<<endl;
cout<<"2: Vente"<<endl;
cin>> achat_vente;

if((achat_vente==1) )
	{
typeCallPut="Call ";
}
if((achat_vente==2) )
	{
typeCallPut="Put ";
}

if (achat_vente!=1 && achat_vente!=2){goto erreurAchatVente;}

goto debut3;
erreurnum_sims:
cout<<"Erreur: Veuillez recommencer en vous assurant de taper un nombre entier compris entre 1 et 5"<<endl <<endl <<endl;

debut3:
cout<<"Veuillez entrer le numero correspondant au nombre de simulations vous souhaitez effectuer:"<<endl;
cout<<"1: 25000"<<endl;
cout<<"2: 50000"<<endl;
cout<<"3: 100000"<<endl;
cout<<"4: 1000000"<<endl;
cout<<"5: Autre"<<endl;

cin>> nb_sims;

if (nb_sims==1){ num_sims=25000; }

if (nb_sims==2){ num_sims=50000; }

if (nb_sims==3){ num_sims=100000; }

if (nb_sims==4){ num_sims=1000000; }

if (nb_sims==5){
cout<<"Veuillez saisir le nombre de simulation souhaite:";
cin>> num_sims; 
}

if (nb_sims!=1 && nb_sims!=2 && nb_sims!=3 && nb_sims!=4 && nb_sims!=5) { goto erreurnum_sims ;}

cout<<"Veuillez saisir les parametres de l'option:"<<endl;

cout<<"prix spot S(0):"<<endl;
cin>>S;

if(categorie!=12){
cout<<"prix d'exercice (strike) K:"<<endl;
cin>>K;
}
cout<<"maturite T:"<<endl;
cin>>T;

cout<<"Taux sans risque r:"<<endl;
cin>>r;

cout<<"Volatilite implicite sigma:"<<endl;
cin>>v;

if(categorie!=1 && categorie!=2){
goto debut4;
erreurnum_intervals:
cout<<"Erreur: Veuillez recommencer en vous assurant de taper un nombre entier compris entre 1 et 5"<<endl <<endl <<endl;
debut4:
cout<<"Veuillez entrer le numero correspondant au nombre d'intervalles de temps:"<<endl;
cout<<"1: 100"<<endl;
cout<<"2: 500"<<endl;
cout<<"3: 1000"<<endl;
cout<<"4: 2000"<<endl;
cout<<"5: Autre"<<endl;
cin>> nb_intervals;

if (nb_intervals==1){ num_intervals=100; }

if (nb_intervals==2){ num_intervals=500; }

if (nb_intervals==3){ num_intervals=1000; }

if (nb_intervals==4){ num_intervals=2000; }

if (nb_intervals==5){
cout<<"Veuillez saisir le nombre de d'intervalles souhaite:";
cin>> num_intervals; 
}

if (nb_intervals!=1 && nb_intervals!=2 && nb_intervals!=3 && nb_intervals!=4 && nb_intervals!=5) { goto erreurnum_intervals ;}
}
	
// Creation de l'objet Pay Off correspondant au choix

// =====================  
//Option Vanille
// =====================  

if(categorie==1)
{
	typeOption="Vanille";

	if((achat_vente==1) )
	{
	PayOffCall pay_off(K);
	OptionVanille Vanille(pay_off,T);
	resultat= MonteCarloVanille(Vanille, S, v, r, num_sims); 
	}

	if((achat_vente==2) )
	{
	PayOffPut pay_off(K);
	OptionVanille Vanille(pay_off,T);
	resultat= MonteCarloVanille(Vanille, S, v, r, num_sims);	
	}

}

// =====================  
//Option Asiatique Arithmetique 
// =====================  

if(categorie==2) 
{
	typeOption="Asiatique Arithmetique";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	if((achat_vente==1) )
	{
		PayOffCall pay_off(K);
		OptionAsiatAritmetic AsiatArith(pay_off);
		resultat=MonteCarloPathDependent(AsiatArith,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if((achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionAsiatAritmetic AsiatArith(pay_off);
		resultat=MonteCarloPathDependent(AsiatArith,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}

// =====================  
//Option Asiatique Geometrique 
// =====================  

if(categorie==3)
{
	typeOption="Asiatique Geometrique";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	if((achat_vente==1) )
	{
		PayOffCall pay_off(K);
		OptionAsiatGeom AsiatArith(pay_off);
		resultat=MonteCarloPathDependent(AsiatArith,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if( (achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionAsiatGeom AsiatArith(pay_off);
		resultat=MonteCarloPathDependent(AsiatArith,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}


// ====================
// Option Barriere Haute Desactivante
// ====================

if(categorie==4)
{
	typeOption="Barriere Haute Desactivante";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	cout<<"Veuillez entrer la barriere haute:"<<endl;
	cin>> H; 

	if((achat_vente==1) )
	{
		
		PayOffCall pay_off(K);
		OptionBarriereHauteDesactivante BHD(pay_off,H);
		resultat=MonteCarloPathDependent(BHD,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
		
	}
	if((achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionBarriereHauteDesactivante BHD(pay_off,H);
		resultat=MonteCarloPathDependent(BHD,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}



// ====================
// Option Barriere Haute Activante
// ====================
if(categorie==5)
{
	typeOption="Barriere Haute Activante";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	cout<<"Veuillez entrer la barriere haute:"<<endl;
	cin>> H; 
 
	if((achat_vente==1) )
	{
		PayOffCall pay_off(K);
		OptionBarriereHauteActivante BHA(pay_off,H);
		resultat=MonteCarloPathDependent(BHA,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if((achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionBarriereHauteActivante BHA(pay_off,H);
		resultat=MonteCarloPathDependent(BHA,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	std::cout << "Number d'intervalles:  " << num_intervals << std::endl;
	std::cout << "Barriere haute:        " << H << std::endl;
}

// ====================
// Option Barriere Basse Desactivante
// ====================
if(categorie==6)
{
	typeOption="Barriere Basse Desactivante";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	cout<<"Veuillez entrer la barriere basse:"<<endl;
	cin>> L; 

	if((achat_vente==1) )
	{
		PayOffCall pay_off(K);
		OptionBarriereBasseDesactivante BBD(pay_off,L);
		resultat=MonteCarloPathDependent(BBD,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if((achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionBarriereBasseDesactivante BBD(pay_off,L);
		resultat=MonteCarloPathDependent(BBD,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}

// ====================
// Option Barriere Basse Activante
// ====================
if(categorie==7) 
{
	typeOption="Barriere Basse Activante";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	cout<<"Veuillez entrer la barriere basse:"<<endl;
	cin>> L; 

	if((achat_vente==1) )
	{
		PayOffCall pay_off(K);
		OptionBarriereBasseActivante BBA(pay_off,L);
		resultat=MonteCarloPathDependent(BBA,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if((achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionBarriereBasseActivante BBA(pay_off,L);
		resultat=MonteCarloPathDependent(BBA,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}

// ====================
// Option Double Barriere Desactivante
// ====================

if(categorie==8) 
{
	typeOption="Double Barriere Desactivante";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	cout<<"Veuillez entrer la barriere haute:"<<endl;
	cin>> H; 
	cout<<"Veuillez entrer la barriere basse:"<<endl;
	cin>> L; 

	if((achat_vente==1))
	{
		PayOffCall pay_off(K);
		OptionDoubleBarriereDesactivante DBD(pay_off,L,H);
		resultat=MonteCarloPathDependent(DBD,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if((achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionDoubleBarriereDesactivante DBD(pay_off,L,H);
		resultat=MonteCarloPathDependent(DBD,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}


// ====================
// Option Double Barriere  Activante
// ====================
if(categorie==9)
{
	typeOption="Double Barriere Activante";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 
	cout<<"Veuillez entrer la barriere haute:"<<endl;
	cin>> H; 
	cout<<"Veuillez entrer la barriere basse:"<<endl;
	cin>> L;

	if((achat_vente==1) )
	{
		PayOffCall pay_off(K);
		OptionDoubleBarriereActivante DBA(pay_off,L,H);
		resultat=MonteCarloPathDependent(DBA,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if((achat_vente==2) )
	{
		PayOffPut pay_off(K);
		OptionDoubleBarriereActivante DBA(pay_off,L,H);
		resultat=MonteCarloPathDependent(DBA,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}

// ====================
// Lookback Fixed Strike
// ====================
if(categorie==10)
{
	typeOption="LookBack Put Fixed Strike";
	
	std::vector<double> valeurs(num_intervals, S); 
	std::vector<double> valeurs2(num_intervals, S); 

	if((achat_vente==1) )
	{
		PayOffCall pay_off(K);
		OptionCallLookBackFixedStrike LBFS(pay_off);
		resultat=MonteCarloPathDependent(LBFS,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
	if((achat_vente==2) )
	{
		PayOffCall pay_off(K);
		OptionPutLookBackFixedStrike LBFS(pay_off);
		resultat=MonteCarloPathDependent(LBFS,valeurs,valeurs2,T,v,r,num_sims,num_intervals);
	}
}


  std::cout << "Prix du " << typeCallPut<< typeOption<< ":"<<resultat << endl<<endl<<endl;
  goto debut5;
 
  erreurreponse:
  cout << "Erreur: Veuillez recommencer en vous assurant de taper 1 ou 2" << endl <<endl <<endl;
  
  debut5:
  int reponse;
  cout<<"Souhaitez-vous pricer une autre option?"<<endl;
  cout<<"1: Oui"<<endl;
  cout<<"2: Non"<<endl;
  cin>> reponse;

  if (reponse!=1 && reponse!=2) { goto erreurreponse ;}

  if(reponse==1)
  {
  goto debut;
  }
}


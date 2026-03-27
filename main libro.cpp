#include <iostream>
using namespace std;
/* Scrivere il codice delle funzioni che creano un nuovo libro e la funzione che inserisce un nuovo libro 
(lo genero all’interno della funzione usando la funzione scritta in precedenza) all’interno di una libreria come visto in claasse
Fare delle prove e degli esempi del funzionamento nel main */
struct libro{
	string titolo;
	string autore;
	int anno;
	int pagine;
};

struct libreria{
	libro elenco[10];
	int nlibri;
};

libro nuovolibro(string titolo,string autore,int anno,int pagine){
	libro x;
	x.titolo=titolo;
	x.autore=autore;
	x.anno=anno;
	x.pagine=pagine;
	return x;
}

bool aggiungilibro(libreria &lib,string titolo,string autore,int anno,int pagine ){
	if(lib.nlibri>10){
		return false;
	}
	lib.elenco[lib.nlibri]=nuovolibro( titolo, autore, anno, pagine);
	lib.nlibri++;
	return true;
}
string visualizza(libreria lib ){
	string s;
	for(int i=0;i<lib.nlibri;i++){
		s+=lib.elenco[i].titolo+"\t";
		s+=lib.elenco[i].autore+"\t";
		s+=to_string(lib.elenco[i].anno)+"\n";
		s+=to_string(lib.elenco[i].pagine)+"\n";
	}
	return s;
}
int main(int argc, char** argv) {
	libreria bib;
	bib.nlibri=0;
	libro x=nuovolibro("X","Y",2007,200);
	aggiungilibro(bib,x.titolo,x.autore,x.anno,x.pagine);
cout<<	visualizza(bib);
	return 0;
}
#include "Artista.h"
#include "Album.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Artista::Artista(vector<Album*>::iterator i, vector<Album*>d, string n)
{
	iteD=i;
	discos=d;
	nombreA=n;
}

void Artista::getDiscos(vector<Album*>d,vector<Album*>::iterator i, string art){
	for(i=d.begin();i!=d.end(); i++){
			if(art==(*i)->getNombreArt()){
				cout<<(*i)->getNombreAl()<<endl;
			}
	}
}

string Artista::getArtista()const{
	return nombreA;
}

Artista::~Artista()
{
	//dtor
}

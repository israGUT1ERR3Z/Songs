#include "Album.h"
#include <string>
#include <vector>
#include <iostream>
#include "Cancion.h"
using namespace std;

Album::Album(vector<Cancion*>C, vector<Cancion*>::iterator t,string n, int aa,string art)
{
	tracklist=t;
	can=C;
	a=aa;
	nombre=n;
	artista=art;
}

int Album::getA(){
	return a;
}

void Album::getTracklist(vector<Cancion*>c, vector<Cancion*>::iterator t,string al){
	int cont=1;
	for(t=c.begin();t!=c.end(); t++){
			if(al==(*t)->getNombreAlbum()){
				cout<<cont<<". "<<(*t)->getNombreC()<<endl;
				cont++;
			}
	}
}

string Album::getNombreAl(){
	return nombre;
}

string Album::getNombreArt(){
	return artista;
}

Album::~Album()
{
	//dtor
}

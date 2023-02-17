#ifndef ARTISTA_H
#define ARTISTA_H
#include "Album.h"
#include <vector>
#include <string>
using namespace std;

class Artista
{
	public:
		Artista(vector<Album*>::iterator i, vector<Album*>d, string n);
		void getDiscos(vector<Album*>d,vector<Album*>::iterator i, string art);
		string getArtista()const;
		virtual ~Artista();

	protected:

	private:
		vector<Album*>discos;
		vector<Album*>::iterator iteD;
		string nombreA;
};

#endif // ARTISTA_H

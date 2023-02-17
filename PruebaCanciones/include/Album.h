#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include <vector>
#include "Cancion.h"
using namespace std;


class Album
{
	public:
		Album(vector<Cancion*>c, vector<Cancion*>::iterator t,string n, int aa,string art);
		int getA();
		void getTracklist(vector<Cancion*>c, vector<Cancion*>::iterator t,string al);
		string getNombreAl(),getNombreArt();
		virtual ~Album();

	protected:

	private:
		int a;
		vector<Cancion*>can;
		vector<Cancion*>::iterator tracklist;
		string nombre,artista;
};

#endif // ALBUM_H

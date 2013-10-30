/***************************************
 * graphStl.h
 *
 * Created on 19 de Julho de 2013, 11:51
 * 
 * @author Nuno Malheiro
 * rev1: g++ compatibility 23/10/2013
 ***************************************/

#ifndef _graphStlPath_
#define _graphStlPath_

#include <string.h> // memset include for g++
#include <stack>
#include <queue>
#include <bitset>
#include <type_traits>


using namespace std;

#include "graphStl.h"


template<class TV,class TE>
class graphStlPath : public graphStl <TV,TE>
{
protected:	
	void lengthFirstVisitRecursive(typename list < graphVertex <TV,TE> >::iterator itv, bitset <MAX_VERTICES> &taken, queue <TV> &q) const;
	void distinctPathsRecursive(typename list < graphVertex <TV,TE> >::iterator itvo,typename list < graphVertex <TV,TE> >::iterator itvd, bitset <MAX_VERTICES> &taken, stack <TV> &s,  queue < stack <TV> > &qr);

public:
	graphStlPath();

	queue <TV> lengthFirstVisit(const TV &vContent);
	queue <TV> breadthFirstVisit(const TV &vContent);
	queue < stack <TV> > distinctPaths(const TV &vOrigin,const TV &vDestination);	
	bool dijkstrasAlgorithm(const TV &vContent, vector <int> &pathKeys, vector <TE> &dist);
	queue <TV> getDijkstrasPath(int vKeyOrigin, vector <int> pathKeys);
};

template<class TV,class TE>
graphStlPath<TV,TE>::graphStlPath() : graphStl<TV,TE>()
{
}



#endif
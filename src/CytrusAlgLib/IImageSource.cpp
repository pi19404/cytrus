/* Carata Lucian, BSc Thesis Work
** Technical University of Iasi, 
** Faculty of Automatic Control and Computer Enigineering, 2009.
** 
** Author: Carata Lucian
** Project: Cytrus
** License notice:  GNU GPL
**
** -----------------------------------------------------------------
** IImageSource.cpp
**
*/
#include "stdafx.h"
#include "IImageSource.h"
using namespace cytrus::cameraHAL;

typedef std::set<IImageConsumer*> imageConsumerSet;

bool IImageSource::registerImageConsumer(IImageConsumer *c){
	std::pair<imageConsumerSet::iterator, bool> p=consumers.insert(c);
	return p.second;
}

bool IImageSource::removeImageConsumer(IImageConsumer *c){
	imageConsumerSet::const_iterator foundConsumer=consumers.find(c);
	if(foundConsumer!=consumers.end()){
		consumers.erase(foundConsumer);
		return true;
	}
	return false;
}
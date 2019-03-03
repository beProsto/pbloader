#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <SDL2/SDL.h>

#include "storage.hpp"

class SurfaceManager {
public:
	SurfaceManager() { }

	void Add(const std::string& key, SDL_Surface* surface) { surfaces.Add(key, surface); }
	void Remove(const std::string& key) { surfaces.Remove(key); }
	void Clear() { surfaces.Clear(); }
	int Size() { return surfaces.Size(); };
	SDL_Surface* Get(const std::string& key) { return surfaces.Get(key); }
private:
	res::Storage<SDL_Surface*> surfaces;
};

#endif
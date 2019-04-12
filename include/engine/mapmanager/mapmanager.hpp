#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

class MapManager {
private:
    int* location_x = (int*)0x00541118;
    int* location_y = (int*)0x00541114;

    int last_location_x;
    int last_location_y;
public:
    MapManager() { }
    ~MapManager() { }

    int GetLocationX() { return *location_x; }
    int GetlocationY() { return *location_y; }

    /* Update last_location_x and last_location_y */
    void Refresh();
};

#endif
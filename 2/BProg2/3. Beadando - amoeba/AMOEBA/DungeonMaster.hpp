#ifndef DUNGEONMASTER_HPP_INCLUDED
#define DUNGEONMASTER_HPP_INCLUDED

#include <vector>

using namespace std;

class DungeonMaster
{
protected:
    bool player;
    bool ingame;
    int round;
public:
    DungeonMaster();
    virtual void eventLoop();
    virtual void tick(int xx, int yy, vector<vector<Thingy*>> &dolgok);
    virtual void check(vector<vector<Thingy*>> &dolgok);
    virtual void sclear();
};

#endif // DUNGEONMASTER_HPP_INCLUDED

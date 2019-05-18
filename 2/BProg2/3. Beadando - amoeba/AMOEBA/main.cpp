#include "graphics.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "Thingy.hpp"
#include "DungeonMaster.hpp"
#include <vector>
using namespace genv;
using namespace std;


int main()
{
    DungeonMaster *ds = new DungeonMaster();
    ds->eventLoop();
    return 0;
}

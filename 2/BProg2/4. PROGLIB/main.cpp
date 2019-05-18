#include "graphics.hpp"
#include "Widget.hpp"
#include "SText.hpp"
#include "Nums.hpp"
#include "Checkbox.hpp"
#include "Menu.hpp"
#include "Input.hpp"
#include <vector>
using namespace genv;
using namespace std;


int main()
{

    gout.open(600, 600);
    Input *as1 = new Input(50, 50, 80, 30);
    event ev;
    while(gin >> ev)
    {
        as1->draw();
        as1->react(ev);
        gout << refresh;
    }

    return 0;
}

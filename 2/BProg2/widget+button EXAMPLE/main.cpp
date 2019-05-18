#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include <vector>

using namespace std;
using namespace genv;


///////////////////////////////////////////////////
class MyWindow : public Window {
public:
    StaticText *tx1;
    TextEditor *ed1;
    PushButton *button;
    MyWindow() {
        button = new PushButton(this, 10, 10, 60, 60,"=", "egyenlo");
        tx1 = new StaticText(75,20,100,40,"pipa");
        ed1 = new TextEditor(10,100,100,40,"editor");
        widgets.push_back(tx1);
        widgets.push_back(ed1);
        widgets.push_back(button);
    }
    void esemeny(string mitortent) {
        if (mitortent == "egyenlo") {
            tx1->setText(ed1->value());
        }
    }
};

int main()
{
    gout.open(400,400);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}

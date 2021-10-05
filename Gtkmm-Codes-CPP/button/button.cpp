#include<gtkmm-3.0/gtkmm/application.h>
#include "button.h"

int main()
{
    auto app = Gtk::Application::create("something");

    Buttons button ;

    return app->run(button) ;

}
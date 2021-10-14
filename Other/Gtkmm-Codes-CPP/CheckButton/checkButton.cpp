#include "checkButton.h"
#include <gtkmm-3.0/gtkmm/application.h>

int main()
{
    
    auto app = Gtk::Application::create();

    ExampleWindow window;

    return app->run(window);

}
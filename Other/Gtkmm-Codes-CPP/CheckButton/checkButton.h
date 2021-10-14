#include<gtkmm-3.0/gtkmm/window.h>
#include<gtkmm-3.0/gtkmm/checkbutton.h>
#include<gtkmm-3.0/gtkmm/togglebutton.h>
#include<iostream>

/*
    Toggle button and checkbutton acts the same way except the appearance
    both are having same function get_active() and set_active()
*/

class ExampleWindow : public Gtk::Window
{
    
    public:

    ExampleWindow();
    virtual ~ ExampleWindow();

    protected:
    
    // signal handlers
    void on_button_clicked();

    Gtk::CheckButton m_button;

};

ExampleWindow :: ExampleWindow() :m_button("something")
{
    
    set_title("check_button");
    
    set_border_width(10);

    m_button.signal_clicked().connect(sigc::mem_fun(*this,&ExampleWindow::on_button_clicked));

    add(m_button);

    show_all_children();

}

ExampleWindow :: ~ExampleWindow()
{

}

void ExampleWindow :: on_button_clicked()
{
    std::cout << "The button was clicked: state = " 
    << (m_button.get_active()?"true":"false")
    << std::endl;
}
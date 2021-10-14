#include<gtkmm-3.0/gtkmm/button.h>
#include<gtkmm-3.0/gtkmm/window.h>
#include<iostream>

class Buttons : public Gtk::Window
{
    public:

    Buttons();
    virtual ~Buttons();


    protected:

    // signal handlers
    void on_button_clicked();

    // child widgets 
    Gtk::Button m_button ;


};

Buttons::Buttons() : m_button("bsdk")
{
    
    set_border_width(10);

    m_button.signal_clicked().connect(sigc::mem_fun(*this,&Buttons::on_button_clicked));

    add(m_button);

    m_button.show();

}

Buttons::~Buttons()
{

}

void Buttons::on_button_clicked()
{
    std::cout << "Button is clicked" << std::endl ;
}
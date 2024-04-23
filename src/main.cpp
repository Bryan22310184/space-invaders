#include <iostream>
#include <string>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/screen/terminal.hpp>
#include <fstream>
#include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{

    Dibujo dTanque("./assents/images/canon.txt");
    Dibujo dAlien("./assents/images/alien.txt");
    Dibujo dBloque("./assents/images/canon.txt");

    int fotograma=0;

    while(true)
    {
        fotograma++;
        Element personaje=hbox({spinner(21,fotograma) | bold | color(Color::Blue1) | bgcolor(Color::Yellow1) });
        Element tanque= dTanque.GetElement() | bold  | color(Color::Green) | bgcolor(Color::Blue) });
        Element lienzo = hbox({personaje, tanque, dAlien.GetElement});

    
        Screen pantalla = Screen::Create(
            Dimension::Full(),
            Dimension::Fit(lienzo)
        );

    Render(pantalla,lienzo);
    pantalla.Print();
    cout<<pantalla.ResertPosition();
    
    this_thread::sleep_for(0.1s);

    return 0;
}
#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <thread>
using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    string prueba = "DVD";
    int posicionInicialX = 0;
    int posicionInicialY = 0;
    while (true)
    {
        posicionInicialY++;
        this_thread::sleep_for(0.1s);
        auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Fixed(10));
        Render(Pantalla, border(text("Hola")));
        Pantalla.PixelAt(5, 5).character = 'm';
       
        for (auto &&letra : prueba)
        {
            Pantalla.PixelAt(posicionX, posicionY).character = letra;
            posicionX++;
        }

        Pantalla.Print();
        cout<<Pantalla.ResetPosition();
    }

}
#include <iostream>
#include <string>
#include <vector>

// die verschiedenen Zustände des Getränkeautomaten
enum struct zustand {
    auswahl,
    bezhalen,
    ausgabe,
    wartung,
    ende
};

// die Datenstruktur eines Getränks
struct s_getraenk
{
    /* _name */
    /* _preis */
    /* _anzahl */
};


int main(int argc, char const *argv[])
{
    // Variable für den Zustand
    zustand state = zustand::auswahl;
    // Ein Vector um die Getränke abzuspeichern
    std::vector<s_getraenk> getraenke = {

    };

    std::cout << "Bitte ein Getränk auswählen:\n";

    while (true)
    {
        /* hier kommt der Zustandsautomat hin */
        switch (state)
        {
        case /* constant-expression */:
            /* code */
            break;

        default:
            break;
        }
    }

    return 0;
}

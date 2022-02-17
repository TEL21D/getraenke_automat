#include <iostream>
#include <string>
#include <vector>

// die verschiedenen Zustände des Getränkeautomaten
enum struct zustand {
    auswahl,
    bezahlen,
    ausgabe,
    wartung,
    ende
};

// die Datenstruktur eines Getränks
struct s_getraenk
{
    std::string _name;
    int _preis;
    int _anzahl;
};


int getraenkAuswaehlen(const std::vector<s_getraenk> &getraenke);
void getraenkBezahlen(const std::vector<s_getraenk> &getraenke);
void getraenkAusgeben();
void geldEinwerfen();

int main(int argc, char const *argv[])
{
    // Variable für den Zustand
    zustand state = zustand::auswahl;
    // Ein Vector um die Getränke abzuspeichern
    std::vector<s_getraenk> getraenke = {
        {"Cola", 250, 4},
        {"Coke Zero", 200, 4},
        {"Fanta", 250, 0},
        {"Wasser", 100, 10}
    };

    int auswahl = 0;

    while (state != zustand::ende)
    {
        /* hier kommt der Zustandsautomat hin */
        switch (state)
        {
        case zustand::auswahl:
            auswahl = getraenkAuswaehlen(getraenke);
            state = zustand::bezahlen;
            break;
        case zustand::bezahlen:
            //getreank
            break;
        case zustand::ausgabe:
            /* code */
            break;
        case zustand::wartung:
            /* code */
            break;
        case zustand::ende:
            std::cout << "\nGetränkeautomat fährt herunter\n";
            break;

        default:
            break;
        }
    }

    return EXIT_FAILURE;
}

int getraenkAuswaehlen(const std::vector<s_getraenk> &getraenke) {
    int in;
    while (true)
    {
        std::cout << "\n Bitte wählen Sie ein Getränk aus:\n";
        for (size_t i = 0; i < getraenke.size(); i++)
        {
            std::cout << " " << i+1 << ": " << getraenke[i]._name << " Preis: " << getraenke[i]._preis << "\n";
        }
        std::cin >> in;

        if (getraenke[in-1]._anzahl >= 1)
        {
            return in-1;
        }
        else {
            std::cout << "Das Getränk ist gerade nicht verfügbar. Treffen Sie bitte eine andere Auswahl!\n";
        }
    }
}

void getraenkBezahlen(const std::vector<s_getraenk> &getraenke);
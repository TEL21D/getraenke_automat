#include <iostream>
#include <string>
#include <vector>
#include <map>

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

    void print() {
        std::cout << "Getreank: " << _name << "\nPreis: " << _preis  << std::endl;
    }
};


void getreankAuswahlen();
void getraenkAusgeben();
void geldEinwerfen();

int main(int argc, char const *argv[])
{
    // Variable für den Zustand
    zustand state = zustand::auswahl;
    // Ein Vector um die Getränke abzuspeichern

    std::map<std::string, s_getraenk> m_getraenke = {
        {"Cola", {"Cola", 250, 4}},
        {"Wasser", {"Cola", 100, 10}}
    };

    std::cout << "Bitte ein Getränk auswählen:\n";
    if(m_getraenke.find("Cola") != m_getraenke.end()) {
        m_getraenke["Cola"].print();
    }
    m_getraenke["Wasser"].print();
    if(m_getraenke.find("Fanta") != m_getraenke.end()) {
        m_getraenke["Fanta"].print();
    }
    else {
        std::cout << "Es gibt keine Fanta!\n";
    }


    while (true)
    {
        /* hier kommt der Zustandsautomat hin */
        switch (state)
        {
        case zustand::auswahl:
            /* code */
            break;
        case zustand::bezahlen:
            /* code */
            break;
        case zustand::ausgabe:
            /* code */
            break;
        case zustand::wartung:
            /* code */
            break;
        case zustand::ende:
            /* code */
            break;

        default:
            break;
        }
    }

    return 0;
}

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
void getraenkBezahlen(const std::vector<s_getraenk> &getraenke, int auswahl);
void getraenkAusgeben(const std::vector<s_getraenk> &getraenke);
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
            getraenkBezahlen(getraenke, auswahl);
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
    return 0;
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

void getraenkBezahlen(const std::vector<s_getraenk> &getraenke, int auswahl) {
    int betrag = getraenke[auswahl]._preis;
    int input = 0;
    std::cout <<  "Bitte werfen Sie " << betrag << " Cent in den Automaten ein\n";

    std::cout <<  "1. 100 Cent\n";
    std::cout <<  "2. 200 Cent\n";
    std::cout <<  "3. 50 Cent\n";
    std::cout <<  "10. Zurück zur Getränkeauswahl\n";
    while (betrag > 0) {
        switch (input)
        {
        case 1:
            betrag -= 100;
            break;
        case 2:
            betrag -= 200;
            break;
        case 3:
            betrag -= 50;
            break;
        default:
            break;
        }
        std::cout <<  "Es fehlen noch " << betrag << " Cent\n";
    }
    // Auf Rückgeld prüfen
    if(betrag < 0) {
        std::cout <<  " Rückgeld: " << abs(betrag) << " Cent\n";
    }
}
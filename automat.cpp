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


int getraenkAuswaehlen(const std::vector<s_getraenk> &getraenke, zustand &status);
bool getraenkBezahlen(const std::vector<s_getraenk> &getraenke, int auswahl);
void getraenkAusgeben(const std::vector<s_getraenk> &getraenke);
void wartungsModus(zustand &status, const std::vector<s_getraenk> &getraenke);

int main(int argc, char const *argv[])
{
    // Variable für den Zustand
    zustand state = zustand::auswahl;
    // Ein Vector um die Getränke abzuspeichern

    std::vector<s_getraenk> getraenke = {
        {"Cola", 250, 4},
        {"Coke Zero", 200, 1},
        {"Fanta", 250,  0},
        {"Wasser", 100, 10}
    };

    int auswahl = 0;

    while (state != zustand::ende)
    {
        /* hier kommt der Zustandsautomat hin */
        switch (state)
        {
        case zustand::auswahl:
            auswahl = getraenkAuswaehlen(getraenke, state);
            if (auswahl >= 0)
                state = zustand::bezahlen;
            break;
        case zustand::bezahlen:
            getraenkBezahlen(getraenke, auswahl) ? state = zustand::ausgabe : state = zustand::auswahl;
            break;
        case zustand::ausgabe:
            getraenke[auswahl]._anzahl--;
            std::cout <<  "Getränk wird ausgegeben, bitte entnehmen!\n";

            state = zustand::auswahl;
            break;
        case zustand::wartung:
            wartungsModus(state, getraenke);
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

int getraenkAuswaehlen(const std::vector<s_getraenk> &getraenke, zustand &status) {
    int in;
    while (true)
    {
        std::cout << "\n Bitte wählen Sie ein Getränk aus:\n";
        for (size_t i = 0; i < getraenke.size(); i++)
        {
            std::cout << " " << i+1 << ": " << getraenke[i]._name << " Preis: " << getraenke[i]._preis << "\n";
        }
        std::cout << "\n " << "10: " << "Beenden\n";
        std::cout << "\n " << "999: " << "Warungsmodus\n";

        std::cin >> in;
        if (in == 999)
        {
            status = zustand::wartung;
            return -1;
        }
        if (in == 10)
        {
            status = zustand::ende;
            return -1;
        }

        if (getraenke[in-1]._anzahl >= 1)
        {
            return in-1;
        }
        else {
            std::cout << "Das Getränk ist gerade nicht verfügbar. Treffen Sie bitte eine andere Auswahl!\n";
        }
    }
}

bool getraenkBezahlen(const std::vector<s_getraenk> &getraenke, int auswahl) {
    int betrag = getraenke[auswahl]._preis;
    int input = 0;
    std::cout <<  "Bitte werfen Sie " << betrag << " Cent in den Automaten ein\n";

    std::cout <<  "1. 100 Cent\n";
    std::cout <<  "2. 200 Cent\n";
    std::cout <<  "3. 50 Cent\n";
    std::cout <<  "10. Zurück zur Getränkeauswahl\n";
    while (betrag > 0) {
        std::cout <<  "\n\tEs fehlen noch " << betrag << " Cent\n";
        std::cin >> input;
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
        case 10:
            /* Zurück zur Getränkeauswahl */
            return false;
            break;
        default:
            break;
        }
    }
    // Auf Rückgeld prüfen
    if(betrag < 0) {
        std::cout <<  "\n\tRückgeld: " << abs(betrag) << " Cent\n";
    }
    return true;
}


void wartungsModus(zustand &status, const std::vector<s_getraenk> &getraenke) {
  int eingabe;
  std::cout << "Willkommen im Wartungsmodus\n1: Getränke auflisten\n10: Zurück\n";
  std::cin >> eingabe;
  if(eingabe == 1) {
      for (auto el: getraenke)
      {
          std::cout << " - " << el._name << ": " <<  " Anzahl: "  << el._anzahl<< " Preis: " << el._preis << "\n";
      }
  }
  if(eingabe == 10) status = zustand::auswahl;
}
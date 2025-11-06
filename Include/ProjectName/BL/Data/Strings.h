#pragma once
#include <iostream>
#include <string>

namespace Messerli::Data
{
struct Strings
{
    static inline const std::string greeting = "Hello There!\n";
    static inline const auto line = std::string(40, '-');
    static inline const auto wiggLine = std::string(40, '~');
};

inline std::ostream& operator<<(std::ostream& os, const Strings&)
{
    os << Strings::greeting << Strings::line;
    return os;
}

namespace printOutput
{
inline const std::string yesOut = "Ja";
inline const std::string noOut = "Nein";
inline const std::string inventoryNumber = "Inventarnummer: ";

inline const std::string horsePower = "Ps: ";
inline const std::string brandName = "Hersteller: ";
inline const std::string modelName = "Modell: ";
inline const std::string carType = "Fahrzeugtyp: ";
inline const std::string yearOfProduction = "Baujahr: ";
inline const std::string colorName = "Farbe: ";
inline const std::string priceValue = "Preis: ";
inline const std::string kilometerValue = "Kilometerstand: ";
inline const std::string roofWindow = "Schiebedach: ";
inline const std::string airCondition = "Klimaanlage: ";
inline const std::string navigationSystem = "Navigationssystem: ";
inline const std::string parkingSensors = "Einparkhilfe: ";
inline const std::string parkingAssist = "Parkassistent: ";
inline const std::string convertible = "Cabrio: ";
inline const std::string CarParkPrintHeader = "\n ===== = Aktueller Fuhrpark = =====\n ";
inline const std::string CarParkPrintHeaderPkw = "\n ===== = Aktueller Pkw-Fuhrpark = =====\n ";
inline const std::string CarParkPrintHeaderLkw = "\n ===== = Aktueller Lkw-Fuhrpark = =====\n ";
inline const std::string Lkw = "Lastwagen";
inline const std::string Pkw = "Auto";
inline const std::string of = "- davon: ";
inline const std::string TypesInLot = "Anzahl Fahrzeuge im Fuhrpark: ";

inline const std::string amountAxels = "Anzahl Achsen: ";
inline const std::string loadCapacity = "Ladevolumen (in Tonnen): ";

}

namespace UI
{
inline constexpr auto edgeLeft = '+';
inline constexpr auto edgeRight = '+';
inline constexpr auto edgeTop = '-';
inline constexpr auto edgeBottom = '-';
inline constexpr auto edgeSeparator = '|';

}

namespace Menu
{
constexpr auto mainMenuTitle = "* * * Verwaltung des StadtAuto-Fuhrparks * * *";
constexpr auto mainMenuNewPkw = "1. Neuen Pkw hinzufuegen";
constexpr auto mainMenuNewLkw = "2. Neuen Lkw hinzufuegen";
constexpr auto mainMenuPrintAll = "3. Alle Fahrzeuge anzeigen";
constexpr auto mainMenuPrintPkw = "4. Alle Pkw anzeigen";
constexpr auto mainMenuPrintLkw = "5. Alle Lkw anzeigen";
constexpr auto mainMenuExit = "6. Programm beenden";

constexpr auto navigationHelperEnter = "⏎ = Auswahl bestaetigen";
constexpr auto navigationHelperUpDown = "↑↓ = Hoch/Runter";
constexpr auto navigationHelperBack = "B = Zurueck zum Hauptmenue";
constexpr auto navigationHelperEsc = "Q = Programm beenden";
constexpr auto navigateContinue = "Drücken Sie Eingabe um Fortzufahren"; 
}

namespace Menu::Add
{
constexpr auto AddKfzSuccess = " >> Fahrzeug erfolgreich hinzugefügt<<";
constexpr auto AddPkwTitle = " >> Neuen PKW hinzufügen << ";
constexpr auto AddLkwTitle = " >> Neuen Lkw hinzufügen <<";

}

}

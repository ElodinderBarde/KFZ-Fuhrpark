# KFZ-Fuhrpark



## 🧭 **Gesamtziel**

Das Programm ist eine **Konsolenanwendung zur Verwaltung eines Fahrzeug-Fuhrparks („StadtAuto“)**  
in der Namespace-Struktur `Messerli::UI`, `Messerli::Tools` und `Messerli::Data`.

Es verwendet:

- dynamische Arrays für PKW, LKW und alle Fahrzeuge
    
- ein menügesteuertes UI mit Zeichnung (ASCII-Boxen)
    
- Klassenhierarchie: `Kfz` → `Pkw`, `Lkw`
    
- ein Daten-Setup (`StadtAuto`), um initiale Fahrzeuge zu erstellen
    

---

## 🧩 **Klassenstruktur (Kurzüberblick)**

| Klasse             | Zweck                                                                                   |
| :----------------- | :-------------------------------------------------------------------------------------- |
| **`Kfz`**          | Basisklasse für alle Fahrzeuge (Nummer, Hersteller, Anzeige)                            |
| **`Pkw` / `Lkw`**  | Spezialisierte Fahrzeuge mit Zusatzattributen (z. B. Dach, Achsen, Modell)              |
| **`StadtAuto`**    | Containerklasse, die Fahrzeuge erzeugt und speichert                                    |
| **`ArrayManager`** | Verwaltung und Ausgabe der globalen dynamischen Arrays                                  |
| **`Function`**     | Allgemeine Utility-Funktionen (UTF-8, Statistik, Eingabeumwandlung, Nummerngenerierung) |
| **`Draw`**         | Low-Level-Konsolenfunktionen (Positionierung, Boxen, ClearScreen)                       |
| **`DrawManager`**  | Hauptmenü-Steuerung und -Zeichnung                                                      |
| **`ContentArea`**  | Verwaltung des rechten Anzeige-/Eingabebereichs                                         |
| **`MenuActions`**  | Steuerlogik der Menüpunkte (Fahrzeug hinzufügen, anzeigen, beenden)                     |

---

## ⚙️ **Ablauf beim Programmstart**

### 1. Initialisierung (`Function::InitializeApp`)

- Setzt **Konsole auf UTF-8**.
    
- Erstellt **dynamische Arrays** für alle, PKW und LKW.
    
- Startet das Hauptmenü über `UI::DrawManager::DrawMenu()`.
    

---

## 🧱 **Menüanzeige (`DrawManager::DrawMenu`)**

Das Hauptmenü zeigt:

```
+---------------------------------------------+
| Verwaltung des StadtAuto-Fuhrparks          |
+---------------------------------------------+
| 1. Neuen Pkw hinzufügen                     |
| 2. Neuen Lkw hinzufügen                     |
| 3. Alle Fahrzeuge anzeigen                  |
| 4. Alle Pkw anzeigen                        |
| 5. Alle Lkw anzeigen                        |
| 6. Programm beenden                         |
+---------------------------------------------+
```

- Navigation per **Pfeiltasten ↑ / ↓**
    
- Auswahl per **Enter**
    
- Beenden per **ESC oder Q**
    

Bei Enter wird je nach Auswahl:

- `MenuActions::AddPkw()`
    
- `MenuActions::AddLkw()`
    
- `MenuActions::ShowAll()`
    
- `MenuActions::ShowPkw()`
    
- `MenuActions::ShowLkw()`
    
- oder **Programmende** aufgerufen.
    

---

## 🧰 **MenuActions: Aktionen des Menüs**

### **AddPkw()**

- Öffnet Eingabeboxen für:
    
    - Hersteller
        
    - Modell
        
    - Schiebedach (Y/N)
        
- Generiert Inventarnummer über `Function::GenerateInventoryNumber(Pkw)`
    
- Erstellt ein neues `Pkw`-Objekt → automatisch in `arrayPkw` eingetragen.
    
- Zeigt Bestätigung an.
    

### **AddLkw()**

- Eingabe von:
    
    - Hersteller
        
    - Modell
        
    - Achsenanzahl
        
    - Ladevolumen
        
- Generiert Inventarnummer → neues `Lkw`-Objekt → in `arrayLkw`.
    

### **ShowAll() / ShowPkw() / ShowLkw()**

- Zeigt paginierte Listen (mehrseitig) der Fahrzeuge in der rechten ContentArea.
    
- Navigation mit ← / → (Seitenwechsel), B zum Zurückkehren.
    

---

## 🖥️ **ContentArea**

- Verwaltet den Anzeigebereich rechts im UI.
    
- Funktionen:
    
    - `Clear()` – löscht Inhalt
        
    - `PrintLine()` – Text an Position
        
    - `PrintCentered()` – zentrierte Titel
        
    - `DrawInputBox()` – Eingabeaufforderung mit Rahmen
        
    - `ShowPagedList()` – zeigt Listen mit Seitensteuerung
        
- Nutzt `ArrayManager` und ruft `DisplayAt()` für jedes Objekt auf.
    

---

## 🧮 **ArrayManager**

- Erstellt, prüft und löscht dynamische Arrays.
    
- Hat globale Arrays in `Data::Fuhrpark::Fuhrpark`:
    
    ```cpp
    static inline Types::Kfz** array;
    static inline Types::Pkw** arrayPkw;
    static inline Types::Lkw** arrayLkw;
    ```
    
- Methoden:
    
    - `CreateDynamicArray*()` → alloziert Arrays falls nötig
        
    - `InsertVehicle()` → trägt Objekt ein
        
    - `ArrayPrint()` → gibt Liste mit Statistik aus
        
    - `ArrayPrintAll()` → zeigt alle Arrays farbig
        
    - `DeleteArray()` → räumt Speicher auf
        

---

## 🚗 **Fahrzeugklassen**

### **Kfz**

Basisklasse mit:

- `m_Nr`, `m_Hersteller`
    
- Konstruktor trägt Objekt automatisch ins Hauptarray ein
    
- `Display()` → Ausgabe in Konsole
    
- `DisplayAt(x, y)` → zeichnungsbasierte Ausgabe
    

### **Pkw**

- Felder: `m_PkwTyp`, `m_roofWindow`
    
- Konstruktor trägt Objekt ins `arrayPkw` ein
    
- `DisplayAt()` ergänzt Dach- und Modellinformationen
    

### **Lkw**

- Felder: `m_Axles`, `m_LoadCapacity`, `m_model`
    
- Konstruktor trägt Objekt ins `arrayLkw` ein
    
- `DisplayAt()` gibt Achsen, Modell und Ladevolumen aus
    

---

## 🏙️ **StadtAuto**

- Enthält statisches Limit `Max = 100`
    
- Array `m_vec[Max]` von `Kfz*`
    
- Methoden:
    
    - `Insert(...)` → erstellt Fahrzeuge (Pkw/Lkw)
        
    - `Display()` → ruft für jedes Objekt `Display()` auf
        
- Wird in `Data::Objects::CreateCarpark()` genutzt, um **Initialdaten zu befüllen**.
    

---

## 🧾 **Data & Strings**

### `DataConfig.h`

- Enthält alle globalen Arrays und Zähler.
    
- `Enum::KfzType` unterscheidet `Lkw`, `Pkw`, `All`.
    
- `Objects::CreateCarpark()` erzeugt über 100 vordefinierte Fahrzeuge.
    

### `Strings.h`

- Enthält alle Textkonstanten für UI, Labels und Menü.
    
- Trennung in Unterbereiche: `printOutput`, `UI`, `Menu`, `Menu::Add`.
    

---

## 🔄 **Programmfluss – Gesamt**

```text
main()
  ↓
Function::InitializeApp()
  ↓
UTF-8-Konfiguration
  ↓
ArrayManager::CreateDynamicArray*()
  ↓
DrawManager::DrawMenu()
  ↓
  Benutzer wählt Aktion
     ↓
     MenuActions::AddPkw / AddLkw / ShowAll / ...
        ↓
        ContentArea verwaltet Anzeige & Eingabe
        ↓
        Neue Objekte erzeugen (Pkw/Lkw)
        ↓
        Speicherung in globalen Arrays
        ↓
        Ausgabe oder Navigation zurück ins Menü
```

---

## 🧠 **Wesentliche Konzepte**

- **Polymorphie:** `Display()`/`DisplayAt()` werden virtuell aufgerufen.
    
- **Globale Zustände:** Fuhrpark-Daten werden zentral in `Data::Fuhrpark::Fuhrpark` gehalten.
    
- **UI-Architektur:** klare Trennung von Anzeige (`Draw`, `ContentArea`), Logik (`MenuActions`) und Daten (`ArrayManager`).
    
- **Portabilität:** Windows-spezifische Teile (z. B. Cursorposition) sind durch ANSI-Alternativen ergänzt.
    


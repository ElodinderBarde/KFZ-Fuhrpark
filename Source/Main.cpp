#include "Tools/Function.h"

#include "Data/DataConfig.h"
#include "Tools/ArrayManager.h"
#include "Types/Kfz.h"
#include "Types/Lkw.h"
#include "Types/Pkw.h"
#include "Types/StadtAuto.h"

int main()
{
    namespace Tools = Messerli::Tools;

    Messerli::Types::StadtAuto fuhrpark;
    fuhrpark.Insert("Focus", true, 10001, "Ford");
    fuhrpark.Insert(3, 18.0, 20001, "MAN", "TGX");
    fuhrpark.Insert("Golf", false, 10003, "Volkswagen");
    fuhrpark.Insert("Testa Rossa", false, 10003, "Ferrari");
    fuhrpark.Insert(5, 18.5, 20002, "Mercedes", "Arocs");
    fuhrpark.Insert(2, 10, 20003, "Mercedes", "Lo 2000");
    fuhrpark.Insert(3, 12.5, 20004, "Saurer", "D 330 N");
    fuhrpark.Insert("Civic", true, 10004, "Honda");
    fuhrpark.Insert("Accord", false, 10005, "Honda");
    fuhrpark.Insert("Model S", true, 10006, "Tesla");
    fuhrpark.Insert("Model 3", true, 10007, "Tesla");
    fuhrpark.Insert("Model Y", false, 10008, "Tesla");
    fuhrpark.Insert("Passat", true, 10009, "Volkswagen");
    fuhrpark.Insert("Polo", false, 10010, "Volkswagen");
    fuhrpark.Insert("A3", false, 10011, "Audi");
    fuhrpark.Insert("A4", true, 10012, "Audi");
    fuhrpark.Insert("A6", true, 10013, "Audi");
    fuhrpark.Insert("C-Klasse", true, 10014, "Mercedes");
    fuhrpark.Insert("E-Klasse", true, 10015, "Mercedes");
    fuhrpark.Insert("S-Klasse", false, 10016, "Mercedes");
    fuhrpark.Insert("M3", false, 10017, "BMW");
    fuhrpark.Insert("M5", true, 10018, "BMW");
    fuhrpark.Insert("X5", true, 10019, "BMW");
    fuhrpark.Insert("Corolla", false, 10020, "Toyota");
    fuhrpark.Insert("Yaris", false, 10021, "Toyota");
    fuhrpark.Insert("Supra", true, 10022, "Toyota");
    fuhrpark.Insert("Impreza", true, 10023, "Subaru");
    fuhrpark.Insert("Forester", false, 10024, "Subaru");
    fuhrpark.Insert("Mazda3", false, 10025, "Mazda");
    fuhrpark.Insert("CX-5", true, 10026, "Mazda");
    fuhrpark.Insert("Mustang", true, 10027, "Ford");
    fuhrpark.Insert("Fiesta", false, 10028, "Ford");
    fuhrpark.Insert("Focus RS", true, 10029, "Ford");
    fuhrpark.Insert("500", false, 10030, "Fiat");
    fuhrpark.Insert("Panda", false, 10031, "Fiat");
    fuhrpark.Insert("Giulia", true, 10032, "Alfa Romeo");
    fuhrpark.Insert("Stelvio", true, 10033, "Alfa Romeo");
    fuhrpark.Insert("Octavia", false, 10034, "Skoda");
    fuhrpark.Insert("Superb", true, 10035, "Skoda");
    fuhrpark.Insert("Fabia", false, 10036, "Skoda");
    fuhrpark.Insert("308", false, 10037, "Peugeot");
    fuhrpark.Insert("508", true, 10038, "Peugeot");
    fuhrpark.Insert("208", false, 10039, "Peugeot");
    fuhrpark.Insert("Clio", false, 10040, "Renault");
    fuhrpark.Insert("Megane", true, 10041, "Renault");
    fuhrpark.Insert("Talisman", true, 10042, "Renault");
    fuhrpark.Insert("Leon", true, 10043, "Seat");
    fuhrpark.Insert("Ibiza", false, 10044, "Seat");
    fuhrpark.Insert("Tarraco", true, 10045, "Seat");
    fuhrpark.Insert("Corsa", false, 10046, "Opel");
    fuhrpark.Insert("Astra", true, 10047, "Opel");
    fuhrpark.Insert("Insignia", true, 10048, "Opel");
    fuhrpark.Insert("CX-3", false, 10049, "Mazda");
    fuhrpark.Insert("CX-9", true, 10050, "Mazda");
    fuhrpark.Insert("Cherokee", true, 10051, "Jeep");
    fuhrpark.Insert("Wrangler", true, 10052, "Jeep");
    fuhrpark.Insert("Compass", false, 10053, "Jeep");
    fuhrpark.Insert("Civic Type R", true, 10054, "Honda");
    fuhrpark.Insert("Accord Hybrid", false, 10055, "Honda");
    fuhrpark.Insert(3, 19.0, 20005, "Volvo", "FH16");
    fuhrpark.Insert(3, 17.5, 20006, "DAF", "XF 530");
    fuhrpark.Insert(2, 12.0, 20007, "Iveco", "Stralis");
    fuhrpark.Insert(4, 25.0, 20008, "Scania", "R500");
    fuhrpark.Insert(5, 30.0, 20009, "MAN", "TGS");
    fuhrpark.Insert(3, 16.5, 20010, "Mercedes", "Actros");
    fuhrpark.Insert(2, 8.0, 20011, "Renault", "T460");
    fuhrpark.Insert(4, 22.0, 20012, "Volvo", "FMX");
    fuhrpark.Insert(3, 18.2, 20013, "DAF", "CF 450");
    fuhrpark.Insert(3, 20.0, 20014, "Iveco", "EuroCargo");
    fuhrpark.Insert(2, 10.5, 20015, "MAN", "TGM");
    fuhrpark.Insert(5, 28.5, 20016, "Scania", "S730");
    fuhrpark.Insert(4, 24.0, 20017, "Mercedes", "Atego");
    fuhrpark.Insert(3, 15.0, 20018, "Renault", "C480");
    fuhrpark.Insert(3, 18.3, 20019, "Volvo", "FM12");
    fuhrpark.Insert(2, 9.5, 20020, "Iveco", "EuroStar");
    fuhrpark.Insert(3, 19.8, 20021, "MAN", "TGX 26");
    fuhrpark.Insert(5, 30.5, 20022, "Scania", "R730");
    fuhrpark.Insert(4, 21.0, 20023, "Mercedes", "Antos");
    fuhrpark.Insert(3, 17.2, 20024, "DAF", "LF 320");
    fuhrpark.Insert(3, 14.0, 20025, "Volvo", "FE 350");
    fuhrpark.Insert(3, 19.0, 20026, "Saurer", "D 310");
    fuhrpark.Insert(4, 26.0, 20027, "MAN", "TGX 33");
    fuhrpark.Insert(2, 8.5, 20028, "Iveco", "Daily 70C");
    fuhrpark.Insert(3, 15.5, 20029, "Mercedes", "Econic");
    fuhrpark.Insert(4, 23.0, 20030, "Renault", "Range D");
    fuhrpark.Insert(3, 20.5, 20031, "Scania", "P410");
    fuhrpark.Insert(5, 27.0, 20032, "DAF", "XF 105");
    fuhrpark.Insert(2, 7.5, 20033, "Volvo", "FL 240");
    fuhrpark.Insert(3, 18.8, 20034, "Iveco", "Trakker");
    fuhrpark.Insert(3, 17.3, 20035, "MAN", "TGS 24");
    fuhrpark.Insert(4, 25.4, 20036, "Mercedes", "Actros 2545");

    fuhrpark.Insert("Fiesta", true, 654987, "Ford");
    Tools::Function::InitializeApp();
    return 0;
}

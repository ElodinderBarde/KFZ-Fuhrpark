#include "../UI/draw/tools/MenuActions.h"

#include "../UI/draw/Draw.h"
#include "../UI/draw/Manager/ContentArea.h"
#include "../UI/draw/Manager/DrawManager.h"
#include "Data/DataConfig.h"
#include "Data/Strings.h"
#include "Tools/ArrayManager.h"
#include "Tools/Function.h"
#include "Types/Kfz.h"
#include "Types/Pkw.h"

#include <iostream>

namespace Messerli::UI {
bool Tools::Menu::MenuActions::MenuSwitch(int currentSelection, bool& running)
{
    DrawManager::ClearArea(35, 5, 58, 28);
    Draw::GoTo(37, 8);
    switch (currentSelection) {
        case 0: AddPkw();
            break;
        case 1: AddLkw();
            break;
        case 2: ShowAll();
            break;
        case 3: ShowPkw();
            break;
        case 4: ShowLkw();
            break;
        case 5: running = false;
            break;
        default: break;
    }
    return true;
}

void Tools::Menu::MenuActions::AddPkw()
{
    ContentArea content(35, 5, 58, 28);

    content . Clear();
    bool schiebe{};

    content . PrintCentered(0, Data::Menu::Add::AddPkwTitle);
    std::string hersteller = ContentArea::DrawInputBox(Data::printOutput::brandName);

    content . PrintLine(3, Data::printOutput::brandName + hersteller);
    std::string type = ContentArea::DrawInputBox(Data::printOutput::modelName);

    content . PrintLine(4, Data::printOutput::modelName + type);

    std::string roofOption = content . DrawInputBox(Data::printOutput::roofWindow + " Y/N");
    if (roofOption == "Y" || roofOption == "y") {
        roofOption = "Verfügbar";
        schiebe = true;
    } else {
        roofOption = "Nicht verfügbar";
        schiebe = false;
    }
    int invNumer = Messerli::Tools::Function::GenerateInventoryNumber(Data::Fuhrpark::Enum::KfzType::Pkw);

    content . PrintLine(5, Data::printOutput::roofWindow + roofOption);

    auto* pkw = new Types::Pkw(type, schiebe, invNumer, hersteller);

    content . PrintLine(7, Data::printOutput::inventoryNumber + std::to_string(invNumer));
    content . PrintLine(25, Data::Menu::Add::AddKfzSuccess);
    content . PrintLine(26, Data::Menu::navigateContinue);

    std::cin . get();
    content . Clear();
}

void Tools::Menu::MenuActions::AddLkw()
{
    ContentArea content(35, 5, 58, 28);

    Draw::GoTo(37, 5);
    content . Clear();

    content . PrintCentered(0, Data::Menu::Add::AddLkwTitle);
    std::string hersteller = ContentArea::DrawInputBox(Data::printOutput::brandName);
    content . PrintLine(3, Data::printOutput::brandName + hersteller);
    std::string model = ContentArea::DrawInputBox(Data::printOutput::modelName);
    content . PrintLine(4, Data::printOutput::modelName + model);
    std::string axels = ContentArea::DrawInputBox(Data::printOutput::amountAxels);
    content . PrintLine(5, Data::printOutput::amountAxels + axels);
    std::string load = ContentArea::DrawInputBox(Data::printOutput::loadCapacity);
    content . PrintLine(6, Data::printOutput::loadCapacity + load);

    auto axelCount = Messerli::Tools::Function::ToIntSafe(axels);
    auto loadCap = Messerli::Tools::Function::ToDoubleSafe(load);
    int invNumer = Messerli::Tools::Function::GenerateInventoryNumber(Data::Fuhrpark::Enum::KfzType::Lkw);

    auto* lkw = new Types::Lkw(axelCount, loadCap, invNumer, hersteller, model);

    content . PrintLine(7, Data::printOutput::inventoryNumber + std::to_string(invNumer));
    content . PrintLine(25, Data::Menu::Add::AddKfzSuccess);
    content . PrintLine(26, Data::Menu::navigateContinue);

    std::cin . ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin . get();
    content . Clear();
}

void Tools::Menu::MenuActions::ShowAll()
{
    ContentArea content(35, 5, 58, 28);
    Draw::GoTo(37, 5);
    content . ShowPagedList(Data::Fuhrpark::Enum::All);
    std::cin . get();
}

void Tools::Menu::MenuActions::ShowPkw()
{
    ContentArea content(35, 5, 58, 28);
    Draw::GoTo(37, 5);
    std::cout << ">> Nur PKW anzeigen\n";
    content . ShowPagedList(Data::Fuhrpark::Enum::KfzType::Pkw);
    std::cin . get();
}

void Tools::Menu::MenuActions::ShowLkw()
{
    ContentArea content(35, 5, 58, 28);
    Draw::GoTo(37, 5);
    std::cout << ">> Nur LKW anzeigen\n";

    content . ShowPagedList(Data::Fuhrpark::Enum::KfzType::Lkw);
    std::cin . get();
}
}
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

struct Pipe {
    std::string name;
    double length;
    int diameter;
    bool underRepair;
};

struct CompressorStation {
    std::string name;
    int totalWorkshops;
    int workingWorkshops;
    int stationClass;
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void inputPipe(Pipe& pipe) {
    std::cout << "Vvedite nazvanie truby: ";
    std::getline(std::cin, pipe.name);
    
    std::cout << "Vvedite dlinu truby (km): ";
    while (!(std::cin >> pipe.length) || pipe.length <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe chislo dlya dliny: ";
        clearInputBuffer();
    }
    
    std::cout << "Vvedite diametr truby (mm): ";
    while (!(std::cin >> pipe.diameter) || pipe.diameter <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe chislo dlya diametra: ";
        clearInputBuffer();
    }
    
    pipe.underRepair = false;
    clearInputBuffer();
}

void inputCompressorStation(CompressorStation& cs) {
    std::cout << "Vvedite nazvanie kompressornoj stancii: ";
    clearInputBuffer();
    std::getline(std::cin, cs.name);
    
    std::cout << "Vvedite obshhee kolichestvo cehov: ";
    while (!(std::cin >> cs.totalWorkshops) || cs.totalWorkshops <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe celoe chislo: ";
        clearInputBuffer();
    }
    
    std::cout << "Vvedite kolichestvo rabotayushhih cehov: ";
    while (!(std::cin >> cs.workingWorkshops) || cs.workingWorkshops < 0 || cs.workingWorkshops > cs.totalWorkshops) {
        std::cout << "Nevernyj vvod. Vvedite chislo ot 0 do " << cs.totalWorkshops << ": ";
        clearInputBuffer();
    }
    
    std::cout << "Vvedite klass stancii: ";
    while (!(std::cin >> cs.stationClass) || cs.stationClass <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe celoe chislo: ";
        clearInputBuffer();
    }
    clearInputBuffer();
}

void displayPipe(const Pipe& pipe) {
    std::cout << "Truba: " << pipe.name 
              << ", Dlina: " << pipe.length << " km"
              << ", Diametr: " << pipe.diameter << " mm"
              << ", V remonte: " << (pipe.underRepair ? "Da" : "Net") << std::endl;
}

void displayCompressorStation(const CompressorStation& cs) {
    std::cout << "Kompressornaja stancija: " << cs.name
              << ", Ceha: " << cs.workingWorkshops << "/" << cs.totalWorkshops
              << ", Klass: " << cs.stationClass << std::endl;
}

void togglePipeRepair(Pipe& pipe) {
    pipe.underRepair = !pipe.underRepair;
    std::cout << "Status remonta truby izmenen na: " << (pipe.underRepair ? "V remonte" : "Rabochaja") << std::endl;
}

void editPipeName(Pipe& pipe) {
    std::cout << "Tekushee nazvanie truby: " << pipe.name << std::endl;
    std::cout << "Vvedite novoe nazvanie: ";
    std::getline(std::cin, pipe.name);
    std::cout << "Nazvanie obnovleno!" << std::endl;
}

void editPipeLength(Pipe& pipe) {
    std::cout << "Tekushaya dlina truby: " << pipe.length << " km" << std::endl;
    std::cout << "Vvedite novuyu dlinu (km): ";
    while (!(std::cin >> pipe.length) || pipe.length <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe chislo: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    std::cout << "Dlina obnovlena!" << std::endl;
}

void editPipeDiameter(Pipe& pipe) {
    std::cout << "Tekushij diametr truby: " << pipe.diameter << " mm" << std::endl;
    std::cout << "Vvedite novyj diametr (mm): ";
    while (!(std::cin >> pipe.diameter) || pipe.diameter <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe chislo: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    std::cout << "Diametr obnovlen!" << std::endl;
}

void editPipe(Pipe& pipe) {
    int choice;
    do {
        std::cout << "\nRedaktor truby:" << std::endl;
        std::cout << "1. Izmenit nazvanie" << std::endl;
        std::cout << "2. Izmenit dlinu" << std::endl;
        std::cout << "3. Izmenit diametr" << std::endl;
        std::cout << "4. Pereklyuchit status remonta" << std::endl;
        std::cout << "0. Vernutsja v glavnoe menu" << std::endl;
        std::cout << "Vvedite vash vybor: ";
        
        while (!(std::cin >> choice)) {
            std::cout << "Nevernyj vvod. Vvedite chislo: ";
            clearInputBuffer();
        }
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                editPipeName(pipe);
                break;
            case 2:
                editPipeLength(pipe);
                break;
            case 3:
                editPipeDiameter(pipe);
                break;
            case 4:
                togglePipeRepair(pipe);
                break;
            case 0:
                std::cout << "Vozvrat v glavnoe menu..." << std::endl;
                break;
            default:
                std::cout << "Nevernyj vybor. Poprobujte snova." << std::endl;
        }
    } while (choice != 0);
}

void editStationName(CompressorStation& cs) {
    std::cout << "Tekushee nazvanie stancii: " << cs.name << std::endl;
    std::cout << "Vvedite novoe nazvanie: ";
    std::getline(std::cin, cs.name);
    std::cout << "Nazvanie obnovleno!" << std::endl;
}

void editStationTotalWorkshops(CompressorStation& cs) {
    std::cout << "Tekushee obshhee kolichestvo cehov: " << cs.totalWorkshops << std::endl;
    std::cout << "Vvedite novoe obshhee kolichestvo cehov: ";
    int newTotal;
    while (!(std::cin >> newTotal) || newTotal <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe celoe chislo: ";
        clearInputBuffer();
    }
    
    if (newTotal < cs.workingWorkshops) {
        cs.workingWorkshops = newTotal;
        std::cout << "Kolichestvo rabotayushhih cehov avtomaticheski umensheno do " << newTotal << std::endl;
    }
    
    cs.totalWorkshops = newTotal;
    clearInputBuffer();
    std::cout << "Obshhee kolichestvo cehov obnovleno!" << std::endl;
}

void editStationWorkingWorkshops(CompressorStation& cs) {
    std::cout << "Tekushee kolichestvo rabotayushhih cehov: " << cs.workingWorkshops << "/" << cs.totalWorkshops << std::endl;
    std::cout << "Vvedite novoe kolichestvo rabotayushhih cehov: ";
    int newWorking;
    while (!(std::cin >> newWorking) || newWorking < 0 || newWorking > cs.totalWorkshops) {
        std::cout << "Nevernyj vvod. Vvedite chislo ot 0 do " << cs.totalWorkshops << ": ";
        clearInputBuffer();
    }
    cs.workingWorkshops = newWorking;
    clearInputBuffer();
    std::cout << "Kolichestvo rabotayushhih cehov obnovleno!" << std::endl;
}

void editStationClass(CompressorStation& cs) {
    std::cout << "Tekushij klass stancii: " << cs.stationClass << std::endl;
    std::cout << "Vvedite novyj klass stancii: ";
    while (!(std::cin >> cs.stationClass) || cs.stationClass <= 0) {
        std::cout << "Nevernyj vvod. Vvedite polozhitelnoe celoe chislo: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    std::cout << "Klass stancii obnovlen!" << std::endl;
}

void startWorkshop(CompressorStation& cs) {
    if (cs.workingWorkshops < cs.totalWorkshops) {
        cs.workingWorkshops++;
        std::cout << "Ceh zapushen. Rabotajushhih cehov: " << cs.workingWorkshops << "/" << cs.totalWorkshops << std::endl;
    } else {
        std::cout << "Vse ceha uzhe rabotajut!" << std::endl;
    }
}

void stopWorkshop(CompressorStation& cs) {
    if (cs.workingWorkshops > 0) {
        cs.workingWorkshops--;
        std::cout << "Ceh ostanovlen. Rabotajushhih cehov: " << cs.workingWorkshops << "/" << cs.totalWorkshops << std::endl;
    } else {
        std::cout << "Net rabotajushhih cehov!" << std::endl;
    }
}

void editCompressorStation(CompressorStation& cs) {
    int choice;
    do {
        std::cout << "\nRedaktor kompressornoj stancii:" << std::endl;
        std::cout << "1. Izmenit nazvanie" << std::endl;
        std::cout << "2. Izmenit obshhee kolichestvo cehov" << std::endl;
        std::cout << "3. Izmenit kolichestvo rabotayushhih cehov" << std::endl;
        std::cout << "4. Izmenit klass stancii" << std::endl;
        std::cout << "5. Zapustit ceh" << std::endl;
        std::cout << "6. Ostanovit ceh" << std::endl;
        std::cout << "0. Vernutsja v glavnoe menu" << std::endl;
        std::cout << "Vvedite vash vybor: ";
        
        while (!(std::cin >> choice)) {
            std::cout << "Nevernyj vvod. Vvedite chislo: ";
            clearInputBuffer();
        }
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                editStationName(cs);
                break;
            case 2:
                editStationTotalWorkshops(cs);
                break;
            case 3:
                editStationWorkingWorkshops(cs);
                break;
            case 4:
                editStationClass(cs);
                break;
            case 5:
                startWorkshop(cs);
                break;
            case 6:
                stopWorkshop(cs);
                break;
            case 0:
                std::cout << "Vozvrat v glavnoe menu..." << std::endl;
                break;
            default:
                std::cout << "Nevernyj vybor. Poprobujte snova." << std::endl;
        }
    } while (choice != 0);
}

void saveToFile(const Pipe& pipe, const CompressorStation& cs, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "PIPE" << std::endl;
        file << pipe.name << std::endl;
        file << pipe.length << std::endl;
        file << pipe.diameter << std::endl;
        file << pipe.underRepair << std::endl;
        
        file << "STATION" << std::endl;
        file << cs.name << std::endl;
        file << cs.totalWorkshops << std::endl;
        file << cs.workingWorkshops << std::endl;
        file << cs.stationClass << std::endl;
        
        std::cout << "Dannyye sohraneny v fajl: " << filename << std::endl;
    } else {
        std::cout << "Oshibka: Ne udalos' otkryt' fajl dlja zapisi!" << std::endl;
    }
}

void loadFromFile(Pipe& pipe, CompressorStation& cs, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        
        std::getline(file, line);
        std::getline(file, pipe.name);
        file >> pipe.length;
        file >> pipe.diameter;
        file >> pipe.underRepair;
        clearInputBuffer();
        
        std::getline(file, line);
        std::getline(file, cs.name);
        file >> cs.totalWorkshops;
        file >> cs.workingWorkshops;
        file >> cs.stationClass;
        clearInputBuffer();
        
        std::cout << "Dannyye zagruzheny iz fajla: " << filename << std::endl;
    } else {
        std::cout << "Oshibka: Ne udalos' otkryt' fajl dlja chtenija!" << std::endl;
    }
}

int main() {
    Pipe pipe;
    CompressorStation cs;
    bool pipeExists = false;
    bool stationExists = false;
    
    int choice;
    
    std::cout << "Sistema upravlenija truboprovodnym transportom" << std::endl;
    
    do {
        std::cout << "\nGlavnoe menu:" << std::endl;
        std::cout << "1. Dobavit trubu" << std::endl;
        std::cout << "2. Dobavit kompressornuju stanciju" << std::endl;
        std::cout << "3. Prosmotr vseh obektov" << std::endl;
        std::cout << "4. Redaktirovat trubu" << std::endl;
        std::cout << "5. Redaktirovat kompressornuju stanciju" << std::endl;
        std::cout << "6. Sohranit v fajl" << std::endl;
        std::cout << "7. Zagruzit iz fajla" << std::endl;
        std::cout << "0. Vyhod" << std::endl;
        std::cout << "Vvedite vash vybor: ";
        
        while (!(std::cin >> choice)) {
            std::cout << "Nevernyj vvod. Vvedite chislo: ";
            clearInputBuffer();
        }
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                inputPipe(pipe);
                pipeExists = true;
                break;
                
            case 2:
                inputCompressorStation(cs);
                stationExists = true;
                break;
                
            case 3:
                if (pipeExists) {
                    displayPipe(pipe);
                } else {
                    std::cout << "Dannyye o trube otsutstvujut." << std::endl;
                }
                
                if (stationExists) {
                    displayCompressorStation(cs);
                } else {
                    std::cout << "Dannyye o kompressornoj stancii otsutstvujut." << std::endl;
                }
                break;
                
            case 4:
                if (pipeExists) {
                    editPipe(pipe);
                } else {
                    std::cout << "Net truby dlja redaktirovanija. Snachala dobavte trubu." << std::endl;
                }
                break;
                
            case 5:
                if (stationExists) {
                    editCompressorStation(cs);
                } else {
                    std::cout << "Net kompressornoj stancii dlja redaktirovanija. Snachala dobavte stanciju." << std::endl;
                }
                break;
                
            case 6:
                if (pipeExists || stationExists) {
                    saveToFile(pipe, cs, "pipeline_data.txt");
                } else {
                    std::cout << "Net dannyh dlja sohranenija." << std::endl;
                }
                break;
                
            case 7:
                loadFromFile(pipe, cs, "pipeline_data.txt");
                pipeExists = true;
                stationExists = true;
                break;
                
            case 0:
                std::cout << "Vyhod iz programmy. Do svidanija!" << std::endl;
                break;
                
            default:
                std::cout << "Nevernyj vybor. Pozhalujsta, poprobujte snova." << std::endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
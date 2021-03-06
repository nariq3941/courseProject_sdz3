#include <iostream>
#include "TimeMeasurement.h"
#include "DiscreteKnapsackProblem.h"
#include "TravellingSalesmanProblem.h"
#include "AlgorithmTest.h"

void displayMenu(const std::string &info, const std::string &whatToGenerate,
                 const std::string &collectionOfWhat) //Menu dla problemu plecakowego i komiwojażera.
{
    std::cout << std::endl;
    std::cout << info << std::endl;
    std::cout << "1. Wczytaj z pliku." << std::endl;
    std::cout << "2. Wygeneruj " << whatToGenerate << " losowo." << std::endl;
    std::cout << "3. Wyświetl zbiór " << collectionOfWhat << "." << std::endl;
    if (whatToGenerate == "przedmioty") {
        std::cout << "4. Algorytm - zachłanny, wersja: sortowanie po wartości." << std::endl;
        std::cout << "5. Algorytm - zachłanny, wersja: sortowanie po stosunku wartość/rozmiar." << std::endl;
        std::cout << "6. Algorytm - dynamiczny." << std::endl;
    } else {
        std::cout << "4. Algorytm - zachłanny." << std::endl;
        std::cout << "5. Algorytm - zupełny." << std::endl;
    }
    std::cout << "0. Powrot do menu." << std::endl;
    std::cout << "Podaj opcje: ";
}

void menu_discrete_knapsack_problem() //Obsługa problemu plecakowego.
{
    DiscreteKnapsackProblem k;
    std::string path;
    int option;
    do {
        displayMenu("*** Problem plecakowy ***", "przedmioty", "przedmiotów");
        std::cin >> option;
        std::cout << std::endl;
        switch (option) {
            case 1: //Tworzenie zbioru przedmiotów z pliku txt.
                std::cout << "Podaj sciezke pliku z danymi: ";
                std::cin >> path;
                try {
                    k.ReadItemsFromFile(path);
                } catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 2: //Generowanie przedmiotów pseudolosowo.
                try {
                    k.GenerateRandomItems();
                    k.PrintItemsForTheKnapsack();
                }
                catch (std::invalid_argument &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 3: //Wyświetlanie zbioru przedmiotów.
                try {
                    k.PrintItemsForTheKnapsack();
                }
                catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 4: //Algorytm 1. - zachłanny: wersja z sortowaniem po wartości.
                try {
                    k.GreedyAlgorithm(true);
                    k.PrintItemsForTheKnapsack();
                    std::cout << std::endl;
                    k.PrintSolution();
                }
                catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 5: //Algorytm 1. - zachłanny: wersja z sortowaniem po stosunku wartość/rozmiar.
                try {
                    k.GreedyAlgorithm(false);
                    k.PrintItemsForTheKnapsack();
                    std::cout << std::endl;
                    k.PrintSolution();
                }
                catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 6: //Algorytm 2. - dynamiczny.
                try {
                    k.DynamicAlgorithm();
                    k.PrintItemsForTheKnapsack();
                    std::cout << std::endl;
                    k.PrintSolution();
                }
                catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            default:
                break;
        }
        
    } while (option != 0);
}

void menu_travelling_salesman_problem() //Obsługa problemu komiwojażera.
{
    TravellingSalesmanProblem s;
    std::string path;
    int option;
    do {
        displayMenu("*** Problem komiwojażera ***", "miasta", "miast");
        std::cin >> option;
        std::cout << std::endl;
        switch (option) {
            case 1: //Tworzenie zbioru miast z pliku txt.
                std::cout << "Podaj sciezke pliku z danymi: ";
                std::cin >> path;
                try {
                    s.ReadCitiesFromFile(path);
                } catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 2: //Generowanie miast pseudolosowo.
                try {
                    s.GenerateRandomCities();
                    s.PrintCitiesForTheTravellingSalesman();
                }
                catch (std::invalid_argument &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 3: //Wyświetlanie zbioru miast.
                try {
                    s.PrintCitiesForTheTravellingSalesman();
                }
                catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 4: //Algorytm 1. - zachłanny.
                try {
                    s.GreedyAlgorithm();
                    s.PrintCitiesForTheTravellingSalesman();
                    std::cout << std::endl;
                    s.PrintSolution();
                }
                catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 5: //Algorytm 2. - zupełny.
                try {
                    s.BruteForceAlgorithm();
                    s.PrintCitiesForTheTravellingSalesman();
                    std::cout << std::endl;
                    s.PrintSolution();
                }
                catch (std::logic_error &e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            default:
                break;
        }
        
    } while (option != 0);
}

void menu_tests() //Obsługa testów czasowych.
{
    AlgorithmTest test;
    int option;
    int numberOfRepetitions;
    int maxDistanceBetweenCity;
    do {
        std::cout << std::endl;
        std::cout << "*** Testy czasowe ***" << std::endl;
        std::cout << "1. Testy czasowe dla algorytmów problemu plecakowego." << std::endl;
        std::cout << "2. Testy czasowe dla algorytmu zachłannego problemu komiwojażera." << std::endl;
        std::cout << "3. Testy czasowe dla algorytmu zupełnego problemu komiwojażera." << std::endl;
        std::cout << "Podaj opcje: ";
        std::cin >> option;
        std::cout << std::endl;
        switch (option) {
            case 1: //Testy czasowe dla algorytmów problemu plecakowego.
                int maxValueForItem;
                std::cout << "Podaj ilość instancji każdego zestawu danych w celu uśrednienia wyniku: ";
                std::cin >> numberOfRepetitions;
                std::cout << "Podaj maksymalną wartość przedmiotu: ";
                std::cin >> maxValueForItem;
                test.DiscreteKnapsackProblem_Test(numberOfRepetitions, maxValueForItem);
                break;
            
            case 2: //Testy czasowe dla algorytmu zachłannego problemu komiwojażera.
                std::cout << "Podaj ilość instancji każdego zestawu danych w celu uśrednienia wyniku: ";
                std::cin >> numberOfRepetitions;
                std::cout << "Podaj maksymalną wartość odległości pomiędzy miastami: ";
                std::cin >> maxDistanceBetweenCity;
                test.TravellingSalesmanProblem_Test_Greedy(numberOfRepetitions, maxDistanceBetweenCity);
                break;
            
            case 3: //Testy czasowe dla algorytmu zupełnego problemu komiwojażera.
                std::cout << "Podaj ilość instancji każdego zestawu danych w celu uśrednienia wyniku: ";
                std::cin >> numberOfRepetitions;
                std::cout << "Podaj maksymalną wartość odległości pomiędzy miastami: ";
                std::cin >> maxDistanceBetweenCity;
                test.TravellingSalesmanProblem_Test_BruteForce(numberOfRepetitions, maxDistanceBetweenCity);
                break;
            
            default:
                break;
        }
        
    } while (option != 0);
}

int main() {
    int option;
    do {
        std::cout << std::endl;
        std::cout << "==== MENU GŁÓWNE ===" << std::endl;
        std::cout << "1. Problem plecakowy." << std::endl;
        std::cout << "2. Problem komiwojażera." << std::endl;
        std::cout << "3. Testy czasowe." << std::endl;
        std::cout << "0. Wyjscie." << std::endl;
        std::cout << "Podaj opcje: ";
        std::cin >> option;
        std::cout << std::endl;
        
        switch (option) {
            case 1:
                menu_discrete_knapsack_problem();
                break;
            case 2:
                menu_travelling_salesman_problem();
                break;
            case 3:
                menu_tests();
                break;
            default:
                break;
        }
        
    } while (option != 0);
    
    return 0;
}

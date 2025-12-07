#ifndef TESTS_UNITAIRES_HPP
#define TESTS_UNITAIRES_HPP

#include <vector>
#include <string>

class TestsUnitaires {
private:
    std::vector<std::vector<int>> matrice_depart;
    std::vector<std::vector<int>> matrice_attendue;
    int iterations;
    std::string nom_test;

public:
    TestsUnitaires(const std::string& nom,
                   const std::vector<std::vector<int>>& depart,
                   const std::vector<std::vector<int>>& attendue,
                   int iter);

    bool tester();  // lance la simulation et compare
};

#endif

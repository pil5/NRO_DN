#include <iostream>
#include <fstream>
#include <vector>


double centralnaDiferenca(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (data[idx + 1].second - data[idx - 1].second) / (2 * dx); 
}
  
double naprejDiferenca(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (-3 * data[idx].second + 4 * data[idx + 1].second - data[idx + 2].second) / (2 * dx);
}


double nazajDiferenca(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (3 * data[idx].second - 4 * data[idx - 1].second + data[idx - 2].second) / (2 * dx);
}





int main() {
    std::ifstream datoteka("poly.txt");
    

    int stVrednosti;
    int prva;
    int zadnja;
    datoteka >> stVrednosti;

    std::vector<std::pair<double, double>> data;
    double x, fx;
    for (int i = 0; i < stVrednosti; ++i) {
        datoteka >> x >> fx;
        data.emplace_back(x, fx);
        if(i==0){
            prva = x;
        }
        if(i==stVrednosti - 1){
            zadnja = x;
        }
    }

    datoteka.close();

    double dx = static_cast<double>(zadnja - prva)/stVrednosti; // ∆x
    std::ofstream outputFile("diff_poly.txt");
   

    
    for (int i = 0; i < stVrednosti; ++i) {
        double derivative;
        if (i == 0) {
            derivative = naprejDiferenca(data, i, dx);
        } 
        else if (i == stVrednosti - 1) {
            derivative = nazajDiferenca(data, i, dx);
        } 
        else {
            derivative = centralnaDiferenca(data, i, dx);
        }
        outputFile << "Odvod f'(" << data[i].first << ") = " << derivative << std::endl;
    }

    outputFile.close();

    std::cout << "Odvodi shranjeni v diff_poly.txt\n";

    return 0;
}
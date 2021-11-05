// shuffle algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <vector>       // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <map>
int main () 
{
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    std::vector<std::string> cousins{"Etienne","Camille","Clement","Baptiste","Matthieu","Soline","Pierre-Antoine","Clemence","Benoit","Simon"};
    std::map<std::string,std::vector<std::string>> exclusion;

    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Etienne"       , std::vector<std::string>{"Camille","Clement"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Camille"       , std::vector<std::string>{"Etienne","Clement","Soline"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Clement"       , std::vector<std::string>{"Camille","Etienne"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Baptiste"      , std::vector<std::string>{"Matthieu","Soline"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Matthieu"      , std::vector<std::string>{"Baptiste","Soline"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Soline"        , std::vector<std::string>{"Matthieu","Baptiste"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Pierre-Antoine", std::vector<std::string>{"Clemence","Benoit","Simon"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Clemence"      , std::vector<std::string>{"Pierre-Antoine","Benoit","Simon"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Benoit"        , std::vector<std::string>{"Pierre-Antoine","Clemence","Simon"}));
    exclusion.insert(std::pair<std::string,std::vector<std::string>> ("Simon"         , std::vector<std::string>{"Pierre-Antoine","Clemence","Benoit"}));

        




    bool found =false ;
    while (!found){
      std::shuffle(cousins.begin(), cousins.end(), e);
      std::cout << "----------------------------------------------------:"<< std::endl;
      for (std::string& x: cousins) std::cout << ' ' << x;
      std::cout << std::endl;
      found=true;
      for (int i = 0; i < 10 ; i++){
        std::string cousin=cousins[i];
        std::string next;
        if ( i != 9) {
          next = cousins[i+1];
        } 
        else{
          next = cousins[0];
        }
        if (std::find(exclusion[cousin].begin(), exclusion[cousin].end(), next) != exclusion[cousin].end()) {
          std::cout << "ERR:" << cousin << " ne peut pas donner a: " << next << std::endl;
          found = false;
        }
      }
    }

    
    
    return 0;
}

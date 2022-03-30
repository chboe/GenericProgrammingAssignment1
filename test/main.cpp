#include "../src/List.hpp"
#include "../src/Tree.hpp"
#include "iostream"

int main() {
    DM852::List bing;
    bing.push_back("ha");
    bing.push_back("haha");
    bing.push_back("hahaha");
    bing.insert(bing.begin(), "hahahaha");
    bing.erase(bing.end());

    DM852::List bong;
    bong.push_back("ha");
    bong.push_back("haha");
    bong.push_back("hahaha");
    bong.insert(bong.begin(), "hahahaha");
    std::cout<<(bing == bong)<<std::endl;

    bing.clear();
    bong.clear();
    std::cout<<(bing == bong)<<std::endl;
    std::cout<<(bing.size())<<std::endl;

    DM852::Tree wing;
    wing.insert(5, "ha");
    wing.insert(3, "ha");
    wing.insert(8, "ha");
    wing.insert(1, "ha");
    wing.insert(9, "ha");
    wing.insert(4, "ha");
    wing.insert(6, "ha");
    wing.erase(9);
    wing.erase(wing.end());


    DM852::Tree wong;
    wong.insert(5, "ha");
    wong.insert(3, "ha");
    wong.insert(8, "ha");
    wong.insert(1, "ha");
    wong.insert(9, "ha");
    wong.insert(4, "ha");
    wong.insert(6, "ha");
    std::cout<<(wong.size())<<std::endl;
    wong.erase(9);
    wong.erase(wong.end());
    std::cout<<(wong.size())<<std::endl;

    DM852::Tree asd = wing;

    std::cout<<(wing == wong)<<std::endl;

}
#include "List.hpp"
#include "iostream"

int main() {
    DM852::List bing;
    bing.push_back("ha");
    bing.push_back("haha");
    bing.push_back("hahaha");
    bing.push_back("hahahaha");

    DM852::List bong;
    bong.push_back("ha");
    bong.push_back("haha");
    bong.push_back("hahaha");
    bong.push_back("hahahaha");

    std::cout<<(bing == bong)<<std::endl;
}
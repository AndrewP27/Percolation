// Percolation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Model.h"
#include <iostream>

int main()
{
    int size;
    std::cin >> size;
    Model model = Model(size);
    bool running = true;
    while(running)
        running = !model.Run();
    model.showGraph();
    std::cout << running << std::endl << std::endl;
    std::cin >> size;
    return 0;
}


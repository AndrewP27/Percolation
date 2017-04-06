#include "stdafx.h"
#include "Model.h"
#pragma once
#include <iostream>
#include <stdlib.h>     
#include <time.h>

Model::Model()
{
    size = 5;
    createIds();
    /* initialize random seed: */
    srand(time(NULL));
}

Model::Model(int nSize)
{
    size = nSize;
    createIds();
    /* initialize random seed: */
    srand(10);
}

Model::~Model()
{
}

void Model::createIds()
{
    //ids = new int[size * size+2];
    isEmpty = new bool[size* size+2];
    idPointer = new int[size * size+2];
    numOfObj = new int[size * size + 2];
    for (int i = 0; i < size* size+2; i++)
    {
       // ids[i] = i;
        numOfObj[i] = 1;
        if (i <= 5)
            idPointer[i] = 0;
        else if(i >= 21)
            idPointer[i] = 26;
        else
            idPointer[i] = i;

        isEmpty[i] = false;
    }
}

void Model::addHole()
{
    int index;
    bool trying = true;
    while (trying)
    {
        index = rand() % (size*size)+1;
        if (!isEmpty[index])
        {
            isEmpty[index] = true;
            trying = false;
        }
    }

    // Above
    if (!(index < size))
    {
        if (isEmpty[index - 5])
            Union(index, index - 5);
    }

    // Below
    if (!(index > size * size - size))
    {
        if (isEmpty[index + 5])
            Union(index, index + 5);
    }

    // Left
    if (!((index-1)%size == 0))
    {
        if (isEmpty[index - 1])
            Union(index, index - 1);
    }

    // Right
    if (!((index)%size == 0))
    {
        if (isEmpty[index + 1])
            Union(index, index + 1);
    }

}

void Model::showGraph()
{
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (isEmpty[i*size + j+1])
                std::cout << "O";
            else
                std::cout << "#";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int Model::findRoot(int startIndex)
{
    int currentIndex = startIndex;
    while (idPointer[currentIndex] != currentIndex)
    {
        currentIndex = idPointer[currentIndex];
    }
    return currentIndex;
}

void Model::Union(int q, int p)
{
    int qRoot = findRoot(q);
    int pRoot = findRoot(p);
    if (numOfObj[qRoot] > numOfObj[pRoot])
    {
        numOfObj[qRoot]++;
        idPointer[pRoot] = qRoot;
    }
    else
    {
        numOfObj[pRoot]++;
        idPointer[qRoot] = pRoot;
    }
}

bool Model::Check(int q, int p)
{
    return (findRoot(p) == findRoot(q));
}

void Model::printPoints()
{
    for (int i = 0; i < size*size+2; i++)
    {
        std::cout << idPointer[i]<<", ";
    }
    std::cout << std::endl;
    
}

bool Model::Run()
{
    addHole();
    //printPoints();
    //showGraph();

    bool check = Check(0, 26);
    return check;
}
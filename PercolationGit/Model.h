#pragma once
class Model
{
private:
    int size;
    int* ids;
    int* idPointer;
    int* numOfObj;
    bool* isEmpty;
    void createIds();
    int findRoot(int startIndex);
    void Union(int q, int p);
    bool Check(int q, int p);
    void addHole();
    void printPoints();
public:
    Model();
    Model(int nSize);
    void showGraph();
    bool Run();
    ~Model();
};


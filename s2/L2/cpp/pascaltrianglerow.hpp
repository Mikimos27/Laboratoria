#ifndef PASCALTRIANGLEROW
#define PASCALTRIANGLEROW

class pascaltrianglerow{
private:
    int* data;
    int n;
public:
    pascaltrianglerow(int n);
    ~pascaltrianglerow();
    void Create(int n);
    int Elem(int m);
};

#endif

//
// Created by frost on 07.10.2018.
//

#ifndef UNTITLED1_TRITSET_H
#define UNTITLED1_TRITSET_H

#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;

enum Trit {Unknown, False, True};

class TritSet
{

private:
    vector <unsigned int> sequence;
    unsigned int cur_index;
    unsigned int major_index;
    unsigned int newInd;
    int countTrue, countFalse, countUnk;

public:

    TritSet(unsigned int);

    size_t capacity() const;

    void shrink();

    class Helper {

    private:
        int index;
        TritSet &A;
        Helper(int, TritSet &);

    public:

        friend class TritSet;
        operator Trit() const;
        Helper &operator=(const Trit);
        ~Helper() = default;;
    };

    Helper operator[](unsigned int);

    Trit operator[](unsigned int) const;

    void fillTheTrit(int);

    friend bool operator==(Trit, Trit);

    friend TritSet operator&(TritSet &certainA, TritSet &certainB);

    friend TritSet operator~(TritSet &);

    friend TritSet operator|(TritSet &certainA, TritSet &certainB);

    int cardinality(Trit current) const;

    unordered_map<Trit, int, hash<int>> cardinality() const;

    void trim(size_t);

    size_t length() const;

    ~TritSet() = default;;

};

bool operator==(Trit, Trit);

TritSet operator&(TritSet &certainA, TritSet &certainB);

TritSet operator~(TritSet &);

TritSet operator|(TritSet &certainA, TritSet &certainB);

#endif //UNTITLED1_TRITSET_H

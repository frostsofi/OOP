#include "TritSet.h"

TritSet:: TritSet(unsigned int mySize)
{
    sequence.resize(mySize/4/sizeof(unsigned int) + 1);
    major_index = mySize - 1;
    newInd = cur_index = 0;
    countTrue = 0;
    countFalse = 0;
    countUnk = mySize;
}

size_t TritSet:: capacity() const
{
    return major_index;
}

void TritSet:: shrink()
{
    if (newInd != 0)
        sequence.erase(sequence.begin() + newInd + 1, sequence.end());
    else
        sequence.erase(sequence.begin(), sequence.end());
    major_index = newInd;
}

TritSet:: Helper:: Helper(const int j, TritSet &my) : index(j), A(my)
{}

TritSet:: Helper:: operator Trit() const
{
    bitset <sizeof(unsigned int)*8> currentNumber;
    bitset <2> one_trit;

    if (index > A.major_index)
        return False;
    A.newInd = index * 2 / sizeof(unsigned int) / 8;
    A.cur_index = index * 2 - (A.newInd) * sizeof(unsigned int) * 8;
    currentNumber = A.sequence[A.newInd];
    one_trit[1] = currentNumber[A.cur_index];
    one_trit[0] = currentNumber [A.cur_index + 1];
    return static_cast<Trit>(one_trit.to_ulong());
}

Trit TritSet::operator[](unsigned int k) const
{
    if (k > major_index)
        return False;
    int cur = k * 2 / sizeof(unsigned int) / 8;
    int cur_bit = k * 2 - (cur*sizeof(unsigned int))*8;
    bitset <sizeof(unsigned int)*8> currentNumber;
    bitset <2> one_trit;
    currentNumber = sequence[cur];
    one_trit[1] = currentNumber[cur_bit];
    one_trit[0] = currentNumber [cur_bit + 1];
    return static_cast<Trit>(one_trit.to_ulong());

}

TritSet::Helper &TritSet:: Helper:: operator=(const Trit item)
{
    A.newInd = index * 2 / sizeof(unsigned int) / 8;
    A.cur_index = index * 2 - (A.newInd) * sizeof(unsigned int) * 8;
    if (item != Unknown)
    {
        if (A.newInd > A.sequence.capacity())
        {
            A.sequence.resize(A.newInd + 1);
            A.major_index = A.cur_index + A.newInd*sizeof(unsigned int)*8;
        }
            if (item == True)
                A.countTrue++;
            else
                A.countFalse++;
            A.countUnk--;
        A.fillTheTrit(item);
    }
}

TritSet::Helper TritSet::operator[](unsigned int j)
  {
           Helper A(j,*this);
            return A;
  }

void TritSet::fillTheTrit(int item)
{
    bitset <sizeof(unsigned int)*8> currentNumber;
    currentNumber = sequence[newInd];
    currentNumber[cur_index] = item / 2;
    currentNumber[cur_index + 1] = item % 2;
    sequence[newInd] = currentNumber.to_ulong();
}


bool operator==(Trit my, Trit now)
{
    if (my != now)
        return 0;
    return 1;
}

TritSet operator&(TritSet &certainA, TritSet &certainB)
{
    int i, max;
    bitset <sizeof(unsigned int)*8> currentNumberA;
    bitset <sizeof(unsigned int)*8> currentNumberB;
    bitset <sizeof(unsigned int)*8> currentNumberC;
    if (certainA.capacity() > certainB.capacity())
        max = certainA.capacity();
    else
        max = certainB.capacity();
    TritSet certainC(max + 1);
    for (i = 0; i < max; i++)
    {
        currentNumberA = certainA.sequence[i];
        currentNumberB = certainB.sequence[i];
        for (int j = 0; j < sizeof(unsigned int)*8; j += 2)
        {
            currentNumberC[j] = currentNumberA[j] & currentNumberB[j];
            currentNumberC[j + 1] = currentNumberA[j + 1] | currentNumberB[j + 1];
        }
        certainC.sequence[i] = currentNumberC.to_ulong();
    }

    return certainC;
}

TritSet operator~(TritSet &certainA)
{
    bitset <sizeof(unsigned int)*8> currentNumberA;
    bitset <sizeof(unsigned int)*8> currentNumberC;

    TritSet certainC(certainA.capacity()+1);
    for (int i = 0; i < certainA.capacity(); i++)
    {
        currentNumberA = certainA.sequence[i];
        for (int j = 0; j < sizeof(unsigned int)*8; j += 2)
        {
            if (currentNumberA[j] != currentNumberA[j+1])
            {
                currentNumberC[j] = ~currentNumberA[j];
                currentNumberC[j + 1] = ~currentNumberA[j + 1];
            }
        }
        certainC.sequence[i] = currentNumberC.to_ulong();

    }
    return certainC;
}

TritSet operator|(TritSet &certainA, TritSet &certainB)
{
    bitset <sizeof(unsigned int)*8> currentNumberA;
    bitset <sizeof(unsigned int)*8> currentNumberB;
    bitset <sizeof(unsigned int)*8> currentNumberC;
    int i, max;
    if (certainA.capacity() > certainB.capacity())
        max = certainA.capacity();
    else
        max = certainB.capacity();
    TritSet certainC(max+1);
    for (i = 0; i < max; i++)
    {
        currentNumberA = certainA.sequence[i];
        currentNumberB = certainB.sequence[i];
        for (int j = 0; j < sizeof(unsigned int)*8; j += 2)
        {
            currentNumberC[j] = currentNumberA[j] | currentNumberB[j];
            currentNumberC[j + 1] = currentNumberA[j+ 1] & currentNumberB[j + 1];
        }
        certainC.sequence[i] = currentNumberC.to_ulong();

    }
    return certainC;

}

int TritSet::cardinality(Trit  current) const
{
    if (current == True)
        return countTrue;
    if (current == False)
        return countFalse;
    return countUnk;
}

unordered_map<Trit, int, hash<int>> TritSet::cardinality() const
{
    unordered_map<Trit, int, hash<int>> common;
    common = {{True, countTrue}, {False, countFalse}, {Unknown, countUnk}};
    return common;
}

void TritSet::trim(size_t lastIndex)
{
    newInd = lastIndex*2/sizeof(unsigned int)/8;
    for (int i = newInd; i < major_index; i++)
        sequence[i] = 0;
}

size_t TritSet::length() const
{
      return (cur_index/2) + newInd*sizeof(unsigned int)*8;
}

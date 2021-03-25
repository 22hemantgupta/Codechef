#include <bits/stdc++.h>
using namespace std;
uvec numbertheory::mahonian_row(uword n)
{
    uword i = 2;
    uvec current;
    current.ones(i);
    uword current_size;
    uvec prev;
    uword prev_size;

    if (n == 0)
    {
        current.ones(1);
        return current;
    }

    while (i <= n)
    {                                         // increment through the rows
        prev_size = current.size();           // reset prev size to current size
        prev.set_size(prev_size);             // set size of prev vector
        prev = current;                       //copy contents of current to prev vector
        current_size = 1 + (i * (i + 1) / 2); // reset current_size
        current.zeros(current_size);          // reset current vector with zeros

        for (uword j = 0; j < i + 1; j++) //increment through current vector
            for (uword k = 0; k < prev_size; k++)
                current(k + j) += prev(k);
        i++; //increment to next row
    }
    return current; //return current vector
}

uword numbertheory::mahonian_fast(uword n, uword c)
{
    **This function returns the coefficient of c order of row n of
         **the Mahonian numbers
     // check for input errors
     if (c >= 1 + (n * (n + 1) / 2))
    {
        cout << "Error. Invalid input parameters" << endl;
    }
    uvec mahonian;
    mahonian.zeros(1 + (n * (n + 1) / 2));
    mahonian = mahonian_row(n);
    return mahonian(c);
}

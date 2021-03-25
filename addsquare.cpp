#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <bitset>
using namespace std;
const int mx = 100001;
int main()
{
    int width, height, numVer, numHor;
    cin >> width >> height >> numVer >> numHor;
    bitset<mx> vertical, horizontal, revHorizontal;
    for (int i = 0; i < numVer; i++)
    {
        int verLine;
        cin >> verLine;
        vertical.set(verLine);
    }
    // read in y-coordinates of horizontal lines and store in bitset
    for (int i = 0; i < numHor; i++)
    {
        int horLine;
        cin >> horLine;
        horizontal.set(horLine);
        revHorizontal.set(height - horLine);
    }
    bitset<mx> verDiff, horDiff;
    for (int i = 0; i <= width; i++)
    {
        if (vertical[i])
        {
            verDiff |= (vertical >> i);
        }
    }
    for (int i = 0; i <= width; i++)
        if (horizontal[i])
        {
            // and for each line (at y=j) above it set bit j-i of horDiff
            horDiff |= (horizontal >> i);
        }
    int maxSquare = 0;
    // loop over all possible y-coordinates of the new line
    for (int c = 0; c <= height; c++)
    {
        // newHorDiff will store the newly formed distances,
        bitset<mx> newHorDiff;
        // update the distances between the new line and those above it
        newHorDiff |= (horizontal >> c);
        // update the distances between the new line and those below it
        newHorDiff |= (revHorizontal >> (height - c));
        // calculate how many squares can be created
        // there is a square of a particular side-length if that side-length
        // is the distance between two horizontal lines,
        // and the distance between two vertical lines
        int numSquare = (verDiff & (horDiff | newHorDiff)).count();
        maxSquare = max(maxSquare, numSquare);
    }

    // -1 to ignore a 0-area square.
    cout << maxSquare - 1 << endl;

    return 0;
}
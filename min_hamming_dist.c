/***************************************************************************************
*    Title: min_hamming_dist.c
*    Author: Yacin Belmihoub-Martel
*    Date: 12/29/2019
*    Computes the minimum hamming distance in an array of 32 bit integers.
*    Heavily inspired from https://en.wikipedia.org/wiki/Hamming_distance#Algorithm_example
***************************************************************************************/

// Idée: Paralléliser l'exécution avec des child process en appelant fork()...

int distance_hamming(unsigned int val1, unsigned int val2)
{
    int distance = 0;

    // iterate through the xor of both values until val is all 0
    for (unsigned int val=val1^val2; val > 0; val = val >> 1)
    {
        // if a bit is 1, increment the counter
        if (val & 1)
            distance++;
    }
    
    return distance;
}

int min_Hamming(unsigned int tab[], unsigned int tab_size)
{
    int min_distance = 32;

    for (int j=0; j < tab_size; j++)
    {
        for (int i=j+1; i < tab_size; i++)
        {
            // if both numbers are equal, then min distance is 0
            if (tab[i-1] == tab[i])
                return 0;
            int distance = distance_hamming(tab[j], tab[i]);
            // if distance is smaller than min_distance, found new min
            if (distance < min_distance)
                min_distance = distance;
        }
    }

    return min_distance;
}

// Test the function on a small array
int main ()
{
    unsigned int tab[7] = {10, 325, 58, 978, 74, 19, 22};

    int distance_min = min_Hamming(tab, 7);    
    return distance_min;
}

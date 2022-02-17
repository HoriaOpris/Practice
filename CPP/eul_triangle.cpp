/*
               75
              95 64
             17 47 82
            18 35 87 10
           20 04 82 47 65
          19 01 23 75 03 34
         88 02 77 73 07 63 67
        99 65 04 28 06 16 70 92
       41 41 26 56 83 40 80 70 33
      41 48 72 33 47 32 37 16 94 29
     53 71 44 65 25 43 91 52 97 51 14
    70 11 33 28 77 73 17 78 39 68 17 57
   91 71 52 38 17 14 91 43 58 50 27 29 48
  63 66 04 68 89 53 67 30 73 16 69 87 40 31
 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 
 By starting at the top of the triangle below and moving to adjacent numbers
 on the row below the maximum total from top to bottom is ?
 */

#include <iostream>
#include <fstream>

#define DEMO_SIZE 4
#define PROBLEM_SIZE 15

#define SIZE PROBLEM_SIZE

int n[PROBLEM_SIZE][PROBLEM_SIZE] =
{
    75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    95,64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    17,47,82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    18,35,87,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    20, 4,82,47,65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    19, 1,23,75, 3,34, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    88, 2,77,73, 7,63,67, 0, 0, 0, 0, 0, 0, 0, 0,
    99,65, 4,28, 6,16,70,92, 0, 0, 0, 0, 0, 0, 0,
    41,41,26,56,83,40,80,70,33, 0, 0, 0, 0, 0, 0,
    41,48,72,33,47,32,37,16,94,29, 0, 0, 0, 0, 0,
    53,71,44,65,25,43,91,52,97,51,14, 0, 0, 0, 0,
    70,11,33,28,77,73,17,78,39,68,17,57, 0, 0, 0,
    91,71,52,38,17,14,91,43,58,50,27,29,48, 0, 0,
    63,66, 4,68,89,53,67,30,73,16,69,87,40,31, 0,
     4,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23,
};

int v[DEMO_SIZE][DEMO_SIZE]=
{
    3,0,0,0,
    7,4,0,0,
    2,4,6,0,
    8,5,9,3
};

int Sum(int arr[], int size)
{
    int sum = 0;

    for (auto i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void InitPath(int arrOut[], int arrPath[], int arrVals[][SIZE])
{
    for (unsigned i = 0; i < SIZE; i++)
    {
        arrOut[i] = arrVals[i][arrPath[i]];
    }
}

int main(void)
{
    int path[SIZE] = {0};
    bool was_changed[SIZE] = {0};
    int max = 0;
    int routes = 0;

  std::ofstream myfile;
  myfile.open ("out.txt");

    while (path[0] == 0)
    {
        int out[SIZE];
        InitPath(out, path, n);

        // if (max < Sum(out, SIZE))
        // {
        //     max = Sum(out, SIZE);
        //     std::cout << max << std::endl;
        // }

        for (auto i = 0; i < SIZE; i++)
        {
            myfile << path[i] << " ";
        }

        myfile << std::endl;
        routes++;

        for (auto j = SIZE - 1; j >= 0; j--)
        {
            if (was_changed[j] == false)
            {
                // if (((path[j] + 1) - path[j - 1]) > 1)
                // {
                //     was_changed[j] = false;
                //     path[j]--;
                // }
                // else
                // {
                    was_changed[j] = true;

                    if (path[j] == 0)
                    {
                        for (auto k = j + 1; k < SIZE; k++)
                        {
                            path[k] = 1;
                        }
                    }

                    path[j]++;
                    break;
                // }
            }
            else
            {
                was_changed[j] = false;
            }
        }
    }

    std::cout << routes;
    myfile.close();

    return 0;
}

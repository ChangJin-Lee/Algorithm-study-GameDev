#include <iostream> 
#include <string>
#define FastCPP ios::sync_with_stdio(NULL), cin.tie(0);

using namespace std; 

int map [9][9] = {0, };

bool isFinished()
{
    for(int y = 0; y < 9; ++y)
    {
        for(int x = 0; x < 9; ++x)
        {
            if (map[y][x] == 0) return 0;
        }
    }

    return 1;
}

bool isSudoku(int y, int x, int num)
{
    // check horizontal, vertical numbers 
    for (int idx = 0; idx < 9; ++idx)
    {
        if (map[y][idx] == num) return 0;
        if (map[idx][x] == num) return 0;
    }

    // sArr[(x / 3) * 3 + y / 3]
    int xbox = x / 3 * 3;
    int ybox = y / 3 * 3;

    // check 3 x 3 box 
    for (int yi = ybox; yi < ybox + 3; ++yi)
    {
        for (int xi = xbox; xi < xbox + 3; ++xi)
        {
            if (map[yi][xi] == num) return 0;
        }
    }

    return 1;
}



// idx. y, x
bool sudoku(int y)
{
    for (int yi = y; yi < 9; ++yi)
    {
        for (int xi = 0; xi < 9; ++xi)
        {
            if(map[yi][xi] != 0) continue;

            for (int num = 1; num <= 9; ++num)
            {
                if (isSudoku(yi, xi, num))
                {
                    map[yi][xi] = num;
                    sudoku(yi);
                    if (isFinished()) return 0;

                    map[yi][xi] = 0;
                }
            }
            return 0;
        }
    }
    return 1;
}



int main()
{
    FastCPP;
    for(int y = 0; y < 9; ++y)
    {
        string nums;
        cin >> nums;

        for(int x = 0; x < 9; ++x)
        {
            map[y][x] = nums[x] - '0';
        }
    }

    sudoku(0);
    
    for(int y = 0; y < 9; ++y)
    {
        for(int x = 0; x < 9; ++x)
        {
            cout << map[y][x];
        }
        cout << '\n';
    }

    return 0;
}

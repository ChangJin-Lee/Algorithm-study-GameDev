// header file 'iostream' and header file 'cstdio' have different file memories 
// `<iostream>` is part of C++ and provides a more modern and flexible approach to input/output through the stream concept.
// `<cstdio>` is part of the C Standard Library and offers traditional C-style input/output using functions.

// #include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int WordChecker (char n []);

int main()
{
    int words = 0;
    
    // string input;
    char input[100]; 
    int count = 0;

    // cin >> words;
    scanf("%d", &words);

   for(int i = 0; i < words; i++)
   {
        // cin >> input;
        scanf("%s", input);
        
        count += WordChecker(input);
   }

    // cout << count;
    printf("%d", count);

    return 0;
}

int WordChecker(char n [])
{
    // reset array to false
    bool arr [26] = {false};

    // int length = n.length();
    int length = strlen(n);

    for(int i = 0; i < length; i++)
    {
        if((i > 0) && (n[i] == n[i-1]))
        {
            arr[n[i]-'a'] = true;
            continue;
        }

        if(arr[n[i]-'a'] == true)
        {
            return 0; 
        }
  
        arr[n[i]-'a'] = true;
    }

    return 1;
}

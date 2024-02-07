#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    int prev;
    int next;
};


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    /*list<int> myList;
    list<int>::iterator iter = myList.begin();

    string command = "";
    int stationNumber, station, constructionCount = 0;

    cin >> stationNumber >> constructionCount;

    while(stationNumber--)
    {
        cin >> station;

        myList.push_back(station);
    }

    while(constructionCount--)
    {
        cin >> command;
        cin >> stationNumber;

        while(*iter != stationNumber)
        {
            if(iter == myList.end())
            {
                iter = myList.begin();
            }
            else
            {
                iter++;
            }
        }
        
        if(command == "BN") // print next station number and add new station front
        {
            cin >> station;

            if(*iter == myList.back())
            {
                iter = myList.begin();
            }
            else
            {
                ++iter;
            }

            cout << *iter << '\n';
            iter = myList.insert(iter, station);

        }
        else if(command == "BP") // print previous station number and add new station after 
        {
            cin >> station;

            if(*iter == myList.front())
            {
                iter = myList.end();
            }
            else
            {
                --iter;
            }

            cout << *iter << '\n';
            ++iter;
            iter = myList.insert(iter, station);
        }
        else if(command == "CP") // delete next station and print the deleted station number 
        {
            if(*iter == myList.front())
            {
                iter = myList.end();
            }
            else
            {
                --iter;
            }

            cout << *iter << '\n';
            iter = myList.erase(iter);
        }
        else if(command == "CN") // delete previous station and print the deleted station number 
        {
            if(*iter == myList.back())
            {
                iter = myList.begin();
            }
            else
            {
                ++iter;
            }

            cout << *iter << '\n';
            iter = myList.erase(iter);
        }
    }

    myList.clear();*/

    vector<node> myList(1000001);
    vector<int> stations; 

    int stationNumber, station, constructionCount = 0;
    int head, tail, prevNum = 0;


    string command = "";

    cin >> stationNumber >> constructionCount;

    for(int idx = 0; idx < stationNumber; idx++)
    {
        cin >> station;

        if(idx == 0)
        {
            head = station;
        }
        else if(idx == stationNumber - 1)
        {
            tail = station;
        }
        
        // set prev as previous station number 
        myList[station].prev = prevNum;
        // leave next
        myList[station].next = 0;

        // set prev station's next as current number 
        myList[prevNum].next = station;
        // set prevNumber as station 
        prevNum = station;
    }

    // connect head and tail 
    myList[head].prev = tail;
    myList[tail].next = head;

    while(constructionCount--)
    {
        cin >> command;
        cin >> stationNumber;
        
        if(command == "BN") // print next station number and add new station after
        {
            // new station 
            cin >> station;

            cout << myList[stationNumber].next << '\n';

            // new station's next is current staion's next 
            myList[station].next = myList[stationNumber].next;
            // new stations' prev is current station
            myList[station].prev = stationNumber;
            // current station's next -> prev is new station 
            myList[myList[stationNumber].next].prev = station;
            // current station's next is new station
            myList[stationNumber].next = station;

        }
        else if(command == "BP") // print previous station number and add new station front 
        {
            // new station 
            cin >> station;

            cout << myList[stationNumber].prev << '\n';
            
            // new station's next is current station
            myList[station].next = stationNumber;
            // new station's prev is current station's prev 
            myList[station].prev = myList[stationNumber].prev;
            // current station's prev -> next is new station 
            myList[myList[stationNumber].prev].next = station;
            // current station's prev is new station
            myList[stationNumber].prev = station;
        }
        else if(command == "CN") // delete next station and print the deleted station number 
        {
            cout << myList[stationNumber].next << '\n';

            // next -> next -> station's prev = current station
            myList[myList[myList[stationNumber].next].next].prev = stationNumber;
            // current station's next = next -> next station
            myList[stationNumber].next = myList[myList[stationNumber].next].next;
        }
        else if(command == "CP") // delete previous station and print the deleted station number 
        {
            cout << myList[stationNumber].prev << '\n';
            
            // prev -> prev -> station's next = current station
            myList[myList[myList[stationNumber].prev].prev].next = stationNumber;
            // current station's prev = prev -> prev station
            myList[stationNumber].prev = myList[myList[stationNumber].prev].prev;

        }
    }
    return 0;
}

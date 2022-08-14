#include<cstdio>
#include<string>
#include<fstream>
#include<iostream>
#include"mulsys.h"
#include<ctime>

using namespace std;

bool load(short array[4]){
    printf("loading...\n");
    string line; //load
    ifstream file (".\\progress");
    if (file.is_open())  //process file
    {
        uint8_t tmp = 0;
        while (getline(file, line)) //process file by line
        {
            if(line != "")
            {
                array[tmp] = stoi(line);
                tmp++;
            }
        }
        file.close();
        printf("ok\n");
        clearscr();
        return true;
    }
    else if(!(file.is_open()))
    {
        printf("\n !!ERROR!! Can't find progress file!\n Please check if you move file called \"progress\" or renamed.\n");
        printf(" Notice that even from \"progress\" rename to \"progress.txt\" do count as rename.\n");
        printf(" If you can\'t find progress file, please go to where you download and download again.\n And unfortunately your original tree have been lost, you'll grow a new tree.\n");
        wincmd("pause>nul");
        return false;
    }
}
void write(short array[4]){
    ofstream myfile ("progress");
    if (myfile.is_open())
    {
        for (uint8_t re = 0; re < 4; re++)
        {
            myfile << array[re] << endl;
        }
        myfile.close();
    }
}

int main()
{
    short storage[4] = {load(storage)}; // 0 = tree now, 1 = user have, 2 = grow need, 3 = day
    string in; 
    bool run = true;

    if(load(storage))
    {
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        uint8_t daynow = (now->tm_mday);
        
        if(storage[0] % 15 == 0 && storage[3] != daynow)
            storage[2]++;
        
        if (daynow - storage[3] <= 31)
        {
            printf("\"grow\" to grow your tree | \"loremipsum\" to get a drip of water. | \"esc\" to exit\n\n Your tree is now %dmm high,\n Which is %.1fcm high.\n You have now %d drip of water,\n And your tree need %d drip of water to grow.\n ", storage[0], storage[0] / 10.0, storage[1], storage[2]);
            
            while (run)
            {
                cin >> in;

                if (in == "grow")
                {
                    if(storage[1] - storage[2] >= 0)
                    {
                        if (daynow != storage[3])
                        {
                            storage[0] ++;
                            storage[1] -= storage[2];
                            storage[3] = now->tm_mday;
                            clearscr();
                            printf("\"grow\" to grow your tree | \"loremipsum\" to get a drip of water. | \"esc\" to exit\n\n Your tree is now %dmm high,\n Which is %.1fcm high.\n You have now %d drip of water,\n And your tree need %d drip of water to grow.\n ", storage[0], storage[0] / 10.0, storage[1], storage[2]);
                        }
                        else
                        {
                            printf(" Your tree have been growed today! Please wait for a day!\n ");
                        }
                    }
                    else
                        printf(" You don't have enough water. Type \"loremipsum\" to get a drip of water.\n ");
                }
                if (in == "loremipsum")
                {
                    storage[1] ++;

                    clearscr();
                    printf("\"grow\" to grow your tree | \"loremipsum\" to get a drip of water. | \"esc\" to exit\n\n Your tree is now %dmm high,\n Which is %.1fcm high.\n You have now %d drip of water,\n And your tree need %d drip of water to grow.\n ", storage[0], storage[0] / 10.0, storage[1], storage[2]);
                }
                if (in == "loremipsumdolorsitelit")
                {
                    storage[1] ++;
                    storage[1] ++;

                    clearscr();
                    printf("\"grow\" to grow your tree | \"loremipsum\" to get a drip of water. | \"esc\" to exit\n\n Your tree is now %dmm high,\n Which is %.1fcm high.\n You have now %d drip of water,\n And your tree need %d drip of water to grow.\n ", storage[0], storage[0] / 10.0, storage[1], storage[2]);
                }
                if (in == "esc")
                {
                    run = !run;
                }
                write(storage);
            }
        }
        else
        {
            printf("\n\n You've forgot to take care your tree for %d days,\n And sadly your tree passed away.\n Enter RIP to replant a tree and promise that you'll not gonna leave your tree alone over 31 days.\n\n ", (now->tm_mday) - storage[3]);
            cin >> in;
            if(in == "RIP" || in == "rip" || in == "Sorry" || in == "sorry" || in == "Promise")
            {
                short a[4] = { 1, storage[1], 1, daynow };
                write(a);
                for (short re = 0; re < 4; re++)
                {
                    storage[re] = a[re];
                }
                

                printf(" OK, here you go.\n *Plants a new tree*\n Take care!\n Press space to close this window. You can manually open this game by your self or reboot your computer.");
                wincmd("pause>nul");
            }
        }

        if(daynow % 5 == 0 && storage[3] != daynow)
            storage[1] += 3;
        
        storage[3] = daynow;
        write(storage);
        printf("\n Saved.");
    }

    return 0;   
}

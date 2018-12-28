#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

class intro  // The introduction of the game.
{
private:
    string playersName;
    
    
public:
    void showIntro(string playersName);
    void showHelp();
    string getName();
    
};

string intro::getName() //Getting to know the player.
{
    cout << "Hello student, please enter your name: ";
    getline(cin, playersName);
    
    return playersName;
}


void intro::showIntro(string playersName) // This function will show the instructions and rules to the player.
{
    cout << "\n\nHi " << playersName << ", congratulations and welcome to Centralia College, Home of the Blazers." << endl;
    cout << "Before you go to your first class, you have a couple of tasks to complete." << endl;
    cout << "\n**********Your task**********" << endl;
    cout << "\n1: Buy 2 Books from the bookstore" << endl;
    cout << "2: Say hi to a couple of friends." << endl;
    cout << "3: Go to class in WSC" << endl;
    cout << "4: Get out of class" << endl;
    cout << "5: Say good-bye to your friends." << endl;
    cout << "5: Return 1 book to the bookstore" << endl;
    cout << "6: Head back to the parking lot" << endl;
    cout << "7: Drive home" << endl;
    
    cout << "\n  **********RULES**********" << endl;
    cout << "\n\nYou will move your way around campus and on the road with these keys:" << endl;
    cout << "(N)orth, (E)ast, (S)outh, (W)est, (P)ause, (I)nventory to see what you may have." << endl;    // The user has to use N,E,W,S,I,P to move and look and puase.
    cout << "\nFortunately, I will display the areas you can go though and provide you enough money to go buy your accesories." << endl;
    cout << "Also, throughout the game, you will always be facing north. Ex: left = (W)est, right = (E)ast" << endl;
    
}

void intro::showHelp() // This will show the user any help if they get stuck in the game.
{
    cout << "\n**********Your task**********" << endl;
    cout << "\n1: Buy 2 Books from the bookstore" << endl;
    cout << "2: Say hi to a couple of friends." << endl;
    cout << "3: Go to class in WSC" << endl;
    cout << "4: Get out of class" << endl;
    cout << "5: Say good-bye to your friends." << endl;
    cout << "5: Return 1 book to the bookstore" << endl;
    cout << "6: Head back to the parking lot" << endl;
    cout << "7: Drive home" << endl;
    
    cout << "\n  **********RULES**********" << endl;
    cout << "\n\nYou will move your way around campus with these keys:" << endl;
    cout << "(N)orth, (E)ast, (S)outh, (W)est, (P)ause, (I)nventory to see what you may have." << endl;    // The user has to use N,E,W,S,I,P to move and look and puase.
    cout << "\nFortunately, I will display the areas you can go though and provide you enough money to go buy your accesories." << endl;
    cout << "Also, throughout the game, you will always be facing north. Ex: left = (W)est, right = (E)ast" << endl;
}




class frontCover // This is really called the menu but I called it frontcover.
{
public:
    char showMenu(string);
    
};

char frontCover::showMenu(string playersName) //The Menu that appears first when playing the game.
{
    char response;
    
    cout << "\n			***** Menu *****" << endl;
    cout << "\n(N)ew Game" << endl;
    cout << "(Q)uit Game" << endl;
    
    cin >> response;
    
    return response;
}


class bookstore
{
private:
    string bookChoice_1;  //Book numbers one
    string bookChoice_2;  //Boke number two
    int bookChoice;
public:
    int numBooks;		// The number of books the user has.
    
public:
    char whereToGoBookStore(string); //The function to where the user will want to go.
    int buyBook(int, int);
    int sellBook(string, string, int, int);
    
};


char bookstore::whereToGoBookStore(string playersName) // Asks the user which they want to go in the bookstore
{
    char response;
    
    cout << "\nTo buy a book, go foward." << endl;
    cout << "To return a book, turn around." << endl;
    cout << "To get out, go right " << endl;
    cout << "Which way do you want to go " << playersName << "?" << endl;
    cin >> response;
    
    
    
    return response;
}

int bookstore::buyBook(int money, int bookChoice)  // To buy a book and return the value of money the user will have left.
{
    
    int response;
    cout << "Now you have the choice of picking the books you want." << endl;
    cout << "Would you like to buy (1 or 2) books?" << endl;
    cin >> response;
    
    if (response == 1) // The price of one book.
    {
        cout << "That book will cost you $35." << endl;
        money = money - 35;
        bookChoice += 1;
        
        return money;
        
    }
    
    else if (response == 2) // The price of two books.
    {
        cout << "Your total cost will be $65." << endl;
        money = money - 65;
        bookChoice += 2;
        return money;
    }
    
    return money;
    
}

int bookstore::sellBook(string bookChoice_1, string bookChoice_2, int bookChoice, int money) // The seller will sell a book.
{
    int bookName;
    
    cout << "It looks like you are returning your book." << endl;
    cout << "Which book (1 or 2) do you want to sell?" << endl;
    cin >> bookName;
    
    if (bookName == 1) // Selling book one.
    {
        money = money + 35;
        
        bookChoice -= 1;
        
        if (money > 100)
        {
            cout << " Sorry, you cannot sell more than what you had. " << endl;
        }
        
        return money;
    }
    
    else { // Selling both books.
        
        money = money + 65;
        
        bookChoice -= 2;
        
        if (money > 100)
        {
            cout << " Sorry, you cannot sell more than what you had. " << endl;
        }
        
        return money;
    }
    
}


class wsc		// This is where the student will be if he or she goes to the right from the plaza.
{
    
public:
    char whereToGoWSC(string);
    
};

char wsc::whereToGoWSC(string playersName)
{
    char response;
    cout << "Your class is in front of you and the plaza is to the left you as well." << endl;
    cout << "Where would you like to go " << playersName << "?" << endl;
    cin >> response;
    
    return response;
}



class classes
{
private:
    
public:
    char whereToGoClasses(string);
    int thingsToDoClasses(string);
    
};


char classes::whereToGoClasses(string playersName) // This will tell the student where to go while in the WSC, but not in the classroom
{
    char response;
    
    cout << "You can go back to get to the WSC hallway/building." << endl;
    cin >> response;
    
    return response;
    
}

int classes::thingsToDoClasses(string playersName)		// This describes the classroom in the WSC.
{
    int answer;
    
    cout << "\nYou are now in class and your math professor comes to the class and asks everyone to do a one math probelm up on the board." << endl;
    cout << "He said, You can only leave this class if you get it right. If you get it wrong, this sentence will repeat itself." << endl;
    cout << "\n\nThe math problem is,((4*15)/2 + 3*4)/ 2" << endl;
    
    cin >> answer;
    
    return answer;
}



class parkingLot   // This is where the user will begin the game. Once the player is done with his or her tasks, they will come back here.
{
    
private:
    
public:
    char whereToGoParkingLot(string);
    
};

char parkingLot::whereToGoParkingLot(string playersName)
{
    char response;
    
    cout << "\nIn this parking lot you have one option to go somewhere and that will be going forward to start in the Plaza." << endl;
    
    cin >> response;
    
    return response;
}



class plaza // This is the middle of the campus and the text adventure.
{
private:
    
public:
    char whereToGoPlaza(string);    //This will guide the players on where he or she would like to go. It will return a char, so I can track where they want to go.
};

char plaza::whereToGoPlaza(string playersName)
{
    char response;
    
    cout << "\nYou have three options to move from this lovely plaza point. You can go back to the parking lot, left to the bookstore, and/or the right to the WSC building." << endl;
    
    cin >> response;
    
    return response;
}



class inventory
{
    
public:
    int inventoryStuff(int, int, string);
};

int inventory::inventoryStuff(int money, int bookChoice, string playersName)
{
    
    char back;
    
    cout << "Players Name: " << playersName << endl;			// This will show the players name.
    cout << "\nPlayers money account: $" << money << endl;		// This will show the m=palyers money amount.
    cout << "Number of books: " << bookChoice << endl;			// This will show the players number of books he or she has.
    cout << "\n\nOnce your done looking at your inventory, push (b)ack." << endl;
    
    cin >> back;
    
    return back;
}


class pause
{
    
public:
    char showPause();
};

char pause::showPause()
{
    char response;
    
    cout << "*****Pause******" << endl;	// I made apasue class becuase I wanted to gice the play the opportunity to seek help or quit once they are done.
    cout << "(R)esume" << endl;
    //cout << "(S)ave" << endl;		// I couldnt do save because my macbook was acking weird about it.
    cout << "(H)elp" << endl;
    cout << "(M)enu" << endl;
    
    cin >> response;
    
    return response;
}



/*class load																	 // This load function will not work because I will not have a save class.
 {
 private:
 
 public:
	int loadMoney(int);
	int loadBookChoice(int);
 
 };
 
 int load::loadMoney(int money_saved)   // This will return the money that the user had before.
 {
	int money = money_saved;
 
	return money;
 }
 
 int load::loadBookChoice(int bookChoice_saved) // This will return the money that the user will return.
 {
	int bookChoice = bookChoice_saved;
 
	return bookChoice;
 }
 
 

class save // Once the main calls save, the save will keep everything in the the saved members.
{
    
private:
    int money_saved;
    
public:
    int saveMoney(int);
    int saveBookChoice(int);
};

int save::saveMoney(int money)      // The money will be saved into the money_saved folder.
{
    int money_saved = money;
    
    return money_saved;
}

int save::saveBookChoice(int bookChoice) // The books will be save into the bookChoice_saved folder.
{
    int bookChoice_saved = bookChoice;
    
    return bookChoice_saved;
}

*/

class room   //Describes all the rooms in the game.
{
    
private:
    string m_roomName;
    string m_roomType;
    
public:
    void changeRoom(string roomName);
    void changeScript(string roomType);
    
    void displayRoomName();
    void displayRoomScript();
    
};

void room::changeRoom(string newRoomName)
{
    m_roomName = newRoomName;
}

void room::changeScript(string newRoomType)
{
    m_roomType = newRoomType;
}

void room::displayRoomName()
{
    cout << m_roomName << endl;
}

void room::displayRoomScript()
{
    cout << m_roomType << endl;
}

int main()
{
    
    
    string playersName;     //Players Name*****************************
    int money = 100;        //The player will start with $100.***********************************
    char toGo;              //This will track the players doings*****************************
    string bookChoice_1;    //Book numbers one
    string bookChoice_2;    //Boke number two
    int bookChoice = 0;		// This will keep track of how many books the user has.******************************
    string quitAnswer;		// If the user wants to quit the program.
    int answer = 0;         // Math question to move on
    
    intro begin;			// these are the classes I ahve.
    frontCover menu;
    parkingLot parking;
    room rooms[5];		// There will be about 5 rooms in this game.
    bookstore bookStore;
    wsc waltonScienceCenter;
    classes school;
    inventory pockets;
    pause pause;
    plaza center;
    
    
    playersName = begin.getName();
    
menu:
    
    toGo = menu.showMenu(playersName);		// This will show the main menu for the player if they want to play or quit.
    
    switch (toGo)
    {
        case 'q': goto quit;		 // If they quit, they will be directed to the quit option on the bottom of this code.
        case 'Q': goto quit;
    }
    
    
    begin.showIntro(playersName);  // This is where all the information about the game is shown.
    
    do {
    parking_lot_1:
        
        rooms[4].changeRoom("\n****Parking Lot****");
        rooms[4].displayRoomName();
        rooms[4].changeScript("\nYou have just arrived at Centralia College in the busy parking lot at 7:30 in the morning next to Kemp Hall.");
        //rooms[4].displayRoomScript();
        
        
        toGo = parking.whereToGoParkingLot(playersName); // I am creating the direction after parking lot. make going west.
        
        switch (toGo)
        {
            case 'n': goto plaza;		 // If the players goes north, than they will head to the plaza.
                
        }
        
        if (toGo == 'i')		// This will show the inventory that the player will have.
        {
            toGo = pockets.inventoryStuff(money, bookChoice, playersName);
            
            if (toGo == 'b') // If the player wants to go back, they can go back by pushing b.
            {
                goto parking_lot_1;
            }
        }
        
        else if (toGo == 'p')		// This will show the pause menu for the player
        {
            toGo = pause.showPause();
            
            switch (toGo) // This will show the options that the puase menu will have.
            {
                case 'r': goto parking_lot_1;
                case 'm': goto menu;
                case 'h': begin.showHelp(); goto parking_lot_1;
                    //case 's': money_saved = saved.saveMoney(money), bookChoice_saved = saved.saveBookChoice(bookChoice);
            }
            
            goto parking_lot_1;
        }
        
    } while (toGo == 'e' || toGo == 'w');
    
    //********************************************************Everything from up top is the same on the bottom for comments. So I will comment on the major things now, not the same as before.
    do {
        
    wsc:
        
        
        rooms[1].changeRoom("\n****WSC****");
        rooms[1].displayRoomName();
        rooms[1].changeScript("\nYou have just entered the Walton Science Center. There are classes all along the hallways and countless students.\n");
        rooms[1].displayRoomScript();
        
        toGo = waltonScienceCenter.whereToGoWSC(playersName);
        
        switch (toGo)
        {
            case 'n': goto classes;
            case 'w': goto plaza;
        }
        if (toGo == 'i' || toGo == 'I')
        {
            toGo = pockets.inventoryStuff(money, bookChoice, playersName);
            
            if (toGo == 'b' || toGo == 'B')
            {
                goto wsc;
            }
        }
        
        else if (toGo == 'p' || toGo == 'P')
        {
            toGo = pause.showPause();
            
            switch (toGo)
            {
                case 'r': goto wsc;
                case 'm': goto menu;
                case 'h': begin.showHelp(); goto wsc;
            }
            
            goto wsc;
        }
        
        
    } while (toGo == 'S' || toGo == 's' || toGo == 'e');
    
bookstore:
    
    rooms[2].changeRoom("\n****Bookstore****");
    //rooms[2].displayRoomName();
    rooms[2].changeScript("\nYou have just enterd the bookstore. If you look to the right, you will see a couple of student scavenging last second books for their classes.\nOn your left, you see a cashier being overwhelmed by the everlasting line of impatient students who bought the wrong books.\n");
    rooms[2].displayRoomScript();

store:
    toGo = bookStore.whereToGoBookStore(playersName);
    
    if (toGo == 'N' || toGo == 'n')
    {
        money = bookStore.buyBook(money, bookChoice);    // This is where the student will buy there books
        if (money == 65)		// If the amount of this money is left, that means the student only bought one book.
        {
            cout << "\nYou successfullu bought 1 book." << endl;
            bookChoice += 1;
            
        }
        else if (money == 35)
        {
            cout << "\nYou successfully bought 2 books." << endl;
            bookChoice += 2;  // Otherwise, the studnet bought 2 books.
        }
        
        else if (money < 0)
        {
            cout << "Sorry, you can't afford that. Maybe try selling a couple of your books." << endl;
            
            goto bookstore;
        }
    }
    
    if (toGo == 's' || toGo == 'S')
    {
        money = bookStore.sellBook(bookChoice_1, bookChoice_2, bookChoice, money);		// This is where the student will return one of the books.
        if (money == 70)
        {
            bookChoice -= 1;			// If the money amount has that much, that the player will 1 bookChoice Otherwise 2 bookChoice
        }
        
        else
        {
            bookChoice -= 2;
        }
    }
    
    
    if (toGo == 'e' || toGo == 'E')
    {
        goto plaza;
    }
    
    else if (toGo == 'i' || toGo == 'I')
    {
        toGo = pockets.inventoryStuff(money, bookChoice, playersName);
    }
    else if (toGo == 'b' || toGo == 'B')
    {
        goto bookstore;
    }
    
    else if (toGo == 'p' || toGo == 'P')
    {
        toGo = pause.showPause();
        
        switch (toGo)
        {
            case 'r': goto bookstore;
            case 'm': goto menu;
            case 'h': begin.showHelp(); goto bookstore;
            //case 's': money_saved = saved.saveMoney(money), bookChoice_saved = saved.saveBookChoice(bookChoice);
                //case 's': goto save;
        }
    }
    
    goto store;
    
    
    
    do {
    classes:
        
        rooms[0].changeRoom("\n****classes****");
        rooms[0].displayRoomName();
        rooms[0].changeScript("\nYou have entered your class.\nWhat you see here is a huge open auditorium with 32 students sitting randomly in the different rows of seats.");
        rooms[0].displayRoomScript();
        
        do {
            answer = school.thingsToDoClasses(playersName);
        } while (answer != 21 || answer == 'i' || answer == 'b' || answer == 's');
        
        toGo = school.whereToGoClasses(playersName);
        switch (toGo)
        {
            case 's': goto wsc;
                
        }
        
        if (toGo == 'i')
        {
            toGo = pockets.inventoryStuff(money, bookChoice, playersName);
            
            if (toGo == 'b')
            {
                goto classes;
            }
        }
        
        else if (toGo == 'p')
        {
            toGo = pause.showPause();
            
            switch (toGo)
            {
                case 'r': goto classes;
                case 'm': goto menu;
                case 'h': begin.showHelp(); goto classes;
            }
            
            goto classes;
        }
        
        
        
    } while (toGo == 'e' && toGo == 'w' && toGo == 'n');
    
    do {
    plaza:
        
        rooms[3].changeRoom("\n****Plaza****");
        rooms[3].displayRoomName();
        rooms[3].changeScript("\nYou are in the middle of the campus right here. This is where the flowers bloom to their fullest with brilliant colors of Spring.");
        rooms[3].displayRoomScript();
        
        toGo = center.whereToGoPlaza(playersName);
        
        switch (toGo)
        {
            case 'e': goto wsc;
            case 'w': goto bookstore;
            case 's': goto finishedGame;
        }
        
        if (toGo == 'i' || toGo == 'I')
        {
            toGo = pockets.inventoryStuff(money, bookChoice, playersName);
            
            if (toGo == 'b')
            {
                goto plaza;
            }
        }
        
        else if (toGo == 'p')
        {
            toGo = pause.showPause();
            
            switch (toGo)
            {
                case 'r': goto plaza;
                case 'm': goto menu;
                case 'h': begin.showHelp(); goto plaza;
                    //case 's': money_saved = saved.saveMoney(money), bookChoice_saved = saved.saveBookChoice(bookChoice);
            }
            
            goto plaza;
        }
    } while (toGo == 'n' || toGo == 'N');
    
finishedGame:
    if (answer == 21 && bookChoice == 1) // If the player inventory matches these integers, than the player can beat the game.
    {
        cout << "Congratulations! You have completed all the tasks!" << endl;
        return 0;
    }
    
    else
    {
        string response;
        
        cout << "\n\nYou cannot finish this game unless you complete all tasks." << endl;
        cout << "\nPush (b) to go back." << endl;
        cin >> response;
        
        goto plaza;
    }
    
    ////////////////////////I tried to save my game but my macbook has some kind of feature where it wouldn't let me access the files.
    
    
    /*Save:
     
     
     string fileName;		// This will save the filename of what the user wants it to be.
     int moneySave = money;			// This will save the amount of money the user will have.
     char toGoSave = toGo;			// This will save the locationt he user is at.
     int bookChoiceSave = bookChoice;		// This will save the number of books the user has.
     ofstream saveData;
     ifstream takeData;
     takeData.open("Data.dat");
     takeData >> fileName;
     takeData.close();
     cout << "What will you file name be: " << fileName;
     cout << "\nWhat is your file name?";
     cin >> fileName;
     saveData.open("data.dat");
     saveData << fileName;
     saveData << moneySave;
     saveData << toGoSave;
     saveData << bookChoiceSave;	
     saveData.close();
     
     
     load:
     
     cout << "You have successfuly loaded your game." << endl;
     
     int money = moneySave;
     int bookChoice = bookChoiceSave;
     char toGo = toGoSave;
     
     goto plaza;
     
     */
    
    
    
    
quit:
    
    cout << "Are you sure you want to quit?" << endl; // If the player goes to pause and menu then a quit this will appear and will give the player the option to quit.
    cin >> quitAnswer;
    
    if (quitAnswer != "no")
    {
        return 0;  // The program will be executed.
    }
    else
    {
        goto menu;
    }
}

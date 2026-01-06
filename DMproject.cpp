#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
//this portion calculates factorial which will be further used in the program
long long factorial(int number){
    long long result = 1;

    
    for (int i = 1; i <= number; i++)
    {
        result = result * i;
    }

    return result;
}
//this portion calculates probability which will be further used in the program
void Probability(double favorable,double total)
{
    cout << "Favorable Outcomes = " << favorable << endl;
    cout << "Total Outcomes     = " << total << endl;
    double probability = favorable /total;
    cout << "Probability        = " << favorable << " / " << total 
    << " = " << fixed << setprecision(6) << probability << endl;
}

//this portion calculates combinations which will be further used in the program
long long nC2(int n)
{
    return (long long)n * (n - 1) / 2;
}


//this portion calculates the probability of a face card
void probabilityFaceCard()
{
    cout << "\n ****Probability of Drawing a Face Card****"<<endl;
    int favorable = 12;
    int total = 52;

    Probability(favorable, total);
}
//this portion calculates the probability of a sprcific face card
void probabilityofOneFaceCard(string str)
{
    if(str!="jack" && str!="Jack" && str!="joker" && str!="Joker" && str!="king" && str!="King" &&
       str!="queen" && str!="Queen")
        return;

    cout << "\n **** Probability of Drawing " << str << " Card ****" << endl;

    int favorable = 4;
    int total = 52;

    Probability(favorable, total);
}
//this portion calculates the probability of a number card
void probabilityofNumberCard()
{
    cout << "\n ****Probability of Drawing Number Card****"<<endl;
    int favorable = 40;
    int total = 52;

    Probability(favorable, total);
}
//this portion calculates the probability of a single number card
void probabilityofOneFaceCard(int number)
{
    cout << "\n ****Probability of Drawing "<<number<<" Card****"<<endl;
    int favorable = 4;
    int total = 52;

    Probability(favorable, total);
}
//this portion calculates the probability of an ace card
void probabilityofAceCard()
{
    cout << "\n ****Probability of Drawing Ace Card****"<<endl;
    int favorable = 4;
    int total = 52;

    Probability(favorable, total);
}
//this portion calculates the probability of drawing a specific card
void probabilitySpecificCard()
{
    cout << "\n****Probability of Drawing a Specific Card****"<<endl;
    int favorable = 1;
    int total = 52;
    Probability(favorable, total);
}
//this portion calclates the probability of drawing card of a specific suit
void probabilitySpecificSuit()
{
    cout << "\n****Probability of Drawing a Specific Suit****\n";
    int favorable = 13;
    int total = 52;

    Probability(favorable, total);
}
// Probability of NOT drawing an Ace
void probabilityNoAce()
{
    cout << "\n****Probability of NOT Drawing an Ace****"<<endl;

    int favorable = 48; 
    int total = 52;

    Probability(favorable, total);
}
//this portion calculates the probability of two draws of a same card
void probabilityTwoSameRank()
{
    cout << "\n--- Probability of Drawing Two Cards of Same Rank ---\n";
    long long favorable = 13 * nC2(4); 
    long long total = nC2(52);

    Probability(favorable, total);
}


// Probability of drawing one Ace and one non-Ace
void probabilityOneAceOneNonAce()
{
    cout << "\n--- Probability of Drawing One Ace and One Non-Ace ---\n";

    long long favorable = 4 * 48;  
    long long total = nC2(52);      
    Probability(favorable, total);
}

//monte carlo simulation
void simulateAceProbability()
{
    srand(time(0));

    int runs = 100000;
    int count = 0;

    for(int i = 0; i < runs; i++)
    {
        int card = rand() % 52;
        if(card < 4)
        count++;
    }

    cout << "\n****Simulation Result (Ace Probability)****\n";
    cout << "Experimental Probability = "<< (double)count / runs << endl;
}
void simulateFaceCardProbability()
{
    srand(time(0));

    int runs = 100000;
    int count = 0;

    for(int i = 0; i < runs; i++)
    {
        int card = rand() % 52;
        if(card < 12)
            count++;
    }

    cout << "\n****Simulation Result (Face Card Probability)****\n";
    cout << "Experimental Probability = "<< (double)count / runs << endl;
}
void simulateTwoSameRank()
{
    srand(time(0));

    int runs = 100000;
    int count = 0;

    for(int i = 0; i < runs; i++)
    {
        int card1 = rand() % 52;
        int card2 = rand() % 52;
        if(card1 == card2)
        {
            i--;
            continue;
        }
        if(card1 % 13 == card2 % 13)
            count++;
    }

    cout << "\n****Simulation Result (Two Cards Same Rank)****\n";
    cout << "Experimental Probability = "<< (double)count / runs << endl;
}

//this portion calculates the probability of two same cards
void probabilityBothSame ()
{
    cout << "\n****Probability of Drawing Two Same Colored Cards****\n";

    long long favorable = nC2(26) + nC2(26);  // 650
    long long total = nC2(52);                // 1326

    Probability(favorable, total);
}

//main menu
void mainMenu()
{
    cout << "\n**************CARD PROBABILITY SYSTEM *************\n";
    cout << "1. One Card Probability\n";
    cout << "2. Two Card Probability\n";
    cout << "3. Simulation (Experimental Probability)\n";
    cout << "0. Exit\n";
    cout << "*********************************************************\n";
}
//one card menu is created in a menu to shorten the main menu
void oneCardMenu()
{
    cout << "\n***********ONE CARD PROBABILITY**********\n";
    cout << "1. Probability of a face card\n";
    cout << "2. Probability of a specific face card (Jack/Queen/King)\n";
    cout << "3. Probability of a number card\n";
    cout << "4. Probability of a specific number card\n";
    cout << "5. Probability of an Ace\n";
    cout << "6. Probability of a specific card\n";
    cout << "7. Probability of a specific suit\n";
    cout << "8. Probability of NOT drawing an Ace\n";
    cout << "0. Back to Main Menu\n";
    cout << "***************************************************\n";
}
//two card menu is created in a function to shorten the main menu
void twoCardMenu()
{
    cout << "\n*********TWO CARD PROBABILITY**********\n";
    cout << "1. Two cards of same rank\n";
    cout << "2. One Ace and one non-Ace\n";
    cout << "3. Two cards of same color\n";
    cout << "0. Back to Main Menu\n";
    cout << "*******************************************\n";
}

void simulationMenu()
{
    cout << "\n***************SIMULATION MENU*************\n";
    cout << "1. Simulate probability of drawing an Ace Card\n";
    cout << "2. Simulate probability of drawing a Face Card\n";
    cout << "3. Simulate probability of drawing same rank Card\n";
    cout << "0. Back to Main Menu\n";
    cout << "************************************************\n";
}


//THE MAIN FUNCTION
int main()
{
    cout<<"*******WELCOME TO CARD OUTCOME PROBABILITY CALCULATOR*******"<<endl;
    int choice;
    int subchoice = 0;
    while(true)
    {
        mainMenu();
        cout<<"\nPlease enter your choice: ";
        cin >> choice;
        if(choice == 0)
        {
            cout << "Thank you for using the program. Goodbye!\n";
            break;
        }
        switch (choice)
        {
        case 1:
        { 
            while(true)
            {
                oneCardMenu();
                cout << "Enter your choice: ";
                cin >> subchoice;
                if(subchoice == 0)
                {
                    cout << "Byee!! We are returning to Main Menu...\n";
                    break;
                }
                switch(subchoice)
                {
                    case 1: probabilityFaceCard(); break;
                    case 2:
                    {
                        string face;
                        cout << "Enter face card (Jack / Queen / King): ";
                        cin >> face;
                        probabilityofOneFaceCard(face);
                        break;
                    }
                    case 3: probabilityofNumberCard(); break;
                    case 4:
                    {
                        int num;
                        cout << "Enter number card (2-10): ";
                        cin >> num;
                        probabilityofOneFaceCard(num);
                        break;
                    }
                    case 5: probabilityofAceCard(); break;
                    case 6: probabilitySpecificCard(); break;
                    case 7: probabilitySpecificSuit(); break;
                    case 8: probabilityNoAce(); break;
                    default: cout << "OOPS!! Invalid Option\n";
                }
            }
            break;
        }
        case 2:
        {
            while(true)
            {
                twoCardMenu();
                cout << "Enter your choice: ";
                cin >> subchoice;

                if(subchoice == 0)
                {
                    cout << "Byee!! We are returning to Main Menu...\n";
                    break;
                }
                switch(subchoice)
                {
                    case 1: probabilityTwoSameRank(); break;
                    case 2: probabilityOneAceOneNonAce(); break;
                    case 3: probabilityBothSame(); break;
                    default: cout << "OOPS!! Invalid Option\n";
                }
            }
            break;
        }
        case 3:
        {
            while(true)
            {
                simulationMenu();
                cout << "Enter your choice: ";
                cin >> subchoice;

                if(subchoice == 0)
                {
                    cout << "Byee!! We are returning to Main Menu...\n";
                    break;
                }
                switch(subchoice)
                {
                    case 1: simulateAceProbability(); break;
                    case 2: simulateFaceCardProbability(); break;
                    case 3: simulateTwoSameRank(); break;
                    default: cout << "OOPS!! Invalid choice\n";
                }
            }
            break;
        }
        default:
            cout << "Invalid Main Menu Option!\n";
        }
    }
    return 0;
}







   

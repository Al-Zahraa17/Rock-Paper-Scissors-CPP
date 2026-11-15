//course(5)
//Project(1) _ My Solution:

#include <iostream>  
using namespace std;  

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  
}

int NumberOfRounds(){

    int Number;
    cout<<"How many rounds 1 to 10 ? "<<endl;
    cin>>Number;
    return Number;
}

int PlayerChoise(){
int Number;
    do{
        cin>>Number;
    }while(Number>3 || Number<1);
return Number;
}

string Check123(int Number){

    if(Number==1)
        return "Stone";
    else if (Number==2)
        return "Paper";
    else
        return "Scissors";
}

string ComparisonChoices(int Computer,int Player){

    if(Computer == 1 && Player == 3){
        return "[Computer]";}
    else if(Computer == 1 && Player == 2)
        return "[Player]";
        
    else if(Computer == 2 && Player == 1)
        return "[Computer]";
    else if(Computer == 2 && Player == 3)
        return "[Player]";

    else if(Computer == 3 && Player == 1)
        return "[Player]";
    else if(Computer == 2 && Player == 1)
        return "[Computer]";
        
     else if(Computer == 3 && Player == 2)
        return "[Computer]";
    else if(Computer == Player)
        return "[No Winner]";
      
}

void Counter(int& DrawCount,int Computer,int Player,int& counter)
{ 
    if(ComparisonChoices(Computer,Player)=="[Computer]"){
        counter++;}
    else if(ComparisonChoices(Computer,Player)=="[No Winner]"){
        DrawCount++;
    }
}

void ScreenColor(int Computer,int Player){

    if(ComparisonChoices(Computer, Player)=="[Computer]"){
        system("color 4F");}

    else if(ComparisonChoices(Computer, Player)=="[Player]"){
        system("color 2F");}

    else if(ComparisonChoices(Computer, Player)=="[No Winner]"){
        system("color 0E");}

}

void PrintGameOver(){
    cout<<"\t\t\t\t__________________________"<<endl;
    cout<<"\t\t\t\t +++ G a m e  O v e r +++"<<endl;
    cout<<"\t\t\t\t__________________________"<<endl;
}

void PrintAndFreqwency()
{
    system("cls");
    int Computer;
    int Player,Number;
    int counter=0;
    int DrawCount=0;
    Number = NumberOfRounds();
    
    for(int i=1;i<=Number;i++){
        Computer=RandomNumber(1,3);

        cout<<"Your Choise [1]:Stone, [2]:Paper ,[3]:Slcssors ? ";
        Player = PlayerChoise();
        ScreenColor(Computer, Player);
        Counter(DrawCount,Computer,Player, counter);
        cout<<endl;
        cout<<"Round [ "<<i<<" ] beings:"<<endl;
        cout<<"___________ Round [ "<<i<<" ] ___________"<<endl;
        cout<<"Player1 Choise  : "<<Check123(Player)<<endl;
        cout<<"Computer Choise : "<<Check123(Computer)<<endl;
        cout<<"Round Winner    : "<<ComparisonChoices(Computer, Player)<<endl;
        cout<<"___________________________________"<<endl;   
    }
    PrintGameOver();
    cout<<"\t\t\t\t_____[ Game Results ]_____"<<endl;
    cout<<"Game Rounds        : "<<Number<<endl;
    cout<<"Player1 won times  : "<<Number-counter-DrawCount<<endl;
    cout<<"Computer won times : "<<counter<<endl;
    cout<<"Draw times         : "<<DrawCount<<endl;

    if(counter>Number-counter-DrawCount){
        system("color 4F");
        cout<<"\n\t\t\t   [Computer] is the Winner of the Game"<<endl;}
    else if(counter<Number-counter-DrawCount){
        system("color 2F");
        cout<<"\n\t\t\t    [Player1] is the Winner of the Game"<<endl;}
    else{
        system("color 0E");
        cout<<"\n\t\t\t  [No Winner] (Draw) of the Game"<<endl;}
}
int main(){
    srand((unsigned)time(NULL));
    PrintAndFreqwency();
}
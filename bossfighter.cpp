#include <conio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <string.h>


using namespace std;
HANDLE hCon;
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void Col(Color c){
	if(hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}
int keyp,delka=0,i;
int hp=100,block=0,energy=100,dmg=0,wep=0;
int hpb=500,dmgb=15,blockb=15;
int rdmg=dmg-20,rest=0,dps=0,dpsb=0,energyloss=0,impo=0,blockr=0;
 
char zn;    
      
     void instructions()
     {    
          SetConsoleTitle("Instructions");
          system("cls");
          cout << "The goal of this game is to kill a boss. Very simple, isnt it \? \nSimple instructions : \n [1] Attack = deals dmg to the boss, depends on RNG \n [2] Cover  = blocks all dmg thats dealt by the boss this turn\n [3] Rest   = restores energy, next attack dmg is doubled after resting\n\nPress a key to return to menu";
          keyp=getch();       
     }
      void about()
      {    
           SetConsoleTitle("About");           
           system("cls");
           cout << "This is a small testing project made by ";
           Col(GRAY);
           cout << "Adam Brabec ";
           Col(WHITE);
           cout << "\n\nPress a key to return to menu";
           keyp=getch();
      }            
 
 int main()
{     
      srand (time(0));      
      while((keyp!='1') || (keyp!='2') || (keyp!='3'))
      {    
      SetConsoleTitle("Main menu");
      system("cls");
      Col(RED);
      cout << "\n\t\t\t\t BOSSFIGHTER";
      Col(WHITE);
      cout << "\n\n\n [1] Play \n [2] Instructions \n [3] About\n";
      keyp=getch();
           if (keyp=='1') break;
           else if (keyp=='2') instructions();
           else if (keyp=='3')  about();           
           }          
      
      
           
      SetConsoleTitle("BOSSFIGHTER");     
      char text1[100]="Welcome to my lair adventurer!\nUnfortunately,",text2[100]="YOU FACE ME! BIG GLURM!!!",text3[100]="\nFight me or run like coward !";         
      system("cls");
      delka=strlen(text1);
      for (i = 0; i <=delka; i++)
      {
          cout << text1[i];
          Sleep(100);      
          }      
      delka=strlen(text2);
      Col(RED);
      for (i = 0; i <=delka; i++)
      {
          cout << text2[i];
          Sleep(100);      
          }
      Col(WHITE);      
      Sleep(500);
      delka=strlen(text3);
      for (i = 0; i <=delka; i++)
      {
          cout << text3[i];
          Sleep(100);
          }
      cout << "\nPress a key to continue";
      system("PAUSE > NUL");     
      while((keyp!='1') || (keyp!='2'))      
      {            
            system("cls");
            cout << "What would you like to do?";
            cout << "\n[1]   Equip yourself and prepare for a fight";
            cout << "\n[2]   Run away!";
            keyp=getch();
            if (keyp=='2') goto end;
            if (keyp=='1') break;            
            }
            
      while((keyp!='1') || (keyp!='2') || (keyp!='3'))
      {            
            system("cls");
            cout << "What weapon would you like to take?";
            cout << "\nYour curent stats:"; Col(RED); cout << " Health: " << hp; Col(DARKTEAL); cout << " Damage: " << dmg; Col(BLUE); cout << " Block: " << block; Col(YELLOW); cout << " Energy: " << energy; Col(WHITE);cout << "\n\n[1]"; 
            Col(TEAL);
            cout << "\tQuick bow of sea";
            Col(GRAY);
            cout << "\n\tSome say it's a bow of legend that died in sea battle.\n\tOthers say it's just a regular bow";
            Col(WHITE);
            cout << "\n\t+30 damage -5 block +50 energy\n\t10 energy per turn\n\n[2]";
            Col(GREEN);            
            cout << "\tSharp two-handed axe of terror";
            Col(GRAY);
            cout << "\n\tThis axe looks really sharp!";
            Col(WHITE);
            cout << "\n\t+35 damage +5 block +20 energy\n\t15 energy per turn\n\n[3]";
            Col(DARKYELLOW);
            cout << "\tRusty one-handed sword with round shield";
            Col(GRAY);
            cout << "\n\tTime made a significant mark on that sword";
            Col(WHITE);
            cout << "\n\t+15 damage +30 block -20 energy +80 health\n\t 5 energy per turn";
            
            keyp=getch();
            if (keyp=='1') {dmg=dmg+30;block=block- 5;energy=energy+50;wep=1;break;}
            if (keyp=='2') {dmg=dmg+35;block=block+ 5;energy=energy+20;wep=2;break;}
            if (keyp=='3') {dmg=dmg+15;block=block+30;energy=energy-20;hp=hp+80;wep=3;break;}
            }  
            if(wep==1)
            energyloss=10;
            if(wep==2)
            energyloss=15;
            if(wep==3)
            energyloss=5;      
            
      while((keyp!='1') || (keyp!='2') || (keyp!='3'))      
      {            
            system("cls");
            cout << "What armor would you like to wear?";
            cout << "\nYour curent stats:"; Col(RED); cout << " Health: " << hp; Col(DARKTEAL); cout << " Damage:20-" << dmg; Col(BLUE); cout << " Block: " << block; Col(YELLOW); cout << " Energy: " << energy; Col(WHITE);cout << "\n\n[1]"; 
            Col(TEAL);
            cout << "\tFlashing metal chestplate and leggins";
            Col(GRAY);
            cout << "\n\tIt's flashing! That must be a miracle!";
            Col(WHITE);
            cout << "\n\t+5  damage +50 health -10 block +20 energy\n\n[2]";
            Col(GREEN);            
            cout << "\tStinking leather chestplate and leggins";
            Col(GRAY);
            cout << "\n\tThis armor really stinks, better stay away from it... right?";
            Col(WHITE);
            cout << "\n\t+20 damage -30 health +5  block +10 energy\n\n[3]";
            Col(DARKYELLOW);
            cout << "\tLegendary chesplate and leggins";
            Col(GRAY);
            cout << "\n\tArmor that belong to old legend, must have!... or not?";
            Col(WHITE);
            cout << "\n\t+15 damage +80 health -20 block -5 energy";
            
            keyp=getch();
            if (keyp=='1') {dmg=dmg+ 5;block=block-10;energy=energy+20;hp=hp+50;break;}
            if (keyp=='2') {dmg=dmg+20;block=block+5;energy=energy+10;hp=hp-30;break;}
            if (keyp=='3') {dmg=dmg+15;block=block-20;energy=energy-5 ;hp=hp+80;break;}
            }
            blockr=block;                 
      
      while (hpb>0)
      {
            system("cls");
            cout << "Your curent stats:"; Col(RED); cout << " Health: " << hp; Col(DARKTEAL); cout << " Damage:20-" << dmg; Col(BLUE); cout << " Block: " << block << "\%"; Col(YELLOW); cout << " Energy: " << energy; Col(WHITE);
            cout << "\nBoss curent stats:"; Col(RED); cout << " Health: " << hpb; Col(DARKTEAL); cout << " Damage: 5-" << dmgb; Col(BLUE); cout << " Block: " << blockb << "\%"; Col(YELLOW); cout << " Energy: unlimited "; Col(WHITE);
            cout << "\n\n[1] Attack\n\n[2] Cover\n\n[3] Rest\n";
            keyp=getch();
            if (keyp=='1')
            {
                  if(energy>0)
                  {
                           energy=energy-energyloss;
                           dps=rand()%rdmg+20;
                           if(rand()%100<=blockb)
                           {                           
                                  cout <<"\n\n\nYour attack missed.";
                                  Beep(200,400);
                                  Sleep(50);
                                  }                           
                           else
                           {                                  
                               if(rest==1)
                               {
                                   dps=dps*2;
                                   rest=0;
                                   }                        
                               cout << "\n\n\nYour attack did ";
                               Col(RED);
                               cout << dps;
                               Col(WHITE);
                               cout << " points of damage";                               
                               hpb=hpb-dps;
                               if (dps>dmg)
                                {
                                    Col(RED);
                                    cout << "\nIT'S A CRITICAL HIT!";
                                    Col(WHITE);
                                    }
                               Beep(400,800);
                               Sleep(50);                                                  
                               }
                           }
                           else
                           {
                               cout << "\n\nYou can't attack with this low energy";
                               impo=1;
                               }
                           }
                  
            if (keyp=='2') {if(energy>0) {block=block+50;energy=energy-5;}else{cout << "\n\nYou can't block with this low energy";impo=1;}}
            if (keyp=='3') {if(energy<50){rest=1; cout << "You gained";Col(YELLOW); cout << " 50 "; Col(WHITE); cout << "energy points.";energy=energy+50;} else{cout << "\n\nYou may rest only under 50 energy";impo=1;}}
            if(impo==0)
            {
                        dpsb=rand()%dmgb+5;                
                        if(rand()%100<=block) 
                        {                          
                                cout <<"\nBoss attack missed.";
                                Beep(200,400);
                                Sleep(50);
                                cout <<"\nPress a key to continue.";
                                system("PAUSE > NUL");
                                }
                        else
                        {
                            if (rand()%100==1)
                            dpsb=dpsb*2;
                            else
                            {
                                hp=hp-dpsb;                            
                                cout << "\nBoss's attack did ";                            
                                Col(RED);
                                cout << dpsb;
                                Col(WHITE);
                                cout << " points of damage"; 
                                Beep(400,800);
                                Sleep(50);
                                if (dpsb>dmgb)
                                {
                                    Col(RED);
                                    cout << "\nIT'S A CRITICAL HIT!";
                                    Col(WHITE);
                                    }
                                cout <<"\nPress a key to continue.";               
                                system("PAUSE > NUL");
                                }                
                            }
                        if (hp<=0)
                        break;
                        if (hpb<0)
                        {
                           system("cls");
                           cout << "YOU WIN!!!";                           
                           Beep(700,400);Sleep(10);Beep(600,400);Sleep(10);Beep(600,400);Sleep(10);Beep(700,400);
                           system("PAUSE > NUL");
                           return 0;  
                           }      
                        }            
            else
            system("PAUSE > NUL");           
            block=blockr;
            impo=0;
      }
            
    end:
    system("cls");
    cout<<"YOU ARE LOSER!\nGame over";
    Beep(700,400);Sleep(10);Beep(600,400);Sleep(10);Beep(500,400);Sleep(10);Beep(400,400);Sleep(10);Beep(300,400);Sleep(10);Beep(200,400);Sleep(10);Beep(100,400);
    system("PAUSE > NUL");
    return 0;    

}

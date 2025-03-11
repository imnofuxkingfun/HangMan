#include<cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void game_won()
{
    std:: cout<< R"(
    
    *•. ♡  GAME WON! ♡ .•*          

                    you get to live another day....  
    
    )" << '\n';
}

void game_over(char *word)
{
    cout<<"The word was: "<<word;

 std::cout << R"(
 
 
 

            G̵A̵M̸E̷  ̷O̶V̵E̵R̴

        T̴H̶E̵ ̴H̸A̷N̷G̵M̷A̵N̷ ̸G̴O̶T̸ ̸Y̴O̵U̴ ̵

)" << '\n';



}

void draw_man(int nr)
{
    
        cout<<" _____ "<<'\n'<<"|     ⋮"<<'\n'<<"|     ";
        if(nr >= 1) cout<< "0";
        cout<<'\n'<<"|    ";
        if(nr >= 3) cout<<"/";
            else cout<<" ";
        if(nr >= 2) cout<< "|";
        if(nr >= 4) cout<<"\\";
        cout<<'\n'<<"|    ";
        if(nr >= 5) cout<<"/ ";
        if(nr >= 6) cout<<"\\";
        cout<<'\n'<<"|__________";
        
    
    cout<<'\n';
    if(nr == 0) cout<<"No hanged parts yet!"<<'\n';
}

int main()
{   
    //category picking
    srand (time(0));
    int category = rand()%3;
    {    cout<<"-------------------------------------"<<'\n'<<"The category is: ";
    
        if(category==0) cout<<"Colors";
        if(category==1) cout<<"Supernatural beings";
        if(category==2) cout<<"Astronomy terms";
        
        cout<<'\n';
    }   
        
    // word picking
    int rword = rand()%10;
    char word[21];
    if(category==0){
        char colors[][21]={"indigo", "ivory", "peach", "coral","azure", "periwinkle", "mauve", "plum", "viridian", "ultramarine"};
        strcpy(word,colors[rword]);
    }
    
    if(category==1){
        char spn[][21]={"jackalope", "cerberus", "vampire", "banshee", "ghoul", "werewolf", "dragon", "centaur", "selkie", "angel"};
        strcpy(word,spn[rword]);
    }
    
    if(category==2){
        char astronomy[][21]={"celestial", "comet", "crater", "asteroid", "ecliptic", "eclipse", "meteor", "zenith", "constellation", "galaxy"};
        strcpy(word,astronomy[rword]);
    }
    
    
    cout<<"Number of letters: "<<strlen(word)<<'\n';
    
    // guess word creation
    char s[21];
    for(int i = 0; i < strlen(word); i++)
        s[i] = '-';
    s[strlen(word)] = '\0';
    
    int guess = 0;

    cout<<"-------------------------------------"<<'\n'<<"Let the game begin!"<<'\n'<<"-------------------------------------"<<'\n';
    
    char wrong[15];
    for(int i = 0; i < 12; i++)
        if(i%2==0) wrong[i] = '_';
        else wrong[i] = ' ';
    wrong[12] = '\0';
    int w = 0;
    
    while(guess < 6 && strcmp(word,s) != 0)
    { 
        char x;
        cout<<'\n'<<"Guess a letter: ";
        cin>>x;
        
        if(x >= 'a' && x <= 'z'){
        
        if(strchr(word,x) != NULL)                   // yes
        {   cout<<x<<" is in the word :) !"<<'\n';
            int ok = 1;
            for(int i = 0; i < strlen(word) && ok; i++)
                if(word[i] == x)
                {
                    if(s[i] != x) s[i] = x; 
                    else ok = 0;
                }
                
            if(ok == 0) cout<<"You already guessed "<<x<<'\n';
        }
        else{                                       // no
            cout<<x<<" is not in the word >:) !"<<'\n';
            if(strchr(wrong, x) == NULL){
                wrong[w] = x;
                w += 2;
                guess++;
            }
            else cout<<"You already guessed "<<x<<'\n';
        }
        
        draw_man(guess);
        cout<<"the word: ";
        for(int i = 0; i < strlen(word); i++)
            cout<<s[i]<<" ";
        cout<<'\n'<<"misses: "<<wrong<<'\n'<<"-------------------------------------"<<'\n';
        }
        
        else cout<<"that character isn't allowed >:( ! try again :) "<<'\n'<<'\n';
        
    }
    cout<<'\n';
    if(strcmp(word,s) == 0) game_won();
    else game_over(word);

    return 0;
}



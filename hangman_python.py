
import random

def game_won():
    print ('''   
    *•. ♡  GAME WON! ♡ .•*          

                    you get to live another day....  ''')
                    
    
def game_over(word):
    print("The word was: " + word)
    print ('''
 
 

            G̵A̵M̸E̷  ̷O̶V̵E̵R̴

        T̴H̶E̵ ̴H̸A̷N̷G̵M̷A̵N̷ ̸G̴O̶T̸ ̸Y̴O̵U̴ ̵             ''' )
        
    
def draw_man(nr):
    print (" _____")
    print("|     ⋮")
    if (nr >= 1): print("|    ", end = ' ')
    else: print("|    ")
    if(nr >= 1): print ('0')
    if(nr >= 2): print("|   ", end = ' ')
    else: print("|   ")
    if(nr >= 3): print("/",end = '')
    elif (nr >=2): print(" ", end = '')
    if(nr >= 2): 
        if(nr >= 4): print("|",end = '')
        else: print ("|")
    if(nr >= 4): print("\\")
    if(nr >= 5): print("|   ",end = ' ')
    else: print("|   ")
    if(nr >= 5): 
        if(nr >= 6): print("/",end = ' ')
        else: print("/")
    if(nr >= 6): print("\\")
    print("|__________")
    print('\n')
    if(nr == 0): print("No hanged parts yet!")
    
def main():
    #category picking
    category = random.choice(["Colors", "Supernatural beings", "Astronomy terms"])
    print("-------------------------------------")
    print ("The category is: "  + category)
    
    #word picking
    if(category == "Colors"):
        word = random.choice(["indigo", "ivory", "peach", "coral","azure", "periwinkle", "mauve", "plum", "viridian", "ultramarine"])
        
    if(category == "Supernatural beings"):
        word = random.choice(["jackalope", "cerberus", "vampire", "banshee", "ghoul", "werewolf", "dragon", "centaur", "selkie", "angel"])
        
    if(category == "Astronomy terms"):
        word = random.choice(["celestial", "comet", "crater", "asteroid", "ecliptic", "eclipse", "meteor", "zenith", "constellation", "galaxy"])

    print ("Number of letters:", end = ' ')
    print(len(word))
    
    #guess word creation 
    guess = 0
    wrong = ["_"] * 6
    s = ["-"] * len(word)
    w = 0
    
    print("-------------------------------------")
    print("Let the game begin!")
    print("-------------------------------------")
    
        
    while(guess < 6 and "-" in s):
        x = input("Guess a letter: ")
        if(x.islower() == False):
            print("that character isn't allowed >:( ! try again :) ", '\n')
            continue
        if(x in word): 
            print(x + " is in the word :) !")
            ok = 1
            for i in range(len(word)):
                if(ok and word[i] == x):
                    if(s[i] != x): s[i] = x;
                    else: ok =0 
            if(ok == 0): print("You already guessed " + x)
        else:
            print(x + " is not in the word >:) !")
            if(x not in wrong):
                wrong[w] = x
                w += 1
                guess += 1
            else: print("You already guessed " + x)
            
        draw_man(guess)
        print("the word:", end = ' ')
        for i in range(len(word)-1):
            print(s[i],end = ' ')
        print(s[len(word)-1])
        print("misses:", end = ' ')
        for i in range(5):
            print(wrong[i], end = ' ')
        print(wrong[5])
            
        print("-------------------------------------")
        
    print('\n')
    if(guess == 6): game_over(word)
    else: game_won()

    
    
main()
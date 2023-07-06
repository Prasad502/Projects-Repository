import random,sys

global ai_score,user_score

def prs(input):
    global ai_score, user_score
    ai_score = 0
    user_score = 0
    
    Flag_User = "lost"
    
    player = input
    
    ai = random.randint(1,5)
    
    if (ai == 1):
        ai_player = "rock"
    elif (ai == 2):
        ai_player = "paper"
    elif (ai == 3):
        ai_player = "scissor"
    elif (ai == 4):
        ai_player = "lizard"
    elif (ai == 5):
        ai_player = "spock"
        
    print("User Played : " + str(player) + " and computer played : " + str(ai_player))

    if ((ai_player == "rock" and player == "lizard") or (ai_player == "rock" and player == "scissor")):
        ai_score += 1

    elif ((ai_player == "paper" and player == "rock") or (ai_player == "paper" and player == "spock")):
        ai_score += 1

    elif ((ai_player == "scissor" and player == "paper") or (ai_player == "scissor" and player == "lizard")):
        ai_score += 1

    elif ((ai_player == "lizard" and player == "spock") or (ai_player == "lizard" and player == "paper")):
        ai_score += 1
        
    elif ((ai_player == "spock" and player == "scissor") or (ai_player == "spock" and player == "rock")):
        ai_score += 1
        
    elif (ai_player == player):
        Flag_User = "draw"
    
    else:
        user_score += 1
        Flag_User = "win"
    
    return ai_score,user_score,Flag_User,ai_player,player
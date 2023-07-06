import eel
from AI.RPSLS import prs

eel.init('Files')

@eel.expose
def User_Input(Input):
    ai_score, user_score, Flag_User, ai_player, player = prs(Input)
    print(ai_score, user_score, Flag_User)
    temp = list()
    temp.append(ai_score)
    temp.append(user_score)
    temp.append(Flag_User)
    temp.append(ai_player)
    temp.append(player)
    temp1 = tuple(temp)
    eel.User_Input_return(temp1)

eel.start("index.html", size=(1920,1080))
# 2048-
ENGG1340_GroupProject
Team members: Wong Chak Chung, Mak Yu To
Description:
This game is a text-based version of the popular puzzle game 2048. The object of the game is combine number tiles to get the 2048 tile or player can challenge the highest score that they can reach. 

Game rules:
The game starts with a 4 times 4 gird and two tiles numbered 2 appear in random positions in the grid.Each turn, player can enter w, a, s, d which separately represent up, left, down, right. After the player enter a direction, the tiles on the grid will move to the direction that the player chose as far as possible until there is the boundary of the grid or a different numbered tile. If there is a same numbered tiles on the direction that the player chose of a tile,  the two tiles will add up to a tile with a larger number. E.g. 
-------------------------
| 2   |     |     |     |
-------------------------
-------------------------
| 2   |     |     |     |
-------------------------
-------------------------
|     |     |     |     |
-------------------------
-------------------------
|     |     |     |     |
-------------------------
if the player chooses w (i.e. up) :
-------------------------
| 4   |     |     |     |
-------------------------
-------------------------
|     |     |     |     |
-------------------------
-------------------------
|     |     |     |     |
-------------------------
-------------------------
|     |     |     |     |
-------------------------
After this, a random tile of number 2 or 4 will appear in a random empty position of the grid. Then player chose a direction again and the the preceding repeats until the player get 2048 (which means the player wins) or there is no further possible move (which means game over).

Features:
1. 


# 2048-
## ENGG1340_GroupProject
Team members: Wong Chak Chung, Mak Yu To
## Description:
This game is a text-based version of the popular puzzle game 2048. The object of the game is combine number tiles to get the 2048 tile or player can challenge the highest score that they can reach. 
## Game rules:
The game starts with a 4 times 4 gird and two tiles numbered 2 appear in random positions in the grid.Each turn, player can enter w, a, s, d which separately represent up, left, down, right. After the player enter a direction, the tiles on the grid will move to the direction that the player chose as far as possible until there is the boundary of the grid or a different numbered tile. If there is a same numbered tiles on the direction that the player chose of a tile,  the two tiles will add up to a tile with a larger number. e.g.  
\---------------------  
|&nbsp; 2 &nbsp;|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
\---------------------  
|&nbsp; 2 &nbsp;|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
\---------------------  
|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
\---------------------  
|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
if the player chooses w (i.e. up) :  
\---------------------  
|&nbsp; 4 &nbsp;|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
\---------------------  
|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
\---------------------  
|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
\---------------------  
|&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |&emsp; &nbsp; |  
\---------------------  
After this, a random tile of number 2 or 4 will appear in a random empty position of the grid. Then player chose a direction again and the the preceding repeats until the player get 2048 (which means the player wins) or there is no further possible move (which means game over).

## Features:
1. Tiles will randomly appear on the grid. (code requirement 1 Generation of random game sets or events, using rand() and srand() in stdlib)
2. The game can be continued after reaching 2048. 
3. Top 10 highest score will be recorded. (code requirement 4 File i/o , the scores can be stored in a file as integers and can be read afterwards)
4. Game can be saved and continued. (code requirement 4 File i/o , the 4 times 4 grid can be output as a series of integers and can be loaded again)
5. New game mode (tbc)


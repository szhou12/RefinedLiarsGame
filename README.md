# The Refined Liar's Dice Game: A ECE114 Project

## Synopsis
The refined version of Liar’s Game is designed in this project.

The original version refers to [liar's dice](https://en.wikipedia.org/wiki/Liar%27s_dice).

## Getting Started
This game is designed for 2 to 6 players.

To start this game, the project asks how many players are going to play and each one’s name. Each player will be given 5 dice. Then in each round, each player rolls five dice and keeps the result secret from other players. They then take turns bidding on the total results.

The rule of bidding is designed as follows: the player announces any face value and the total number of dice that the player believes are showing that value in the game.

Players take turns to make the bid. Each player has two choices during his/her turn: to make a higher bid, or to challenge the previous bid – call the previous player “liar”.

The rule to make a higher bid is like this: a valid bid must have either higher face value than the bid or higher quantity of any face value than the previous bid.

For example, if the previous player bids “I have three twos”, then the current player must bid as “I have four twos”, “I have three fours”, “I have four ones” and so on.

When a player believes that the bidding has gone too high, he/she challenges the previous bid.
If this happens, all dice are revealed.
If the bid is valid, that is, at least as many of the face value are showing as were bid, then the previous player wins.
Otherwise, the challenger wins.
For example, the previous player bids “three twos”, and the current player challenges the previous player’s bid.
If there are at least three twos on the table, then the previous player wins and the current player loses. Otherwise, the current player wins and the previous player loses.

Any player who wins will get one point. But any player who loses will lose one point.
When they want to end the game, the project will calculate and report the points each player have. The player who has the highest number of points is the winner.

## Contributor
Shuyu Zhou

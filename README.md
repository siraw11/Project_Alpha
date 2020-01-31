# Octopus Killer

Something here...

**Gameplay Video**

https://streamable.com/yqlkb

# Game Screens

**Home Screen**

![Alt text](/Screenshots%20%26%20GIFS/Home.png?raw=true "Home")

**Achievement Screen**

![Alt text](/Screenshots%20%26%20GIFS/Achievement.png?raw=true "Achievement")

**Game Screen**

The game target is to kill all the octopus, you can shoot in all four direction. The enemies have two HP each, you have five.
The game has two levels, at the start of any level your healt will be restored.

![Alt text](/Screenshots%20%26%20GIFS/Game.png?raw=true "Game")

**Pause Screen**

![Alt text](/Screenshots%20%26%20GIFS/Pause.png?raw=true "Pause")

**Death Screen**

![Alt text](/Screenshots%20%26%20GIFS/Death.png?raw=true "Death")

**End Screen**

![Alt text](/Screenshots%20%26%20GIFS/end.png?raw=true "End")

**Bullet Potion**

The bullet potion is meant to multiply the shooting range of the bullet, as you can see in the GIF down below you can kill octopus from a larger distance.

![Alt text](/Screenshots%20%26%20GIFS/Clip_Bullet.gif?raw=true "Bullet")

**Speed & Jump Potion**

This potion makes you faster and allows you to jump higher, so you can jump three blocks heights

![Alt text](/Screenshots%20%26%20GIFS/Clip_Jump.gif?raw=true "Jump")

**Enemy behaviour**

The enemy behaviour is based on a Strategy Pattern, there are four states: Idle, Catch, Attack e Reset.

Idle: Wait for the player, we switch to Idle only if the enemy is stopped and if he is at the spawn point;

Catch: The enemy starts chasing the player when you enter in his spawn range. The movement is set according to the position of the player, before setting the new position a checkCollision is made with the map;

Attack: If enemy and player collide, and the reload time of the attack is less than difference between the current time and that of the last attack, enemy passes to Attack state;

Reset: We go into the Reset state when the player is no longer in the enemy's spawn range and the enemy isn't in the spawn point, as in the case of Catch, we will check the collision with the map before setting the new position.

![Alt text](/Screenshots%20%26%20GIFS/Clip_Enemy.gif?raw=true "Enemy")

**Death**

Oh... yeah, you can die too!

![Alt text](/Screenshots%20%26%20GIFS/Clip_Death.gif?raw=true "Death")

#pragma once


#define SCREEN_WIDTH 1920

#define SCREEN_HEIGHT 1080

#define SPLASH_STATE_SHOW_TIME 0.1

#define SPLASH_SCENE_BACKGROUND_FILEPATH "../Resources/MainMenu/background.jpg"

#define FONT "../Resources/Font/Bebas-Regular.ttf"

#define MAIN_MENU_BACKGROUND_FILEPATH "../Resources/MainMenu/background.jpg"

#define PAUSE_BACKGROUND_FILEPATH "../Resources/MainMenu/background.jpg"

#define ARCHER_BUTTON_FILEPATH "../Resources/MainMenu/Archer_Button.png"

#define KNIGHT_BUTTON_FILEPATH "../Resources/MainMenu/Knight_Button.png"

#define MAGE_BUTTON_FILEPATH "../Resources/MainMenu/Mage_Button.png"

#define RETRY_BUTTON_FILEPATH "../Resources/MainMenu/RetryButton.png"

#define EXIT_BUTTON_FILEPATH "../Resources/MainMenu/ExitButton.png"

#define GAMEWIN_BACKGROUND_FILEPATH "../Resources/MainMenu/GameWin.jpg"

#define GAMEOVER_BACKGROUND_FILEPATH "../Resources/MainMenu/GameOver.jpg"

#define MAIN_MENU_TITLE_FILEPATH "../Resources/MainMenu/Game Title.png"

#define MAIN_MENU_PLAY_BUTTON "../Resources/MainMenu/Play_Button.png"

#define RESUME_BUTTON "../Resources/MainMenu/Resume Button.png"

#define HOME_BUTTON "../Resources/MainMenu/Home Button.png"

#define SELECT_CLASS "../Resources/MainMenu/SelectClass_Button.png"

#define RETRY_BUTTON "../Resources/MainMenu/Retry Button.png"

#define HEART_UI "../Resources/Sprites/item/heart.png"

#define MANA_UI "../Resources/Sprites/item/mana.png"

#define ARMOR_UI "../Resources/Sprites/item/armor.png"

#define ARROW_UI "../Resources/Sprites/item/arrow_1.png"

#define TIME_BEFORE_SHOWING_GAME_OVER 1

#define STATE_WON 1

#define STATE_LOSE 2

#define STATE_PLAYING 0

#define SCALE 3

#define TILE_WIDTH 32

#define TILE_HEIGHT 32

#define LEFT_FRONT_DOOR 17

#define RIGHT_FRONT_DOOR 18

#define LEFT_SIDE_DOOR 19

#define RIGHT_SIDE_DOOR 20

#define ENEMY_WALK_DISTANCE 320

#define ENEMY_SCALE 2.5

#define HERO_SCALE 1.75

#define ENEMY_SIZE 64

#define HERO_SIZE 64

#define PROJECTILE_SIZE 64

#define BOSS_PROJECTILE_WIDTH 64

#define BOSS_PROJECTILE_HEIGTH 50

#define BOSS_PROJECTILE_SCALE 2.f

#define BOSS_SCALE 5

#define BOSS_SIZE 64

#define MAP_WIDTH 120*32

#define MAP_HEIGHT 84*32

#define CHEST_SIZE 32

#define CHEST_SCALE 3

enum GameStatus{
    isPlaying, isGameOver, isWin
};
















































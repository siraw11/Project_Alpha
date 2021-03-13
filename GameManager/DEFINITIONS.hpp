#pragma once

#define FONT "./Resources/Font/Bebas-Regular.ttf"

#define MAIN_MENU_BACKGROUND_FILEPATH "./Resources/MainMenu/background.jpg"

#define ARCHER_BUTTON_FILEPATH "./Resources/MainMenu/Archer_Button.png"

#define ARCHER_MENU_FILEPATH "./Resources/MainMenu/archer_menu.png"

#define KNIGHT_BUTTON_FILEPATH "./Resources/MainMenu/Knight_Button.png"

#define KNIGHT_MENU_FILEPATH "./Resources/MainMenu/knight_menu.png"

#define MAGE_BUTTON_FILEPATH "./Resources/MainMenu/Mage_Button.png"

#define MAGE_MENU_FILEPATH "./Resources/MainMenu/mage_menu.png"

#define RETRY_BUTTON_FILEPATH "./Resources/MainMenu/RetryButton.png"

#define EXIT_BUTTON_FILEPATH "./Resources/MainMenu/ExitButton.png"

#define MAIN_MENU_TITLE_FILEPATH "./Resources/MainMenu/Game Title.png"

#define WIN_TITLE_FILEPATH "./Resources/MainMenu/WinState_title.png"

#define GAME_OVER_TITLE_FILEPATH "./Resources/MainMenu/GameOver_title.png"

#define SELECT_CLASS "./Resources/MainMenu/SelectClass_Button.png"

#define RETRY_BUTTON "./Resources/MainMenu/RetryButton.png"

#define HEART_UI "./Resources/Sprites/item/heart.png"

#define MANA_UI "./Resources/Sprites/item/mana.png"

#define ARMOR_UI "./Resources/Sprites/item/armor.png"

#define ARROW_UI "./Resources/Sprites/item/arrow_1.png"

#define TROPHY_FILEPATH "./Resources/Sprites/item/trophy.png"

#define ARROW_SOUND "./Resources/Sound/arrow-whoosh.wav"

#define CHEST_OPENING "./Resources/Sound/Chest_Opening.wav"

#define SWORD_SOUND "./Resources/Sound/dagger-woosh.wav"

#define FEMALE_HIT_SOUND "./Resources/Sound/female-pain.wav"

#define FIREBALL_SOUND "./Resources/Sound/fire-woosh.wav"

#define MAN_HIT_SOUND "./Resources/Sound/man-pain.wav"

#define MONSTER_HIT_SOUND "./Resources/Sound/monster-pain.wav"

#define OW_SOUND "./Resources/Sound/ow-exclamation.wav"

#define SCREAM_SOUND "./Resources/Sound/scream-pain.wav"

#define BONE_SOUND "./Resources/Sound/bone-crack.wav"

#define CLICK_SOUND "./Resources/Sound/click.wav"

#define YOU_LOSE_SOUND "./Resources/Sound/you-lose.wav"

#define YOU_WIN_SOUND "./Resources/Sound/you-win.wav"

#define BACKGROUND_SOUND "./Resources/Sound/outlast.wav"


const int SCALE=3;

const int TILE_WIDTH = 32;

const int TILE_HEIGHT = 32;

const int LEFT_FRONT_DOOR = 17;

const int RIGHT_FRONT_DOOR = 18;

const int LEFT_SIDE_DOOR = 19;

const int RIGHT_SIDE_DOOR = 20;

const int ENEMY_WALK_DISTANCE = 320;

const float ENEMY_SCALE = 2.5;

const float HERO_SCALE = 1.75;

const int ENEMY_SIZE = 64;

const int  HERO_SIZE = 64;

const int PROJECTILE_SIZE = 64;

const int  BOSS_PROJECTILE_WIDTH = 64;

const int  BOSS_PROJECTILE_HEIGTH = 50;

const int  BOSS_PROJECTILE_SCALE = 2.f;

const int  BOSS_SCALE = 5;

const int  BOSS_SIZE = 64;

const int  MAP_WIDTH = 120*32;

const int  MAP_HEIGHT = 84*32;

const int  CHEST_SIZE = 32;

const int CHEST_SCALE = 3;

const int BADGE_WIDTH = 120;

const int BADGE_SCALE = 3;

const int TEXT_BADGE_WIDTH = 180;

const int TEXT_BADGE_HEIGHT = 20;

const float TEXT_SCALE = 1.5;

const int TEXT_POSX = 3830;

const int TROPHY_TEXTURE_SCALEX = 2;

const int TROPHY_TEXTURE_SCALEY = 2;

const float TROPHY_SCALE = 3.5;


const int TROPHY_POSY = 20;

const int TROPHY_POSX = 3775;

enum GameStatus{
    isPlaying, isGameOver, isWin
};

enum class BadgeType{
    walker, killer
};















































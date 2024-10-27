#include "SFML/Graphics.hpp" 
#include "Player.h"
#include "Display.h"

import Paths;

int main()
{
    Display display;
    display.loadLogoTXT(LOGO_TEXTURE_PATH);
    display.loadMenuTXT(MENU_TEXTURE_PATH);
    display.loadPlatformTXT(PLATFORM_TEXTURE_PATH);
    display.loadPlayerTXT(PLAYER_TEXTURE_PATH);
    display.loadWallTXT(WALL_TEXTURE_PATH);
    display.loadBackgroundTXT(BACKGROUND_TEXTURE_PATH);
    display.loadCoinTXT(COIN_TEXTURE_PATH);
    display.loadBoardTXT(BOARD_TEXTURE_PATH);
    display.loadLeaderboard(LEADERBOARD_FILE_PATH);
    display.loadControlsTXT(CONTROLS_TEXTURE_PATH);
    display.begin();

    return 0;
}
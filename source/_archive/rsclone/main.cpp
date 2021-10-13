#include "game.h"

int main()
{
	Game game;
	game.Init();
	game.LoadAssets();
	game.Loop();

	return 0;
}

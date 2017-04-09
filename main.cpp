

#include <memory>

#include "game.hpp"

int main(int argc, char** argv) {


	auto game = std::make_unique<Game>();
	
	game->run();
	
	return 0;
}
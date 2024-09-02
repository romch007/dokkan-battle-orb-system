#pragma once

#include <vector>
#include <SFML/Graphics/Color.hpp>

#include <orb.hpp>

void dfs(const Board& board, const Orb* orb, const sf::Color color, std::vector<const Orb*>& currentPath, std::vector<const Orb*>& longestPath);

std::vector<const Orb*> findLongestPath(const Board& board, const Orb* startingOrb);

#include <algorithm.hpp>

void dfs(const Board& board, const Orb* orb, const sf::Color color, std::vector<const Orb*>& currentPath, std::vector<const Orb*>& longestPath) {
    if (!orb) return;

    size_t x = orb->getX();
    size_t y = orb->getY();
    if (orb->color() != Color::RAINBOW && orb->color() != color)
        return;

    currentPath.push_back(orb);

    const Orb* left;
    const Orb* right;
    if (y-- % 2 == 0) {
        left = x != 0 ? &board[y][x - 1] : nullptr;
        right = &board[y][x];
    } else {
        left = &board[y][x];
        right = x < board[y].size() - 1 ? &board[y][x + 1] : nullptr;
    }

    // if the first orb is a rainbow one
    if (color == Color::RAINBOW) {
        dfs(board, left, left ? left->color() : color, currentPath, longestPath);
        dfs(board, right, right ? right->color() : color, currentPath, longestPath);
    } else {
        dfs(board, left, color, currentPath, longestPath);
        dfs(board, right, color, currentPath, longestPath);
    }

    if (currentPath.size() > longestPath.size())
        longestPath = currentPath;

    currentPath.pop_back();
}

std::vector<const Orb*> findLongestPath(const Board& board, const Orb* startingOrb) {
    std::vector<const Orb*> currentPath, longestPath;
    dfs(board, startingOrb, startingOrb->color(), currentPath, longestPath);
    return longestPath;
}

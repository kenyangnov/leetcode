#include <algorithm>

#define MAX_X 10
#define MAX_Y 10
// 已知以下接口表示位置(x, y)上有无障碍物：
// 返回0则无障碍物，返回1则有障碍物
bool isBlock(int x, int y);

// 任务：实现函数 bool remove(int x1, int y1, int x2, int y2)，判断任意两个给定的点能否消除

// STEPS:
// 1. 水平条件
static bool horizon(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return false;
    }
    if (x1 != x2) {
        return false;
    }

    int start_y = std::min(y1, y2);
    int end_y = std::max(y1, y2);
    for (int j = start_y; j < end_y; j++) {
        if (isBlock(x1, j)) {
            return false;
        }
    }
    return true;
}

// 2. 垂直检测
static bool vertical(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return false;
    }
    if (y1 != y2) {
        return false;
    }

    int start_x = std::min(x1, x2);
    int end_x = std::max(x1, x2);
    for (int i = start_x; i < end_x; i++) {
        if (isBlock(i, y1)) {
            return false;
        }
    }
    return true;
}

// 3. 一个拐角检测
static bool turn_once(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return false;
    }
    // 拐角至可能是：(c_x, c_y) 或 (d_x, d_y)
    int c_x = x1, c_y = y2;
    int d_x = x2, d_y = y1;

    bool ret = false;
    if (!isBlock(c_x, c_y)) {
        ret = ret || (horizon(x1, y1, c_x, c_y) && vertical(c_x, c_y, x2, y2));
    }
    if (!isBlock(d_x, d_y)) {
        ret = ret || (vertical(x1, y1, d_x, d_y) && horizon(d_x, d_y, x2, y2));
    }
    if (ret) {
        return true;
    }
    return false;
}

// 4. 两个拐角检测
static bool turn_twice(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return false;
    }
    for (int i = 0; i <= MAX_X; i++) {
        for (int j = 0; j <= MAX_Y; j++) {
            if (i != x1 && i != x2 && j != y1 && j != y2) {
                continue;
            }
            if ((i == x1&& j == y1) || (i == x2 && j == y2)) {
                continue;
            }
            if (isBlock(i, j)) {
                continue;
            }
            if (turn_once(x1, y1, i, j) && (horizon(i, j, x2, y2) || vertical(i, j, x2, y2))) {
                return true;
            }
            if (turn_once(i, j, x2, y2) && (horizon(x1, y1, i, j) || vertical(x1, y1, i, j))) {
                return true;
            }
        }
    }
    return false;
}

// 5. 整合
bool remove(int x1, int y1, int x2, int y2) {
    bool ret;

    ret = horizon(x1, y1, x2, y2);
    if (ret) {
        return true;
    }

    ret = vertical(x1, y1, x2, y2);
    if (ret) {
        return true;
    }

    ret = turn_once(x1, y1, x2, y2);
    if (ret) {
        return true;
    }

    ret = turn_twice(x1, y1, x2, y2);
    if (ret) {
        return true;
    }

    return false;
}
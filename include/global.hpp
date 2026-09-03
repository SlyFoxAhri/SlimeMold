#pragma once
#include "iostream"

extern int cellsize;
extern int cellcount;

enum startPos {SCATTER_START = 0, CENTER_START = 1, CUSTOM_POS = 2};
enum edgeBvr {WRAP = 0, EDGE = 1};
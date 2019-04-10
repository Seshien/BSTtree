#pragma once
#include "pch.h"
bool compare(std::vector<int>::iterator left, std::vector<int>::iterator right);
bool compare(std::vector<int>& data, int left, int right);
void mergeSort(std::vector<int>& data);
void _mergeSort(std::vector<int>& data, int left, int right);
void merge(std::vector<int>& data, int left, int mid, int right);
void show(const std::vector<int> & d);
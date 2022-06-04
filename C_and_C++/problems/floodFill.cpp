#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  

using namespace std;



void dfs(int i, int j, int m, int n, int oldColor, int newColor, vector<vector<int>>& image){

	/* std::cout << "here1 "<< i<<" "<<j << std::endl; */
	/* if(i == 0 and j == 2){ */
	/* 	std::cout << "Reached 1: " << image[i][j] << std::endl; */
	/* } */
	if(i < 0 || i >= m || j < 0 || j >= n){
		/* if(i == 0 and j == 2){ */
		/* 	std::cout << "Reached final " <<i<< " "<< j << std::endl; */
		/* } */
		return;
	}
	/* if(i == 0 and j == 2){ */
	/* 	std::cout << "Reached 2: " << std::endl; */
	/* } */
	if(image[i][j] != oldColor){
		return;
	}
	/* if(i == 0 and j == 2){ */
	/* 	std::cout << "Reached 3: " << std::endl; */
	/* } */
	image[i][j] = newColor;
	dfs(i-1, j, m, n, oldColor, newColor, image);
	dfs(i+1, j, m, n, oldColor, newColor, image);
	dfs(i, j-1, m, n, oldColor, newColor, image);
	dfs(i, j+1, m, n, oldColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int m = image.size();
	int n = image[0].size();
	int oldColor = image[sr][sc];
	if(oldColor != newColor){
		dfs(sr, sc, m, n, oldColor, newColor, image);
	}
	return image;
}

int32_t main(){

	vector<vector<int>> image = {{0,0,0}, {0,1,1}};
	int sr = 1;
	int sc = 0;
	int newColor = 2;
	for(auto v : floodFill(image, sr, sc, newColor)){
		for(auto i : v){
			std::cout << i <<" ";
		}
		std::cout << std::endl;
	}
	

	return 0;
}


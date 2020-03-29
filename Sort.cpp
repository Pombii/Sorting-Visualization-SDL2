
#include "SDL.h" 
#include <iostream>
#include <vector>
using namespace std;

class SortingAlgo {
public:

	void resetWindow(SDL_Renderer* r) {
		SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
		SDL_RenderClear(r);
	}

	void drawlines(SDL_Renderer* r, vector<SDL_Rect*>& initvec) {
		int randHeight = 0;
		for (int i = 0; i < 780; i += 21) {													//Randomly generates a line with a length between 0-400
			SDL_Rect* myrect = new SDL_Rect();
			randHeight = rand() % 400;		
			myrect->x = i;
			myrect->w = 20;
			myrect->y = 400;
			myrect->h = -randHeight;
			initvec.push_back(myrect);													
			SDL_SetRenderDrawColor(r, 255, 255, 255, 255);						        
			SDL_RenderFillRect(r, myrect);
			SDL_RenderPresent(r);
			SDL_Delay(10);
		}

	}

	void bubbleSort(SDL_Renderer* r, vector<SDL_Rect*>& v) {
		int temp;
		for (int i = 0; i < v.size(); i++) {											//Starting the bubble sort
			for (int j = 0; j < v.size() - 1; j++) {
				if (v[j]->h < v[j + 1]->h) {													//Swaps the two elements
					SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
					SDL_RenderFillRect(r, v[j]);
					SDL_RenderPresent(r);
					SDL_Delay(75);
					SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
					SDL_RenderFillRect(r, v[j]);

					temp = v[j]->h;
					v[j]->h = v[j + 1]->h;
					v[j + 1]->h = temp;

					SDL_SetRenderDrawColor(r, 255, 255, 255, 255);						//Provides the animation
					SDL_RenderFillRect(r, v[j]);
					SDL_RenderFillRect(r, v[j + 1]);

					SDL_RenderPresent(r);
				}
			}
		}
	}


	void selectionSort(SDL_Renderer* r, vector<SDL_Rect*>& v) {
			int temp = 0;
			int minindex = 0;
			for (int i = 0; i < v.size() - 1; i++) {											//starting the selection sort
				minindex = i;
				for (int j = i + 1; j < v.size(); j++) {
					if (v[j]->h >= v[minindex]->h) 
						minindex = j;															//swaps the two indices of the lowest element
				}
				SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
				SDL_RenderFillRect(r, v[minindex]);
				SDL_RenderFillRect(r, v[i]);
				SDL_RenderPresent(r);
				SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
				SDL_RenderFillRect(r, v[i]);
				SDL_Delay(500);

				temp = v[minindex]->h;
				v[minindex]->h = v[i]->h;
				v[i]->h = temp;

				SDL_SetRenderDrawColor(r, 255, 255, 255, 255);						//Provides the animation
				SDL_RenderFillRect(r, v[i]);
				SDL_RenderFillRect(r, v[minindex]);
				SDL_RenderPresent(r);

			}
		}
};


int main(int argc, char* argv[])
{

	SDL_Window* mywin;
	SDL_Renderer* rend;
	SortingAlgo S;
	vector<SDL_Rect*> bubVec;
	vector<SDL_Rect*> selVec;
	vector<SDL_Rect*> quickVec;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {										//Starts the SDL library to 0
		cout << "error initializing SDL: %s\n" << SDL_GetError() << endl;
	}

	mywin = SDL_CreateWindow("Sorting", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, SDL_WINDOW_RESIZABLE);						//Creating a window and renderer
	rend = SDL_CreateRenderer(mywin, -1, SDL_RENDERER_ACCELERATED);


	S.drawlines(rend, bubVec);
	SDL_Delay(2000);
	S.bubbleSort(rend, bubVec);
	
	S.resetWindow(rend);

	S.drawlines(rend, selVec);
	SDL_Delay(2000);
	S.selectionSort(rend, selVec);
	SDL_Delay(10000);

	SDL_DestroyRenderer(rend);											//Destroys the window and renderer
	SDL_DestroyWindow(mywin);
	SDL_Quit();

	return 0;
}

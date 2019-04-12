/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <SDL_mixer.h>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		#ifdef _SDL_TTF_H
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

//The application time based timer
class LTimer
{
    public:
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};

class Fruit
{
    friend class Dot;
    public:

		//Initializes the variables
		Fruit();

        //The dimensions of the fruit.
        static const int FRUIT_WIDTH = 30;
        static const int FRUIT_HEIGHT = 30;

		//Shows the fruit on the screen
		void render();
		void PositionX();
		void PositionY();

		SDL_Rect fCollider;


    private:
		//The X and Y offsets of the fruit
        int fPosX, fPosY;



};

//The dot that will move around on the screen
class Dot
{
    public:
		//The dimensions of the dot
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 20;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 7;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e);

		//Moves the dot
		void move(Dot body_list[], int body_lth);

		//Shows the dot on the screen
		void render();

        //Dot's collision box
        SDL_Rect mCollider;

        		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;

    private:



};



//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Box collision dectector.
bool checkcollision(SDL_Rect a, SDL_Rect b);

Mix_Chunk *gMedium = NULL;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font* gFont = NULL;

//Scene textures
LTexture gTimeTextTexture;
LTexture gPausePromptTexture;
LTexture gStartPromptTexture;
LTexture gPointTexture;
LTexture gDotTexture;
LTexture gFruitTexture;
LTexture gBackTexture;

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}


bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}


	//Return success
	return mTexture != NULL;
}


void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

LTimer::LTimer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void LTimer::start()
{
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void LTimer::stop()
{
    //Stop the timer
    mStarted = false;

    //Unpause the timer
    mPaused = false;

	//Clear tick variables
	mStartTicks = 0;
	mPausedTicks = 0;
}

void LTimer::pause()
{
    //If the timer is running and isn't already paused
    if( mStarted && !mPaused )
    {
        //Pause the timer
        mPaused = true;

        //Calculate the paused ticks
        mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
    }
}

void LTimer::unpause()
{
    //If the timer is running and paused
    if( mStarted && mPaused )
    {
        //Unpause the timer
        mPaused = false;

        //Reset the starting ticks
        mStartTicks = SDL_GetTicks() - mPausedTicks;

        //Reset the paused ticks
        mPausedTicks = 0;
    }
}

Uint32 LTimer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool LTimer::isStarted()
{
	//Timer is running and paused or unpaused
    return mStarted;
}

bool LTimer::isPaused()
{
	//Timer is running and paused
    return mPaused && mStarted;
}

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
    //The sides of the rectangles.
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect  A.
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B.
    leftB = b.x+10;
    rightB = b.x + b.w+10;
    topB = b.y+10;
    bottomB = b.y + b.h+10;

    //If any of the sides from A are outside of B.
    if(bottomA <= topB)
    {
        return false;
    }
    if(topA >= bottomB)
    {
        return false;
    }
    if(rightA <= leftB)
    {
        return false;
    }
    if(leftA >= rightB)
    {
        return false;
    }
    //If none of the sides from A are outside B.
    return true;
}

Fruit::Fruit()
{
    //Initialize the offsets
    PositionX();
    PositionY();
    //Set collision box dimensions.
    fCollider.w = FRUIT_WIDTH;
    fCollider.h = FRUIT_HEIGHT;


}

void Fruit::PositionX()
{
    //srand(time(NULL));
    fPosX=(rand()%610)+1;
    fCollider.x = fPosX;
}

void Fruit::PositionY()
{
    //srand(time(NULL));
    fPosY=(rand()%450)+1;
    fCollider.y = fPosY;
}

Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Set collision box dimension.
    mCollider.w = DOT_WIDTH;
    mCollider.h = DOT_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY = -DOT_VEL;mVelX=0; break;
            case SDLK_DOWN: mVelY = DOT_VEL;mVelX=0;break;
            case SDLK_LEFT: mVelX = -DOT_VEL;mVelY=0; break;
            case SDLK_RIGHT: mVelX = DOT_VEL;mVelY=0; break;
            case SDLK_s:
                mVelX=0;
                mVelY=0;
                break;
            case SDLK_p:
                    mVelX=0;
                    mVelY=0;
                    break;
        }
    }
}

void Dot::move(Dot body_list[], int body_lth)
{

    for(int i=1; i<body_lth; i++)
    {
        if(mVelX>0&&mVelY==0){
          body_list[i].mPosX = body_list[i-1].mPosX-30;
          body_list[i].mPosY = body_list[i-1].mPosY;
        }
        if(mVelX<0&&mVelY==0){
          body_list[i].mPosX = body_list[i-1].mPosX+30;
          body_list[i].mPosY = body_list[i-1].mPosY;
        }
        if(mVelY>0&&mVelX==0){
          body_list[i].mPosY = body_list[i-1].mPosY-30;
          body_list[i].mPosX = body_list[i-1].mPosX;
        }

         if(mVelY<0&&mVelX==0){
          body_list[i].mPosY = body_list[i-1].mPosY+30;
          body_list[i].mPosX = body_list[i-1].mPosX;
        }

    }
    //Move the dot left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    //If the dot went too far to the left or right
    if( ( body_list[0].mPosX < 0 ))
    {
        //Move back
        body_list[0].mPosX += SCREEN_WIDTH;
    }
    if((body_list[0].mPosX+DOT_WIDTH > SCREEN_WIDTH))
    {
        body_list[0].mPosX -=SCREEN_WIDTH;
    }

    //Move the dot up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    //If the dot went too far up or down
    if( ( body_list[0].mPosY < 0 ))
    {
        //Move back
        body_list[0].mPosY += SCREEN_HEIGHT;
    }
    if(( body_list[0].mPosY + DOT_HEIGHT > SCREEN_HEIGHT ))
    {
        body_list[0].mPosY-=SCREEN_HEIGHT;
    }


}

void Fruit::render()
{
    //Show the fruit
    gFruitTexture.render(fPosX,fPosY);
}
void Dot::render()
{
    //Show the dot
	gDotTexture.render( mPosX, mPosY );
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
				//Initialize SDL_ttf
				if(TTF_Init()==-1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !gDotTexture.loadFromFile( "26_motion/ball.bmp" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

    if( !gBackTexture.loadFromFile( "26_motion/bg3.png" ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}
	gMedium = Mix_LoadWAV( "21_sound_effects_and_music/medium.wav" );
	if( gMedium == NULL )
	{
		printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	if( !gFruitTexture.loadFromFile( "Fruuuuuuitttt=)/star.png" ) )
	{
		printf( "Failed to load fruit texture!\n" );
		success = false;
	}
    gFont = TTF_OpenFont( "23_advanced_timers/Capture_it.ttf", 28 );
	if( gFont == NULL )
	{
		printf( "Failed to load Capture_it font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Set text color as black
		SDL_Color textColor = { 0, 0, 0, 255 };

		//Load stop prompt texture
		if( !gStartPromptTexture.loadFromRenderedText( "Direction Key: (Re)Start", textColor ) )
		{
			printf( "Unable to render start/stop prompt texture!\n" );
			success = false;
		}

		//Load pause prompt texture
		if( !gPausePromptTexture.loadFromRenderedText( "P: Pause / S: Stop", textColor ) )
		{
			printf( "Unable to render pause/unpause prompt texture!\n" );
			success = false;
		}

	}

	return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
	gFruitTexture.free();
    gTimeTextTexture.free();
	gStartPromptTexture.free();
	gPausePromptTexture.free();
	gPointTexture.free();
	gBackTexture.free();
	gMedium = NULL;

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int LTH_MAX=30;
int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Set text color as black
			SDL_Color textColor = { 0, 0, 0, 255 };

			//The application timer
			LTimer timer;

			//In memory text stream
			std::stringstream timeText;
			std::stringstream pointText;
			//The fruit that will appear randomly on the screen
			//The dot that will be moving around on the screen
            int body_lth =1;
			Fruit fruit;
			Dot body_list[body_lth];
			int score=0;

			//While application is running
			while( !quit )
			{

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

                    body_list[0].handleEvent(e);

				}

				body_list[0].move(body_list,body_lth);



                if(checkCollision(body_list[0].mCollider, fruit.fCollider))
                {
                    score=score+10;
                    if(body_lth < LTH_MAX)
                    {
                        body_lth++;
                        fruit.PositionX();
                        fruit.PositionY();
                        cout<<"current body_lth:"<<body_lth<<endl;
                        Mix_PlayChannel( -1, gMedium, 0 );
                    }
                }


				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
                gBackTexture.render(0,0);
				//Render
				fruit.render();
                for(int i=0; i<body_lth;i++)
                {
                    body_list[i].render();
                }



                //time display.
                if( e.type == SDL_KEYDOWN )
                {
						//Start/stop
                    if( e.key.keysym.sym == SDLK_UP || SDLK_DOWN || SDLK_LEFT || SDLK_RIGHT )

                    {

                        if(!timer.isStarted())
                        {
                            timer.start();
                            cout<<"timer starts."<<endl;
                        }


                        if( timer.isPaused() )
                        {
                            timer.unpause();
                            cout<<"timer unpaused."<<endl;
                        }

                    }
                        	//Pause/unpause
                    if( e.key.keysym.sym == SDLK_p )
                    {
                            timer.pause();
                            cout<<"timer paused."<<endl;
                    }
                    if(e.key.keysym.sym == SDLK_s)
                    {
                        if( timer.isStarted() )
                        {
                            timer.stop();
                            cout<<"timer stopped."<<endl;
                        }
                    }
                }
                //Set text to be rendered
				timeText.str( "" );
				timeText << "Seconds since start time " << ( timer.getTicks() / 1000.f ) ;
				pointText.str("");
                pointText<< "Score:"<<score;
				//Render text
				if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor ) )
				{
					printf( "Unable to render time texture!\n" );
				}
				if( !gPointTexture.loadFromRenderedText( pointText.str().c_str(), textColor ) )
				{
					printf( "Unable to render point texture!\n" );
				}

                //Render textures
				gStartPromptTexture.render( ( SCREEN_WIDTH - gStartPromptTexture.getWidth() ) / 2, 0 );
				gPausePromptTexture.render( ( SCREEN_WIDTH - gPausePromptTexture.getWidth() ) / 2, gStartPromptTexture.getHeight() );
				gTimeTextTexture.render( ( SCREEN_WIDTH - gTimeTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTimeTextTexture.getHeight() ) / 2 );
				gPointTexture.render((SCREEN_WIDTH-gPointTexture.getWidth())/2,380);
				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

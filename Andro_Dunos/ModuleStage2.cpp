#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleStage1.h"
#include "ModuleStage2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer1.h"
#include "ModulePlayer2.h"
#include "ModuleHiScore.h"
#include "ModuleMixer.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

ModuleStage2::ModuleStage2()	//@AndresSala
{
	//ANDRO DUNOS RECTS
	// Background1Rect  
	background2Rect.x = 48;
	background2Rect.y = 27;
	background2Rect.w = 410; 
	background2Rect.h = 224;

	//map1Rect	
	map2Rect.x = 0;
	map2Rect.y = 0; 
	map2Rect.w = 6154;
	map2Rect.h = 1802;

}

ModuleStage2::~ModuleStage2()
{}

// Load assets
bool ModuleStage2::Start()
{
	LOG("Loading background assets");	// Temporal, must decide if we load a full image,
	bool ret = true;					// a single enormous tileset, maybe a tile array for the background
	
	background2Text = App->textures->Load("Assets/Sprites/Levels/STAGE 2/Tileset/Background_lvl_2.png");
	map2Text = App->textures->Load("Assets/Sprites/Levels/STAGE 2/Tileset/Map_2.png");

	App->player1->Enable();
	if (App->input->secondPlayerState == true) //@AndresSala
	{
		App->player2->Enable();
	}

	// Enemies
	App->enemies->Enable();

	// Collider
	App->collision->Enable();
	
	// Ground Collider
	App->collision->AddCollider({ 0, 198, 320, 224 }, COLLIDER_WALL);

	//Music
	MusicLvl2 = App->mixer->LoadMusic("Assets/Audio/Music/07_Stage_2 -Mechanized-Unit-Loop.ogg");
	Mix_FadeInMusic(MusicLvl2, -1, 1000);
	Mix_VolumeMusic(MUSICVol);
	return ret;
}

bool ModuleStage2::CleanUp()
{
	// reset Background movement (position) values
	movementx = 0;
	movementxBack = 0;
	movementxPlanetsBack = 0;
	movementy = -55;

	//--------
	LOG("Unloading players");
	App->player1->Disable();
	if (App->input->secondPlayerState == true) //@AndresSala
	{
		App->player2->Disable();
	}

	LOG("Unloading enemies");
	App->enemies->Disable();

	LOG("Unloading stage 2");
	App->textures->Unload(background2Text);
	App->textures->Unload(map2Text);

	LOG("Unloading colliders")
		App->collision->Disable();

	Mix_FadeOutMusic(TIMEFADE);
	App->mixer->UnloadMusic(MusicLvl2);

	return true;
}

// Update: draw background
update_status ModuleStage2::Update()
{
	// Draw everything -------------------------------------- Andro Dunos
	App->render->Blit(background2Text, movementxBack, 0, &background2Rect); // level background
	App->render->Blit(map2Text, 0, 0, &map2Rect); // level map

	//make so pressing SPACE the other stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->stage2, App->scene_HiScore, 1);
	}

	//@andressala

	return UPDATE_CONTINUE;
}
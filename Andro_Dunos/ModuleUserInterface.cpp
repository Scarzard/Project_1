#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleMainMenu.h"
#include "ModuleStage1.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStage2.h"
#include "ModulePlayer1.h"
#include "ModulePlayer2.h"
#include "ModuleHiScore.h"
#include "ModuleMixer.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleHiScore.h"
#include "ModuleUserInterface.h"
#include "ModuleFont.h"

ModuleUserInterface::ModuleUserInterface()
{
	//ANDRO DUNOS RECTS

}

ModuleUserInterface::~ModuleUserInterface()
{}

// Load assets
bool ModuleUserInterface::Start()
{
	LOG("Loading User Interface");	
	bool ret = true;

	score = 0;
	font_score = App->fonts->Load("Assets/Sprites/User_Interface/Grafical_Interface/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);
	
	
	return ret;
}

// Unload assets
bool ModuleUserInterface::CleanUp()
{
	LOG("Unloading UI");
	//Unload fonts
	App->fonts->UnLoad(font_score);
	return true;
}

// Update: draw background
update_status ModuleUserInterface::Update()
{
	if (App->mainMenu->IsEnabled() == false)
	{
		App->fonts->BlitText(10, 10, font_score, "1p");

		App->fonts->BlitText(190, 10, font_score, "2p");
	}
	return UPDATE_CONTINUE;
}
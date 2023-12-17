#include "header.h"

using namespace std;
using namespace FMOD;

System* pSystem;
Sound* pSound1, *pSound2;
Channel* pChannel = 0, *pChannel1 = 0;

void SoundSystem() {
	System_Create(&pSystem);

	pSystem->init(4, FMOD_LOOP_OFF, NULL);

	pSystem->createSound("ball_sound.wav", FMOD_LOOP_OFF, 0, &pSound1);

	pSystem->createSound("anipang_bgm.mp3", FMOD_LOOP_NORMAL, 0, &pSound2);

	//pSystem->init(4, FMOD_INIT_NORMAL, NULL);

	//pSystem->createSound("ball_sound.wav", FMOD_LOOP_NORMAL, 0, &pSound1);
}

void Play() {
	pSystem->playSound(pSound1, 0, false, &pChannel);
}

void BgmPlay() {
	pSystem->playSound(pSound2, 0, false, &pChannel1);
}
#pragma once
#include "Systems/SystemComponent.h"
#include "fmod.hpp"
#include <vector>
#include <map>


#define SOUND_MAX 1.0f
#define SOUND_MIN 0.0f
#define SOUND_DEFAULT 0.5f
#define SOUND_WEIGHT 0.1f

enum class SOUND_NAME {NONE = 0, BG, CLICK, MAX_COUNT};

class SoundClass : public SystemComponent
{
public:
	SoundClass();
	~SoundClass();

	void Initialize()override;
	void Update(float) override;
	void Shutdown();
	void Load();

	void Play(SOUND_NAME type);
	void Stop(SOUND_NAME type);
	void ErrorCheck(FMOD_RESULT result);
	void DeleteSound(int type);
	void SetVolume(SOUND_NAME type, float value);
	void Slience(void);

private:
	FMOD::System*												m_fmod_system;
	std::map< SOUND_NAME, FMOD::Channel*>	m_ch;
	std::map< SOUND_NAME, FMOD::Sound*>		m_sound;
	FMOD_RESULT m_result;
};
extern SoundClass* mSOUND;
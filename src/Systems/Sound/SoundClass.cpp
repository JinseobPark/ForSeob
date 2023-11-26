#include "SoundClass.h"

SoundClass* mSOUND = nullptr;
SoundClass::SoundClass()
{
	assert(mSOUND == nullptr && "No more than one instance of Sound system!");
	mSOUND = this;
}

SoundClass::~SoundClass()
{
	Shutdown();
}

void SoundClass::Initialize()
{
	m_result = FMOD::System_Create(&m_fmod_system);
	ErrorCheck(m_result);
	m_result = m_fmod_system->init(32, FMOD_INIT_NORMAL, 0);
	ErrorCheck(m_result);

	Load();
}

void SoundClass::Update(float)
{
	m_fmod_system->update();
}

void SoundClass::Shutdown()
{
	for (auto sound : m_sound)
		sound.second->release();
	m_fmod_system->close();
	m_fmod_system->release();
}

void SoundClass::Load()
{
	m_result = m_fmod_system->createStream("Media/tetris.mp3", FMOD_LOOP_NORMAL, 0, &m_sound[SOUND_NAME::BG]);
	ErrorCheck(m_result);
	m_result = m_fmod_system->createStream("Media/click.wav", FMOD_DEFAULT, 0, &m_sound[SOUND_NAME::CLICK]);
	ErrorCheck(m_result);
}

void SoundClass::Play(SOUND_NAME type)
{
	m_result = m_fmod_system->playSound( m_sound[type], NULL, false, &m_ch[type]);
	ErrorCheck(m_result);
}

void SoundClass::Stop(SOUND_NAME type)
{
	m_ch[type]->stop();
}

void SoundClass::ErrorCheck(FMOD_RESULT result)
{
}

void SoundClass::DeleteSound(int type)
{
}

void SoundClass::SetVolume(SOUND_NAME type, float value)
{
	auto it = m_ch.find(type);
	if (it != m_ch.end()) {
		m_ch[type]->setVolume(value);
	}
}

void SoundClass::Slience(void)
{
}

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <soloud.h>
#include <soloud_wav.h>

struct sound
{
	SoLoud::Wav file;
	float volume = 1.0f, pan = 0.5f, playspeed = 1.0f;
	int handle = 0;
	sound(const char* path)
	{
		file.load(path);
	}
};

class Audio {
public:
	SoLoud::Soloud soloud;

	void init()
	{
		soloud.init();
	}
	void clean()
	{
		soloud.deinit();
	}
	//the settings on your sound will only take effect at least at the second time you play it 
	void play(sound* sound)
	{
		sound->handle = soloud.play(sound->file);         // Play the sound
		soloud.setVolume(sound->handle, sound->volume);           // Set volume; 1.0f is "normal"
		soloud.setPan(sound->handle, sound->pan);             // Set pan; -1 is left, 1 is right
		soloud.setRelativePlaySpeed(sound->handle, sound->playspeed);// Play a bit slower; 1.0f is normal
	}
	void stop(sound* sound)
	{
		sound->file.stop();
	}
	void stopall() {
		soloud.stopAll();
	}
	void setlooppoint(sound* sound, float skipHowManySeconds) {
		double t = sound->file.getLoopPoint();
		sound->file.setLoopPoint(t + skipHowManySeconds);
	}
	void loop(sound* sound, int amountofloops) {
		sound->file.setLooping(amountofloops);
	}
};

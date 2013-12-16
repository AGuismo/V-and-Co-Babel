#include			"PAudioStream.h"

int					main()
{
	PAudioStream	audio;

	if (audio.init())
	{
		audio.record();
		audio.play();
		audio.play();
	}
	system("pause");
}
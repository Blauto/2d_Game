// stdafx.h: do��cz plik do standardowych systemowych plik�w do��czanych,
// lub specyficzne dla projektu pliki do��czane, kt�re s� cz�sto wykorzystywane, ale
// s� rzadko zmieniane
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <thread>
#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <sstream>



// TODO: W tym miejscu odwo�aj si� do dodatkowych nag��wk�w wymaganych przez program


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Player.h"
#include "BallManager.h"
#include "Ball.h"
#include "SlabMenager.h"
#include "Slab.h"
#include "Bonus.h"
#include "BonusMenager.h"
#include "BallMultipler.h"
#include "PaddleShrink.h"
#include "PaddleShuter.h"
#include "PaddleStick.h"
#include "PaddleTenter.h"
#include "SpeedAccelerant.h"
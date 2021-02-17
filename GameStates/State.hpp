#pragma once

#include "../PlayerType.h"
#include "../Hero.h"


namespace Alpha
{
	class State
	{
	public:
		virtual void Init() = 0; //inizializzazione state

		virtual void HandleInput() = 0; //gestisce gli input
		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual void Pause() { } //mette in pausa
		virtual void Resume() { }// riparte
	};
}
#pragma once
#ifndef RENDERER
#define RENDERER

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

namespace qz
{
	class iScene
	{
	public:
		ftxui::Component Renderer = 0;
	};

	class Renderer
	{
	public:
		static Renderer* get();
		static Renderer* initialise();

		void start();
		void stop();

	private:
		Renderer();

		static Renderer* pRenderer_;

		ftxui::ScreenInteractive screen_;
	};
}

#endif // !RENDERER

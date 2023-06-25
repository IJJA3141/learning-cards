#pragma once
#ifndef SCENE
#define SCENE

#include <ftxui/component/component.hpp>

namespace qz
{
	class iScene
	{
	public:
		ftxui::Component Renderer = 0;
	};
}

#endif // !SCENE
